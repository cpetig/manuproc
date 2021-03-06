// $Id: Optionmenu_Kundengruppe.cc,v 1.10 2006/10/31 16:10:37 christof Exp $
/*  libKomponenten: ManuProC's Widget library
 *  Copyright (C) 2002-2005 Adolf Petig GmbH & Co. KG
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

#include "Optionmenu_Kundengruppe.hh"
#include <Gtk_OStream.h>
#include <SelectMatching.h>
#include <Misc/i18n.h>

Optionmenu_Kundengruppe::Optionmenu_Kundengruppe()
{ fuelle_menu();
  get_menu()->signal_deactivate().connect(activate.slot());
}

Kundengruppe::ID Optionmenu_Kundengruppe::get_value() const
{
  int i=long(const_cast<Gtk::MenuItem*>(get_menu()->get_active())->get_data("user_data"));
  return (Kundengruppe::ID)i;
}


void Optionmenu_Kundengruppe::reload()
{
 fuelle_menu(true);
 get_menu()->signal_deactivate().connect(activate.slot());
}


void Optionmenu_Kundengruppe::fuelle_menu(bool _reload)
{
  std::vector<cH_Kundengruppe> V;
  Query("select grpnr,obergruppe,name,kommentar,owner,obergruppe_uniq from ku_gruppe order by grpnr").FetchArray(V);
  Gtk::OStream os(this);
  if(_reload) os.flush();

  for(std::vector<cH_Kundengruppe>::iterator i=V.begin();i!=V.end();++i)
   {
     os << dbgettext((*i)->GrpName());
     os.flush((void*)(*i)->Id());
   }
  os << _("-- Alle Gruppen --"); os.flush((void*)(KundengruppeID::None));
}

void Optionmenu_Kundengruppe::register_value(Kundengruppe::ID id, std::string const& name)
{ Gtk::OStream os(this,std::ios::app);
  os << dbgettext(name);
  os.flush(gpointer(id));
}

namespace Gtk {
static bool operator==(gpointer data,const Kundengruppe::ID &i)
{ 
  return long(data)==i;
}
}

void Optionmenu_Kundengruppe::set_value(const Kundengruppe::ID &i)
{  Gtk::Menu_Helpers::SelectMatching(*this,i);
}

