// generated 2006/5/22 16:46:05 CEST by christof@vesta.petig-baender.de
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 2.8.17 and gtkmm 2.8.5
//
// Please modify the corresponding derived classes in ./src/info_dialog.cc


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
#include "info_dialog_glade.hh"
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


info_dialog_glade::info_dialog_glade(
)
{  
   
   Gtk::Dialog *info_dialog = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Button *button40 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-close")));
   text = Gtk::manage(new class Gtk::Label(_("Bitte Schließen")));
   button40->set_flags(Gtk::CAN_FOCUS);
   button40->set_flags(Gtk::CAN_DEFAULT);
   button40->set_relief(Gtk::RELIEF_NORMAL);
   info_dialog->get_action_area()->property_layout_style().set_value(Gtk::BUTTONBOX_END);
   text->set_alignment(0.5,0.5);
   text->set_padding(0,0);
   text->set_justify(Gtk::JUSTIFY_CENTER);
   text->set_line_wrap(false);
   text->set_use_markup(false);
   text->set_selectable(false);
   info_dialog->get_vbox()->set_homogeneous(false);
   info_dialog->get_vbox()->set_spacing(8);
   info_dialog->get_vbox()->pack_start(*text, Gtk::PACK_SHRINK, 0);
   info_dialog->set_title("");
   info_dialog->set_modal(true);
   info_dialog->property_window_position().set_value(Gtk::WIN_POS_NONE);
   info_dialog->set_resizable(true);
   info_dialog->property_destroy_with_parent().set_value(false);
   info_dialog->set_has_separator(true);
   info_dialog->add_action_widget(*button40, -7);
   button40->show();
   text->show();
   info_dialog->show();
}

info_dialog_glade::~info_dialog_glade()
{  delete gmm_data;
}
