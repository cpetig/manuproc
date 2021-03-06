// generated 2006/8/14 17:36:02 CEST by christof@vesta.petig-baender.de
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --noaccelerators Komponenten.glade
// for gtk 2.10.1 and gtkmm 2.9.10
//
// Please modify the corresponding derived classes in ././KundenBox.cc


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
#include "KundenBox_glade.hh"
#ifndef ENABLE_NLS
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif


KundenBox_glade::KundenBox_glade(
) : Gtk::Table(2, 2, false)
{  
   
   Gtk::Table *KundenBox = this;
   label_kdnr = Gtk::manage(new class Gtk::Label(_("Kundennr")));
   label_nam = Gtk::manage(new class Gtk::Label(_("Name")));
   kundennr = new class SearchCombo();
   kundenname = new class SearchComboContent<Kunde::ID>();
   label_kdnr->set_justify(Gtk::JUSTIFY_CENTER);
   label_nam->set_justify(Gtk::JUSTIFY_CENTER);
   KundenBox->attach(*label_kdnr, 0, 1, 0, 1, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   KundenBox->attach(*label_nam, 1, 2, 0, 1, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   KundenBox->attach(*kundennr, 0, 1, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   KundenBox->attach(*kundenname, 1, 2, 1, 2, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   label_kdnr->show();
   label_nam->show();
   kundennr->show();
   kundenname->show();
   KundenBox->show();
   kundennr->signal_activate().connect(SigC::slot(*this, &KundenBox_glade::Kundennr_activate));
   kundennr->signal_search().connect(SigC::slot(*this, &KundenBox_glade::Kundennr_search), false);
   kundenname->signal_activate().connect(SigC::slot(*this, &KundenBox_glade::Name_activate));
   kundenname->signal_search().connect(SigC::slot(*this, &KundenBox_glade::Name_search), false);
}

KundenBox_glade::~KundenBox_glade()
{  delete kundennr;
   delete kundenname;
}
