/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 2002 Adolf Petig GmbH & Co. KG
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
//#include <Misc/SQLerror.h>
#include <Misc/Trace.h>
//#include <sqlca.h>
//#include <Auftrag/AufEintragZuMengenAenderung.h>
//#include <Misc/Transaction.h>
#include <Misc/relops.h>
#include <unistd.h>
#include <Misc/inbetween.h>

#if 0
bool ppsInstanzReparatur::ReparaturKK_KundenKinder(const int uid,const bool analyse_only) const
{
  SQLFullAuftragSelector psel=SQLFullAuftragSelector::sel_Status(ppsInstanzID::Kundenauftraege,OPEN,AuftragBase::plan_auftrag_id);
  SelectedFullAufList K(psel);
  bool alles_ok=true;
  for(SelectedFullAufList::const_iterator i = K.begin();i!=K.end(); ++i)
   {
     AufEintragZu::list_t L=AufEintragZu(*i).get_Referenz_list_ungeplant(true);
     assert(L.size()==1);
     for(AufEintragZu::list_t::const_iterator j=L.begin();j!=L.end();++j)
      { 
        bool ok=KK_teste_summen_fuer(j->AEB,i->Artikel(),uid,analyse_only);
        if(!ok) alles_ok=false;
      }
   }
  return alles_ok;
}

bool ppsInstanzReparatur::KK_teste_summen_fuer(const AufEintragBase aeb,const ArtikelBase ElternArtikel,const int uid,const bool analyse_only) const
{
  assert(aeb.Id()==AuftragBase::ungeplante_id);
  AufEintrag AE0(aeb);
  AuftragBase::mengen_t ElternMenge=0;
  // ElternMenge
  { 
   AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(aeb,false,AufEintragZu::list_ohneArtikel);
   for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
     {
       ElternMenge += AufEintrag(i->AEB).getRestStk();
     }
  }
  ArtikelBaum::faktor_t F=ArtikelBaum(ElternArtikel).Faktor(AE0.Artikel());
  ElternMenge = ElternMenge*F;
  // Geplane Kinder
  AuftragBase::mengen_t PlanMenge=0;
  {
  AufEintragZu::list_t L=AufEintragZu(aeb).get_Referenz_list_geplant();
  for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
   {
     // Und deren Dispo-Eltern
     AuftragBase::mengen_t DispoMenge=0;
     AufEintragZu::list_t D=AufEintragZu(i->AEB).get_Referenz_list_dispo(false);
std::cout << "\tDispo: "<<D.size()<<'\n';
     for(AufEintragZu::list_t::const_iterator j=D.begin();j!=D.end();++j)
      { assert(j->AEB.Id()==AuftragBase::dispo_auftrag_id);
        DispoMenge += j->Menge;
      }
     AufEintrag DispoAE(i->AEB);
     PlanMenge += DispoAE.getRestStk() - DispoMenge;
   }
  }
std::cout << "AUSGABE: "<<aeb<<'\t'<< ElternMenge <<" = "<< AE0.getStueck()
<<" + "<< PlanMenge<<'\t';
 if(ElternMenge != AE0.getStueck() + PlanMenge )
  {
std::cout << "\tFehler";
/*
   if(analyse_only) analyse("Von Eltern ben�tigte Menge (EM="+ElternMenge.String()+") stimmt nicht mit \n"
      " offener Menge (OM="+AE0.getStueck().Stringa()+") und"
      " der geplanter Menge (GM="+PlanMenge.String()+") �berein.\n"
      " EM = OM + Summe(GM - Summe(DispoMenge))\n",AE0);
   else assert(!"nicht implementiertn");
*/
  }
std::cout << "\n";

  // und nun rekursiv
  AufEintragZu::list_t L=AufEintragZu(aeb).get_Referenz_list_ungeplant();
  for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
   {
     KK_teste_summen_fuer(i->AEB,AE0.Artikel(),uid,analyse_only);
   }
  return false; // oder true?
}

////////////////////////////////////////////////////////////////////////////
/*
struct st_art_instanz{cH_ppsInstanz instanz; ArtikelBase artikel;
            st_art_instanz(cH_ppsInstanz i,const ArtikelBase a) : instanz(i),artikel(a) {}
            st_art_instanz() : instanz(ppsInstanzID::None)  {}
            bool operator<(const st_art_instanz &b) const
               {return instanz<b.instanz || (instanz==b.instanz && artikel<b.artikel);}
            };
*/

bool ppsInstanzReparatur::ReparaturST_AuftragsZuordnung(const int uid,const bool analyse_only,const bool kinder) const
{
  if(KundenInstanz() && !kinder) 
      return ReparaturG_keine_Eltern(uid,analyse_only);

  SQLFullAuftragSelector sel1er= SQLFullAuftragSelector::sel_Status(Id(),OPEN,AuftragBase::none_id);
  SelectedFullAufList AL1(sel1er);
  for(SelectedFullAufList::iterator i=AL1.begin();i!=AL1.end();++i)
   {
     AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(*i,kinder,AufEintragZu::list_ohneArtikel);
     if(i->Id() == AuftragBase::dispo_auftrag_id && !kinder && !L.empty())
         return ReparaturG_keine_Eltern(uid,analyse_only);

//     std::map<st_art_instanz,AuftragBase::mengen_t> MArt;
     std::map<ArtikelBase,AuftragBase::mengen_t> MArt;
     for(AufEintragZu::list_t::const_iterator j=L.begin();j!=L.end();++j)
      {
//         MArt[st_art_instanz(j->AEB.Instanz(),j->Art)]+=j->Menge;
        MArt[j->Art]+=j->Menge;
      }
     
//     for(std::map<st_art_instanz,AuftragBase::mengen_t>::const_iterator j=MArt.begin();j!=MArt.end();++j)
     for(std::map<ArtikelBase,AuftragBase::mengen_t>::const_iterator j=MArt.begin();j!=MArt.end();++j)
      {
        ArtikelBaum::faktor_t F=ArtikelBaum(i->Artikel()).Faktor(j->first);
//cout << i->getRestStk()<<'*'<<F<<'='<<i->getRestStk()*F<<'\n';
        if     ( kinder && j->second != i->getRestStk()*F)
         { if(analyse_only) {analyse("Zumme der Zuordnung an Kinder != getRestStk()",*i,j->second, i->getRestStk()*F);return false;}
           else assert(!"nicht implementiert");
         }
        else if(!kinder && j->second != i->getStueck())         
         { if(analyse_only) {analyse("Zumme der Zuordnung von Eltern != getStueck()",*i,j->second, i->getRestStk());return false;}
           else assert(!"nicht implementiert");
         }
      }
   }
 return true;
}

////////////////////////////////////////////////////////////////////////////
bool ppsInstanzReparatur::ReparaturH_LagerZuordnungen(const int uid,const bool analyse_only) const
{
  assert(LagerInstanz());
  // 1er haben keien Kinder
  SQLFullAuftragSelector psel=SQLFullAuftragSelector::sel_Status(Id(),OPEN,AuftragBase::plan_auftrag_id);
  SelectedFullAufList K(psel);
  for(SelectedFullAufList::const_iterator i = K.begin();i!=K.end(); ++i)
   {
     AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(*i,true,AufEintragZu::list_ohneArtikel);
     if(!L.empty())
      { if(analyse_only) {analyse("Analyse: 1er im Lager d�rfen keine Kinder haben\n",*i); return false;}
        else assert(!"nicht implementiert");
      }
   } 
  // 2er haben keine Kinder und keine Eltern
  SQLFullAuftragSelector psel2=SQLFullAuftragSelector::sel_Status(Id(),OPEN,AuftragBase::dispo_auftrag_id);
  SelectedFullAufList K2(psel);
  for(SelectedFullAufList::const_iterator i = K2.begin();i!=K2.end(); ++i)
   {
     AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(*i,true,AufEintragZu::list_ohneArtikel);
     if(!L.empty())
      { if(analyse_only) {analyse("Analyse: 2er im Lager d�rfen keine Kinder haben\n",*i); return false;}
        else assert(!"nicht implementiert");
      }
     AufEintragZu::list_t L2=AufEintragZu::get_Referenz_list(*i,false,AufEintragZu::list_ohneArtikel);
     if(!L.empty())
      { if(analyse_only) {analyse("Analyse: 2er im Lager d�rfen keine Eltern haben\n",*i); return false;}
        else assert(!"nicht implementiert");
      }
   } 
  return true;
}



////////////////////////////////////////////////////////////////////////////

bool ppsInstanzReparatur::ReparaturK_Kundenzuordnung(const int uid,const bool analyse_only) const
{
   bool alles_ok=true;
   assert(KundenInstanz());
   SQLFullAuftragSelector sel1er= SQLFullAuftragSelector::sel_Status(Id(),OPEN,AuftragBase::plan_auftrag_id);
   SelectedFullAufList AL1(sel1er);
   for(SelectedFullAufList::iterator i=AL1.begin();i!=AL1.end();++i)
    {
      cH_ppsInstanz I=ppsInstanz::getBestellInstanz(i->Artikel());
      AufEintragZu::list_t L=AufEintragZu(*i).get_Referenz_list_ungeplant(true);
      assert(L.size()<=1);
      if(L.empty()) {
         alles_ok=false;
         if(analyse_only) analyse("Keine Kinder f�r Kundenauftrag",*i);
         else assert(!"nicht implementiert");
       }
      for(AufEintragZu::list_t::const_iterator j=L.begin();j!=L.end();++j)
        {
         try{ 
          AufEintrag AE(j->AEB);
          if(j->Menge!=i->getRestStk()) {
            alles_ok=false;
            if(analyse_only) analyse("Menge des Kundenauftrags und der Zuordnung ans Kind stimmt nicht �berein",*i,i->getStueck(),j->Menge);
            else assert(!"nicht implementiert");
//            else MengenReparatur(uid,*i,AE,j->Menge);
           }
          if(AE.Artikel()!=i->Artikel()){
            alles_ok=false;
            if(analyse_only) analyse("Artikel des Kundenauftrags und dem Kind stimmt nicht �berein",*i,i->Artikel(),AE.Artikel());
            else assert(!"nicht implementiert");
//            else Reparatur_Kundenauftrag_AE(uid,*i,AE,j->Menge);
           }
          if(AE.Instanz()!=I){
            alles_ok=false;
            if(analyse_only) analyse("Instanzen des Kundenauftrags und des Kindes stimmt nicht �berein",*i,I,AE.Instanz());
            else assert(!"nicht implementiert");
//            else Reparatur_Kundenauftrag_AE(uid,*i,AE,j->Menge);
           }
          if(AE.getLieferdatum()!=i->getLieferdatum()){
            alles_ok=false;
            if(analyse_only) analyse("Datum des Kundenauftrags und des Kindes stimmt nicht �berein",*i,i->getLieferdatum().to_iso(),AE.getLieferdatum().to_iso());
            else assert(!"nicht implementiert");
//            else Reparatur_Kundenauftrag_AE(uid,*i,AE,j->Menge);
           }
         } catch(AufEintrag::NoAEB_Error &e) 
           {  
            if(analyse_only) analyse("Kundenauftrag-Zuordnung, zeigt ins nichts\n",*i,j->AEB,j->Menge);
            else assert(!"nicht implementiert");
//            else  Reparatur_Kundenauftrag_AEB(uid,*i,j->AEB,j->Menge);
           }
        }      
    }
  return alles_ok;
}

void ppsInstanzReparatur::Reparatur_Kundenauftrag_AE(const int uid,const AufEintrag &KundeAE,AufEintrag &KindAE,const AuftragBase::mengen_t &menge) const
{
  KindAE.MengeAendern(uid,-menge,true,KundeAE,ManuProC::Auftrag::r_Anlegen);  
  Reparatur_Kundenauftrag_AEB(uid,KundeAE,KindAE,menge);
}

void ppsInstanzReparatur::Reparatur_Kundenauftrag_AEB(const int uid,const AufEintrag &KundeAE,const AufEintragBase &KindAE,const AuftragBase::mengen_t &menge) const
{
  AufEintragZu::remove(KundeAE,KindAE);
  KundeAE.ArtikelInternNachbestellen(uid,KundeAE.getRestStk(),ManuProC::Auftrag::r_Anlegen);
}

void ppsInstanzReparatur::MengenReparatur(const int uid,const AufEintrag &AE,AufEintrag &AEK,const ABmt& zumenge) const 
{
   assert(AEK.Id()==AuftragBase::ungeplante_id);
   AuftragBase::mengen_t diffmenge=AE.getRestStk()-zumenge;
   AufEintragZu(AE).setMengeDiff__(AEK,diffmenge);

   AufEintrag::mengen_t verplante_menge=0;
   AufEintragZu::list_t L=AufEintragZu(AEK).get_Referenz_list_geplant(true);
   for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
      verplante_menge+=i->Menge;
   AuftragBase::mengen_t sollmenge = verplante_menge + AEK.getStueck();
   if(sollmenge!=AE.getStueck())
     AEK.MengeAendern(uid,AE.getStueck()-sollmenge,true,AufEintragBase(),ManuProC::Auftrag::r_Reparatur); 
}


///////////////////////////////////////////////////////////////////////////

bool ppsInstanzReparatur::ReparaturD_0_ZuSumme_1(const int uid,const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  return Reparatur_Zuordnungen(uid,analyse_only,AuftragBase::plan_auftrag_id,false,Dungeplant);
}

bool ppsInstanzReparatur::ReparaturE_2_ZuSumme_1(const int uid,const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  if(LagerInstanz()) {/*std::cout << "Sinnlos f�r LagerInstanz\n"; */return true;}
  else
     return Reparatur_Zuordnungen(uid,analyse_only,AuftragBase::dispo_auftrag_id,true,Egeplant);
}

bool ppsInstanzReparatur::ReparaturF_2_ZuSumme_1Rest(const int uid,const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  if(LagerInstanz()) {/*std::cout << "Sinnlos f�r LagerInstanz\n";*/ return true;}
  else
     return Reparatur_Zuordnungen(uid,analyse_only,AuftragBase::plan_auftrag_id,false,Fdispo);
}


bool ppsInstanzReparatur::Reparatur_Zuordnungen(const int uid,const bool analyse_only,
   const AuftragBase::ID auftragid,const bool kinder,const e_zumode zumode) const throw(SQLerror)
{
   bool alles_ok=true;
   ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
   assert(Id() != ppsInstanzID::Kundenauftraege);
   SQLFullAuftragSelector sel1er= SQLFullAuftragSelector::sel_Status(Id(),OPEN,auftragid);
   SelectedFullAufList AL1(sel1er);
//cout << AL1.size()<<'\n';
   for(SelectedFullAufList::iterator i=AL1.begin();i!=AL1.end();++i)
    {
      AuftragBase::mengen_t Msum=0, M0sum=0;
      AufEintragZu::list_t L;
      switch (zumode) {
         case Dungeplant: { L=AufEintragZu(*i).get_Referenz_list_dispo(kinder);
//                            AufEintragZu::list_t L2=AufEintragZu(*i).get_Referenz_list_dispo(kinder);
//                              L.splice(L.end(),L2);
                              break;}
         case Egeplant: {  L=AufEintragZu(*i).get_Referenz_list_geplant(kinder); 
                           if(PlanungsInstanz() && L.empty())
                              L=AufEintragZu(*i).get_Referenz_list_ungeplant(kinder);
                           break;}
         case Fdispo:     L=AufEintragZu(*i).get_Referenz_list_dispo(kinder); break;
        }
//cout << *i<<"\tChild-LSize="<<L.size()<<'\n';
      for(AufEintragZu::list_t::const_iterator j=L.begin();j!=L.end();++j)
        {
          if(j->AEB.Id()==AuftragBase::ungeplante_id) M0sum+=j->Menge;
          else Msum+=j->Menge;
//cout << *i<<'\t'<<j->AEB<<'\t'<<j->Menge<<'\t'<<Msum<<'\n';
        }
      switch (zumode) {
         case Dungeplant: alles_ok=check_D_ungeplant(uid,analyse_only,*i,L); break;
         case Egeplant:   alles_ok=check_E_geplant(uid,analyse_only,*i,Msum+M0sum); break;   
         case Fdispo:     alles_ok=check_F_dispo(uid,analyse_only,*i,Msum+M0sum);break;
       }
    }
 return alles_ok;
} 

bool ppsInstanzReparatur::check_D_ungeplant(const int uid,const bool analyse_only,const AufEintrag &AE,const AufEintragZu::list_t &L) const
{
  int count=0;
  for(AufEintragZu::list_t::const_iterator j=L.begin();j!=L.end();++j)
      if(j->AEB.Id()==AuftragBase::ungeplante_id) ++count;
  if(!count) return true;
  if(analyse_only) { 
       analyse("Zuordung von 0er an 1|20000er darf es in einer Instanz nicht geben",AE);
       return false; }
  else assert(!"nicht implementiert\n");  
  return true;
}


/*
bool ppsInstanzReparatur::check_D_ungeplant(const int uid,const bool analyse_only,const AufEintrag &AE,const ABmt &M0sum,const ABmt &Msum) const
{
  if(AE.getGeliefert() <= M0sum) 
    { bool k=check_E_geplant(uid,analyse_only,AE,Msum);
      if(analyse_only) return k;
      if(!k) assert(!"nicht implementiert");
//      if(!k) check_D_ungeplantReparatur(uid,AE,Msum);
    }
  else if(Msum>AE.getStueck())
   { 
//std::cout << Msum<<'\t'<<AE.getStueck()<<'\t'<<AE.getRestStk()<<'\n';
     if(analyse_only) { 
            analyse("Zuord.-Summen ist gr��er als Auftragssumme",AE,Msum,AE.getStueck());
            return false; }
     else assert(!"nicht implementiert\n");  
   }
  return true;
}

*/
/*
void ppsInstanzReparatur::check_D_ungeplantReparatur(const int uid,const AufEintrag &AE,const AuftragBase::mengen_t &menge) const
{
  AuftragBase::mengen_t DiffMenge=AE.getStueck()-menge;
  assert(DiffMenge!=0);
  ReparaturE_2_ZuSumme_1(uid,true); 
//std::cout << "REP1: "<<AE<<'\t'<<DiffMenge<<'\n';
  AufEintragZu::list_t L=AufEintragZu(AE).get_Referenz_list_dispo(false);
  for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
   {
     AuftragBase::mengen_t M=0;
     if(DiffMenge>0) M =  DiffMenge;
     else            M = -AuftragBase::min(i->Menge,-DiffMenge);
//std::cout << "REP2: "<<i->AEB<<'\t'<<M<<'\n';
     i->AEB.updateStkDiffBase__(uid,M);
     AufEintragZu(i->AEB).setMengeDiff__(AE,M);
     DiffMenge -= M;
     if(!DiffMenge) return;
   }
  L=AufEintragZu(AE).get_Referenz_list_ungeplant(false);
  if(DiffMenge<0) DiffMenge*=-1;
  for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
   {
     AuftragBase::mengen_t M=AuftragBase::min(i->Menge,DiffMenge);
//std::cout << "REP3: "<<i->AEB<<'\t'<<M<<'\n';
     AufEintrag(i->AEB).MengeAendern(uid,M,true,ManuProC::Auftrag::r_Reparatur);
     AufEintragZu(i->AEB).setMengeDiff__(AE,-M);
     DiffMenge -= M;
     if(!DiffMenge) return;
   } 
}
*/

bool ppsInstanzReparatur::check_E_geplant(const int uid,const bool analyse_only,const AufEintrag &AE,const ABmt &Msum) const
{
  if(Msum!=AE.getStueck())
   { 
//std::cout <<"check_E_geplant: "<< AE<<'\t'<<Msum<<'\t'<<AE.getStueck()<<'\t'<<AE.getRestStk()<<'\t'<<Msum-AE.getStueck()<<'\n';
     if(analyse_only || AE.Id()!=AuftragBase::dispo_auftrag_id) {
        std::cout << "Analyse: Zuord.-Summen ("<<Msum<<") stimmen nicht ("<<AE.getStueck()<<") f�r "<<AE<<'\n';
        return false; }
     else assert(!"nicht implementiert\n");  
//     else AE.updateStkDiffBase__(uid,Msum-AE.getStueck());
   }
 return true;
}

bool ppsInstanzReparatur::check_F_dispo(const int uid,const bool analyse_only,const AufEintrag &AE,const ABmt &Msum) const
{
  if(Msum>AE.getRestStk())
   { 
     if(analyse_only) { std::cout << "Analyse: Zuord.-Summen ("<<Msum<<") sind gr��er als ("<<AE.getRestStk()<<") f�r "<<AE<<'\n';
                        return false; }
     else assert(!"nicht implementiert\n");  
//     else check_F_dispoReparatur(uid,AE,Msum);
   }
  return true;
}

void ppsInstanzReparatur::check_F_dispoReparatur(const int uid,const AufEintrag &AE,const AuftragBase::mengen_t &menge) const
{
  ReparaturE_2_ZuSumme_1(uid,true); 
  AuftragBase::mengen_t ReduceMenge=menge-AE.getRestStk();
  assert(ReduceMenge>0);
//std::cout << "R1: "<<AE<<'\t'<<ReduceMenge<<'\n';
  AufEintragZu::list_t L=AufEintragZu(AE).get_Referenz_list_dispo(false);
  for(AufEintragZu::list_t::const_iterator i=L.begin();i!=L.end();++i)
   {
     AuftragBase::mengen_t M=AuftragBase::min(ReduceMenge,i->Menge);
//std::cout << "R2: "<<i->AEB<<'\t'<<M<<'\n';
     i->AEB.updateStkDiffBase__(uid,-M);
     AufEintragZu(i->AEB).setMengeDiff__(AE,-M);
     ReduceMenge-=M;
     if(!ReduceMenge) return;
   }  
}



////////////////////////////////////////////////////////////////////////////

#endif

#warning sehr Datenbanklastig implementiert, neu implementieren
void ppsInstanzReparatur::Reparatur_0er_und_2er(const int uid,const bool analyse_only) const throw(SQLerror)
{
   ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
   assert(Id() != ppsInstanzID::Kundenauftraege);
   SQLFullAuftragSelector sel0er= SQLFullAuftragSelector::sel_Status(Id(),OPEN,AuftragBase::ungeplante_id);
   SelectedFullAufList AL(sel0er);
//cout << "REPARATUR 2er 0er AL.size()\t"<<AL.size()<<'\n';
   for(SelectedFullAufList::iterator i=AL.begin();i!=AL.end();++i)
    {
      SQLFullAuftragSelector sel2er;
      if(PlanungsInstanz()) {std::cerr<<"U N G E T E S T E T f�r PlanungsInstenz\n"; continue;}
      if(LagerInstanz())
         sel2er=SQLFullAuftragSelector::sel_Artikel_Planung_id(Id(),Kunde::eigene_id,i->Artikel(),AuftragBase::dispo_auftrag_id,OPEN,LagerBase::Lagerdatum());
      else 
         sel2er=SQLFullAuftragSelector::sel_Artikel_Planung_id(Id(),Kunde::eigene_id,i->Artikel(),AuftragBase::dispo_auftrag_id,OPEN);
      SelectedFullAufList L2er(sel2er);
//std::cout << i->Instanz()<<'\t'<<i->Artikel()<<'\t'<<L2er.size()<<'\n';
      AuftragBase::mengen_t menge0er=i->getStueck();
      for(SelectedFullAufList::iterator j=L2er.begin();j!=L2er.end();++j)
       {
         if(j->getLieferdatum()>i->getLieferdatum()) continue;
         AuftragBase::mengen_t M=AuftragBase::min(menge0er,j->getStueck());
         if(M==0) continue;
         AuftragBase zielauftrag(Id(),AuftragBase::plan_auftrag_id);
std::cout << "RepLan: "<<*i<<'\t'<<zielauftrag<<"Menge: "<<M<<'\n';
         if(analyse_only)
           std::cout << "Analyse: Planen von "<<*i<<"  nach  "<<zielauftrag<<"\tMenge: "<<M<<'\n';
         else
          {
      assert(!"nicht implementiert\n");  
//            int znr=i->Planen(uid,M,zielauftrag,i->getLieferdatum(),ManuProC::Auftrag::r_Reparatur);
//            j->updateStkDiffBase__(uid,-M);
//            if(!LagerInstanz()) AufEintragZu(*j).Neu(AufEintragBase(zielauftrag,znr),0);
          }
         menge0er-=M;
         if(menge0er<=0) break;
       }
    }
}

#if 0

////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
namespace{
struct st_table{std::string table; std::string column;
              st_table(const std::string &t,const std::string &c) 
               : table(t),column(c) {}};
}



////////////////////////////////////////////////////////////////////////////////

void ppsInstanzReparatur::Reparatur_Konsistenz(const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  if(KundenInstanz()) return; // Finger WEG
  force_eigene_KundenId(analyse_only);
  force_open_0er_und_2er(analyse_only);
  force_2er_0er_geliefert_ist_null(analyse_only);
}

void ppsInstanzReparatur::force_2er_0er_geliefert_ist_null(const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  std::vector<st_table> Vtable;
  Vtable.push_back(st_table("auftragentry","geliefert"));
  std::vector<AuftragBase::ID> Vauftragid;
  Vauftragid.push_back(AuftragBase::ungeplante_id);
  Vauftragid.push_back(AuftragBase::dispo_auftrag_id);
  force_execute(Vtable,Vauftragid,0,"geliefert",analyse_only);
}


void ppsInstanzReparatur::force_open_0er_und_2er(const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  std::vector<st_table> Vtable;
  Vtable.push_back(st_table("auftragentry","status"));
  Vtable.push_back(st_table("auftrag","stat"));
  std::vector<AuftragBase::ID> Vauftragid;
  Vauftragid.push_back(AuftragBase::ungeplante_id);
  Vauftragid.push_back(AuftragBase::dispo_auftrag_id);
  force_execute(Vtable,Vauftragid,OPEN,"Stati",analyse_only);
}

void ppsInstanzReparatur::force_execute(const std::vector<st_table> &Vtable,
          const std::vector<AuftragBase::ID> &Vauftragid,
          const int Wert,const std::string &was,
          const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  for(std::vector<st_table>::const_iterator i=Vtable.begin();i!=Vtable.end();++i)
   {
     std::string com="update "+i->table+" set "+i->column+"="+itos(Wert)+
                  " where instanz="+itos(Id())+" and "+i->column+"!="+itos(Wert)+
                  " and auftragid="; 
     for(std::vector<AuftragBase::ID>::const_iterator j=Vauftragid.begin();j!=Vauftragid.end();++j)
      {
        Transaction tr;
        Query::Execute(com+=itos(*j));
        SQLerror::test(__FILELINE__,100);
        if(sqlca.sqlerrd[2])
         {
           if(analyse_only) std::cout << "Analyse: ";
           std::cout << *j<<"er "+was+" ("<<Name()<<","<<*this<<") ge�ndert: "<< sqlca.sqlerrd[2]<<'\n';
         }
        if(!analyse_only) tr.commit();
      }
   }
}



void ppsInstanzReparatur::force_eigene_KundenId(const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  if(KundenInstanz()) return; // Finger WEG
  if(!ExterneBestellung())  //Wirklich ALLE Auftr�ge haben die eigene KundenID
   {
     Transaction tr;
     std::string com="update auftrag set kundennr="+itos(Kunde::eigene_id)+
                  " where instanz="+itos(Id())+" and kundennr!="+itos(Kunde::eigene_id);
     Query::Execute(com);
     SQLerror::test(__FILELINE__,100);
     if(sqlca.sqlerrd[2])
      {
        if(analyse_only) std::cout << "Analyse: ";
        std::cout << "F�r alle Auftrag-Id die Kunden ge�ndert: "<< sqlca.sqlerrd[2]<<'\n';
      }
     if(!analyse_only) tr.commit();
   }
  // else // NICHT die 20000er Auftr�ge
  std::vector<st_table> Vtable;
  Vtable.push_back(st_table("auftrag","kundennr"));
  std::vector<AuftragBase::ID> Vauftragid;
  Vauftragid.push_back(AuftragBase::ungeplante_id);
  Vauftragid.push_back(AuftragBase::dispo_auftrag_id);
  Vauftragid.push_back(AuftragBase::plan_auftrag_id);
  force_execute(Vtable,Vauftragid,Kunde::eigene_id,"Kunden",analyse_only);
}

#endif // alter Code

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ppsInstanzReparatur::ReparaturLager(const int uid,const bool analyse_only) const throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  assert(LagerInstanz());
  std::vector<LagerInhalt> LI=getLagerInhalt(); 
  vormerkungen_subrahieren(uid,LI,analyse_only);
}

// hmm. das sieht sehr nach Baustelle aus CP
void ppsInstanzReparatur::vormerkungen_subrahieren(int uid,const  std::vector<LagerInhalt> &LI,const bool analyse_only) const
{
//std::cout << "Anzahl der Artikel im Lager = "<<LI.size()<<'\n';
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  for(std::vector<LagerInhalt>::const_iterator i=LI.begin();i!=LI.end();++i)
   {
     bool set_dispo_to_zero=false;
     AuftragBase::mengen_t menge=i->GesamtMenge();
//std::cout <<i->Artikel().Id()<<' '<<cH_ArtikelBezeichnung(i->Artikel())->Bezeichnung()
//  <<'\t'<<menge<<'\n';

     // Vorgemerkte Menge (1er Auftr�ge) wieder abziehen
     // Schon eingetragene Menge wieder abziehen
     SelectedFullAufList auftraglist1=SelectedFullAufList(SQLFullAuftragSelector::
       sel_Artikel_Planung_id(Id(),ManuProC::DefaultValues::EigeneKundenId,i->Artikel(),AuftragBase::plan_auftrag_id));
     // der Selector holt nur die Auftr�ge mit dem Status OPEN
     for (SelectedFullAufList::const_iterator j=auftraglist1.begin();j!=auftraglist1.end();++j)
       {
         if(j->Id()!=AuftragBase::plan_auftrag_id) assert(!"never get here");
         menge-=j->getRestStk() ;
//std::cout << "\tPlanung abziehen "<<AufEintragBase(*j)<<'\t'<<j->getRestStk()<<'\t'<<menge<<'\n';
         if(menge<0) // mehr Menge vorgeplant als vorhanden
           {
            set_dispo_to_zero=true;
//std::cout << "\t"<<AufEintragBase(*j)<<'\t'<<j->getRestStk()<<'\t'<<menge<<'\n';
//std::cout << "\t\tReparaturMenge: "<<-menge<<'\n';
            if(analyse_only)
              std::cout << "Analyse: Mengenupdate von "<<*j<<" Menge:"<<menge<<'\n';
            else
             {
      assert(!"nicht implementiert\n");  
//               j->updateStkDiffBase__(uid,menge);
//               AufEintragZuMengenAenderung::increase_parents__reduce_assingments(uid,*j,-menge);
             }
            menge=0;
           }
       }
     SelectedFullAufList auftraglist2=SelectedFullAufList(SQLFullAuftragSelector::
          sel_Artikel_Planung_id(Id(),ManuProC::DefaultValues::EigeneKundenId,i->Artikel(),AuftragBase::dispo_auftrag_id));
     assert(auftraglist2.empty() || auftraglist2.size()==1);
     for (SelectedFullAufList::const_iterator j=auftraglist2.begin();j!=auftraglist2.end();++j)
      {
         if(j->Id()!=AuftragBase::dispo_auftrag_id) assert(!"never get here");
         assert(j->getStueck()==j->getRestStk());
         menge-=j->getRestStk();
//std::cout << "\tDispo abziehne "<<AufEintragBase(*j)<<'\t'<<j->getRestStk()<<'\t'<<menge<<'\n';
         if(set_dispo_to_zero)
          {
            if(analyse_only)
              std::cout << "Analyse: Mengenupdate von "<<*j<<" Menge:"<<-j->getStueck()<<'\n';
            else
      assert(!"nicht implementiert\n");  
//              j->updateStkDiffBase__(uid,-j->getStueck());
          }
      }
     if(menge!=0 && !set_dispo_to_zero) 
      {
        if(analyse_only)
             std::cout << "Analyse: DispoAuftr�ge_anlegen: "<<Name()<<'\t'<<i->Artikel()<<"\tMenge:"<<menge<<'\n';
        else
      assert(!"nicht implementiert\n");  
//            DispoAuftraege_anlegen(uid,i->Artikel(),menge);
      }
   }
}   


void ppsInstanzReparatur::DispoAuftraege_anlegen(const int uid,const ArtikelBase &artikel,const AuftragBase::mengen_t &menge) const
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
   assert(EigeneLagerKlasseImplementiert());
std::cout << "Mengen�nderung im Lager "<<Name()<<'\t'<<menge<<'\n';
   if(menge>=0)
      LagerBase(this).rein_ins_lager(artikel,menge,uid);
}

std::vector<LagerInhalt> ppsInstanzReparatur::getLagerInhalt() const
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,Name(),Id());
  std::vector<LagerInhalt> LI;
#if defined PETIG_EXTENSIONS && defined MANUPROC_DYNAMICENUMS_CREATED
  if(Id() == ppsInstanzID::Rohwarenlager)  LI=RohwarenLager().LagerInhalt();
  else if(Id() == ppsInstanzID::Bandlager) LI=JumboLager().LagerInhalt();
  else 
#endif 
   { std::cout << Name()<<' '<<Id()<<' '<<ID()<<"\tKeine LagerKlasse implementiert\n";
     assert(!"never get here\n");
     return LI;
   }
  LagerBase::LagerInhaltSum(LI);
  return LI;
}

////////////////////////////////////////////////////////////////////////////////

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintrag &AE,const std::string &x,const std::string &y) const
{
  std::cout<<"Fehler Analyse: " << AE <<"  => "<<s<<"\t("<<x<<"), ("<<y<<")\n";
}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintrag &AE,const ABmt &x,const ABmt &y) const
{analyse(s,AE,x.String(),y.String());}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintrag &AE,const AufEintragBase &x,const ABmt &y) const
{analyse(s,AE,x.Instanz()->Name()+"/"+itos(x.Id())+"/"+itos(x.ZNr()),y.String());}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintrag &AE,const ArtikelBase &x,const ArtikelBase &y) const
{analyse(s,AE,itos(x.Id()),itos(y.Id()));}

void ppsInstanzReparatur::analyse(const std::string &s,const AufEintrag &AE,const cH_ppsInstanz &x,const cH_ppsInstanz &y) const
{analyse(s,AE,x->Name(),y->Name());}

static void Zuordnung_erniedrigen(AufEintrag &ae,
	AufEintragZu::list_t &eltern,AuftragBase::mengen_t &m,
	AuftragBase::ID typ)
{  for (AufEintragZu::list_t::iterator i=eltern.begin();i!=eltern.end();++i)
   {  if ((typ==AuftragBase::handplan_auftrag_id && i->AEB.Id()<typ)
   		|| i->AEB.Id()!=typ) continue;
      AuftragBase::mengen_t M=AuftragBase::min(m,i->Menge);
      if (!M) continue;
      AufEintragZu(i->AEB).setMengeDiff__(ae,-M);
      i->Menge-=M;
      m-=M;
      if (!m) break;
   }
}

bool ppsInstanzReparatur::Eltern(AufEintrag &ae, AufEintragZu::list_t &eltern, bool analyse_only) const
{  // 2er und Kundenauftr�ge d�rfen keine Kinder haben!
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
   {  if (ae.Instanz()==i->AEB.Instanz())
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
            if (!analyse_only) AufEintragZu(i->AEB).setMenge(ae,0);
            i->Menge=0;
            alles_ok=false;
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
         if (menge2>=ae.getRestStk())
         {  analyse("Mehr Dispomenge als noch frei",ae,i->AEB,menge2-ae.getRestStk());
            if (!analyse_only) 
               AufEintragZu(i->AEB).setMengeDiff__(ae,ae.getRestStk()-menge2);
            i->Menge+=ae.getRestStk()-menge2;
            // vielleicht noch den Ziel 2er reduzieren?
            alles_ok=false;
         }
      }
   }
   // Sum zu gro�: nachbestellen
   if (menge>ae.getStueck())
   {  analyse("mehr v.o. ben�tigt als jemals bestellt",ae,menge,ae.getStueck());
      alles_ok=false;
      if (!analyse_only)
      {if (ae.Id()==AuftragBase::ungeplante_id) 
         ae.MengeAendern(getuid(),menge-ae.getStueck(),true,AufEintragBase(),
         	ManuProC::Auftrag::r_Reparatur);
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
   else if (menge<ae.getRestStk() && !ae.Instanz()->ProduziertSelbst())
   {  analyse("weniger offen als nun v.o. ben�tigt",ae,menge,ae.getStueck());
      alles_ok=false;
      if (!analyse_only)
      {if (ae.Id()==AuftragBase::ungeplante_id)
         ae.MengeAendern(getuid(),menge-ae.getRestStk(),true,AufEintragBase(),
         	ManuProC::Auftrag::r_Reparatur);
       else
         // 2er erh�hen
         AuftragBase(ae.Instanz(),AuftragBase::dispo_auftrag_id).
              BestellmengeAendern(menge-ae.getRestStk(),ae.getLieferdatum(),
              		ae.Artikel(),OPEN,getuid(),ae);
      }
   }
   return alles_ok;
}

bool ppsInstanzReparatur::Kinder(AufEintrag &ae, AufEintragZu::map_t &kinder, bool analyse_only) const
{  bool alles_ok=true;
   if (ae.Id()==AuftragBase::dispo_auftrag_id)
   {  // 2er: Kinder gleiche instanz
      AuftragBase::mengen_t menge2;
      for (AufEintragZu::map_t::iterator i=kinder.begin();i!=kinder.begin();++i)
      {  for (AufEintragZu::list_t::iterator j=i->second.begin();j!=i->second.end();)
         {  if (j->AEB.Instanz()!=ae.Instanz())
            {  analyse("Instanz passt nicht",ae,j->AEB,j->Menge);
             weg:
               if (!analyse_only) AufEintragZu::remove(ae,j->AEB);
               j=i->second.erase(j);
               alles_ok=false;
               continue;
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
      if (menge2!=ae.getStueck())
      {  analyse("2er: Zuordnungen!=eigene Menge",ae,menge2,ae.getStueck());
         if (!analyse_only) 
            ae.MengeAendern(getuid(),menge2-ae.getStueck(),false,
            		AufEintragBase(),ManuProC::Auftrag::r_Reparatur);
      }
   }
   else // 0er, 1er, 3er
   {  for (AufEintragZu::map_t::iterator i=kinder.begin();i!=kinder.begin();++i)
      {  AuftragBase::mengen_t menge;
         for (AufEintragZu::list_t::iterator j=i->second.begin();j!=i->second.end();)
         {  if (ae.Instanz()->NaechsteInstanz(ae.Artikel())!=ppsInstanzID::None
         	&& j->AEB.Instanz()!=ae.Instanz()->NaechsteInstanz(i->first))
            {  analyse("Instanz passt nicht",ae,j->AEB,j->Menge);
             weg1:
               if (!analyse_only) AufEintragZu::remove(ae,j->AEB);
               j=i->second.erase(j);
               alles_ok=false;
               continue;
            }
            else if (ae.Instanz()->NaechsteInstanz(ae.Artikel())==ppsInstanzID::None)
            {  if (!ArtikelBaum(ae.Artikel()).istKind(i->first))
               {  analyse("Kindartikel falsch",ae,j->AEB,j->Menge);
                  goto weg1;
               }
               // Artikel ist schon mal richtig ...
               cH_ppsInstanz bi=ppsInstanz::getBestellInstanz(i->first);
               if (j->AEB.Instanz()!=bi && !bi->PlanungsInstanz())
               {  analyse("Kindartikel bei falscher Instanz",ae,j->AEB,j->Menge);
                  goto weg1;
               }
            }
            AufEintrag ae2(j->AEB);
            if (ae2.getLieferdatum()+ae.Instanz()->ProduktionsDauer()
            		>ae.getLieferdatum()) 
            {  analyse("Datum passt nicht",ae,j->AEB,j->Menge);
               goto weg1;
            }
            menge+=j->Menge;
            ++j;
         }
         // schauen ob offeneMenge=Sum(kinder)
         AuftragBase::mengen_t richtigeMenge=
         	ae.getRestStk()*ArtikelBaum(ae.Artikel()).Faktor(i->first);
         if (menge!=richtigeMenge)
         {  analyse("Zuordnungen!=eigene RestMenge",ae,menge,richtigeMenge);
            assert (analyse_only);
            alles_ok=false;
   // Sum zu klein: nachbestellen
   // Sum zu gross: abbestellen (falls 0er, bei 1er 2er erzeugen)
         }
      }
   }
   return alles_ok;
}

bool ppsInstanzReparatur::Lokal(AufEintrag &ae, bool analyse_only) const
{  bool alles_ok=true;
   if (in(ae.Id(),AuftragBase::dispo_auftrag_id,AuftragBase::ungeplante_id))
   {  if (!!ae.getGeliefert())
      {  alles_ok=false;
         analyse("Bei 0/2ern darf nichts geliefert worden sein.\n",ae);
         if (!analyse_only) 
            Query("update auftragentry set geliefert=0 "
         	"where (instanz,auftragid,zeilennr) = (?,?,?)")
         	<< ae;
//         ae.geliefert=0;
      }
      if (ae.getAufStatus()!=OPEN)
      {  alles_ok=false;
         analyse("0/2er Auftr�ge m�ssen offen sein\n",ae);
         if (!analyse_only) Auftrag(ae).setStatusAuftrag_(OPEN);
      }
      if (ae.getEntryStatus()!=OPEN)
      {  alles_ok=false;
         analyse("0/2er Eintr�ge m�ssen offen sein\n",ae);
         if (!analyse_only) ae.setStatus(OPEN,getuid(),true);
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
//      ae.geliefert=ae.getStueck();
   }
   
   if (ae.Id()==AuftragBase::plan_auftrag_id)
   {  if (ae.Instanz()==ppsInstanzID::Kundenauftraege)
      {  alles_ok=false;   
         analyse("Es darf keine 1er bei den Kundenauftr�gen geben\n",ae);
         // Bitte von Hand reparieren!
      }
      else if (!!ae.getRestStk() && !ae.Instanz()->LagerInstanz())
      {  alles_ok=false;
         analyse("1er Auftr�ge sollten CLOSED sein\n",ae);
         if (!analyse_only) ae.abschreiben(ae.getRestStk());
      }
      if (ae.getEntryStatus()!=CLOSED && !ae.Instanz()->LagerInstanz())
      {  alles_ok=false;
         analyse("1er Auftr�ge sollten CLOSED sein\n",ae);
         if (!analyse_only) ae.setStatus(CLOSED,getuid(),true);
      }
   }
   if (ae.Instanz()!=ppsInstanzID::Kundenauftraege
   	&& !in(ae.getEntryStatus(),OPEN,CLOSED))
   {  alles_ok=false;
      analyse("Interne Auftr�ge m�ssen OPEN/CLOSED sein\n",ae);
      if (!analyse_only) ae.setStatus(CLOSED,getuid(),true);
   }
   if (ae.getGeliefert()>=ae.getStueck()
   	&& ae.getEntryStatus()!=CLOSED)
   {  alles_ok=false;
      analyse("Erf�llte Auftr�ge m�ssen CLOSED sein\n",ae);
      if (!analyse_only) ae.setStatus(CLOSED,getuid(),true);
   }
   else if (ae.Instanz()!=ppsInstanzID::Kundenauftraege 
   	&& ae.getGeliefert()!=ae.getStueck()
   	&& ae.getEntryStatus()!=OPEN)
   {  alles_ok=false;
      analyse("Offene interne Auftr�ge m�ssen OPEN sein\n",ae);
      if (!analyse_only) ae.setStatus(OPEN,getuid(),true);
   }
   
   if (ae.Instanz()->LagerInstanz() 
   	&& ae.Id()==AuftragBase::dispo_auftrag_id
   	&& ae.getLieferdatum()!=LagerBase::Lagerdatum())
   {  alles_ok=false;
      analyse("Das Datum von 2ern im Lager sollte 'epoch' sein",ae);
      // Bitte von Hand reparieren!
   }
   return alles_ok;
}
