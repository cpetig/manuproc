// $Id: glademm_support.cc,v 1.3 2001/01/08 17:12:40 cvs_jacek Exp $
/*  libKomponenten: GUI components for ManuProC's libcommon++
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Christof Petig
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

// generated 1998/11/13 13:05:35 MET by christof@petig.petig.de
// using glademm V0.2.2
//
// some glademm convenience functions
//
// DO NOT EDIT THIS FILE !

#include "glademm_support.hh"

static map<const string,Gtk::Widget *> glademm_widgets;

Gtk::Widget *glademm_get_Widget(const string &name)
{  map<const string,Gtk::Widget *>::iterator i=glademm_widgets.find(name);
   if (i==glademm_widgets.end()) return 0;
   return (*i).second;
}

void glademm_set_Widget(const string &name, Gtk::Widget *val)
{  glademm_widgets[name]=val;
}

