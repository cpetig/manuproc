// $Id: string_Entry.cc,v 1.3 2002/12/03 09:10:44 christof Exp $
/*  libKomponenten: ManuProC's Widget library
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

#include "string_Entry.hh"

void string_Entry::refresh(gpointer x)
{ if (x==&model.Value()) 
  {my_ch_con.block();
   Gtk::Entry::set_text(model.get_value());
   any_change=false;
   my_ch_con.unblock();
  }
}

bool string_Entry::on_focus_out(GdkEventFocus *ev)
{  if (any_change)
   {  ch_con.block();
      model=Gtk::Entry::get_text();
      ch_con.unblock();
      any_change=false;
   }
//   select_region(0,0); // needed ?
   return false;
}

bool string_Entry::on_focus_in(GdkEventFocus *ev)
{  select_region(0,-1);
   return false;
}

string_Entry::string_Entry(const Model_ref<T> &m)
	: any_change(false), model(m)
{  Gtk::Entry::set_text(model.get_value());
   signal_focus_out_event().connect(SigC::slot(*this,&string_Entry::on_focus_out),true);
   signal_focus_in_event().connect(SigC::slot(*this,&string_Entry::on_focus_in),true);
   // I'm not quite sure whether this is needed at all
   signal_activate().connect(SigC::slot(*this,&string_Entry::on_activate),true);
   ch_con=model.signal_changed().connect(SigC::slot(*this,&string_Entry::refresh));
   my_ch_con=signal_changed().connect(SigC::slot(*this,&string_Entry::keypress));
};

void string_Entry::keypress()
{  any_change=true;
}

void string_Entry::on_activate()
{  on_focus_out(0);
}

