/* $Id: Verfuegbarkeit.cc,v 1.4 2003/12/02 10:33:11 christof Exp $ */
/*  pps: ManuProC's ProductionPlanningSystem
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
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

#include <Auftrag/AufEintrag.h>
#include <Auftrag/Verfuegbarkeit.h>
//#include <Auftrag/AufEintrag_loops.h>
#include <Misc/relops.h>
#include <Misc/TraceNV.h>

Verfuegbarkeit::mengen_t Verfuegbarkeit::Mengen::summe() const
{  return  geliefert+ungeplant+geplant+vorraetig+error;
}

namespace
{
struct verf_recurse : distribute_children_cb
{	Verfuegbarkeit::mengen_t offset;
	mutable Verfuegbarkeit::map_t result;
	mutable ArtikelBaum artbaum;

	mutable ArtikelBase lastart;
	mutable Verfuegbarkeit::mengen_t lastoffs;
	mutable cH_ppsInstanz lastinst;

	AuftragBase::mengen_t operator()(const ArtikelBase &, 
	                const AufEintragBase &,AuftragBase::mengen_t) const;
	void operator()(const ArtikelBase &,AuftragBase::mengen_t) const;

	virtual ~verf_recurse() {}
	verf_recurse(const Verfuegbarkeit::mengen_t &o, Verfuegbarkeit::map_t &r,
			const ArtikelBaum &ab) 
		: offset(o), result(r), artbaum(ab) 
	{}
};
}

AuftragBase::mengen_t verf_recurse::operator()(const ArtikelBase &art, 
	                const AufEintragBase &aeb,AuftragBase::mengen_t m) const
{  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,NV("art",art),
		NV("aeb",aeb),NV("m",m),NV("offset",offset));
   if (art!=lastart)
   {  lastart=art;
      lastoffs=offset*artbaum.Faktor(art);
      lastinst=aeb.Instanz();
   }
   AuftragBase::mengen_t offset=lastoffs;
   
   AufEintragZu::list_t Eltern= 
   	AufEintragZu::get_Referenz_list(aeb,AufEintragZu::list_eltern,
					AufEintragZu::list_ohneArtikel);
   for (AufEintragZu::list_t::iterator i=Eltern.begin();i!=Eltern.end();++i)
   {  if (i->AEB==aeb) break;
      else offset+=i->Menge;
   }
   ManuProC::Trace(AuftragBase::trace_channel,__FILELINE__,
   		NV("lastoffs",lastoffs),NV("offset",offset));
   Verfuegbarkeit::verfuegbar(aeb,result,m,offset);
   lastoffs-=m;
   return m;
}

void verf_recurse::operator()(const ArtikelBase &art,AuftragBase::mengen_t m) const
{  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,NV("art",art),
		NV("lastinst",lastinst),NV("m",m));
   if (!!lastinst)
   {  result[Verfuegbarkeit::mapindex(lastinst,art)].error+=m;
   }
   else std::cerr << "verf_recurse::operator(): .error " << m << " von " << art << " �ber\n";
}

void Verfuegbarkeit::verfuegbar(const AufEintrag &ae, map_t &result, 
	mengen_t menge, mengen_t offset)
{  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,NV("ae",ae),
		NV("menge",menge),NV("offset",offset));
   mapindex idx(ae.Instanz(),ae.Artikel());
   if (!menge) menge=ae.getStueck();
   if (offset>=ae.getStueck()) return;
   if (!!ae.getGeliefert())
   {  if (ae.getGeliefert()<offset)
      {  mengen_t m=AuftragBase::max(menge,ae.getGeliefert()-offset);
         result[idx].geliefert+=m;
      	 menge-=m;
         if (!menge) return;
      }
      offset-=ae.getGeliefert();
   }
   if (offset+menge>ae.getStueck()) menge=ae.getStueck()-offset;
   ManuProC::Trace(AuftragBase::trace_channel,__FILELINE__,
   		NV("offset",offset),NV("menge",menge));
   
   assert(ae.Id()!=AuftragBase::dispo_auftrag_id);
   if (ae.Id()==AuftragBase::plan_auftrag_id || ae.Id()>=AuftragBase::handplan_auftrag_id)
   {  if (ae.Instanz()->LagerInstanz())
      {  result[idx].vorraetig+=AuftragBase::min(ae.getRestStk(),menge);
         ManuProC::Trace(AuftragBase::trace_channel,"result",
         	NV("gel",result[idx].geliefert),
   		NV("vorr",result[idx].vorraetig),NV("gepl",result[idx].geplant),
   		NV("unge",result[idx].ungeplant),NV("err",result[idx].error));
         return;
      }
      else
         result[idx].geplant+=AuftragBase::min(ae.getRestStk(),menge);
   }
   else
   {  assert(ae.Id()==AuftragBase::ungeplante_id);
      result[idx].ungeplant+=AuftragBase::min(ae.getRestStk(),menge);
   }
   
   // Rekursion
   distribute_children_rev_artbaum(ae,menge,ae.Artikel(),
   		verf_recurse(offset,result,ae.Artikel()));
   ManuProC::Trace(AuftragBase::trace_channel,"result",
         	NV("gel",result[idx].geliefert),
   		NV("vorr",result[idx].vorraetig),NV("gepl",result[idx].geplant),
   		NV("unge",result[idx].ungeplant),NV("err",result[idx].error));
}