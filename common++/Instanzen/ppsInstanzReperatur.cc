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

#include "ppsInstanz.h"
#include <Lager/Lager.h>
#include <Lager/JumboLager.h>
#include <Lager/RohwarenLager.h>
#include <Misc/SQLerror.h>
#include <sqlca.h>
#include <Auftrag/AufEintragZuMengenAenderung.h>
#include <Aux/Transaction.h>

void ppsInstanz::Reparatur_0er_und_2er(const int uid,const bool analyse_only) const throw(SQLerror)
{
   assert(Id() != ppsInstanzID::Kundenauftraege);
   SQLFullAuftragSelector sel0er= SQLFullAuftragSelector::sel_Status(Id(),OPEN,AuftragBase::ungeplante_id);
   SelectedFullAufList AL(sel0er);
//cout << "REPARATUR 2er 0er AL.size()\t"<<AL.size()<<'\n';
   for(SelectedFullAufList::iterator i=AL.begin();i!=AL.end();++i)
    {
      SQLFullAuftragSelector sel2er;
      if(LagerInstanz())
         sel2er=SQLFullAuftragSelector::sel_Artikel_Planung_id(Id(),Kunde::eigene_id,i->Artikel(),AuftragBase::dispo_auftrag_id,OPEN,LagerBase::Lagerdatum());
      else 
         sel2er=SQLFullAuftragSelector::sel_Artikel_Planung_id(Id(),Kunde::eigene_id,i->Artikel(),AuftragBase::dispo_auftrag_id,OPEN,i->getLieferdatum());
      SelectedFullAufList L2er(sel2er);
//std::cout << i->Instanz()<<'\t'<<i->Artikel()<<'\t'<<L2er.size()<<'\n';
      assert(L2er.empty() || L2er.size()==1);
      if(!L2er.empty() && L2er.begin()->getStueck()!=0) // Reparatur
       {
         AufEintrag A2er=*(L2er.begin());
         AuftragBase::mengen_t M=AuftragBase::min(i->getStueck(),A2er.getStueck());
         AuftragBase zielauftrag(Id(),AuftragBase::plan_auftrag_id);
//cout << "RepLan: "<<*i<<'\t'<<zielauftrag<<"Menge: "<<M<<'\n';
         if(analyse_only)
           cout << "Analyse: Planen von "<<*i<<"  nach  "<<zielauftrag<<"\tMenge: "<<M<<'\n';
         else
          {
            i->Planen(uid,M,zielauftrag,i->getLieferdatum(),ManuProC::Auftrag::r_Reparatur);
            L2er.begin()->updateStkDiffBase__(uid,-M);
          }
       }
    }
}



////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
namespace{
struct st_table{std::string table; std::string column;
              st_table(const std::string &t,const std::string &c) 
               : table(t),column(c) {}};
}



////////////////////////////////////////////////////////////////////////////////

void ppsInstanz::Reparatur_Konsistenz(const bool analyse_only) const throw(SQLerror)
{
  if(KundenInstanz()) return; // Finger WEG
  force_eigene_KundenId(analyse_only);
  force_open_0er_und_2er(analyse_only);
  force_2er_0er_geliefert_ist_null(analyse_only);
}

void ppsInstanz::force_2er_0er_geliefert_ist_null(const bool analyse_only) const throw(SQLerror)
{
  std::vector<st_table> Vtable;
  Vtable.push_back(st_table("auftragentry","geliefert"));
  std::vector<AuftragBase::ID> Vauftragid;
  Vauftragid.push_back(AuftragBase::ungeplante_id);
  Vauftragid.push_back(AuftragBase::dispo_auftrag_id);
  force_execute(Vtable,Vauftragid,0,"geliefert",analyse_only);
}


void ppsInstanz::force_open_0er_und_2er(const bool analyse_only) const throw(SQLerror)
{
  std::vector<st_table> Vtable;
  Vtable.push_back(st_table("auftragentry","status"));
  Vtable.push_back(st_table("auftrag","stat"));
  std::vector<AuftragBase::ID> Vauftragid;
  Vauftragid.push_back(AuftragBase::ungeplante_id);
  Vauftragid.push_back(AuftragBase::dispo_auftrag_id);
  force_execute(Vtable,Vauftragid,OPEN,"Stati",analyse_only);
}

void ppsInstanz::force_execute(const std::vector<st_table> &Vtable,
          const std::vector<AuftragBase::ID> &Vauftragid,
          const int Wert,const std::string &was,
          const bool analyse_only) const throw(SQLerror)
{
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



void ppsInstanz::force_eigene_KundenId(const bool analyse_only) const throw(SQLerror)
{
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



////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ppsInstanz::ReparaturLager(const int uid,const bool analyse_only) const throw(SQLerror)
{
  assert(LagerInstanz());
  std::vector<LagerInhalt> LI=getLagerInhalt(); 
  vormerkungen_subrahieren(uid,LI,analyse_only);
}

void ppsInstanz::vormerkungen_subrahieren(int uid,const  std::vector<LagerInhalt> &LI,const bool analyse_only) const
{
//std::cout << "Anzahl der Artikel im Lager = "<<LI.size()<<'\n';
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
              cout << "Analyse: Mengenupdate von "<<*j<<" Menge:"<<menge<<'\n';
            else
             {
               j->updateStkDiffBase__(uid,menge);
               AufEintragZuMengenAenderung::increase_parents__reduce_assingments(uid,*j,-menge);
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
              cout << "Analyse: Mengenupdate von "<<*j<<" Menge:"<<-j->getStueck()<<'\n';
            else
              j->updateStkDiffBase__(uid,-j->getStueck());
          }
      }
     if(menge!=0 && !set_dispo_to_zero) 
      {
        if(analyse_only)
             cout << "Analyse: DispoAuftr�ge_anlegen: "<<Name()<<'\t'<<i->Artikel()<<"\tMenge:"<<menge<<'\n';
        else
            DispoAuftraege_anlegen(uid,i->Artikel(),menge);
      }
   }
}   


#include <Aux/Trace.h>
void ppsInstanz::DispoAuftraege_anlegen(const int uid,const ArtikelBase &artikel,const AuftragBase::mengen_t &menge) const
{
   assert(EigeneLagerKlasseImplementiert());
std::cout << "Mengen�nderung im Lager "<<Name()<<'\t'<<menge<<'\n';
   if(menge>=0)
      LagerBase(this).rein_ins_lager(artikel,menge,uid);
}



std::vector<LagerInhalt> ppsInstanz::getLagerInhalt() const
{
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

