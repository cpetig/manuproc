/*  pps: ManuProC's ProductionPlanningSystem
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
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

// generated 2001/4/19 10:29:39 CEST by christof@puck.(none)
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
public:
        
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
protected:
        class Gtk::OptionMenu *waehrung;
        struct waehrung
        {   enum enum_t 
	   {   DM, Euro, US_Dollar, 
	   };
        };
        class Gtk::Button *auftrag_ok;
        class Gtk::Button *auftrag_abbruch;
public:
        class KundenBox *kundenbox;
        class Gtk::SpinButton *stkmtr_spinbutton;
        class Gtk::SpinButton *kw_spinbutton;
        class Gtk::SpinButton *jahr_spinbutton;
        class Datewin *liefdatum_datewin;
protected:
        class Gtk::Notebook *liefertermin;
public:
        class Gtk::Button *showkal_button;
        class Gtk::OptionMenu *aufentrystat;
        struct aufentrystat
        {   enum enum_t 
	   {   unbest_tigt, offen, fertig, 
	   };
        };
protected:
        class Gtk::SpinButton *preis_spinbutton;
        class Gtk::Label *waehrunglabel;
public:
        class Gtk::SpinButton *rabattentry_spinbutton;
protected:
        class Gtk::Button *aufentry_abbruch;
        class Gtk::Button *aufentry_ok;
        class Gtk::Label *mengeeinheit;
public:
        class ArtikelBox *artikelbox;
protected:
        class Gtk::SpinButton *preismenge;
        class Gtk::Label *preiseinheit;
public:
        class Gtk::CList *auftrag_clist;
protected:
        
        auftrag_bearbeiten_glade();
        
        ~auftrag_bearbeiten_glade();
};
#define GMM_AUFTRAG_BEARBEITEN (glademm_get<auftrag_bearbeiten >("auftrag_bearbeiten"))
#define GMM_AUFNR_SCOMBO (glademm_get<SearchComboContent<int> >("aufnr_scombo"))
#define GMM_YOURAUFNR_SCOMBO (glademm_get<SearchComboContent<int> >("youraufnr_scombo"))
#define GMM_AUFSTAT (glademm_get<Gtk::OptionMenu >("aufstat"))
#define GMM_AUFBEMERKUNG_ENTRY (glademm_get<Gtk::Entry >("aufbemerkung_entry"))
#define GMM_AUFDATUM_DATEWIN (glademm_get<Datewin >("aufdatum_datewin"))
#define GMM_JAHRGANG_SPINBUTTON (glademm_get<Gtk::SpinButton >("jahrgang spinbutton"))
#define GMM_AUFRABATT_SPINBUTTON (glademm_get<Gtk::SpinButton >("aufrabatt_spinbutton"))
#define GMM_ZAHLZIEL_DATEWIN (glademm_get<Datewin >("zahlziel_datewin"))
#define GMM_ZAHLART (glademm_get<Gtk::OptionMenu >("zahlart"))
#define GMM_KUNDENBOX (glademm_get<KundenBox >("kundenbox"))
#define GMM_STKMTR_SPINBUTTON (glademm_get<Gtk::SpinButton >("stkmtr_spinbutton"))
#define GMM_KW_SPINBUTTON (glademm_get<Gtk::SpinButton >("kw_spinbutton"))
#define GMM_JAHR_SPINBUTTON (glademm_get<Gtk::SpinButton >("jahr_spinbutton"))
#define GMM_LIEFDATUM_DATEWIN (glademm_get<Datewin >("liefdatum_datewin"))
#define GMM_AUFENTRYSTAT (glademm_get<Gtk::OptionMenu >("aufentrystat"))
#define GMM_RABATTENTRY_SPINBUTTON (glademm_get<Gtk::SpinButton >("rabattentry_spinbutton"))
#define GMM_ARTIKELBOX (glademm_get<ArtikelBox >("artikelbox"))
#define GMM_AUFTRAG_CLIST (glademm_get<Gtk::CList >("auftrag_clist"))
#endif
