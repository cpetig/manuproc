// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_SEARCHCOMBO_H
#define _GTKMM_SEARCHCOMBO_H

#include <glibmm.h>

/* $Id: SearchCombo.hg,v 1.5 2004/01/29 14:55:52 christof Exp $ */

/* searchcombo.h
 * 
 * Copyright (C) 1999-2002 Adolf Petig GmbH & Co. KG
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtkmm/box.h>
#include <gtksearchcombo.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSearchCombo GtkSearchCombo;
typedef struct _GtkSearchComboClass GtkSearchComboClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class SearchCombo_Class; } // namespace Gtk
namespace Gtk
{

/** @addtogroup gtkmmEnums Enums and Flags */

/**
 * @ingroup gtkmmEnums
 */
enum SCContext
{
  SEARCH_FETCH,
  SEARCH_OPEN,
  SEARCH_CLOSE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::SCContext> : public Glib::Value_Enum<Gtk::SCContext>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


//: SearchCombo widget
//- A combo is a compound widget which crosses a text entry area and a pull
//- down list.  It may allow text entry or it may just allow list
//- values depending on the settings.  

class SearchCombo : public HBox
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SearchCombo CppObjectType;
  typedef SearchCombo_Class CppClassType;
  typedef GtkSearchCombo BaseObjectType;
  typedef GtkSearchComboClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~SearchCombo();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class SearchCombo_Class;
  static CppClassType searchcombo_class_;

  // noncopyable
  SearchCombo(const SearchCombo&);
  SearchCombo& operator=(const SearchCombo&);

protected:
  explicit SearchCombo(const Glib::ConstructParams& construct_params);
  explicit SearchCombo(GtkSearchCombo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkSearchCombo*       gobj()       { return reinterpret_cast<GtkSearchCombo*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkSearchCombo* gobj() const { return reinterpret_cast<GtkSearchCombo*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_activate();
  virtual void on_search(gboolean * cont, GtkSCContext context);


private:

  
public:
  explicit SearchCombo(bool always_fill=false, bool autoexpand=false);
  
  
  /**
   * @par Prototype:
   * <tt>void %activate()</tt>
   */
  Glib::SignalProxy0<void> signal_activate();
;
  
  /**
   * @par Prototype:
   * <tt>void %search(gboolean * cont, GtkSCContext context)</tt>
   */
  Glib::SignalProxy2<void,gboolean *,GtkSCContext> signal_search();
;
  
//  WRAP_MEMBER(value,value_in_list,value_in_list,bool,guint);
//  WRAP_MEMBER(value,ok_if_empty,ok_if_empty,bool,guint);
//  WRAP_MEMBER(value,case_sensitive,case_sensitive,bool,guint);
//  WRAP_MEMBER(value,always_fill,always_fill,bool,guint);
//  WRAP_MEMBER(value,enable_tab,enable_tab,bool,guint);
//  WRAP_MEMBER(value,autoexpand,autoexpand,bool,guint);
//  WRAP_MEMBER(value,start_idle,start_idle,bool,guint);
  
  /** Allow direct text entry
   * Whether the text in the entry must be or not be in the list.
   *
   * @param value Set to true if the value must be in list.
   *
   * @param empty Set to true if the text area is allowed to be empty.
   */
  
  void set_value_in_list(bool value = true, bool empty = false);

  /** Sets list case sensitive
   * Determines if the list items and text comparisons for
   * set_use_arrows_always() should be case sensitive.
   */
  
  void set_case_sensitive(bool val = true);

  //: Append an item.
  
  void add_item(const Glib::ustring &text);
  
  //: clear entry+list, mark for research
  
  void reset();

  //: set text no research
  
  void set_text(const Glib::ustring &text);
  
  
  Glib::ustring get_text() const;
//  const Glib::ustring get_text() const;
  
  
  void set_always_fill(bool val);
  
  void set_enable_tab(bool val);
  
  guint get_size() const;

  //: set sensitivity
  
  void set_editable(bool val);

  //: autoexpand - think twice!
  
  void set_autoexpand(bool val);
    
  
  void trigger_search();

  
  void set_start_on_idle(bool val);
    
  //: please do not use this function in new programs - it's for compatibility
  Entry* get_entry();
  const Entry* get_entry() const;
  
  
  gint get_selected_index() const;
   
    bool empty() const {  return !get_size(); }
    guint size() const {  return get_size(); }

  /**
 * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
 * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
 * the value of the property changes. 
 */
Glib::PropertyProxy<bool> property_case_sensitive();

  /**
 * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
 * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
 * the value of the property changes. 
 */
Glib::PropertyProxy<bool> property_allow_empty();
   
  /**
 * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
 * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
 * the value of the property changes. 
 */
Glib::PropertyProxy<bool> property_value_in_list();
 

};

} /* namespace Gtk */


namespace Glib
{
  /** @relates Gtk::SearchCombo */
  Gtk::SearchCombo* wrap(GtkSearchCombo* object, bool take_copy = false);
}
#endif /* _GTKMM_SEARCHCOMBO_H */

