// $Id: TreeViewUtility.cc,v 1.20 2004/05/03 13:44:36 christof Exp $
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
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#  include <sigc++/compatibility.h>
#  include <sigc++/bind.h>
#endif

TreeViewUtility::CListEmulator::CListEmulator(const std::vector<Glib::ustring> &t)
	: cols(t.size()), titles(t), view()
{  for (std::vector<Gtk::TreeModelColumn<Glib::ustring> >::iterator i=cols.begin();
		i!=cols.end();++i)
      add(*i);
   m_refStore=Gtk::ListStore::create(*this);
}

TreeViewUtility::CListEmulator::CListEmulator(const Glib::ustring &title)
	: cols(1), view()
{  add(*cols.begin());
   titles.push_back(title);
   m_refStore=Gtk::ListStore::create(*this);
}

void TreeViewUtility::CListEmulator::attach_to(Gtk::TreeView &tv)
{  view=&tv;
   view->remove_all_columns();
   view->set_model(m_refStore);
   for (unsigned i=0;i<cols.size();++i)
      view->append_column(titles.at(i),cols.at(i));
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
   assert(new_size>=old_size); // nur vergr��ern
   cols.resize(new_size);
   titles=_titles;
   for (unsigned i=old_size;i<new_size;++i)
      add(cols[i]);
   m_refStore=Gtk::ListStore::create(*this);
   if (view) // eigentlich sollte das attach erst sp�ter passiert sein ...
      attach_to(*view);
}

void TreeViewUtility::CListEmulator::set_title(const Glib::ustring &_title)
{  std::vector<Glib::ustring> _titles;
   _titles.push_back(_title);
   set_titles(_titles);
}

static void mark_line(const Gtk::TreeModel::Path &p,int *i) 
{  assert(p.size()==1);
   *i=*(p.begin());
}

int TreeViewUtility::CListEmulator::get_selected_row_num() const
{  int row=-1;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   view->get_selection()->selected_foreach_path(sigc::bind(sigc::ptr_fun(&mark_line),&row));
#else
   view->get_selection()->selected_foreach(SigC::bind(SigC::slot(&mark_line),&row));
#endif
   return row;
}

static void increment(const Gtk::TreeModel::iterator&,int *i) { ++*i; }

bool TreeViewUtility::CListEmulator::selection_empty() const
{  int num=0;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   view->get_selection()->selected_foreach_iter(sigc::bind(sigc::ptr_fun(&increment),&num));
#else
   view->get_selection()->selected_foreach(SigC::bind(SigC::slot(&increment),&num));
#endif   
   return !num;
}

void TreeViewUtility::CListEmulator::set_column_justification(int col, Gtk::AlignmentEnum just)
{  view->get_column(col)->set_alignment(just);
   gfloat al=0;
   if (just==Gtk::ALIGN_RIGHT) al=1;
   else if (just==Gtk::ALIGN_CENTER) al=.5;
   view->get_column(col)->get_first_cell_renderer()->property_xalign()=al;
}

void TreeViewUtility::CListEmulator::set_column_justification(int col, Gtk::Justification just)
{  Gtk::AlignmentEnum al=Gtk::ALIGN_LEFT;
   switch(just)
   {  case Gtk::JUSTIFY_LEFT: al=Gtk::ALIGN_LEFT; break;
      case Gtk::JUSTIFY_RIGHT: al=Gtk::ALIGN_RIGHT; break;
      case Gtk::JUSTIFY_CENTER: al=Gtk::ALIGN_CENTER; break;
      case Gtk::JUSTIFY_FILL: al=Gtk::ALIGN_LEFT; break;
   }
   set_column_justification(col,al);
}

Gtk::TreeModel::iterator TreeViewUtility::CListEmulator::append(const gchar* text[])
{  Gtk::TreeModel::iterator iter =get_store()->append();
   for (unsigned i=0;i<cols.size();++i)
      (*iter)[cols[i]]=text[i];
   return iter;
}

Gtk::TreeModel::iterator TreeViewUtility::CListEmulator::append(const std::vector<Glib::ustring> &text)
{  Gtk::TreeModel::iterator iter =get_store()->append();
   for (unsigned i=0;i<cols.size() && i<text.size();++i)
      (*iter)[cols[i]]=text[i];
   return iter;
}

void TreeViewUtility::CListEmulator::add(Gtk::TreeModelColumnBase& column)
{  Gtk::TreeModelColumnRecord::add(column);
   m_refStore=Gtk::ListStore::create(*this);
   if (view) // eigentlich sollte das attach erst sp�ter passiert sein ...
      attach_to(*view);
}
