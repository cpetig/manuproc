// $Id: TreeViewUtility.cc,v 1.10 2004/01/30 13:26:25 christof Exp $
/*  libKomponenten: GUI components for ManuProC's libcommon++
 *  Copyright (C) 2002 Adolf Petig GmbH & Co. KG, written by Christof Petig
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

#include "TreeViewUtility.h"
#include <stdarg.h>
#include <cassert>

TreeViewUtility::CListEmulator::CListEmulator(const std::vector<Glib::ustring> &t)
	: cols(t.size()), titles(t)
{  for (std::vector<Gtk::TreeModelColumn<Glib::ustring> >::iterator i=cols.begin();
		i!=cols.end();++i)
      add(*i);
   m_refStore=Gtk::ListStore::create(*this);
}

TreeViewUtility::CListEmulator::CListEmulator(const Glib::ustring &title)
{  cols.push_back(Gtk::TreeModelColumn<Glib::ustring>());
   add(cols.back());
   titles.push_back(title);
   m_refStore=Gtk::ListStore::create(*this);
}

void TreeViewUtility::CListEmulator::attach_to(Gtk::TreeView &tv)
{  tv.set_model(m_refStore);
   for (unsigned i=0;i<cols.size();++i)
      tv.append_column(titles.at(i),cols.at(i));
   view=&tv;
}

TreeViewUtility::CList::CList(const std::vector<Glib::ustring> &titles)
  : emu(titles)
{  emu.attach_to(*this);
}

TreeViewUtility::CList::CList(const char *title1, ...)
  : emu()
{  va_list ap;
   va_start(ap,title1);
   std::vector<Glib::ustring> titles;
   titles.push_back(title1);
   const char *t;
   while ((t=va_arg(ap,const char *)))
   {  titles.push_back(t);
   }
   va_end(ap);
   emu.set_titles(titles);
   emu.attach_to(*this);
}

void TreeViewUtility::CListEmulator::set_titles(const std::vector<Glib::ustring> &_titles)
{  unsigned old_size=titles.size(),new_size=_titles.size();
   assert(new_size>old_size); // nur vergrößern
   cols.resize(new_size);
   titles=_titles;
   for (unsigned i=old_size;i<new_size;++i)
      add(cols[i]);
   m_refStore=Gtk::ListStore::create(*this);
}

void TreeViewUtility::CListEmulator::set_title(const Glib::ustring &_title)
{  std::vector<Glib::ustring> titles;
   titles.push_back(_title);
   set_titles(titles);
}

int TreeViewUtility::CListEmulator::get_selected_row_num() const
{  Gtk::TreeModel::iterator it=view->get_selection()->get_selected();
   assert(!!it);
   Gtk::TreeModel::Path p=view->get_model()->get_path(it);
   assert(p.size()==1);
   return *(p.begin());
}

static void increment(const Gtk::TreeModel::iterator&,int *i) { ++*i; }

bool TreeViewUtility::CListEmulator::selection_empty() const
{  int num=0;
   view->get_selection()->selected_foreach(SigC::bind(SigC::slot(&increment),&num));
   return !num;
}
