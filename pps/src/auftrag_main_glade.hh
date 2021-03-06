// generated 2006/6/23 11:01:34 CEST by jacek@jaceksdell.(none)
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/Monotone/pps/auftrag.glade
// for gtk 2.8.6 and gtkmm 2.8.0
//
// Please modify the corresponding derived classes in ./src/auftrag_main.hh and./src/auftrag_main.cc

#ifndef _AUFTRAG_MAIN_GLADE_HH
#  define _AUFTRAG_MAIN_GLADE_HH


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
#include <gtkmm/radiomenuitem.h>
#include <gtkmm/checkmenuitem.h>
#include <gtkmm/menubar.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/toggletoolbutton.h>
#else //
#include <gtkmm/togglebutton.h>
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#include "Optionmenu_Instanz.hh"
#include "Optionmenu_Warengruppe.hh"
#include "SimpleTree.hh"
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/frame.h>
#include <gtkmm/viewport.h>
#include <gtkmm/paned.h>
#include "datewin.hh"
#include "OrderBox.hh"
#include <gtkmm/spinbutton.h>
#include "KundenBox2.hh"
#include <gtkmm/label.h>
#include <gtkmm/table.h>

class auftrag_main_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        Gtk::Tooltips _tooltips;
        class Gtk::Window * auftrag_main;
        class Gtk::RadioMenuItem * main_kndbez;
        class Gtk::RadioMenuItem * main_intbez;
        class Gtk::RadioMenuItem * kundenauftragsnummer;
        class Gtk::RadioMenuItem * interne_auftragsnummer;
        class Gtk::RadioMenuItem * kalenderwoche;
        class Gtk::RadioMenuItem * datum;
        class Gtk::RadioMenuItem * kunden_name1;
        class Gtk::RadioMenuItem * kunden_ort;
        class Gtk::RadioMenuItem * kunden_nr;
        class Gtk::RadioMenuItem * materialbedarf_sortiert_nach_artikel;
        class Gtk::RadioMenuItem * materialbedarf_sortiert_nach_menge;
        class Gtk::RadioMenuItem * auftraege_ohne_kunde;
        class Gtk::RadioMenuItem * auftraege_mit_kunde;
        class Gtk::CheckMenuItem * preload_orders;
        class Gtk::RadioMenuItem * alle_auftraege;
        class Gtk::RadioMenuItem * unbestaetigte_auftraege;
        class Gtk::RadioMenuItem * offene_auftraege;
        class Gtk::RadioMenuItem * stornierte_auftraege;
        class Gtk::RadioMenuItem * geschlossene_auftraege;
        class Gtk::RadioMenuItem * ungeplante_menge_menu;
        class Gtk::RadioMenuItem * plan_menge_menu;
        class Gtk::RadioMenuItem * dispo_menge_menu;
        class Gtk::RadioMenuItem * alle_lagermengen;
        class Gtk::MenuBar * main_menubar;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * endemain_button;
#else //
        class Gtk::Button * endemain_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * mainprint_button;
#else //
        class Gtk::Button * mainprint_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * mainreload_button;
#else //
        class Gtk::Button * mainreload_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * erfassen_button;
#else //
        class Gtk::Button * erfassen_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * lieferschein_button;
#else //
        class Gtk::Button * lieferschein_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * rechnung_button;
#else //
        class Gtk::Button * rechnung_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToggleToolButton * togglebutton_bestellen;
#else //
        class Gtk::ToggleButton * togglebutton_bestellen;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToggleToolButton * togglebutton_material;
#else //
        class Gtk::ToggleButton * togglebutton_material;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToggleToolButton * togglebutton_auftraege;
#else //
        class Gtk::ToggleButton * togglebutton_auftraege;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * button_auftrag_erledigt;
#else //
        class Gtk::Button * button_auftrag_erledigt;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * button_Kunden_erledigt;
#else //
        class Gtk::Button * button_Kunden_erledigt;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * button_faerben;
#else //
        class Gtk::Button * button_faerben;
#endif //
        class Optionmenu_Instanz * akt_instanz;
        class Optionmenu_Warengruppe * offen_warengruppe;
        class SimpleTree * maintree_s;
        class Gtk::ScrolledWindow * scrolledwindow_maintree_s;
        class Gtk::Frame * frame_offene_mengen;
        class Gtk::Viewport * viewport_materialbedarf;
        class Gtk::Frame * frame_materialbedarf;
        class Gtk::VPaned * vpaned_an_mat;
        class datewin * Datum_instanz;
        class Gtk::Button * button_instanz_get_selection;
        class Gtk::Button * button_neue_anr;
        class OrderBox * searchcombo_auftragid;
        class Gtk::SpinButton * spinbutton_geplante_menge;
        class Gtk::Frame * frame_mengen_eingabe;
        class Optionmenu_Instanz * OptMen_Instanz_Bestellen;
        class KundenBox2 * kunden_lieferant;
        class Gtk::Label * info_label_instanzen;
        class Gtk::Table * table_instanzen;
        class SimpleTree * tree_neuer_auftrag;
        class Gtk::Frame * frame_instanzen;
        
        auftrag_main_glade();
        
        ~auftrag_main_glade();
private:
        virtual void on_beenden_activate() = 0;
        virtual void on_erfassen_activate() = 0;
        virtual void on_neuladen_activate() = 0;
        virtual void on_main_drucken_activate() = 0;
        virtual void on_lieferscheine_activate() = 0;
        virtual void on_main_bezeichnung_activate() = 0;
        virtual void on_kunden_anr_activate() = 0;
        virtual void on_zeitdarstellung_activate() = 0;
        virtual void on_kundendarstellung_activate() = 0;
        virtual void on_materialbedarf_sortiert() = 0;
        virtual void on_auftraege_kunde_activate() = 0;
        virtual void on_preload_orders_activate() = 0;
        virtual void on_alle_auftraege_activate() = 0;
        virtual void on_unbest_auftraege_activate() = 0;
        virtual void on_offene_auftraege_activate() = 0;
        virtual void on_storno_auftraege_activate() = 0;
        virtual void on_closed_auftraege_activate() = 0;
        virtual void auftrags_id_aenderung() = 0;
        virtual void on_bestellplanung_activate() = 0;
        virtual void on_mainprint_button_clicked() = 0;
        virtual void on_rechnung_activate() = 0;
        virtual void on_togglebutton_bestellen_toggled() = 0;
        virtual void on_togglebutton_material_toggled() = 0;
        virtual void on_togglebutton_auftraege_toggled() = 0;
        virtual void on_button_artikeleingabe_clicked() = 0;
        virtual void on_button_auftrag_erledigt_clicked() = 0;
        virtual void on_button_Kunden_erledigt_clicked() = 0;
        virtual void on_button_faerben_clicked() = 0;
        virtual void on_offwarengrp_activate() = 0;
        virtual void on_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_unselect_row() = 0;
        virtual void on_node_selected(Handle<const TreeRow> node) = 0;
        virtual void on_leaf_unselected() = 0;
        virtual void on_button_instanz_get_selection_clicked() = 0;
        virtual void on_button_instanz_print_clicked() = 0;
        virtual void on_button_neue_anr_clicked() = 0;
        virtual void on_searchcombo_auftragid_activate() = 0;
        virtual void on_OptMenu_Instanz_Bestellen_activate() = 0;
        virtual void on_kunden_lieferant_activate() = 0;
        virtual void tree_neuer_auftrag_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual bool on_delete_event(GdkEventAny *ev) = 0;
};
#endif
