// generated 2006/6/23 16:28:38 CEST by christof@vesta.petig-baender.de
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 2.8.17 and gtkmm 2.8.5
//
// Please modify the corresponding derived classes in ./src/auftrag_bearbeiten.hh and./src/auftrag_bearbeiten.cc

#ifndef _AUFTRAG_BEARBEITEN_GLADE_HH
#  define _AUFTRAG_BEARBEITEN_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtkmm/accelgroup.h>

class GlademmData
{  
        
        Glib::RefPtr<Gtk::AccelGroup> accgrp;
public:
        
        GlademmData(Glib::RefPtr<Gtk::AccelGroup> ag) : accgrp(ag)
        {  
        }
        
        Glib::RefPtr<Gtk::AccelGroup>  getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtkmm/window.h>
#include <gtkmm/tooltips.h>
#include <gtkmm/checkmenuitem.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#include <gtkmm/checkbutton.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#include "WWaehrung.hh"
#include "datewin.hh"
#include <gtkmm/spinbutton.h>
#include "KundenBox2.hh"
#include <gtkmm/entry.h>
#include "SearchComboContent.hh"
#include "WAuftragStatus.hh"
#include "Optionmenu_AuftragLabel.hh"
#include "ZahlungsArtBox.hh"
#include <gtkmm/handlebox.h>
#include <gtkmm/label.h>
#include <gtkmm/table.h>
#include "WPreis.hh"
#include "ArtikelBox.hh"
#include "PreisBox.hh"
#include "SimpleTree.hh"
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/expander.h>
#else //
#endif //
#include <gtkmm/paned.h>
#include <gtkmm/box.h>

class auftrag_bearbeiten_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        Gtk::Tooltips _tooltips;
        class Gtk::Window * auftrag_bearbeiten;
        class Gtk::CheckMenuItem * masseneingabe1;
        class Gtk::CheckMenuItem * kombinierte_artikel;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * newauftrag_button;
#else //
        class Gtk::Button * newauftrag_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * button_drucken;
#else //
        class Gtk::Button * button_drucken;
#endif //
        class Gtk::CheckButton * checkbutton_ean_drucken;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
        class Gtk::Button * auftrag_ok;
        class Gtk::Button * auftrag_abbruch;
        class WWaehrung * bea_WWaehrung;
        class datewin * zahlziel_datewin;
        class Gtk::SpinButton * aufrabatt_spinbutton;
        class KundenBox2 * kundenbox;
        class Gtk::Entry * aufbemerkung_entry;
        class SearchComboContent<int> * youraufnr_scombo;
        class SearchComboContent<int> * aufnr_scombo;
        class WAuftragStatus * WAufStat;
        class datewin * aufdatum_datewin;
        class Optionmenu_AuftragLabel * auftrag_label;
        class Gtk::Entry * auftragswert;
        class ZahlungsArtBox * zahlart;
        class Gtk::SpinButton * stkmtr_spinbutton;
        class WAuftragStatus * WAufEntryStat;
        class Gtk::SpinButton * rabattentry_spinbutton;
        class Gtk::Button * lager_bestand;
        class Gtk::Label * lagerbest_label;
        class Gtk::Label * bestellt_label;
        class Gtk::Label * verfuegbar_label;
        class Gtk::Label * lieferant_offen;
        class Gtk::Button * offen_bei_lieferant;
        class Gtk::Table * table_vorraetige_menge;
        class Gtk::Label * mengeeinheit;
        class Gtk::Button * aufentry_abbruch;
        class Gtk::Button * aufentry_ok;
        class Gtk::Button * bestellplan;
        class WPreis * WPreis;
        class datewin * liefdatum_datewin;
        class ArtikelBox * artikelbox;
        class Gtk::CheckButton * preisautomatik;
        class PreisBox * preislisten;
        class Gtk::Table * table_preislisten;
        class Gtk::Table * table_auftragseintraege;
        class SimpleTree * auftrag_clist;
        class Gtk::ScrolledWindow * scrolledwindow_auftraege;
        class Gtk::TextView * notiz;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * notiz_save;
#else //
        class Gtk::Button * notiz_save;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::Expander * frame_notiz;
#else //
        class Gtk::HandleBox * frame_notiz;
#endif //
        class Gtk::VPaned * notiz_paned;
        class Gtk::VBox * aufeintrag_box;
        
        auftrag_bearbeiten_glade();
        
        ~auftrag_bearbeiten_glade();
private:
        virtual void on_backtomain_button_clicked() = 0;
        virtual void on_newauftrag_button_clicked() = 0;
        virtual void on_clear_all() = 0;
        virtual void on_auftrag_kopieren_activate() = 0;
        virtual void on_provisionierung_activate() = 0;
        virtual void on_splitten() = 0;
        virtual void on_ean_etiketten_activate() = 0;
        virtual void on_button_preview_clicked() = 0;
        virtual void on_button_drucken_clicked() = 0;
        virtual void on_checkbutton_ean_drucken_clicked() = 0;
        virtual void on_rueckstand_clicked() = 0;
        virtual void on_auftrag_ok_clicked() = 0;
        virtual void on_auftrag_abbruch_clicked() = 0;
        virtual void waehrung_geaendert() = 0;
        virtual void on_zahlziel_activate() = 0;
        virtual bool on_aufrabatt_spinbutton_focus_out_event(GdkEventFocus *ev) = 0;
        virtual void on_aufrabatt_spinbutton_activate() = 0;
        virtual void on_kunden_activate() = 0;
        virtual void on_aufbemerkung_activate() = 0;
        virtual void on_youraufnrscombo_activate() = 0;
        virtual void on_youraufnrscombo_search(gboolean *cont,GtkSCContext context) = 0;
        virtual void on_aufnrscombo_activate() = 0;
        virtual void on_aufnrscombo_search(gboolean *cont,GtkSCContext context) = 0;
        virtual void auftragstatus_geaendert() = 0;
        virtual void on_datum_activate() = 0;
        virtual void auftraglabel_geaendert() = 0;
        virtual void on_zahlart_activate() = 0;
        virtual void on_stkmtr_spinbutton_activate() = 0;
        virtual void on_aufentrystat_optionmenu_clicked() = 0;
        virtual void on_rabattentry_spinbutton_activate() = 0;
        virtual void on_offen_bei_lieferant_clicked() = 0;
        virtual void on_aufentry_abbruch_clicked() = 0;
        virtual void on_aufentry_ok_clicked() = 0;
        virtual void on_bestellplan_clicked() = 0;
        virtual void on_activate_wpreis() = 0;
        virtual void on_preis_changed() = 0;
        virtual void on_lieferdatum_activate() = 0;
        virtual void onSelArtikel() = 0;
        virtual void on_preisautomatik_clicked() = 0;
        virtual void preisliste_reset() = 0;
        virtual void on_auftrag_preislisten_activate() = 0;
        virtual void on_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_unselect() = 0;
        virtual void on_notiz_changed() = 0;
        virtual void on_notiz_save_clicked() = 0;
};
#endif
