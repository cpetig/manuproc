/* $Id: ArtikelImLager.h,v 1.3 2002/12/20 15:35:39 thoma Exp $ */
/*  pps: ManuProC's production planning system
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Malte Thoma
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

#ifndef ARTIKELIMLAGER
#define ARTIKELIMLAGER

#include <Artikel/ArtikelBase.h>
#include <Auftrag/AuftragBase.h>
#include <Auftrag/AufEintrag.h>

class ArtikelImLager : public ArtikelBase
{
      AuftragBase::mengen_t menge_dispo_auftraege;
      AuftragBase::mengen_t menge_plan_auftraege;

      std::vector<AufEintrag> V_dispo_auftraege;
      std::vector<AufEintrag> V_plan_auftraege;

      void reduce_in_dispo_or_plan(const bool dispo,const int uid,AuftragBase::mengen_t menge) const;

   public:
      ArtikelImLager(const cH_ppsInstanz &instanz,const ArtikelBase &artikel,const Petig::Datum &datum) throw(SQLerror);

      AuftragBase::mengen_t getMengeDispo() const {return menge_dispo_auftraege;}
      AuftragBase::mengen_t getMengePlan() const {return menge_plan_auftraege;}

      std::vector<AufEintrag> getDispoAuftraege() const {return V_dispo_auftraege;}
      std::vector<AufEintrag> getPlanAuftraege() const {return V_plan_auftraege;}

      void reduce_in_dispo(const int uid,AuftragBase::mengen_t menge) const
         {reduce_in_dispo_or_plan(true,uid,menge);}
      void reduce_in_plan(const int uid,AuftragBase::mengen_t menge) const
         {reduce_in_dispo_or_plan(false,uid,menge);}
};

#endif
