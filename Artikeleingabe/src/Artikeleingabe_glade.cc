// generated 2004/11/29 17:49:53 CET by christof@felix.petig.de
// using glademm V2.6.0_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /2nddisk/localhome/christof/g++3.3/Artikeleingabe/artikeleingabe.glade
// for gtk 2.4.13 and gtkmm 2.4.5
//
// Please modify the corresponding derived classes in ./src/Artikeleingabe.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <sigc++/compatibility.h>
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif //
#include "Artikeleingabe_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/image.h>
#include <gtkmm/stockid.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#include <gtkmm/toolbar.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/frame.h>
#include <gtkmm/table.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/separator.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <gtkmm/separatortoolitem.h>
#endif //
#include <gtkmm/scrolledwindow.h>
#include "Artikeleingabe.hh"

Artikeleingabe_glade::Artikeleingabe_glade(
) : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *Artikeleingabe = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Image *button_close_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-quit"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   Gtk::ToolButton *button_close = Gtk::manage(new class Gtk::ToolButton(*button_close_img, "Beenden"));
#endif //
   Gtk::Image *button_drucken_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-print"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   Gtk::ToolButton *button_drucken = Gtk::manage(new class Gtk::ToolButton(*button_drucken_img, "Drucken"));
#endif //
   Gtk::Toolbar *toolbar1 = Gtk::manage(new class Gtk::Toolbar());
   label_warnung = Gtk::manage(new class Gtk::Label(""));
   
   Gtk::HBox *hbox3 = Gtk::manage(new class Gtk::HBox(false, 0));
   artikelbox = new class ArtikelBox(1);
   artikelbox_neu = new class ArtikelBox(1);
   no_instanz = Gtk::manage(new class Gtk::CheckButton("keine Instanz"));
   was_tun = new class WasTun();
   standard_instanz = new class Optionmenu_Instanz(Optionmenu_Instanz::allesAnzeigen);
   
   Gtk::Label *label1 = Gtk::manage(new class Gtk::Label("Wird bestellt bei"));
   Gtk::Frame *frame1 = Gtk::manage(new class Gtk::Frame());
   standard_einheit = new class Optionmenu_Einheit();
   
   Gtk::Label *label2 = Gtk::manage(new class Gtk::Label("Einheit"));
   Gtk::Frame *frame2 = Gtk::manage(new class Gtk::Frame());
   Gtk::Table *table6 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Label *label13 = Gtk::manage(new class Gtk::Label("Neu"));
   OM_Einheit = new class Optionmenu_Einheit();
   
   Gtk::Label *label18 = Gtk::manage(new class Gtk::Label("Einheit"));
   mindbest_check = Gtk::manage(new class Gtk::CheckButton("prüfen"));
   
   Gtk::Adjustment *mindbestand_adj = Gtk::manage(new class Gtk::Adjustment(0, 0, 10000, 1, 10, 10));
   mindbestand = Gtk::manage(new class Gtk::SpinButton(*mindbestand_adj, 1, 0));
   
   Gtk::HBox *hbox4 = Gtk::manage(new class Gtk::HBox(false, 0));
   Gtk::Label *label19 = Gtk::manage(new class Gtk::Label("Mindestbestand"));
   Gtk::Frame *frame6 = Gtk::manage(new class Gtk::Frame());
   eingabebox = new class EingabeBox();
   pixmap_edit = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-cancel"), Gtk::IconSize(4)));
   
   Gtk::HBox *hbox2 = Gtk::manage(new class Gtk::HBox(false, 0));
   Gtk::Label *label20 = Gtk::manage(new class Gtk::Label("Bezeichnung ändern"));
   Gtk::Frame *frame4 = Gtk::manage(new class Gtk::Frame());
   alias_warengruppe = new class Optionmenu_Warengruppe(1);
   alias_schema = new class KundenBox2();
   alias_eingabe = new class EingabeBox();
   alias_pixmap = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-cancel"), Gtk::IconSize(4)));
   
   Gtk::HBox *hbox1 = Gtk::manage(new class Gtk::HBox(false, 2));
   Gtk::Label *label21 = Gtk::manage(new class Gtk::Label("gleicher Artikel in anderem Bezeichnungsschema"));
   Gtk::Frame *frame5 = Gtk::manage(new class Gtk::Frame());
   Gtk::Label *label9 = Gtk::manage(new class Gtk::Label("Wird bestellt bei"));
   Artikel_Bestellen_bei = new class Optionmenu_Instanz(Optionmenu_Instanz::allesAnzeigen);
   change_no_instanz = Gtk::manage(new class Gtk::CheckButton("keine Instanz"));
   show_in_prlist = Gtk::manage(new class Gtk::CheckButton("in den Preislisten anzeigen"));
   
   Gtk::Table *table7 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Label *label14 = Gtk::manage(new class Gtk::Label("Ändern"));
   Gtk::Label *label4 = Gtk::manage(new class Gtk::Label("entsteht aus  "));
   Gtk::VSeparator *vseparator3 = Gtk::manage(new class Gtk::VSeparator());
   Gtk::Image *button_artikel_delete_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-delete"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_artikel_delete = Gtk::manage(new class Gtk::ToolButton(*button_artikel_delete_img, "TEXT\n"
		""));
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   
   Gtk::SeparatorToolItem *separatortoolitem1 = Gtk::manage(new class Gtk::SeparatorToolItem());
#endif //
   Gtk::Image *button_artikel_wechsel_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-go-forward"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_artikel_wechsel = Gtk::manage(new class Gtk::ToolButton(*button_artikel_wechsel_img, "Artikel\n"
		"wechsel"));
#endif //
   toolbar_loeschen = Gtk::manage(new class Gtk::Toolbar());
   artikelboxb = new class Artikel_Bestellen();
   table_artikelherkunft = Gtk::manage(new class Gtk::Table(2, 2, false));
   tree = new class SimpleTree(10);
   
   Gtk::ScrolledWindow *scrolledwindow1 = Gtk::manage(new class Gtk::ScrolledWindow());
   Gtk::VBox *vbox3 = Gtk::manage(new class Gtk::VBox(false, 0));
   Gtk::Label *label15 = Gtk::manage(new class Gtk::Label("Zusammensetzung"));
   Gtk::Label *label3 = Gtk::manage(new class Gtk::Label("Zeige Artikel der Instanz"));
   checkbutton_offene_auftraege = Gtk::manage(new class Gtk::CheckButton("Nur Artikel in offenen\n"
		"Aufträgen anzeigen"));
   optionmenu_instanz = new class Optionmenu_Instanz(Optionmenu_Instanz::allesAnzeigen);
   progressbar = Gtk::manage(new class Gtk::ProgressBar());
   
   Gtk::Table *table9 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Label *label16 = Gtk::manage(new class Gtk::Label("Übersicht"));
   Gtk::Image *button_verschmelzen_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-convert"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   Gtk::ToolButton *button_verschmelzen = Gtk::manage(new class Gtk::ToolButton(*button_verschmelzen_img, "Verschmelzen"));
#endif //
   Gtk::Toolbar *toolbar2 = Gtk::manage(new class Gtk::Toolbar());
   artbox_verschmelzen = new class ArtikelBox(1);
   
   Gtk::Label *label11 = Gtk::manage(new class Gtk::Label("(Dieser Artikel wird in den oben angegebenen Umbenannt)"));
   table_verschmelzen = Gtk::manage(new class Gtk::Table(2, 2, false));
   
   Gtk::Table *table3 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Label *label17 = Gtk::manage(new class Gtk::Label("Art. umbenenn.?"));
   table_preis *table_preis = Gtk::manage(new class table_preis(gmm_data));
   Gtk::Label *label22 = Gtk::manage(new class Gtk::Label("Preis"));
   top_notebook = Gtk::manage(new class Gtk::Notebook());
   
   Gtk::VBox *vbox2 = Gtk::manage(new class Gtk::VBox(false, 0));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar1->append(*button_close);
#else //
   
   
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Beenden", *button_close_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *button_close = static_cast<Gtk::Button *>(toolbar1->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar1->append(*button_drucken);
#else //
   
   
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *button_drucken_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *button_drucken = static_cast<Gtk::Button *>(toolbar1->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar_loeschen->append(*button_artikel_delete);
#else //
   
   
   toolbar_loeschen->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("TEXT\n"
		"", *button_artikel_delete_img, Gtk::Toolbar_Helpers::Callback0()));
   button_artikel_delete = static_cast<Gtk::Button *>(toolbar_loeschen->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar_loeschen->append(*separatortoolitem1);
#else //
   toolbar_loeschen->tools().push_back(Gtk::Toolbar_Helpers::Space());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar_loeschen->append(*button_artikel_wechsel);
#else //
   
   
   toolbar_loeschen->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Artikel\n"
		"wechsel", *button_artikel_wechsel_img, Gtk::Toolbar_Helpers::Callback0()));
   button_artikel_wechsel = static_cast<Gtk::Button *>(toolbar_loeschen->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar2->append(*button_verschmelzen);
#else //
   
   
   toolbar2->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Verschmelzen", *button_verschmelzen_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *button_verschmelzen = static_cast<Gtk::Button *>(toolbar2->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_close->set_visible_horizontal(true);
   button_close->set_visible_vertical(true);
   button_close->set_is_important(false);
#endif //
   button_close_img->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_drucken->set_visible_horizontal(true);
   button_drucken->set_visible_vertical(true);
   button_drucken->set_is_important(false);
#endif //
   button_drucken_img->show();
   toolbar1->set_tooltips(true);
   toolbar1->set_toolbar_style(Gtk::TOOLBAR_ICONS);
   toolbar1->set_orientation(Gtk::ORIENTATION_HORIZONTAL);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar1->set_show_arrow(false);
#endif //
   label_warnung->set_alignment(0,0.5);
   label_warnung->set_padding(0,0);
   label_warnung->set_justify(Gtk::JUSTIFY_CENTER);
   label_warnung->set_line_wrap(false);
   label_warnung->set_use_markup(false);
   label_warnung->set_selectable(false);
   hbox3->pack_start(*toolbar1, Gtk::PACK_SHRINK, 0);
   hbox3->pack_start(*label_warnung, Gtk::PACK_SHRINK, 0);
   artikelbox->set_sensitive(false);
   no_instanz->set_flags(Gtk::CAN_FOCUS);
   no_instanz->set_relief(Gtk::RELIEF_NORMAL);
   no_instanz->set_mode(true);
   no_instanz->set_active(true);
   standard_instanz->set_sensitive(false);
   label1->set_alignment(0.5,0.5);
   label1->set_padding(0,0);
   label1->set_justify(Gtk::JUSTIFY_LEFT);
   label1->set_line_wrap(false);
   label1->set_use_markup(false);
   label1->set_selectable(false);
   frame1->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame1->set_label_align(0,0.5);
   frame1->add(*standard_instanz);
   frame1->set_label_widget(*label1);
   label2->set_alignment(0.5,0.5);
   label2->set_padding(0,0);
   label2->set_justify(Gtk::JUSTIFY_LEFT);
   label2->set_line_wrap(false);
   label2->set_use_markup(false);
   label2->set_selectable(false);
   frame2->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame2->set_label_align(0,0.5);
   frame2->add(*standard_einheit);
   frame2->set_label_widget(*label2);
   table6->set_row_spacings(0);
   table6->set_col_spacings(0);
   table6->attach(*artikelbox_neu, 0, 2, 3, 4, Gtk::FILL, Gtk::FILL, 0, 0);
   table6->attach(*no_instanz, 0, 1, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table6->attach(*was_tun, 0, 2, 0, 1, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK|Gtk::FILL, 0, 0);
   table6->attach(*frame1, 0, 1, 2, 3, Gtk::FILL, Gtk::FILL, 0, 0);
   table6->attach(*frame2, 1, 2, 2, 3, Gtk::FILL, Gtk::FILL, 0, 0);
   label13->set_alignment(0.5,0.5);
   label13->set_padding(0,0);
   label13->set_justify(Gtk::JUSTIFY_CENTER);
   label13->set_line_wrap(false);
   label13->set_use_markup(false);
   label13->set_selectable(false);
   label18->set_alignment(0,0.5);
   label18->set_padding(0,0);
   label18->set_justify(Gtk::JUSTIFY_CENTER);
   label18->set_line_wrap(false);
   label18->set_use_markup(false);
   label18->set_selectable(false);
   mindbest_check->set_flags(Gtk::CAN_FOCUS);
   mindbest_check->set_relief(Gtk::RELIEF_NORMAL);
   mindbest_check->set_mode(true);
   mindbest_check->set_active(true);
   mindbestand->set_flags(Gtk::CAN_FOCUS);
   mindbestand->set_update_policy(Gtk::UPDATE_ALWAYS);
   mindbestand->set_numeric(true);
   mindbestand->set_digits(0);
   mindbestand->set_wrap(false);
   hbox4->pack_start(*mindbest_check, Gtk::PACK_SHRINK, 0);
   hbox4->pack_start(*mindbestand, Gtk::PACK_SHRINK, 0);
   label19->set_alignment(0.5,0.5);
   label19->set_padding(0,0);
   label19->set_justify(Gtk::JUSTIFY_LEFT);
   label19->set_line_wrap(false);
   label19->set_use_markup(false);
   label19->set_selectable(false);
   frame6->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame6->set_label_align(0,0.5);
   frame6->add(*hbox4);
   frame6->set_label_widget(*label19);
   pixmap_edit->set_alignment(0.5,0.5);
   pixmap_edit->set_padding(0,0);
   hbox2->pack_start(*eingabebox);
   hbox2->pack_start(*pixmap_edit, Gtk::PACK_SHRINK, 0);
   label20->set_alignment(0.5,0.5);
   label20->set_padding(0,0);
   label20->set_justify(Gtk::JUSTIFY_LEFT);
   label20->set_line_wrap(false);
   label20->set_use_markup(false);
   label20->set_selectable(false);
   frame4->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame4->set_label_align(0,0.5);
   frame4->add(*hbox2);
   frame4->set_label_widget(*label20);
   alias_pixmap->set_alignment(0.5,0.5);
   alias_pixmap->set_padding(0,0);
   hbox1->pack_start(*alias_warengruppe, Gtk::PACK_EXPAND_PADDING, 0);
   hbox1->pack_start(*alias_schema, Gtk::PACK_EXPAND_PADDING, 0);
   hbox1->pack_start(*alias_eingabe);
   hbox1->pack_start(*alias_pixmap, Gtk::PACK_SHRINK, 0);
   label21->set_alignment(0.5,0.5);
   label21->set_padding(0,0);
   label21->set_justify(Gtk::JUSTIFY_LEFT);
   label21->set_line_wrap(false);
   label21->set_use_markup(false);
   label21->set_selectable(false);
   frame5->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame5->set_label_align(0,0.5);
   frame5->add(*hbox1);
   frame5->set_label_widget(*label21);
   label9->set_alignment(0,0.5);
   label9->set_padding(0,0);
   label9->set_justify(Gtk::JUSTIFY_CENTER);
   label9->set_line_wrap(false);
   label9->set_use_markup(false);
   label9->set_selectable(false);
   change_no_instanz->set_flags(Gtk::CAN_FOCUS);
   change_no_instanz->set_relief(Gtk::RELIEF_NORMAL);
   change_no_instanz->set_mode(true);
   change_no_instanz->set_active(true);
   show_in_prlist->set_flags(Gtk::CAN_FOCUS);
   show_in_prlist->set_relief(Gtk::RELIEF_NORMAL);
   show_in_prlist->set_mode(true);
   show_in_prlist->set_active(true);
   table7->set_row_spacings(0);
   table7->set_col_spacings(0);
   table7->attach(*OM_Einheit, 2, 3, 1, 2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table7->attach(*label18, 2, 3, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table7->attach(*frame6, 3, 4, 1, 2, Gtk::AttachOptions(), Gtk::FILL, 0, 0);
   table7->attach(*frame4, 0, 4, 2, 3, Gtk::FILL, Gtk::FILL, 0, 0);
   table7->attach(*frame5, 0, 4, 3, 4, Gtk::SHRINK|Gtk::FILL, Gtk::FILL, 0, 0);
   table7->attach(*label9, 1, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table7->attach(*Artikel_Bestellen_bei, 1, 2, 1, 2, Gtk::FILL, Gtk::FILL, 0, 0);
   table7->attach(*change_no_instanz, 0, 1, 0, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table7->attach(*show_in_prlist, 3, 4, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   label14->set_alignment(0.5,0.5);
   label14->set_padding(0,0);
   label14->set_justify(Gtk::JUSTIFY_CENTER);
   label14->set_line_wrap(false);
   label14->set_use_markup(false);
   label14->set_selectable(false);
   label4->set_alignment(0,0.5);
   label4->set_padding(0,0);
   label4->set_justify(Gtk::JUSTIFY_CENTER);
   label4->set_line_wrap(false);
   label4->set_use_markup(false);
   label4->set_selectable(false);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_artikel_delete->set_visible_horizontal(true);
   button_artikel_delete->set_visible_vertical(true);
   button_artikel_delete->set_is_important(false);
#endif //
   button_artikel_delete_img->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   separatortoolitem1->set_visible_horizontal(true);
   separatortoolitem1->set_visible_vertical(true);
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_artikel_wechsel->set_visible_horizontal(true);
   button_artikel_wechsel->set_visible_vertical(true);
   button_artikel_wechsel->set_is_important(false);
#endif //
   button_artikel_wechsel_img->show();
   toolbar_loeschen->set_border_width(5);
   toolbar_loeschen->set_tooltips(true);
   toolbar_loeschen->set_toolbar_style(Gtk::TOOLBAR_ICONS);
   toolbar_loeschen->set_orientation(Gtk::ORIENTATION_HORIZONTAL);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar_loeschen->set_show_arrow(false);
#endif //
   table_artikelherkunft->set_row_spacings(0);
   table_artikelherkunft->set_col_spacings(0);
   table_artikelherkunft->attach(*label4, 0, 1, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table_artikelherkunft->attach(*vseparator3, 1, 2, 0, 2, Gtk::FILL, Gtk::FILL, 3, 0);
   table_artikelherkunft->attach(*toolbar_loeschen, 2, 3, 0, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table_artikelherkunft->attach(*artikelboxb, 0, 1, 1, 2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   scrolledwindow1->set_shadow_type(Gtk::SHADOW_NONE);
   scrolledwindow1->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
   scrolledwindow1->property_window_placement().set_value(Gtk::CORNER_TOP_LEFT);
   scrolledwindow1->add(*tree);
   vbox3->pack_start(*table_artikelherkunft, Gtk::PACK_SHRINK, 0);
   vbox3->pack_start(*scrolledwindow1);
   label15->set_alignment(0.5,0.5);
   label15->set_padding(0,0);
   label15->set_justify(Gtk::JUSTIFY_CENTER);
   label15->set_line_wrap(false);
   label15->set_use_markup(false);
   label15->set_selectable(false);
   label3->set_alignment(0,0.5);
   label3->set_padding(0,0);
   label3->set_justify(Gtk::JUSTIFY_CENTER);
   label3->set_line_wrap(false);
   label3->set_use_markup(false);
   label3->set_selectable(false);
   checkbutton_offene_auftraege->set_flags(Gtk::CAN_FOCUS);
   checkbutton_offene_auftraege->set_relief(Gtk::RELIEF_NORMAL);
   checkbutton_offene_auftraege->set_mode(true);
   checkbutton_offene_auftraege->set_active(false);
   table9->set_row_spacings(0);
   table9->set_col_spacings(0);
   table9->attach(*label3, 1, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*checkbutton_offene_auftraege, 0, 1, 0, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*optionmenu_instanz, 1, 2, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*progressbar, 0, 2, 2, 3, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   label16->set_alignment(0.5,0.5);
   label16->set_padding(0,0);
   label16->set_justify(Gtk::JUSTIFY_CENTER);
   label16->set_line_wrap(false);
   label16->set_use_markup(false);
   label16->set_selectable(false);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   button_verschmelzen->set_visible_horizontal(true);
   button_verschmelzen->set_visible_vertical(true);
   button_verschmelzen->set_is_important(false);
#endif //
   button_verschmelzen_img->show();
   toolbar2->set_tooltips(true);
   toolbar2->set_toolbar_style(Gtk::TOOLBAR_ICONS);
   toolbar2->set_orientation(Gtk::ORIENTATION_HORIZONTAL);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar2->set_show_arrow(false);
#endif //
   label11->set_alignment(0,0.5);
   label11->set_padding(0,0);
   label11->set_justify(Gtk::JUSTIFY_CENTER);
   label11->set_line_wrap(false);
   label11->set_use_markup(false);
   label11->set_selectable(false);
   table_verschmelzen->set_row_spacings(0);
   table_verschmelzen->set_col_spacings(0);
   table_verschmelzen->attach(*toolbar2, 1, 2, 0, 2, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   table_verschmelzen->attach(*artbox_verschmelzen, 0, 1, 0, 1, Gtk::EXPAND|Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
   table_verschmelzen->attach(*label11, 0, 1, 1, 2, Gtk::AttachOptions(), Gtk::SHRINK, 0, 0);
   table3->set_row_spacings(0);
   table3->set_col_spacings(0);
   table3->attach(*table_verschmelzen, 0, 3, 0, 1, Gtk::FILL, Gtk::FILL, 0, 0);
   label17->set_alignment(0.5,0.5);
   label17->set_padding(0,0);
   label17->set_justify(Gtk::JUSTIFY_CENTER);
   label17->set_line_wrap(false);
   label17->set_use_markup(false);
   label17->set_selectable(false);
   label22->set_alignment(0.5,0.5);
   label22->set_padding(0,0);
   label22->set_justify(Gtk::JUSTIFY_LEFT);
   label22->set_line_wrap(false);
   label22->set_use_markup(false);
   label22->set_selectable(false);
   top_notebook->set_flags(Gtk::CAN_FOCUS);
   top_notebook->set_show_tabs(true);
   top_notebook->set_show_border(true);
   top_notebook->set_tab_pos(Gtk::POS_TOP);
   top_notebook->set_scrollable(false);
   top_notebook->append_page(*table6, *label13);
   top_notebook->pages().back().set_tab_label_packing(false, true, Gtk::PACK_START);
   top_notebook->append_page(*table7, *label14);
   top_notebook->pages().back().set_tab_label_packing(false, true, Gtk::PACK_START);
   top_notebook->append_page(*vbox3, *label15);
   top_notebook->pages().back().set_tab_label_packing(false, true, Gtk::PACK_START);
   top_notebook->append_page(*table9, *label16);
   top_notebook->pages().back().set_tab_label_packing(false, true, Gtk::PACK_START);
   top_notebook->append_page(*table3, *label17);
   top_notebook->pages().back().set_tab_label_packing(false, true, Gtk::PACK_START);
   top_notebook->append_page(*table_preis, *label22);
   top_notebook->pages().back().set_tab_label_packing(false, true, Gtk::PACK_START);
   vbox2->pack_start(*hbox3, Gtk::PACK_SHRINK, 0);
   vbox2->pack_start(*artikelbox, Gtk::PACK_SHRINK, 0);
   vbox2->pack_start(*top_notebook);
   Artikeleingabe->set_title("Artikeleingabe");
   Artikeleingabe->set_default_size(640,400);
   Artikeleingabe->set_modal(false);
   Artikeleingabe->property_window_position().set_value(Gtk::WIN_POS_NONE);
   Artikeleingabe->set_resizable(true);
   Artikeleingabe->property_destroy_with_parent().set_value(false);
   Artikeleingabe->add(*vbox2);
   button_close->show();
   button_drucken->show();
   toolbar1->show();
   label_warnung->show();
   hbox3->show();
   artikelbox->show();
   artikelbox_neu->show();
   no_instanz->show();
   was_tun->show();
   standard_instanz->show();
   label1->show();
   frame1->show();
   standard_einheit->show();
   label2->show();
   frame2->show();
   table6->show();
   label13->show();
   OM_Einheit->show();
   label18->show();
   mindbest_check->show();
   mindbestand->show();
   hbox4->show();
   label19->show();
   frame6->show();
   eingabebox->show();
   pixmap_edit->show();
   hbox2->show();
   label20->show();
   frame4->show();
   alias_warengruppe->show();
   alias_schema->show();
   alias_eingabe->show();
   alias_pixmap->show();
   hbox1->show();
   label21->show();
   frame5->show();
   label9->show();
   Artikel_Bestellen_bei->show();
   change_no_instanz->show();
   show_in_prlist->show();
   table7->show();
   label14->show();
   label4->show();
   vseparator3->show();
   button_artikel_delete->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   separatortoolitem1->show();
#endif //
   button_artikel_wechsel->show();
   toolbar_loeschen->show();
   artikelboxb->show();
   table_artikelherkunft->show();
   tree->show();
   scrolledwindow1->show();
   vbox3->show();
   label15->show();
   label3->show();
   checkbutton_offene_auftraege->show();
   optionmenu_instanz->show();
   progressbar->show();
   table9->show();
   label16->show();
   button_verschmelzen->show();
   toolbar2->show();
   artbox_verschmelzen->show();
   label11->show();
   table_verschmelzen->show();
   label17->show();
   label22->show();
   top_notebook->show();
   vbox2->show();
   Artikeleingabe->show();
   button_close->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_button_close_clicked), false);
   button_drucken->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_button_drucken_clicked), false);
   artikelbox->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::artikelbox_activate));
   artikelbox_neu->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::artikelbox_neu_activate));
   no_instanz->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_no_instanz_toggled), false);
   was_tun->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_was_tun_activate));
   standard_instanz->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_optionmenu_standardinstanz_activate));
   standard_einheit->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_standard_einheit_activate));
   OM_Einheit->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_einheit_activate));
   mindbest_check->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_mindbest_check_toggled), false);
   mindbestand->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_mindbestand_activate), true);
   eingabebox->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::eingabe_activate));
   alias_warengruppe->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_alias_warengruppe_activate));
   alias_schema->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_kunde_activate));
   alias_eingabe->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_alias_eingabe_activate));
   Artikel_Bestellen_bei->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::optionmenu_bestellen_bei_activate));
   change_no_instanz->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_change_no_instanz_toggled), false);
   show_in_prlist->signal_toggled().connect(SigC::slot(*this, &Artikeleingabe_glade::on_show_in_prlist_toggled), false);
   button_artikel_delete->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_button_artikel_delete_clicked), false);
   button_artikel_wechsel->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_button_artikel_wechsel_clicked), false);
   artikelboxb->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::on_Artikel_Bestellen_activate));
   tree->signal_leaf_selected().connect(SigC::slot(*this, &Artikeleingabe_glade::on_leaf_selected));
   tree->signal_node_selected().connect(SigC::slot(*this, &Artikeleingabe_glade::on_node_selected));
   tree->signal_leaf_unselected().connect(SigC::slot(*this, &Artikeleingabe_glade::on_unselect_row));
   checkbutton_offene_auftraege->signal_toggled().connect(SigC::slot(*this, &Artikeleingabe_glade::on_checkbutton_offene_auftraege_toggled), false);
   optionmenu_instanz->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::optionmenu_instanz_activate));
   button_verschmelzen->signal_clicked().connect(SigC::slot(*this, &Artikeleingabe_glade::on_button_verschmelzen_clicked), false);
   artbox_verschmelzen->signal_activate().connect(SigC::slot(*this, &Artikeleingabe_glade::artikelbox_activate));
   top_notebook->signal_switch_page().connect(SigC::slot(*this, &Artikeleingabe_glade::on_notebook1_switch_page), true);
}

Artikeleingabe_glade::~Artikeleingabe_glade()
{  delete artikelbox;
   delete artikelbox_neu;
   delete was_tun;
   delete standard_instanz;
   delete standard_einheit;
   delete OM_Einheit;
   delete eingabebox;
   delete alias_warengruppe;
   delete alias_schema;
   delete alias_eingabe;
   delete Artikel_Bestellen_bei;
   delete artikelboxb;
   delete tree;
   delete optionmenu_instanz;
   delete artbox_verschmelzen;
   delete gmm_data;
}
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2

#include <gtkmm/toolitem.h>
#endif //

table_preis_glade::table_preis_glade(GlademmData *gmm_data
) : Gtk::Table(2, 2, false)
{  
   
   Gtk::Table *table_preis = this;
   Gtk::Adjustment *preis_adj = Gtk::manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   preis = Gtk::manage(new class Gtk::SpinButton(*preis_adj, 1, 2));
   waehrung = new class WWaehrung();
   
   Gtk::Label *label23 = Gtk::manage(new class Gtk::Label(" pro "));
   Gtk::Adjustment *preismenge_adj = Gtk::manage(new class Gtk::Adjustment(1, 0, 10000, 1, 10, 10));
   preismenge = Gtk::manage(new class Gtk::SpinButton(*preismenge_adj, 1, 0));
   einheit = Gtk::manage(new class Gtk::Label("kg"));
   
   Gtk::Label *label25 = Gtk::manage(new class Gtk::Label(" ab "));
   Gtk::Adjustment *mindestmenge_adj = Gtk::manage(new class Gtk::Adjustment(1, 0, 10000, 1, 10, 10));
   mindestmenge = Gtk::manage(new class Gtk::SpinButton(*mindestmenge_adj, 1, 0));
   einheit2 = Gtk::manage(new class Gtk::Label("kg"));
   image_preis_ok = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-convert"), Gtk::IconSize(4)));
   
   Gtk::Button *button1 = Gtk::manage(new class Gtk::Button());
   Gtk::HBox *hbox5 = Gtk::manage(new class Gtk::HBox(false, 0));
   Gtk::HSeparator *hseparator1 = Gtk::manage(new class Gtk::HSeparator());
   preisliste = new class PreisBox();
   preisstaffel = new class SimpleTree(6);
   
   Gtk::ScrolledWindow *scrolledwindow2 = Gtk::manage(new class Gtk::ScrolledWindow());
   Gtk::Button *button2 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-delete")));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   Gtk::ToolItem *toolitem1 = Gtk::manage(new class Gtk::ToolItem());
#endif //
   Gtk::Toolbar *toolbar3 = Gtk::manage(new class Gtk::Toolbar());
   Gtk::HBox *hbox6 = Gtk::manage(new class Gtk::HBox(false, 0));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar3->append(*toolitem1);
#else //
   toolbar3->tools().push_back(Gtk::Toolbar_Helpers::Element(*button2));
   
   Gtk::Widget *toolitem1 = toolbar3->tools().back().get_widget();
#endif //
   preis->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*preis, "Preis", "");
   preis->set_update_policy(Gtk::UPDATE_ALWAYS);
   preis->set_numeric(true);
   preis->set_digits(2);
   preis->set_wrap(false);
   label23->set_alignment(0.5,0.5);
   label23->set_padding(0,0);
   label23->set_justify(Gtk::JUSTIFY_LEFT);
   label23->set_line_wrap(false);
   label23->set_use_markup(false);
   label23->set_selectable(false);
   preismenge->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*preismenge, "Preismenge", "");
   preismenge->set_update_policy(Gtk::UPDATE_ALWAYS);
   preismenge->set_numeric(false);
   preismenge->set_digits(0);
   preismenge->set_wrap(false);
   einheit->set_alignment(0,0.5);
   einheit->set_padding(0,0);
   einheit->set_justify(Gtk::JUSTIFY_CENTER);
   einheit->set_line_wrap(false);
   einheit->set_use_markup(false);
   einheit->set_selectable(false);
   label25->set_alignment(0.5,0.5);
   label25->set_padding(0,0);
   label25->set_justify(Gtk::JUSTIFY_LEFT);
   label25->set_line_wrap(false);
   label25->set_use_markup(false);
   label25->set_selectable(false);
   mindestmenge->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*mindestmenge, "Preismenge", "");
   mindestmenge->set_update_policy(Gtk::UPDATE_ALWAYS);
   mindestmenge->set_numeric(false);
   mindestmenge->set_digits(0);
   mindestmenge->set_wrap(false);
   einheit2->set_alignment(0,0.5);
   einheit2->set_padding(0,0);
   einheit2->set_justify(Gtk::JUSTIFY_CENTER);
   einheit2->set_line_wrap(false);
   einheit2->set_use_markup(false);
   einheit2->set_selectable(false);
   image_preis_ok->set_alignment(0,0.5);
   image_preis_ok->set_padding(0,0);
   _tooltips.set_tip(*button1, "Den Preis übernehmen", "");
   button1->set_relief(Gtk::RELIEF_NONE);
   button1->add(*image_preis_ok);
   hbox5->pack_start(*preis, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*waehrung, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*label23, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*preismenge, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*einheit, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*label25, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*mindestmenge, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*einheit2, Gtk::PACK_SHRINK, 0);
   hbox5->pack_start(*button1, Gtk::PACK_SHRINK, 0);
   scrolledwindow2->set_flags(Gtk::CAN_FOCUS);
   scrolledwindow2->set_shadow_type(Gtk::SHADOW_NONE);
   scrolledwindow2->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
   scrolledwindow2->property_window_placement().set_value(Gtk::CORNER_TOP_LEFT);
   scrolledwindow2->add(*preisstaffel);
   button2->set_flags(Gtk::CAN_FOCUS);
   button2->set_relief(Gtk::RELIEF_NONE);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolitem1->set_visible_horizontal(true);
   toolitem1->set_visible_vertical(true);
   toolitem1->set_is_important(false);
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolitem1->add(*button2);
#endif //
   toolbar3->set_tooltips(true);
   toolbar3->set_toolbar_style(Gtk::TOOLBAR_ICONS);
   toolbar3->set_orientation(Gtk::ORIENTATION_VERTICAL);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolbar3->set_show_arrow(false);
#endif //
   hbox6->pack_start(*scrolledwindow2);
   hbox6->pack_start(*toolbar3, Gtk::PACK_SHRINK, 0);
   table_preis->set_row_spacings(4);
   table_preis->set_col_spacings(2);
   table_preis->attach(*hbox5, 0, 1, 2, 3, Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
   table_preis->attach(*hseparator1, 0, 1, 1, 2, Gtk::EXPAND|Gtk::FILL, Gtk::FILL, 0, 0);
   table_preis->attach(*preisliste, 0, 1, 0, 1, Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
   table_preis->attach(*hbox6, 0, 1, 3, 4, Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
   preis->show();
   waehrung->show();
   label23->show();
   preismenge->show();
   einheit->show();
   label25->show();
   mindestmenge->show();
   einheit2->show();
   image_preis_ok->show();
   button1->show();
   hbox5->show();
   hseparator1->show();
   preisliste->show();
   preisstaffel->show();
   scrolledwindow2->show();
   button2->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
   toolitem1->show();
#endif //
   toolbar3->show();
   hbox6->show();
   table_preis->show();
   preis->signal_activate().connect(SigC::slot(*this, &table_preis_glade::activate_preis), true);
   waehrung->signal_activate().connect(SigC::slot(*this, &table_preis_glade::waehrung_deactivate));
   preismenge->signal_activate().connect(SigC::slot(*this, &table_preis_glade::preismenge_activate), true);
   mindestmenge->signal_activate().connect(SigC::slot(*this, &table_preis_glade::mindestmenge_activate), true);
   button1->signal_activate().connect(SigC::slot(*this, &table_preis_glade::preis_uebernehmen), true);
   preisliste->signal_activate().connect(SigC::slot(*this, &table_preis_glade::andere_Liste));
   button2->signal_activate().connect(SigC::slot(*this, &table_preis_glade::staffelzeile_loeschen), false);
}

table_preis_glade::~table_preis_glade()
{  delete waehrung;
   delete preisliste;
   delete preisstaffel;
}
