// generated 2001/4/26 17:26:00 CEST by christof@puck.(none)
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/auftrag_bearbeiten.hh and./src/auftrag_bearbeiten.cc

#ifndef _AUFTRAG_BEARBEITEN_GLADE_HH
#  define _AUFTRAG_BEARBEITEN_GLADE_HH

#include <gtk--/window.h>
#include <libgnomeui/gtkpixmapmenuitem.h>
#include "SearchComboContent.hh"
#include <gtk--/optionmenu.h>
#include <gtk--/entry.h>
#include "Datewin.hh"
#include <gtk--/spinbutton.h>
#include <gtk--/button.h>
#include "KundenBox.hh"
#include <gtk--/notebook.h>
#include <gtk--/label.h>
#include "ArtikelBox.hh"
#include <gtk--/clist.h>

class auftrag_bearbeiten_glade : public Gtk::Window
{   
protected:
        
        class Gtk::Window *auftrag_bearbeiten;
        class SearchComboContent<int> *aufnr_scombo;
        class SearchComboContent<int> *youraufnr_scombo;
        class Gtk::OptionMenu *aufstat;
        struct aufstat
        {   enum enum_t 
	   {   unbest_tigt, offen, fertig, 
	   };
        };
        class Gtk::Entry *aufbemerkung_entry;
        class Datewin *aufdatum_datewin;
        class Gtk::SpinButton *jahrgang_spinbutton;
        class Gtk::SpinButton *aufrabatt_spinbutton;
        class Datewin *zahlziel_datewin;
        class Gtk::OptionMenu *zahlart;
        struct zahlart
        {   enum enum_t 
	   {   Rechnung, Abbuchung, 
	   };
        };
        class Gtk::OptionMenu *waehrung;
        struct waehrung
        {   enum enum_t 
	   {   DM, Euro, US_Dollar, 
	   };
        };
        class Gtk::Button *auftrag_ok;
        class Gtk::Button *auftrag_abbruch;
        class KundenBox *kundenbox;
        class Gtk::SpinButton *stkmtr_spinbutton;
        class Gtk::SpinButton *kw_spinbutton;
        class Gtk::SpinButton *jahr_spinbutton;
        class Datewin *liefdatum_datewin;
        class Gtk::Notebook *liefertermin;
        class Gtk::Button *showkal_button;
        class Gtk::OptionMenu *aufentrystat;
        struct aufentrystat
        {   enum enum_t 
	   {   unbest_tigt, offen, fertig, 
	   };
        };
        class Gtk::SpinButton *preis_spinbutton;
        class Gtk::Label *waehrunglabel;
        class Gtk::SpinButton *rabattentry_spinbutton;
        class Gtk::Button *aufentry_abbruch;
        class Gtk::Button *aufentry_ok;
        class Gtk::Label *mengeeinheit;
        class ArtikelBox *artikelbox;
        class Gtk::SpinButton *preismenge;
        class Gtk::Label *preiseinheit;
        class Gtk::CList *auftrag_clist;
        
        auftrag_bearbeiten_glade();
        
        ~auftrag_bearbeiten_glade();
};
#endif
