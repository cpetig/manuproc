/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 2002-2003 Adolf Petig GmbH & Co. KG
 *  written by Jacek Jakubowski, Christof Petig, Malte Thoma
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <Auftrag/ppsInstanzReparatur.h>
#include <Auftrag/Auftrag.h>
#include <Lager/Lager.h>
#include <Lager/JumboLager.h>
#include <Lager/RohwarenLager.h>
#include <Lager/FertigWarenLager.h>
#include <Misc/TraceNV.h>
#include <Misc/relops.h>
#include <unistd.h>
#include <Misc/inbetween.h>
#include <Misc/compiler_ports.h>
#include <Artikel/ArtikelStamm.h>
#include <math.h>
#include <selFullAufEntry.h>

bool ppsInstanzReparatur::Reparatur_0er_und_2er(SelectedFullAufList &al, const bool analyse_only) const throw(SQLerror)
{  bool alles_ok=true;
   ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,analyse_only);
   assert(Instanz() != ppsInstanzID::Kundenauftraege);
   
   // Vorsicht, dass al hiernach nicht ver�ndert wird (remove/push)
   std::vector<SelectedFullAufList::iterator> zweier;
   for(SelectedFullAufList::iterator i=al.begin();i!=al.end();++i)
   {  if (i->Id()==AuftragBase::dispo_auftrag_id)
         zweier.push_back(i);
   }
   
   for(SelectedFullAufList::iterator i=al.begin();i!=al.end();++i)
    {  if (i->Id()!=AuftragBase::ungeplante_id) continue;
       AuftragBase::mengen_t menge0er=i->getRestStk();
       if (!menge0er) continue;
       
      for(std::vector<SelectedFullAufList::iterator>::const_iterator j=zweier.begin();j!=zweier.end();++j)
       {  assert ((*j)->Id()==AuftragBase::dispo_auftrag_id);
          if ((*j)->Artikel()!=i->Artikel()) continue;
         if((*j)->getLieferdatum()>i->getLieferdatum()) continue;
         
         if (!(*j)->getRestStk()) continue;

         AuftragBase::mengen_t M=AuftragBase::min(menge0er,(*j)->getRestStk());
         
         analyse("Es existieren passende 0er und 2er",*i,**j,M);
         alles_ok=false;
         
         if(!analyse_only)
          {  AuftragBase::mengen_t M_rest=M;
             AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(*i,
            		AufEintragZu::list_eltern,AufEintragZu::list_ohneArtikel);
             for(AufEintragZu::list_t::reverse_iterator k=L.rbegin();k!=L.rend();++k)
             { AuftragBase::mengen_t M2=AuftragBase::min(k->Menge,M_rest);
                if (!M2) continue;

                i->MengeAendern(-M2,true,k->AEB);
                AufEintrag::ArtikelInternNachbestellen(Instanz(),M2,i->getLieferdatum(),
                		i->Artikel(),k->AEB);

                M_rest-=M2;
                if(!M_rest) break;
             }
             if (!!M_rest) analyse("Fehler: Der 0er hat nicht gen�gend Eltern",*i,M_rest);
             assert(AuftragBase::tolerate_inconsistency || !M_rest);
          }
         menge0er-=M;
         if(!menge0er) break;
       }
    }
  return alles_ok;
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool ppsInstanzReparatur::ReparaturLager(const bool analyse_only) const throw(SQLerror)
{ ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Instanz());
  assert(Instanz()->LagerInstanz());
  std::vector<LagerInhalt> LI=getLagerInhalt(); 

  Query q("select distinct artikelid from auftragentry where instanz=? "
  	"and status=?");
  q << Instanz()->Id() << OPEN;
  std::vector<ArtikelBase> arts;
  q.FetchArray(arts);
  
  for (std::vector<ArtikelBase>::const_iterator i=arts.begin();i!=arts.end();++i)
  {  std::vector<LagerInhalt>::const_iterator j=LI.begin();
     for (;j!=LI.end();++j)
     {  if (*i==j->Artikel()) break;
     }
     if (j==LI.end()) LI.push_back(LagerInhalt(*i));
  }
  return vormerkungen_subtrahieren(LI,analyse_only);
}

bool ppsInstanzReparatur::Lagermenge_setzen(bool analyse_only, const ArtikelBase &art,const AuftragBase::mengen_t &gesmenge,bool retry) const
{   ManuProC::Trace(AuftragBase::trace_channel, __FUNCTION__,
     		NV("art",art),NV("art.Id()",art.Id()),NV("gesmenge",gesmenge));
  bool alles_ok=true;

     bool set_dispo_to_zero=false;
     AuftragBase::mengen_t menge=gesmenge;
     // Vorgemerkte Menge (1er Auftr�ge) wieder abziehen
     // Schon eingetragene Menge wieder abziehen
     SelectedFullAufList auftraglist1=SelectedFullAufList(SQLFullAuftragSelector::
       sel_Artikel_Planung_id(Instanz()->Id(),ManuProC::DefaultValues::EigeneKundenId,art,AuftragBase::plan_auftrag_id));
     // der Selector holt nur die Auftr�ge mit dem Status OPEN
     for (SelectedFullAufList::iterator j=auftraglist1.begin();j!=auftraglist1.end();++j)
       {
         assert(j->Id()==AuftragBase::plan_auftrag_id);
         menge-=j->getRestStk() ;
         if(menge<0) // mehr Menge vorgeplant als vorhanden
         {  analyse("mehr Menge vorgeplant als vorhanden",*j,
         	cH_ArtikelBezeichnung(art)->Bezeichnung(),
         	menge.String());
            alles_ok=false;
            set_dispo_to_zero=true;
            if(!analyse_only)
            {AuftragBase::mengen_t M_rest=-menge;
             AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(*j,
            		AufEintragZu::list_eltern,AufEintragZu::list_ohneArtikel);
             for(AufEintragZu::list_t::reverse_iterator k=L.rbegin();k!=L.rend();++k)
             {  AuftragBase::mengen_t M2=AuftragBase::min(k->Menge,M_rest);
                if (!M2) continue;

		// eine Rekursion w�rde die Menge neu verplanen ...
                j->MengeAendern(-M2,false,k->AEB);
                AufEintrag::ArtikelInternNachbestellen(Instanz(),M2,j->getLieferdatum(),
                		j->Artikel(),k->AEB);

                M_rest-=M2;
                if(!M_rest) break;
             }
             if (!!M_rest) 
             {  if (retry)
                {  analyse("Es ist ein Rest geblieben, erneuter Versuch",*j,M_rest);
                   throw reload();
                }
                analyse("Es ist immer noch ein Rest geblieben, ignoriere Zuordnungen",*j,M_rest);
                j->MengeAendern(-M_rest,false,AufEintragBase());
             }
            }
            menge=0;
           }       
        }

     SelectedFullAufList auftraglist2=SelectedFullAufList(SQLFullAuftragSelector::
          sel_Artikel_Planung_id(Instanz()->Id(),ManuProC::DefaultValues::EigeneKundenId,art,AuftragBase::dispo_auftrag_id));
     assert(auftraglist2.empty() || auftraglist2.size()==1);
     for (SelectedFullAufList::iterator j=auftraglist2.begin();j!=auftraglist2.end();++j)
      {
         if(j->Id()!=AuftragBase::dispo_auftrag_id) assert(!"never get here");
         assert(j->getStueck()==j->getRestStk());
         menge-=j->getRestStk();
         if(set_dispo_to_zero && !!j->getStueck())
          { analyse("set_dispo_to_zero",*j,j->getStueck());
            alles_ok=false;
            if(!analyse_only)
               j->MengeAendern(-j->getStueck(),false,AufEintragBase());
          }
      }
      
     if(menge>0 && !set_dispo_to_zero) 
      { alles_ok=false;
        analyse("DispoAuftr�ge_anlegen",AufEintragBase(Instanz(),2,-1),cH_ArtikelBezeichnung(art)->Bezeichnung(),menge.String());
        if (!analyse_only)
            DispoAuftraege_anlegen(art,menge);
      }
      return alles_ok;
}

bool ppsInstanzReparatur::vormerkungen_subtrahieren(const  std::vector<LagerInhalt> &LI,const bool analyse_only) const
{ bool retry=true;
  bool alles_ok=true;
try_again:
//std::cout << "Anzahl der Artikel im Lager = "<<LI.size()<<'\n';
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Instanz());
  for(std::vector<LagerInhalt>::const_iterator i=LI.begin();
				  		std_neq(i,LI.end());++i)
  {  try
     {  alles_ok&=Lagermenge_setzen(analyse_only,i->Artikel(),
     						i->GesamtMenge(),retry);
     }
     catch (reload &e)
     {  retry=false;
        goto try_again;
     }
  }
   return alles_ok;
}   


void ppsInstanzReparatur::DispoAuftraege_anlegen(const ArtikelBase &artikel,const AuftragBase::mengen_t &menge) const
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Instanz());
   assert(Instanz()->EigeneLagerKlasseImplementiert());
std::cout << "Mengen�nderung im Lager "<<Instanz()<<'\t'<<menge<<" von " << artikel.Id() << '\n';
   if(menge>=0)
      LagerBase(make_value(Instanz())).rein_ins_lager(artikel,menge,false);
}

std::vector<LagerInhalt> ppsInstanzReparatur::getLagerInhalt() const
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Instanz());
  std::vector<LagerInhalt> LI;
#if defined(PETIG_EXTENSIONS) && defined(MANUPROC_DYNAMICENUMS_CREATED)
  if(Instanz() == ppsInstanzID::Rohwarenlager)  LI=RohwarenLager().LagerInhalt();
  else if(Instanz() == ppsInstanzID::Bandlager) LI=JumboLager().LagerInhalt();
  else 
#elif defined(MABELLA_EXTENSIONS) && defined(MANUPROC_DYNAMICENUMS_CREATED)
  if(Instanz() == ppsInstanzID::Fertigwarenlager)  
	LI=FertigWarenLager(FertigWarenLager::default_lagerid).LagerInhalt();
  else 
#endif 
   { std::cout << Instanz()<<' '<<"\tKeine LagerKlasse implementiert\n";
     assert(!"never get here\n");
     return LI;
   }
  LagerBase::LagerInhaltSum(LI);
  return LI;
}

////////////////////////////////////////////////////////////////////////////////

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintragBase &AE,const std::string &x,const std::string &y) const
{
  std::cout << AE << ": " << s << " (" << x << " " << y << ")\n";
}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintragBase &AE,const ABmt &x,const ABmt &y) const
{analyse(s,AE,x.String(),y.String());}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintragBase &AE,const AufEintragBase &x,const ABmt &y) const
{analyse(s,AE,x.str(),y.String());}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintragBase &AE,const ArtikelBase &x,const ArtikelBase &y) const
{analyse(s,AE,itos(x.Id()),itos(y.Id()));}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintragBase &AE,const cH_ppsInstanz &x,const cH_ppsInstanz &y) const
{analyse(s,AE,x->Name(),y->Name());}

void ppsInstanzReparatur::Zuordnung_erniedrigen(AufEintrag &ae,
	AufEintragZu::list_t &eltern,AuftragBase::mengen_t &m,
	AuftragBase::ID typ)
{  for (AufEintragZu::list_t::iterator i=eltern.begin();i!=eltern.end();++i)
   {  if (typ==AuftragBase::handplan_auftrag_id)
      {  if (i->AEB.Id()<typ) continue;
      }
      else if (i->AEB.Id()!=typ) continue;
      AuftragBase::mengen_t M=AuftragBase::min(m,i->Menge);
      if (!M) continue;
      AufEintragZu(i->AEB).setMengeDiff__(ae,-M);
      i->Menge-=M;
      m-=M;
      if (!m) break;
   }
}

void ppsInstanzReparatur::KinderErniedrigen(AufEintrag &ae,
	AufEintragZu::list_t &kinder,AuftragBase::mengen_t m)
{  AufEintrag::ArtikelInternAbbestellen_cb aia(ae);
   for (AufEintragZu::list_t::iterator i=kinder.begin();i!=kinder.end();++i)
   {  AuftragBase::mengen_t M=AuftragBase::min(m,i->Menge);
      if (!M) continue;
      M=aia(ArtikelBase(),i->AEB,M);
      i->Menge-=M;
      m-=M;
      if (!m) break;
   }
}

bool ppsInstanzReparatur::Eltern(AufEintrag &ae, AufEintragZu::list_t &eltern, bool analyse_only, bool raise_prodselbst) const
{  // 2er und Kundenauftr�ge d�rfen keine Kinder haben!
   ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,ae,/*eltern.size(),*/analyse_only);
   if (ae.Id()==AuftragBase::dispo_auftrag_id || ae.Instanz()==ppsInstanzID::Kundenauftraege)
   {  if (!eltern.empty())
      {  analyse("2er und Kundenauftr�ge d�rfen keine Kinder haben!",ae);
         for (AufEintragZu::list_t::iterator i=eltern.begin();i!=eltern.end();)
         {  if (!analyse_only) AufEintragZu::remove(i->AEB,ae);
            i=eltern.erase(i);
         }
         return false;
      }
      return true;
   }
   // 
   bool alles_ok=true;
   for (AufEintragZu::list_t::iterator i=eltern.begin();i!=eltern.end();)
   {  if (ae.Instanz()==i->AEB.Instanz() && i->AEB.Id()!=AuftragBase::dispo_auftrag_id)
      {  analyse("(Roh-Artikel wird auf gleicher Instanz bestellt)",ae,i->AEB,i->Menge);
      }
      if (ae.Instanz()==i->AEB.Instanz() 
// Vorerst deaktiviert   
   		&& i->AEB.Id()==AuftragBase::dispo_auftrag_id)
      {  if (i->AEB.Id()!=AuftragBase::dispo_auftrag_id)
         {  analyse("Eltern auf gleicher Instanz m�ssen 2er sein",ae,i->AEB,i->Menge);
           weg:
            if (!analyse_only) AufEintragZu::remove(i->AEB,ae);
            i=eltern.erase(i);
            alles_ok=false;
            continue;
         }
         AufEintrag ae2(i->AEB);
         if (ae2.Artikel()!=ae.Artikel()
         	|| ae2.getLieferdatum()!=ae.getLieferdatum()) 
         {  analyse("Artikel oder Datum passt nicht",ae,i->AEB,i->Menge);
            goto weg;
         }
      }
      else
      {  if (i->AEB.Id()==AuftragBase::dispo_auftrag_id) 
         {  analyse("2er m�ssen auf der gleichen instanz liegen",ae,i->AEB,i->Menge);
            goto weg;
         }
         // schadet nicht ... ist aber wohl eher die Angelegenheit des 1ers
         if (i->AEB.Id()==AuftragBase::plan_auftrag_id && !!i->Menge)
         {  analyse("1er k�nnen keine Menge bestellen",ae,i->AEB,i->Menge);
            if (!analyse_only) AufEintragZu(i->AEB).setMengeDiff__(ae,-i->Menge);
            i->Menge=0;
            alles_ok=false;
         }
      }
      
      if (!i->Menge)
      {  if (i->AEB.Id()==AuftragBase::dispo_auftrag_id 
      		|| ae.Id()==AuftragBase::ungeplante_id
      	        || i->AEB.Id()==AuftragBase::ungeplante_id)
      	 {  analyse("Zuordnung unn�tig",ae,i->AEB,i->Menge);
      	   nur_der_weg:
            if (!analyse_only) AufEintragZu::remove(i->AEB,ae,i->Pri);
            i=eltern.erase(i);
            alles_ok=false;
            continue;      	    
      	 }
      	 if (ae.Id()==AuftragBase::plan_auftrag_id && !ae.getGeliefert())
      	 {  analyse("Zuordnungen zu leeren 1ern k�nnen weg",ae,i->AEB,i->Menge);
      	    if (really_delete) goto nur_der_weg;
      	 }
      	 unsigned count=0;
      	 for (AufEintragZu::list_t::iterator j=eltern.begin();j!=eltern.end();++j)
      	 {  if (i->AEB==j->AEB) count++;
      	 }
      	 if (count>1)
      	 {  analyse("Es existiert mehr als eine Zuordnung, diese kann weg",ae,i->AEB,i->Menge);
      	    goto nur_der_weg;
      	 }
      }
      
      ++i;
   }
   
   // schauen ob Sum(eltern)=offeneMenge,
   // wenn produziert selbst kann Sum(eltern) niedriger sein (sollte aber nicht)
   AufEintragBase::mengen_t menge2,menge;
   for (AufEintragZu::list_t::iterator i=eltern.begin();i!=eltern.end();++i)
   {  menge+=i->Menge;
      if (i->AEB.Id()==AuftragBase::dispo_auftrag_id)
      {  menge2+=i->Menge;
         if (menge2>ae.getRestStk())
         {  analyse("Mehr Dispomenge als noch frei",ae,i->AEB,menge2-ae.getRestStk());
            if (!analyse_only) 
               AufEintragZu(i->AEB).setMengeDiff__(ae,ae.getRestStk()-menge2);
            i->Menge+=ae.getRestStk()-menge2;
            // vielleicht noch den Ziel 2er reduzieren?
            alles_ok=false;
         }
      }
   }
   if (menge>ae.getRestStk()
   	&& (!ae.Instanz()->ProduziertSelbst() || raise_prodselbst))
   {  analyse("mehr v.o. ben�tigt als noch offen",ae,menge,ae.getRestStk());
      alles_ok=false;
      if (!analyse_only)
      {if (ae.Id()==AuftragBase::ungeplante_id) 
         ae.MengeAendern(menge-ae.getRestStk(),true,AufEintragBase());
       else
       { // Zuordnung erniedrigen, Reihenfolge: 2,0,1,3)
         // danach m�ssen die Eltern neu bestellen (Reparatur)!
         AuftragBase::mengen_t m=menge-ae.getRestStk(); // positiv
         Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::dispo_auftrag_id);
         if (!!m) Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::ungeplante_id);
         if (!!m) Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::plan_auftrag_id);
         if (!!m) Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::handplan_auftrag_id);
         if (!!m) 
         {  analyse("Die Zuordnungen konnten nicht alle entfernt werden",ae,m);
            assert(AuftragBase::tolerate_inconsistency || !m);
         }
       }
      }
   }
   // Sum zu gro�: nachbestellen (kann nur bei ProduziertSelbst passieren)
   else if (menge>ae.getStueck())
   {  analyse("mehr v.o. ben�tigt als jemals bestellt",ae,menge,ae.getStueck());
      alles_ok=false;
      if (!analyse_only)
      {if (ae.Id()==AuftragBase::ungeplante_id) 
         ae.MengeAendern(menge-ae.getStueck(),true,AufEintragBase());
       else
       { // Zuordnung erniedrigen, Reihenfolge: 2,0,1,3)
         // danach m�ssen die Eltern neu bestellen (Reparatur)!
         AuftragBase::mengen_t m=menge-ae.getStueck(); // positiv
         Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::dispo_auftrag_id);
         if (!!m) Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::ungeplante_id);
         if (!!m) Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::plan_auftrag_id);
         if (!!m) Zuordnung_erniedrigen(ae,eltern,m,AuftragBase::handplan_auftrag_id);
       }
      }
   }
   // Sum zu klein: abbestellen (falls 0er, bei 1er 2er erzeugen)
   else if (menge<ae.getRestStk())
   {  analyse("mehr offen als nun v.o. ben�tigt",ae,menge,ae.getStueck());
      alles_ok=false;
      if (!analyse_only)
      {if (in(ae.Id(),AuftragBase::ungeplante_id,AuftragBase::plan_auftrag_id))
       {  assert(ae.Id()!=AuftragBase::plan_auftrag_id || ae.Instanz()->LagerInstanz());
          ae.MengeAendern(menge-ae.getRestStk(),true,AufEintragBase());
       }
       else 
       { assert(ae.Id()>=AuftragBase::handplan_auftrag_id);
         // 2er erh�hen
         AuftragBase(ae.Instanz(),AuftragBase::dispo_auftrag_id).
              BestellmengeAendern(ae.getRestStk()-menge,ae.getLieferdatum(),
              		ae.Artikel(),OPEN,ae);
       }
      }
   }

   // h�chstens so viel geliefert wie ausgeliefert   
   if (ae.Id()==AuftragBase::plan_auftrag_id && !!ae.getGeliefert()
    	&& !ae.Instanz()->ProduziertSelbst())
   {  AuftragBase::mengen_t geliefert_eltern;
      for (AufEintragZu::list_t::iterator i=eltern.begin();i!=eltern.end();++i)
      {  AufEintrag el(i->AEB);
         geliefert_eltern+=ArtikelBaum(el.Artikel()).Faktor(ae.Artikel())
         	* el.getGeliefert();
      }
      if (geliefert_eltern<ae.getGeliefert())
      {  analyse("Mehr geliefert als von den Eltern ausgeliefert wurde\n",
      		ae,ae.getGeliefert(),geliefert_eltern);
      }
   }

   if (eltern.empty() && ae.Id()==AuftragBase::ungeplante_id && !ae.getStueck())
   {  analyse("0er ohne Eltern k�nnen ganz weg",ae);
      if (really_delete) 
      {  Query("delete from auftragentry where (instanz,auftragid,zeilennr)=(?,?,?)")
      		<< ae;
      	 alles_ok=false;
      }
      else 
         std::cout << "$ delete from auftragentry where (instanz,auftragid,zeilennr)=("
		<< ae.Instanz()->Id() << ',' << ae.Id() << ',' << ae.ZNr() << ");\n";
   }
   return alles_ok;
}

bool ppsInstanzReparatur::Kinder(AufEintrag &ae, AufEintragZu::map_t &kinder, bool analyse_only) const
{  bool alles_ok=true;
   ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,ae,/*kinder.size(),*/analyse_only);
   
   if (ae.Id()==AuftragBase::dispo_auftrag_id)
   {  // 2er: Kinder gleiche instanz
      AuftragBase::mengen_t menge2;
      
      for (AufEintragZu::map_t::iterator i=kinder.begin();i!=kinder.end();++i)
      {  for (AufEintragZu::list_t::iterator j=i->second.begin();j!=i->second.end();)
         {  if (ae.Instanz()->LagerInstanz())
            {  analyse("Ein Lager 2er darf keine Kinder haben",ae,j->AEB,j->Menge);
             weg:
               if (!analyse_only) AufEintragZu::remove(ae,j->AEB);
               j=i->second.erase(j);
               alles_ok=false;
               continue;
            }
            if (j->AEB.Instanz()!=ae.Instanz())
            {  analyse("Instanz passt nicht",ae,j->AEB,j->Menge);
               goto weg;
            }
            if (j->AEB.Id()<AuftragBase::handplan_auftrag_id)
            {  analyse("Kind kein 3er",ae,j->AEB,j->Menge);
               goto weg;
            }
            AufEintrag ae2(j->AEB);
            if (ae2.Artikel()!=ae.Artikel()
         	|| ae2.getLieferdatum()!=ae.getLieferdatum()) 
            {  analyse("Artikel oder Datum passt nicht",ae,j->AEB,j->Menge);
               goto weg;
            }
            menge2+=j->Menge;
            ++j;
         }
      }
      if (!ae.Instanz()->LagerInstanz() && menge2!=ae.getStueck())
      {  analyse("2er: Zuordnungen!=eigene Menge",ae,menge2,ae.getStueck());
         if (!analyse_only) 
            ae.MengeAendern(menge2-ae.getStueck(),false,
            		AufEintragBase());
      }
   }
   else // 0er, 1er, 3er
   {  ArtikelBaum ab(ae.Artikel());
      ArtikelStamm as(ae.Artikel());
      ppsInstanz::ID next=ae.Instanz()->NaechsteInstanz(as);
      ManuProC::Datum newdate=ae.getLieferdatum()-ae.Instanz()->ProduktionsDauer();
      
      for (AufEintragZu::map_t::iterator i=kinder.begin();i!=kinder.end();++i)
      {  AuftragBase::mengen_t menge;
         bool artikel_passt_nicht=false;
         ManuProC::Trace(AuftragBase::trace_channel,"-Artikel-",i->first/*,i->second.size()*/);
         cH_ppsInstanz bestellinstanz=next!=ppsInstanzID::None?
				cH_ppsInstanz(next)
                          :ppsInstanz::getBestellInstanz(i->first);
         for (AufEintragZu::list_t::iterator j=i->second.begin();j!=i->second.end();)
         {  if (next!=ppsInstanzID::None && j->AEB.Instanz()!=next)
            {  analyse("Instanz passt nicht",ae,j->AEB,j->Menge);
             weg1:
               if (!analyse_only) AufEintragZu::remove(ae,j->AEB);
               j=i->second.erase(j);
               alles_ok=false;
               continue;
            }
            else if (next==ppsInstanzID::None)
            {  if (!ab.istKind(i->first))
               {  analyse("Kindartikel falsch "+itos(ab.Id())+" "+itos(i->first.Id()),ae,j->AEB,j->Menge);
                  artikel_passt_nicht=true;
                  goto weg1;
               }
               // Artikel ist schon mal richtig ...
               if (j->AEB.Instanz()!=bestellinstanz && !bestellinstanz->PlanungsInstanz())
               {  analyse("Kindartikel bei falscher Instanz",ae,j->AEB,j->Menge);
                  goto weg1;
               }
            }
            if (ae.Id()==AuftragBase::plan_auftrag_id && ae.Instanz()->LagerInstanz()
            	&& (!!j->Menge || j->AEB.Id()==AuftragBase::ungeplante_id))
            {  analyse("Ein Lager 1er darf keine Kinder >0||->0er haben",ae,j->AEB,j->Menge);
               goto weg1;
            }
            if (j->AEB.Id()==AuftragBase::dispo_auftrag_id)
            {  analyse("Kind darf kein 2er sein",ae,j->AEB,j->Menge);
               goto weg1;
            }
            if (ae.getCombinedStatus()!=OPEN)
            {  if (!!j->Menge)
               {  analyse("Nichtoffene Auftr�ge d�rfen nichts (mehr) bestellen",ae,j->AEB,j->Menge);
                  goto weg1;
               }
            }

            AufEintrag ae2(j->AEB);
            if (ae2.getLieferdatum()>newdate 
                // Ausnahme f�r unbestellte aber doch gelieferte Mengen
            	&& !(ae.Id()==AuftragBase::plan_auftrag_id 
            		&& !ae.Instanz()->LagerInstanz()
            		&& ae.getLieferdatum()==LagerBase::Lagerdatum()))
            {  analyse("Datum passt nicht",ae,j->AEB,j->Menge);
               goto weg1;
            }
            menge+=j->Menge;
            ++j;
         }
         // schauen ob offeneMenge=Sum(kinder)
         if (ae.Instanz()==ppsInstanzID::Kundenauftraege)
         {  if (ae.Artikel()!=i->first) // Artikel passt nicht!
               continue;
         }
         else // Intern
            if (artikel_passt_nicht 
            	|| (ae.Id()==AuftragBase::plan_auftrag_id && ae.Instanz()->LagerInstanz()))
               continue;
         
         AuftragBase::mengen_t richtigeMenge=
         	ae.getRestStk()*ab.Faktor(i->first);
         if (ae.getCombinedStatus()!=OPEN) goto exit;
         if (/* analyse_only && */ menge!=richtigeMenge && 
         	between<AuftragBase::mengen_t>(menge,
         		floor(ae.getRestStk()*ab.Faktor(i->first)),
         		richtigeMenge))
         {  analyse("Zuordnungen!=eigene RestMenge (aber innerhalb Rundungsfehler)",ae,menge,richtigeMenge);
         }
         else if (menge!=richtigeMenge)
         {  analyse("Zuordnungen!=eigene RestMenge",ae,menge,richtigeMenge);
            alles_ok=false;
            if (!analyse_only)
            {  if (menge<richtigeMenge) // Sum zu klein: nachbestellen
               {  AufEintrag::ArtikelInternNachbestellen(bestellinstanz,
                                richtigeMenge-menge,newdate,i->first,ae);
               }
               else // mehr bestellt als noch offen: Bestellungen weg!
               {  KinderErniedrigen(ae,i->second,menge-richtigeMenge);
               }
            }
         }
      }
      if (ae.Id()==AuftragBase::plan_auftrag_id && ae.Instanz()->LagerInstanz())
         goto exit;
      if (ae.getCombinedStatus()!=OPEN) goto exit;
      // kam der Artikel �berhaupt vor ?
      if (next!=ppsInstanzID::None)
      {  AufEintragZu::map_t::const_iterator f=kinder.find(ae.Artikel());
         AuftragBase::mengen_t M=ae.getRestStk();
         if (f==kinder.end() && !!M)
         {  alles_ok=false;
            analyse("Artikel fehlt intern v�llig",ae,itos(ae.Artikel().Id()),M.String(true));
            if (!analyse_only)
            {  AufEintrag::ArtikelInternNachbestellen(next,M,newdate,
            				ae.Artikel(),ae);
            }
         }
      }
      else for (ArtikelBaum::const_iterator i=ab.begin();i!=ab.end();++i)
      {  AufEintragZu::map_t::const_iterator f=kinder.find(i->rohartikel);
         AuftragBase::mengen_t M=ae.getRestStk()*i->menge;
         if (f==kinder.end() && !!M) // Artikel nie bestellt
         {  alles_ok=false;
            analyse("Rohartikel fehlt v�llig",ae,itos(i->rohartikel.Id()),M.String(true));
            if (!analyse_only)
            {  AufEintrag::ArtikelInternNachbestellen(
            		ppsInstanz::getBestellInstanz(i->rohartikel),
            		M,newdate,i->rohartikel,ae);
            }
         }
      }
   }
   if (kinder.empty() && ae.Id()==AuftragBase::dispo_auftrag_id && !ae.getStueck())
   {  analyse("2er ohne Kinder k�nnen ganz weg",ae);
      if (really_delete) 
      {  Query("delete from auftragentry where (instanz,auftragid,zeilennr)=(?,?,?)")
      		<< ae;
      	 alles_ok=false;
      }
      else 
         std::cout << "$ delete from auftragentry where (instanz,auftragid,zeilennr)=("
		<< ae.Instanz()->Id() << ',' << ae.Id() << ',' << ae.ZNr() << ");\n";
   }
exit:
   return alles_ok;
}

bool ppsInstanzReparatur::Lokal(AufEintrag &ae, bool analyse_only) const
{  bool alles_ok=true;
   ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,ae,analyse_only);
   if (in(ae.Id(),AuftragBase::dispo_auftrag_id,AuftragBase::ungeplante_id))
   {  if (!!ae.getGeliefert())
      {  alles_ok=false;
         analyse("Bei 0/2ern darf nichts geliefert worden sein.",ae);
         if (!analyse_only) 
            Query("update auftragentry set geliefert=0 "
         	"where (instanz,auftragid,zeilennr) = (?,?,?)")
         	<< ae;
//         ae.geliefert=0;
      }
      if (ae.getAufStatus()!=OPEN)
      {  alles_ok=false;
         analyse("0/2er Auftr�ge m�ssen offen sein",ae,AuftragBase::getStatusStr(ae.getAufStatus()));
         if (!analyse_only) Auftrag(ae).setStatusAuftrag_(OPEN);
      }
      if (ae.getCombinedStatus()!=OPEN)
      {  alles_ok=false;
         analyse("0/2er Eintr�ge m�ssen offen sein",ae);
         if (!analyse_only) ae.setStatus(OPEN,true);
      }
   }
   else if (ae.Instanz()!=ppsInstanzID::Kundenauftraege 
   	&& ae.getGeliefert()>ae.getStueck())
   {  alles_ok=false;
      analyse("Geliefert muss kleiner gleich bestellt sein.",ae,ae.getGeliefert(),ae.getStueck());
      if (!analyse_only) 
         Query("update auftragentry set geliefert=? "
		"where (instanz,auftragid,zeilennr) = (?,?,?)")
		<< ae.getStueck() << ae;
      ae.geliefert=ae.getStueck();
   }
   
   if (ae.Instanz()!=ppsInstanzID::Kundenauftraege 
   	&& !ae.Instanz()->ExterneBestellung()
   	&& ae.getKdNr()!=Kunde::eigene_id)
   {  alles_ok=false;
      analyse("Interne Kundennr falsch",ae,ae.getKdNr());
      if (!analyse_only) 
         Query("update auftrag set kundennr=? "
		"where (instanz,auftragid) = (?,?)")
		<< Kunde::eigene_id << static_cast<AuftragBase&>(ae);
      ae.kdnr=Kunde::eigene_id;
   }
   
   ArtikelStamm as(ae.Artikel());
   // falsche Artikel im Lager zulassen (wenn extern verwaltet)
   if (ae.Instanz()->LagerInstanz() 
   		&& ae.Id()==AuftragBase::dispo_auftrag_id 
   		&& ae.Instanz()->EigeneLagerKlasseImplementiert()
   		&& !!ae.getRestStk()
   		&& !in(ae.Instanz(),ppsInstanz::getBestellInstanz(as),
   			ppsInstanz::getProduktionsInstanz(as)))
   {  analyse("(Lagerinhalt auf falscher Instanz)",ae,cH_ArtikelBezeichnung(ae.Artikel())->Bezeichnung(),itos(ae.Artikel().Id()));
   }
   else if (ae.Instanz()!=ppsInstanzID::Kundenauftraege 
   	&& !in(ae.Instanz(),ppsInstanz::getBestellInstanz(as),
   			ppsInstanz::getProduktionsInstanz(as))
   	&& !ppsInstanz::getBestellInstanz(as)->PlanungsInstanz())
   {  analyse("Artikel auf falscher Instanz",ae,cH_ArtikelBezeichnung(ae.Artikel())->Bezeichnung(),itos(ae.Artikel().Id()));
     loeschen: 
      if (really_delete) 
      {  Query("delete from auftragentry where (instanz,auftragid,zeilennr)=(?,?,?)")
      		<< ae;
      	 alles_ok=false;
      }
      else 
         std::cout << "$ delete from auftragentry where (instanz,auftragid,zeilennr)=("
		<< ae.Instanz()->Id() << ',' << ae.Id() << ',' << ae.ZNr() << ");\n";
      return alles_ok;
      // besser: Kinder f�r diesen Auftrag nicht aufrufen
   }
   
   if (ae.Id()==AuftragBase::plan_auftrag_id)
   {  if (ae.Instanz()==ppsInstanzID::Kundenauftraege)
      {  analyse("Es darf keine 1er bei den Kundenauftr�gen geben",ae);
         goto loeschen;
      }
      else if (!!ae.getRestStk() && !ae.Instanz()->LagerInstanz())
      {  alles_ok=false;
         analyse("ausgelieferte 1er Auftr�ge sollten CLOSED sein",ae,AuftragBase::getStatusStr(ae.getCombinedStatus()));
         if (!analyse_only) ae.abschreiben(ae.getRestStk());
      }
      if (ae.getCombinedStatus()!=CLOSED && !ae.Instanz()->LagerInstanz())
      {  alles_ok=false;
         analyse("1er Auftr�ge sollten CLOSED sein",ae,AuftragBase::getStatusStr(ae.getCombinedStatus()));
         if (!analyse_only) ae.setStatus(CLOSED,true);
      }
   }
   if (ae.Instanz()!=ppsInstanzID::Kundenauftraege
   	&& !in(ae.getCombinedStatus(),OPEN,CLOSED))
   {  alles_ok=false;
      analyse("Interne Auftr�ge m�ssen OPEN/CLOSED sein",ae,AuftragBase::getStatusStr(ae.getCombinedStatus()));
      if (!analyse_only) ae.setStatus(CLOSED,true);
   }
   if (ae.getGeliefert()>=ae.getStueck()
   	&& ae.getCombinedStatus()!=CLOSED
   	&& !(ae.Instanz()!=ppsInstanzID::Kundenauftraege 
   	    && in(ae.Id(),AuftragBase::dispo_auftrag_id,AuftragBase::ungeplante_id))
   	&& !(ae.Id()==AuftragBase::plan_auftrag_id && !ae.getStueck()))
   {  alles_ok=false;
      analyse("Erf�llte Auftr�ge m�ssen CLOSED sein",ae,ae.getGeliefert(),ae.getStueck());
      if (!analyse_only) ae.setStatus(CLOSED,true);
   }
   else if (ae.Instanz()!=ppsInstanzID::Kundenauftraege
   	&& !(ae.Instanz()->Lieferschein() && ae.Id()>=AuftragBase::handplan_auftrag_id)
   	&& ae.getGeliefert()!=ae.getStueck()
   	&& ae.getCombinedStatus()!=OPEN)
   {  alles_ok=false;
      analyse("Offene interne Auftr�ge m�ssen OPEN sein",ae,ae.getGeliefert(),ae.getStueck());
      if (!analyse_only) ae.setStatus(OPEN,true);
   }
   
   if (ae.Instanz()->LagerInstanz() 
   	&& ae.Id()>=AuftragBase::handplan_auftrag_id)
   {  analyse("Es darf keine 3er im Lager geben",ae,ae.getStueck());
      goto loeschen;
   }
   if (ae.Instanz()->LagerInstanz() 
   	&& ae.Id()==AuftragBase::dispo_auftrag_id
   	&& ae.getLieferdatum()!=LagerBase::Lagerdatum())
   {  alles_ok=false;
      analyse("Das Datum von 2ern im Lager sollte 'epoch' sein",ae);
      if (!analyse_only)
         Query("update auftragentry "
		"set lieferdate=? "
		"where (instanz,auftragid,zeilennr)=(?,?,?)")
		<< LagerBase::Lagerdatum()
		<< ae;
   }
   return alles_ok;
}

bool ppsInstanzReparatur::really_delete;
