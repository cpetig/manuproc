/* $Id: ProvAbrechnungEntry.h,v 1.1 2002/11/22 16:01:55 christof Exp $ */
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
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


#ifndef PROVABRECHNUNGENTRY
#define PROVABRECHNUNGENTRY

#include <Aux/fixedpoint.h>
#include <Aux/SQLerror.h>
#include <BaseObjects/ManuProcEntity.h>
#include <Lieferschein/RechnungEntry.h>
#include <Lieferschein/Rechnung.h>
#include <Artikel/Preis.h>
#include <Kunde/Kunde.h>

class ProvAbrechnungEntry : public ManuProcEntity<>
{
 RechnungEntry rngentry;
 Preis umsatz;
 fixedpoint<2> provsatz;
 fixedpoint<2> provision;
 const Kunde::ID verknr;
 
public:

 ProvAbrechnungEntry() : rngentry(RechnungEntryBase()),
 	provsatz(0.0), provision(0.0),verknr(Kunde::none_id) {}
 ProvAbrechnungEntry(const ManuProcEntity<>::ID _abrnr, 
 	const Kunde::ID _verknr, const RechnungEntry::ID _rngid,
	int zeilennr) throw(SQLerror); 	
 ManuProcEntity<>::ID Id() const { return entityid;} 		     
 static void newAbrechnungEntries(
 	const ManuProcEntity<>::ID _abrnr, 
 	const Kunde::ID _verknr, const Rechnung &rng) throw(SQLerror);
};

#endif
