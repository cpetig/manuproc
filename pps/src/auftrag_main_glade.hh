// generated 2005/9/12 11:16:20 CEST by jacek@woody.mabella.de
// using glademm V2.10.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.8
//
// Please modify the corresponding derived classes in ./src/auftrag_main.hh and./src/auftrag_main.cc

#ifndef _AUFTRAG_MAIN_GLADE_HH
#  define _AUFTRAG_MAIN_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/tooltips.h>
#include <libgnomeui/gtkpixmapmenuitem.h>
#include <gtk--/menuitem.h>
#include <gtk--/menu.h>
#include <gtk--/radiomenuitem.h>
#include <gtk--/checkmenuitem.h>
#include <gtk--/menubar.h>
#include <gtk--/button.h>
#include <gtk--/togglebutton.h>
#include "Optionmenu_Instanz.hh"
#include "Optionmenu_Warengruppe.hh"
#include "SimpleTree.hh"
#include <gtk--/scrolledwindow.h>
#include <gtk--/frame.h>
#include <gtk--/viewport.h>
#include <gtk--/paned.h>
#include "Datewin.hh"
#include "SearchComboContent.hh"
#include <gtk--/spinbutton.h>
#include "KundenBox2.hh"
#include <gtk--/label.h>
#include <gtk--/table.h>

class auftrag_main_glade : public Gtk::Window
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Window * auftrag_main;
        class Gtk::MenuBar * main_menubar;
        class Gtk::MenuItem * beenden;
        class Gtk::MenuItem * erfassen;
        class Gtk::MenuItem * neuladen;
        class Gtk::MenuItem * main_drucken;
        class Gtk::MenuItem * trennlinie2;
        class Gtk::MenuItem * abschreiben;
        class Gtk::RadioMenuItem * main_kndbez;
        class Gtk::RadioMenuItem * main_intbez;
        class Gtk::MenuItem * trennlinie5;
        class Gtk::RadioMenuItem * kundenauftragsnummer;
        class Gtk::RadioMenuItem * interne_auftragsnummer;
        class Gtk::MenuItem * trennlinie3;
        class Gtk::RadioMenuItem * kalenderwoche;
        class Gtk::RadioMenuItem * datum;
        class Gtk::MenuItem * trennlinie4;
        class Gtk::RadioMenuItem * kunden_name1;
        class Gtk::RadioMenuItem * kunden_ort;
        class Gtk::RadioMenuItem * kunden_nr;
        class Gtk::MenuItem * trennlinie6;
        class Gtk::RadioMenuItem * materialbedarf_sortiert_nach_artikel;
        class Gtk::RadioMenuItem * materialbedarf_sortiert_nach_menge;
        class Gtk::MenuItem * trennlinie8;
        class Gtk::RadioMenuItem * auftraege_ohne_kunde;
        class Gtk::RadioMenuItem * auftraege_mit_kunde;
        class Gtk::CheckMenuItem * preload_orders;
        class Gtk::MenuItem * trennlinie10;
        class Gtk::RadioMenuItem * unbestaetigte_auftraege;
        class Gtk::RadioMenuItem * offene_auftraege;
        class Gtk::RadioMenuItem * stornierte_auftraege;
        class Gtk::RadioMenuItem * geschlossene_auftraege;
        class Gtk::MenuItem * trennlinie7;
        class Gtk::RadioMenuItem * ungeplante_menge_menu;
        class Gtk::RadioMenuItem * plan_menge_menu;
        class Gtk::RadioMenuItem * dispo_menge_menu;
        class Gtk::RadioMenuItem * alle_lagermengen;
        class Gtk::MenuItem * bestellplanung;
        class Gtk::Button * endemain_button;
        class Gtk::Button * mainprint_button;
        class Gtk::Button * mainreload_button;
        class Gtk::Button * erfassen_button;
        class Gtk::Button * lieferschein_button;
        class Gtk::Button * rechnung_button;
        class Gtk::ToggleButton * togglebutton_bestellen;
        class Gtk::ToggleButton * togglebutton_material;
        class Gtk::ToggleButton * togglebutton_auftraege;
        class Gtk::Button * button_auftrag_erledigt;
        class Gtk::Button * button_Kunden_erledigt;
        class Gtk::Button * button_faerben;
        class Optionmenu_Instanz * akt_instanz;
        class Optionmenu_Warengruppe * offen_warengruppe;
        class SimpleTree * maintree_s;
        class Gtk::ScrolledWindow * scrolledwindow_maintree_s;
        class Gtk::Frame * frame_offene_mengen;
        class Gtk::Viewport * viewport_materialbedarf;
        class Gtk::Frame * frame_materialbedarf;
        class Gtk::VPaned * vpaned_an_mat;
        class Datewin * Datum_instanz;
        class Gtk::Button * button_instanz_get_selection;
        class Gtk::Button * button_neue_anr;
        class SearchComboContent<int> * searchcombo_auftragid;
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
        virtual void on_unbest_auftraege_activate() = 0;
        virtual void on_offene_auftraege_activate() = 0;
        virtual void on_storno_auftraege_activate() = 0;
        virtual void on_closed_auftraege_activate() = 0;
        virtual void auftrags_id_aenderung() = 0;
        virtual void on_bestellplanung_activate() = 0;
        virtual gint on_mainprint_button_clicked(GdkEventButton *ev) = 0;
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
        virtual void on_unselect_row(gint row, gint column, GdkEvent *event) = 0;
        virtual void on_node_selected(const TreeRow &node) = 0;
        virtual void on_leaf_unselected(cH_RowDataBase leaf) = 0;
        virtual void on_button_instanz_get_selection_clicked() = 0;
        virtual gint on_button_instanz_print_clicked(GdkEventButton *ev) = 0;
        virtual void on_button_neue_anr_clicked() = 0;
        virtual void on_searchcombo_auftragid_activate() = 0;
        virtual void on_searchcombo_auftragid_search(gboolean *cont,GtkSCContext context) = 0;
        virtual void on_OptMenu_Instanz_Bestellen_activate() = 0;
        virtual void on_kunden_lieferant_activate() = 0;
        virtual void tree_neuer_auftrag_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual gint on_delete_event(GdkEventAny *ev) = 0;
};
#endif
