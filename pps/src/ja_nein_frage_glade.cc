// generated 2006/5/22 16:46:05 CEST by christof@vesta.petig-baender.de
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 2.8.17 and gtkmm 2.8.5
//
// Please modify the corresponding derived classes in ./src/ja_nein_frage.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (GETTEXT_PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#endif
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <sigc++/compatibility.h>
#include <sigc++/bind.h>
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif //
#include "ja_nein_frage_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/box.h>
#ifndef ENABLE_NLS
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif


ja_nein_frage_glade::ja_nein_frage_glade(
)
{  ja_nein_frage = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Button *button28 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-yes")));
   Gtk::Button *button30 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-no")));
   label_text = Gtk::manage(new class Gtk::Label(_("Sind Sie sicher ?")));
   button28->set_flags(Gtk::CAN_FOCUS);
   button28->set_flags(Gtk::CAN_DEFAULT);
   button28->set_relief(Gtk::RELIEF_NORMAL);
   button30->set_flags(Gtk::CAN_FOCUS);
   button30->set_flags(Gtk::CAN_DEFAULT);
   button30->set_relief(Gtk::RELIEF_NORMAL);
   ja_nein_frage->get_action_area()->property_layout_style().set_value(Gtk::BUTTONBOX_END);
   label_text->set_alignment(0.5,0.5);
   label_text->set_padding(0,0);
   label_text->set_justify(Gtk::JUSTIFY_CENTER);
   label_text->set_line_wrap(false);
   label_text->set_use_markup(false);
   label_text->set_selectable(false);
   ja_nein_frage->get_vbox()->set_homogeneous(false);
   ja_nein_frage->get_vbox()->set_spacing(8);
   ja_nein_frage->get_vbox()->pack_start(*label_text, Gtk::PACK_SHRINK, 0);
   ja_nein_frage->set_title("");
   ja_nein_frage->set_modal(true);
   ja_nein_frage->property_window_position().set_value(Gtk::WIN_POS_NONE);
   ja_nein_frage->set_resizable(true);
   ja_nein_frage->property_destroy_with_parent().set_value(false);
   ja_nein_frage->set_has_separator(true);
   ja_nein_frage->add_action_widget(*button28, -8);
   ja_nein_frage->add_action_widget(*button30, -9);
   button28->show();
   button30->show();
   label_text->show();
   ja_nein_frage->show();
}

ja_nein_frage_glade::~ja_nein_frage_glade()
{  delete gmm_data;
}
