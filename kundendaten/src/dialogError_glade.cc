// generated 2006/5/31 10:21:47 CEST by jacek@jaceksdell.(none)
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/Monotone/kundendaten/kundendaten.glade
// for gtk 2.8.6 and gtkmm 2.8.0
//
// Please modify the corresponding derived classes in ./src/dialogError.cc


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
#include "dialogError_glade.hh"
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


dialogError_glade::dialogError_glade(
)
{  dialogError = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Button *button5 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-ok")));
   button5->set_flags(Gtk::CAN_FOCUS);
   button5->set_flags(Gtk::CAN_DEFAULT);
   button5->set_relief(Gtk::RELIEF_NORMAL);
   dialogError->get_action_area()->property_layout_style().set_value(Gtk::BUTTONBOX_DEFAULT_STYLE);
   dialogError->get_vbox()->set_homogeneous(false);
   dialogError->get_vbox()->set_spacing(8);
   dialogError->set_title(_("Information"));
   dialogError->set_modal(true);
   dialogError->property_window_position().set_value(Gtk::WIN_POS_NONE);
   dialogError->set_resizable(true);
   dialogError->property_destroy_with_parent().set_value(false);
   dialogError->set_has_separator(true);
   dialogError->add_action_widget(*button5, -5);
   button5->show();
   dialogError->show();
}

dialogError_glade::~dialogError_glade()
{  delete gmm_data;
}
