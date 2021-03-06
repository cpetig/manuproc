// $Id: PersonenBox.cc,v 1.7 2006/03/09 21:13:36 christof Exp $
/*  libKomponenten: GUI components for ManuProC's libcommon++
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

#include "PersonenBox.hh"
#include <Aux/itos.h>
#include <Misc/i18n.h>

PersonenBox::PersonenBox()
{
  _tabelle_="kunden";
  _string1_="name2";
  _string2_="firma";
  _int_="kundennr";
  _none_id_=Kunde::none_id;
  setLabel(_("Id"),_("Nachname"),_("Vorname"));
  show_string2(true);

  Join(" join ku_gruppen_map m using (kundennr)");
}

void PersonenBox::set_gruppe(Kundengruppe::ID gid)
{
 Einschraenkung(" and m.grpnr="+itos(gid));
}


void PersonenBox::set_value(int i)
{  cH_Kunde PL(i);
   IntStringBox::set_value(PL->Id(),PL->getName(),PL->getName2());
}

cH_Kunde PersonenBox::get_value()
{
  return cH_Kunde(IntStringBox::get_value());
}

