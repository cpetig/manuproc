// $Id: AufEintragZuMengenAenderung.cc,v 1.18 2003/08/11 14:22:57 christof Exp $
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2003 Adolf Petig GmbH & Co. KG, written by Malte Thoma
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

#include <Auftrag/AufEintragZu.h>  
#include <Auftrag/AufEintrag.h>  
#include <Auftrag/AufEintragZuMengenAenderung.h>
#include <Misc/TraceNV.h>
#include <Misc/relops.h>

#if 0
void AufEintragZuMengenAenderung::change_parent(const int uid,
                                                const AufEintragBase &old_parent,
                                                const AufEintragBase &new_parent,
                                                const AuftragBase::mengen_t &menge) throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,
      NV("Old_AEB",old_parent),NV("New_AEB",new_parent),NV("Menge",menge));
  AufEintragZu::list_t K=AufEintragZu(old_parent).get_Referenz_list(old_parent,true,AufEintragZu::list_ohneArtikel);
  for(AufEintragZu::list_t::const_iterator i=K.begin();i!=K.end();++i)
   {
     AufEintragZu(new_parent).Neu(i->AEB,menge); // Neu versucht zun�chst ein update
     AufEintragZu(old_parent).Neu(i->AEB,-menge); 
   }
}
#endif


#if 0
void AufEintragZuMengenAenderung::Change_Zuordnung_to_Children(const bool child,const AufEintrag &AE,
                        const AuftragBase::mengen_t &menge) throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,NV("AE",AE),NV("Menge",menge),NV("Child",child));
  const bool reduce = (menge<0);
  AuftragBase::mengen_t Me=menge;
  if(reduce) Me*=-1;
  // K ist nach Instanzen sortiert
  AufEintragZu::list_t  K=AufEintragZu(AE).get_Referenz_list_ungeplant();
  std::map<cH_ppsInstanz,AuftragBase::mengen_t> IM;
  for(AufEintragZu::list_t::const_iterator i=K.begin();i!=K.end();++i)
   {
     // Wenn diese Instanz schon behandelt wurde und keine Menge mehr �ber ist
     if(IM.find(i->AEB.Instanz())!=IM.end() && 
        IM.find(i->AEB.Instanz())->second==Me) continue;

     AuftragBase::mengen_t M;
     ArtikelBaum::faktor_t F=ArtikelBaum(AE.Artikel()).Faktor(i->Art);
     if (reduce) M=-AuftragBase::min(i->Menge,Me*F);
     else        M=Me*F;
     IM[i->AEB.Instanz()] += F*M.abs();
//cout << "Change_Zuordnung_to_Children: "<<AE<<'\t'<<i->AEB<<'\t'<<M;
     AufEintragZu(AE).setMengeDiff__(i->AEB,M);
//cout <<"Faktor="<<F<<'\t'<<M<<'\n';
   }
}
#endif

#if 0
void AufEintragZuMengenAenderung::move_zuordnung_zu_geplantem(const int uid,
         AufEintrag &AE0er, AufEintrag &AE1er,
         AuftragBase::mengen_t menge,
         ManuProC::Auftrag::Action reason) throw(SQLerror)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,NV("AE0er",AE0er),NV("AE1er",AE1er),NV("Menge",menge));
  assert(!"AufEintragZuMengenAenderung::move_zuordnung_zu_geplantem  called");
  AufEintragZu::list_t L=AufEintragZu::get_Referenz_list(AE0er,AufEintragZu::list_eltern,AufEintragZu::list_ohneArtikel);
  for(AufEintragZu::list_t::reverse_iterator i=L.rbegin();i!=L.rend();++i)
   {
    AuftragBase::mengen_t M=AuftragBase::min(i->Menge,menge);
    AufEintragZu(i->AEB).setMengeDiff__(AE0er,-M);
    AufEintragZu(i->AEB).Neu(AE1er,M);
    menge-=M;
    if(!menge) break;
   }
}
#endif

// ElternAEB erh�lt die Menge vom 2er
// dies scheint den 1er im Lager zu erh�hen
void AufEintragZuMengenAenderung::freie_dispomenge_verwenden(const int uid,
         const AufEintrag &AE2er,AuftragBase::mengen_t menge,const AufEintragBase &ElternAEB) throw(SQLerror)
{
  AufEintragZu::list_t L=AufEintragZu(AE2er).get_Referenz_list_geplant();
  for(AufEintragZu::list_t::reverse_iterator i=L.rbegin();i!=L.rend();++i)
   {
    AuftragBase::mengen_t M=AuftragBase::min(i->Menge,menge);
    AufEintragZu(AE2er).setMengeDiff__(i->AEB,-M);
    AufEintragZu(ElternAEB).Neu(i->AEB,M);
    menge-=M;
    if(!menge) break;
   }
}
