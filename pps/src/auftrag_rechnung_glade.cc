// generated 2003/3/26 10:23:21 MET by jacek@ijacek.jacek.de
// using glademm V1.1.3f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/auftrag_rechnung.cc

#include "config.h"
#include "auftrag_rechnung_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <gtk--/menuitem.h>
#include <gtk--/menu.h>
#include <gtk--/menubar.h>
#include <libgnomeui/gnome-app.h>
#include <libgnomeui/gnome-app-helper.h>
#include <libgnomeui/gnome-stock.h>
#include <libgnome/libgnome.h>
#include <gtk--/button.h>
#include <gtk--/table.h>
#include <gtk--/label.h>
#include <gtk--/radiomenuitem.h>
#include <gtk--/adjustment.h>
#include <gtk--/toolbar.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/stock_convert_rev2.xpm"
#include <gtk--/box.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/frame.h>
#include <gtk--/paned.h>

auftrag_rechnung_glade::auftrag_rechnung_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  auftrag_rechnung = this;
   
   Gtk::AccelGroup *auftrag_rechnung_accgrp = Gtk::AccelGroup::create();
   gmm_data = new GlademmData(auftrag_rechnung_accgrp);
   
   Gtk::MenuBar *menubar3 = manage(new class Gtk::MenuBar());
   Gtk::MenuItem *pixmapmenuitem1;
   Gtk::MenuItem *menuitem1;
   {  static GnomeUIInfo menuitem1_menu_uiinfo[] = 
      {       GNOMEUIINFO_MENU_CLOSE_ITEM(0, 0), 
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo menubar3_uiinfo[] = 
      {       GNOMEUIINFO_MENU_FILE_TREE(menuitem1_menu_uiinfo),
	      GNOMEUIINFO_END 
      };
      gnome_app_fill_menu(GTK_MENU_SHELL(menubar3->gtkobj()), menubar3_uiinfo, gmm_data->getAccelGroup()->gtkobj(), true, 0);
      pixmapmenuitem1 = Gtk::wrap(GTK_MENU_ITEM(menuitem1_menu_uiinfo[0].widget));
   }
   checkbutton_firmenpapier = manage(new class Gtk::CheckButton(std::string("Firmenpapier"), (gfloat)0, (gfloat)0.5));
   checkbutton_kopie = manage(new class Gtk::CheckButton(std::string("Kopie"), (gfloat)0, (gfloat)0.5));
   checkbutton_ean_drucken = manage(new class Gtk::CheckButton(std::string("EAN"), (gfloat)0, (gfloat)0.5));
   
   Gtk::Table *table17 = manage(new class Gtk::Table(3, 1, false));
   Gtk::Label *label88 = manage(new class Gtk::Label("Preis in"));
   label_auftragspreis = manage(new class Gtk::Label("2,00"));
   
   Gtk::RadioMenuItem::Group _RadioBGroup_artaufpreis;
   radiobutton_artikelpreis = manage(new class Gtk::RadioButton(_RadioBGroup_artaufpreis, std::string("Artikel"), (gfloat)0, (gfloat)0.5));
   radiobutton_auftragspreis = manage(new class Gtk::RadioButton(_RadioBGroup_artaufpreis, std::string("Auftrag"), (gfloat)0, (gfloat)0.5));
   label_artikelpreis = manage(new class Gtk::Label("2,00"));
   radiobutton_preiseingabe = manage(new class Gtk::RadioButton(_RadioBGroup_artaufpreis, std::string("Eingabe"), (gfloat)0, (gfloat)0.5));
   
   Gtk::Adjustment *spinbutton_preiseingabe_adj = manage(new class Gtk::Adjustment(0.3, 0, 10000, 0.1, 10, 10));
   spinbutton_preiseingabe = manage(new class Gtk::SpinButton(*spinbutton_preiseingabe_adj, 1, 2));
   table_preisvergleich = manage(new class Gtk::Table(3, 3, true));
   
   Gtk::Toolbar *toolbar7 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Label *label66 = manage(new class Gtk::Label("W�hrung"));
   rng_WWaehrung = new class WWaehrung(WWaehrung::KURZ);
   
   Gtk::Label *label87 = manage(new class Gtk::Label("Zahlung"));
   optionmenu_zahlart = manage(new class Gtk::OptionMenu());
   rngdatum = new class Datewin();
   rngnr = new class SearchComboContent<int>();
   lieferkunde = new class KundenBox2();
   
   Gtk::Label *label72 = manage(new class Gtk::Label("Kunde"));
   Gtk::Label *label60 = manage(new class Gtk::Label("Rg. Nr."));
   Gtk::Label *label61 = manage(new class Gtk::Label("Rg. Datum"));
   label_rechnung_ctl = manage(new class Gtk::Label(""));
   
   Gtk::Pixmap *pixmap5 = manage(new class Gtk::Pixmap(stock_convert_rev2_xpm));
   Gtk::Label *label92 = manage(new class Gtk::Label("In Gutschrift\n"
		"umwandeln"));
   Gtk::HBox *hbox13 = manage(new class Gtk::HBox(false, 0));
   Gtk::Button *button_gutschrift = manage(new class Gtk::Button());
   Gtk::Button *button_gutschrift_ja = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_YES));
   Gtk::Button *button_gutschrift_nein = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_NO));
   table_gutschrift_sicherheit = manage(new class Gtk::Table(1, 2, true));
   table_gutschrift = manage(new class Gtk::Table(2, 1, false));
   
   Gtk::Label *label94 = manage(new class Gtk::Label("Zahlungsziel"));
   rabatt_typ = manage(new class Gtk::OptionMenu());
   
   Gtk::Adjustment *rabatt_wert_adj = manage(new class Gtk::Adjustment(0, 0, 99, 1, 10, 10));
   rabatt_wert = manage(new class Gtk::SpinButton(*rabatt_wert_adj, 1, 2));
   zahlziel = new class Datewin();
   
   Gtk::Table *table23 = manage(new class Gtk::Table(2, 2, false));
   bezahlt = manage(new class Gtk::CheckButton(std::string("bezahlt"), (gfloat)0, (gfloat)0.5));
   
   Gtk::Table *table10 = manage(new class Gtk::Table(4, 5, false));
   frame_rechnung = manage(new class Gtk::Frame("Rechnung"));
   rtree_daten = new class SimpleTree(7, 3);
   
   Gtk::ScrolledWindow *scrolledwindow6 = manage(new class Gtk::ScrolledWindow());
   rng_notiz = manage(new class Gtk::Text());
   
   Gtk::ScrolledWindow *scrolledwindow13 = manage(new class Gtk::ScrolledWindow());
   Gtk::Toolbar *toolbar15 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::HBox *hbox20 = manage(new class Gtk::HBox(false, 0));
   Gtk::Frame *frame29 = manage(new class Gtk::Frame("Notiz"));
   Gtk::VPaned *vpaned1 = manage(new class Gtk::VPaned());
   frame_rechnungsdaten = manage(new class Gtk::Frame("Rechnungsdaten"));
   
   Gtk::VBox *vbox14 = manage(new class Gtk::VBox(false, 0));
   Gtk::Label *label63 = manage(new class Gtk::Label("Liefer.Nr."));
   lieferscheinnr = manage(new class Gtk::Entry());
   
   Gtk::Toolbar *toolbar8 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Label *label71 = manage(new class Gtk::Label("Liefer. Datum"));
   lieferscheindatum = new class Datewin();
   
   Gtk::Toolbar *toolbar14 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Label *label97 = manage(new class Gtk::Label(""));
   Gtk::Table *table11 = manage(new class Gtk::Table(2, 5, false));
   rtree_offen = new class SimpleTree(4, 4);
   
   Gtk::ScrolledWindow *scrolledwindow7 = manage(new class Gtk::ScrolledWindow());
   vbox_n_b_lieferscheine = manage(new class Gtk::VBox(false, 0));
   
   Gtk::Frame *frame9 = manage(new class Gtk::Frame("nicht berechnete Lieferscheine"));
   Gtk::VBox *vbox13 = manage(new class Gtk::VBox(false, 0));
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Schlie�en", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_CLOSE)), 0));
   Gtk::Button *button23 = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Neu", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_NEW)), 0));
   Gtk::Button *button24 = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Speichern", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SAVE)), 0));
   Gtk::Button *button25 = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Anzeigen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SEARCH)), 0));
   Gtk::Button *button26 = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_PRINT)), 0));
   button27 = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::Element(*table17));
   
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Preise\n"
		"erg�nzen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SEARCH)), 0));
   preis_ergaenzen = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Rng.Zeile\n"
		"l�schen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_CLEAR)), 0));
   rngentry_del = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Preis\n"
		"�berschreiben", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SRCHRPL)), 0));
   button_pr = static_cast<Gtk::Button *>(toolbar7->tools().back()->get_widget());
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::Element(*table_preisvergleich));
   
   
   toolbar15->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("speichern", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SAVE)), 0));
   rng_notiz_save = static_cast<Gtk::Button *>(toolbar15->tools().back()->get_widget());
   
   toolbar8->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Lieferschein\n"
		"�bernehmen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_ATTACH)), 0));
   lief_uebernehmen = static_cast<Gtk::Button *>(toolbar8->tools().back()->get_widget());
   
   toolbar14->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Alle offene Liefer-\n"
		"scheine anschauen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_BOOK_OPEN)), 0));
   Gtk::Button *button_allopen = static_cast<Gtk::Button *>(toolbar14->tools().back()->get_widget());
   
   toolbar14->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("leere Lieferscheine\n"
		"aufr�umen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_CLEAR)), 0));
   button_lieferscheine_aufraumen = static_cast<Gtk::Button *>(toolbar14->tools().back()->get_widget());
   menubar3->set_shadow_type(GTK_SHADOW_OUT);
   button25->set_sensitive(false);
   _tooltips.set_tip(*button27, "Linke Maustaste: Drucken wie gew�hlt. Mittlere Maustaste: Originalrechnung auf Firmanpapier und Kopie auf Standardpapier. Rechte Maustaste: Original auf Firmanpapier und je eine Kopie auf Firmenpapier und Standardpapier.", "");
   checkbutton_firmenpapier->set_flags(GTK_CAN_FOCUS);
   checkbutton_firmenpapier->set_mode(true);
   checkbutton_firmenpapier->set_active(true);
   checkbutton_kopie->set_flags(GTK_CAN_FOCUS);
   checkbutton_kopie->set_mode(true);
   checkbutton_kopie->set_active(false);
   checkbutton_ean_drucken->set_flags(GTK_CAN_FOCUS);
   checkbutton_ean_drucken->set_mode(true);
   checkbutton_ean_drucken->set_active(false);
   table17->set_row_spacings(0);
   table17->set_col_spacings(0);
   table17->attach(*checkbutton_firmenpapier, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table17->attach(*checkbutton_kopie, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table17->attach(*checkbutton_ean_drucken, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   rngentry_del->set_sensitive(false);
   button_pr->set_sensitive(false);
   label88->set_alignment(0,0.5);
   label88->set_padding(0,0);
   label88->set_justify(GTK_JUSTIFY_CENTER);
   label88->set_line_wrap(false);
   label_auftragspreis->set_alignment(0.5,0.5);
   label_auftragspreis->set_padding(0,0);
   label_auftragspreis->set_justify(GTK_JUSTIFY_CENTER);
   label_auftragspreis->set_line_wrap(false);
   radiobutton_artikelpreis->set_flags(GTK_CAN_FOCUS);
   radiobutton_artikelpreis->set_mode(false);
   radiobutton_artikelpreis->set_active(true);
   radiobutton_auftragspreis->set_flags(GTK_CAN_FOCUS);
   radiobutton_auftragspreis->set_mode(false);
   radiobutton_auftragspreis->set_active(false);
   label_artikelpreis->set_alignment(0.5,0.5);
   label_artikelpreis->set_padding(0,0);
   label_artikelpreis->set_justify(GTK_JUSTIFY_CENTER);
   label_artikelpreis->set_line_wrap(false);
   radiobutton_preiseingabe->set_flags(GTK_CAN_FOCUS);
   radiobutton_preiseingabe->set_mode(false);
   radiobutton_preiseingabe->set_active(false);
   spinbutton_preiseingabe->set_flags(GTK_CAN_FOCUS);
   spinbutton_preiseingabe->set_update_policy(GTK_UPDATE_ALWAYS);
   spinbutton_preiseingabe->set_numeric(false);
   spinbutton_preiseingabe->set_digits(2);
   spinbutton_preiseingabe->set_wrap(false);
   spinbutton_preiseingabe->set_snap_to_ticks(false);
   table_preisvergleich->set_row_spacings(0);
   table_preisvergleich->set_col_spacings(0);
   table_preisvergleich->attach(*label88, 0, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table_preisvergleich->attach(*label_auftragspreis, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   table_preisvergleich->attach(*radiobutton_artikelpreis, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table_preisvergleich->attach(*radiobutton_auftragspreis, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table_preisvergleich->attach(*label_artikelpreis, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table_preisvergleich->attach(*radiobutton_preiseingabe, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table_preisvergleich->attach(*spinbutton_preiseingabe, 2, 3, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   toolbar7->set_space_size(5);
   toolbar7->set_tooltips(true);
   toolbar7->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   label66->set_alignment(0,0.5);
   label66->set_padding(0,0);
   label66->set_justify(GTK_JUSTIFY_CENTER);
   label66->set_line_wrap(false);
   label87->set_alignment(0,0.5);
   label87->set_padding(0,0);
   label87->set_justify(GTK_JUSTIFY_CENTER);
   label87->set_line_wrap(false);
   optionmenu_zahlart->set_flags(GTK_CAN_FOCUS);
   {  
      
      Gtk::Menu *_m(manage(new Gtk::Menu()));
      Gtk::MenuItem *_mi;
      _mi = manage(new Gtk::MenuItem("Zahlungsart"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)0);
      optionmenu_zahlart->set_menu(*_m);
      optionmenu_zahlart->set_history(0);
   }
   rngnr->set_usize(100,-1);
   label72->set_alignment(0,0.5);
   label72->set_padding(0,0);
   label72->set_justify(GTK_JUSTIFY_CENTER);
   label72->set_line_wrap(false);
   label60->set_alignment(0,0.5);
   label60->set_padding(0,0);
   label60->set_justify(GTK_JUSTIFY_CENTER);
   label60->set_line_wrap(false);
   label61->set_alignment(0,0.5);
   label61->set_padding(0,0);
   label61->set_justify(GTK_JUSTIFY_CENTER);
   label61->set_line_wrap(false);
   label_rechnung_ctl->set_alignment(0,0.5);
   label_rechnung_ctl->set_padding(0,0);
   label_rechnung_ctl->set_justify(GTK_JUSTIFY_LEFT);
   label_rechnung_ctl->set_line_wrap(false);
   pixmap5->set_alignment(0.5,0.5);
   pixmap5->set_padding(0,0);
   label92->set_alignment(0.5,0.5);
   label92->set_padding(0,0);
   label92->set_justify(GTK_JUSTIFY_CENTER);
   label92->set_line_wrap(false);
   hbox13->pack_start(*pixmap5);
   hbox13->pack_start(*label92, false, false, 0);
   button_gutschrift->set_flags(GTK_CAN_FOCUS);
   button_gutschrift->set_relief(GTK_RELIEF_NORMAL);
   button_gutschrift->add(*hbox13);
   button_gutschrift_ja->set_flags(GTK_CAN_FOCUS);
   button_gutschrift_ja->set_relief(GTK_RELIEF_NORMAL);
   button_gutschrift_nein->set_flags(GTK_CAN_FOCUS);
   button_gutschrift_nein->set_relief(GTK_RELIEF_NORMAL);
   table_gutschrift_sicherheit->set_row_spacings(0);
   table_gutschrift_sicherheit->set_col_spacings(0);
   table_gutschrift_sicherheit->attach(*button_gutschrift_ja, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_gutschrift_sicherheit->attach(*button_gutschrift_nein, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table_gutschrift->set_row_spacings(0);
   table_gutschrift->set_col_spacings(0);
   table_gutschrift->attach(*button_gutschrift, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_gutschrift->attach(*table_gutschrift_sicherheit, 0, 1, 1, 2, 0, 0, 0, 0);
   label94->set_alignment(0,0.5);
   label94->set_padding(0,0);
   label94->set_justify(GTK_JUSTIFY_CENTER);
   label94->set_line_wrap(false);
   rabatt_typ->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*rabatt_typ, "Rabatt/Zuschlag auf alle Rechnungsposten", "");
   {  
      
      Gtk::Menu *_m(manage(new Gtk::Menu()));
      Gtk::MenuItem *_mi;
      _mi = manage(new Gtk::MenuItem("Rabatt"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)0);
      _mi = manage(new Gtk::MenuItem("Zuschlag"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)1);
      rabatt_typ->set_menu(*_m);
      rabatt_typ->set_history(0);
   }
   rabatt_wert->set_usize(60,-1);
   rabatt_wert->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*rabatt_wert, "Rabatt/Zuschlag auf alle Rechnungsposten", "");
   rabatt_wert->set_update_policy(GTK_UPDATE_ALWAYS);
   rabatt_wert->set_numeric(true);
   rabatt_wert->set_digits(2);
   rabatt_wert->set_wrap(false);
   rabatt_wert->set_snap_to_ticks(false);
   table23->set_row_spacings(0);
   table23->set_col_spacings(0);
   table23->attach(*label94, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table23->attach(*rabatt_typ, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table23->attach(*rabatt_wert, 1, 2, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table23->attach(*zahlziel, 1, 2, 0, 1, GTK_SHRINK, GTK_SHRINK, 0, 0);
   bezahlt->set_flags(GTK_CAN_FOCUS);
   bezahlt->set_mode(true);
   bezahlt->set_active(false);
   table10->set_row_spacings(0);
   table10->set_col_spacings(0);
   table10->attach(*label66, 3, 4, 1, 2, GTK_FILL, 0, 0, 0);
   table10->attach(*rng_WWaehrung, 4, 5, 1, 2, 0, 0, 0, 0);
   table10->attach(*label87, 3, 4, 0, 1, GTK_FILL, 0, 0, 0);
   table10->attach(*optionmenu_zahlart, 4, 5, 0, 1, GTK_FILL, 0, 0, 0);
   table10->attach(*rngdatum, 1, 2, 2, 3, 0, GTK_FILL, 0, 0);
   table10->attach(*rngnr, 1, 2, 1, 2, 0, 0, 0, 0);
   table10->attach(*lieferkunde, 1, 3, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table10->attach(*label72, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table10->attach(*label60, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table10->attach(*label61, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table10->attach(*label_rechnung_ctl, 1, 3, 3, 4, GTK_FILL, 0, 0, 0);
   table10->attach(*table_gutschrift, 2, 3, 1, 3, 0, 0, 0, 0);
   table10->attach(*table23, 3, 5, 2, 4, GTK_FILL, GTK_FILL, 0, 0);
   table10->attach(*bezahlt, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   frame_rechnung->set_border_width(5);
   frame_rechnung->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_rechnung->set_label_align(0,0);
   frame_rechnung->add(*table10);
   scrolledwindow6->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow6->add(*rtree_daten);
   rng_notiz->set_flags(GTK_CAN_FOCUS);
   rng_notiz->set_editable(true);
   scrolledwindow13->set_policy(GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
   scrolledwindow13->add(*rng_notiz);
   rng_notiz_save->set_sensitive(false);
   toolbar15->set_space_size(5);
   toolbar15->set_tooltips(true);
   toolbar15->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   hbox20->pack_end(*scrolledwindow13);
   hbox20->pack_start(*toolbar15, false, false, 0);
   frame29->set_border_width(5);
   frame29->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame29->set_label_align(0,0);
   frame29->add(*hbox20);
   vpaned1->set_handle_size(15);
   vpaned1->set_gutter_size(6);
   vpaned1->set_position(130);
   vpaned1->pack1(*scrolledwindow6, false, true);
   vpaned1->pack2(*frame29, true, true);
   frame_rechnungsdaten->set_border_width(5);
   frame_rechnungsdaten->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_rechnungsdaten->set_label_align(0,0);
   frame_rechnungsdaten->add(*vpaned1);
   vbox14->pack_start(*toolbar7, false, false, 0);
   vbox14->pack_start(*frame_rechnung, false, true, 0);
   vbox14->pack_start(*frame_rechnungsdaten);
   label63->set_alignment(0,0.5);
   label63->set_padding(0,0);
   label63->set_justify(GTK_JUSTIFY_LEFT);
   label63->set_line_wrap(false);
   lieferscheinnr->set_usize(100,-1);
   lieferscheinnr->set_flags(GTK_CAN_FOCUS);
   lieferscheinnr->set_visibility(true);
   lieferscheinnr->set_editable(false);
   lieferscheinnr->set_text("");
   lief_uebernehmen->set_sensitive(false);
   _tooltips.set_tip(*lief_uebernehmen, "Kompletten Auftrag in Lieferschein �bernehmen", "");
   toolbar8->set_space_size(5);
   toolbar8->set_tooltips(true);
   toolbar8->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   label71->set_alignment(0,0.5);
   label71->set_padding(0,0);
   label71->set_justify(GTK_JUSTIFY_CENTER);
   label71->set_line_wrap(false);
   toolbar14->set_space_size(5);
   toolbar14->set_tooltips(true);
   toolbar14->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   label97->set_alignment(0,0.5);
   label97->set_padding(0,0);
   label97->set_justify(GTK_JUSTIFY_CENTER);
   label97->set_line_wrap(false);
   table11->set_border_width(5);
   table11->set_row_spacings(0);
   table11->set_col_spacings(1);
   table11->attach(*label63, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table11->attach(*lieferscheinnr, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table11->attach(*toolbar8, 2, 3, 0, 2, GTK_FILL, 0, 0, 0);
   table11->attach(*label71, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table11->attach(*lieferscheindatum, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table11->attach(*toolbar14, 4, 5, 0, 2, GTK_FILL, 0, 0, 0);
   table11->attach(*label97, 3, 4, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   scrolledwindow7->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow7->add(*rtree_offen);
   vbox_n_b_lieferscheine->pack_start(*table11, false, true, 0);
   vbox_n_b_lieferscheine->pack_start(*scrolledwindow7);
   frame9->set_border_width(5);
   frame9->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame9->set_label_align(0,0);
   frame9->add(*vbox_n_b_lieferscheine);
   vbox13->pack_start(*menubar3, false, false, 0);
   vbox13->pack_start(*vbox14);
   vbox13->pack_start(*frame9);
   auftrag_rechnung->set_title("Rechnungen");
   auftrag_rechnung->set_default_size(800,600);
   auftrag_rechnung->set_modal(false);
   auftrag_rechnung->set_position(GTK_WIN_POS_NONE);
   auftrag_rechnung->set_policy(true, true, false);
   auftrag_rechnung->add_accel_group(*(gmm_data->getAccelGroup()));
   auftrag_rechnung->add(*vbox13);
   menubar3->show();
   checkbutton_firmenpapier->show();
   checkbutton_kopie->show();
   table17->show();
   label88->show();
   label_auftragspreis->show();
   radiobutton_artikelpreis->show();
   radiobutton_auftragspreis->show();
   label_artikelpreis->show();
   radiobutton_preiseingabe->show();
   spinbutton_preiseingabe->show();
   toolbar7->show();
   label66->show();
   rng_WWaehrung->show();
   label87->show();
   optionmenu_zahlart->show();
   rngdatum->show();
   rngnr->show();
   lieferkunde->show();
   label72->show();
   label60->show();
   label61->show();
   label_rechnung_ctl->show();
   pixmap5->show();
   label92->show();
   hbox13->show();
   button_gutschrift->show();
   button_gutschrift_ja->show();
   button_gutschrift_nein->show();
   table_gutschrift->show();
   label94->show();
   rabatt_typ->show();
   rabatt_wert->show();
   zahlziel->show();
   table23->show();
   bezahlt->show();
   table10->show();
   frame_rechnung->show();
   rtree_daten->show();
   scrolledwindow6->show();
   rng_notiz->show();
   scrolledwindow13->show();
   toolbar15->show();
   hbox20->show();
   frame29->show();
   vpaned1->show();
   frame_rechnungsdaten->show();
   vbox14->show();
   label63->show();
   lieferscheinnr->show();
   toolbar8->show();
   label71->show();
   lieferscheindatum->show();
   toolbar14->show();
   label97->show();
   table11->show();
   rtree_offen->show();
   scrolledwindow7->show();
   vbox_n_b_lieferscheine->show();
   frame9->show();
   vbox13->show();
   auftrag_rechnung->show();
   pixmapmenuitem1->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_close));
   button23->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_close));
   button24->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_neu));
   button25->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_save));
   button26->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_preview));
   button27->button_press_event.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_print));
   checkbutton_ean_drucken->clicked.connect_after(SigC::slot(this, &auftrag_rechnung_glade::on_checkbutton_ean_drucken_clicked));
   preis_ergaenzen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::Preis_ergaenzen));
   rngentry_del->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::rngzeile_delete));
   button_pr->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::Preis_setzen));
   rng_WWaehrung->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::waehrung_geaendert));
   optionmenu_zahlart->get_menu()->deactivate.connect(SigC::slot(this, &auftrag_rechnung_glade::optionmenu_zahlart_deactivate));
   rngdatum->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rngdate_activate));
   rngnr->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rngnr_activate));
   rngnr->search.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rngnr_search));
   lieferkunde->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_lieferkunde_activate));
   button_gutschrift->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_gutschrift_clicked));
   button_gutschrift_ja->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_gutschrift_ja_clicked));
   button_gutschrift_nein->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_gutschrift_nein_clicked));
   rabatt_typ->get_menu()->deactivate.connect(SigC::slot(this, &auftrag_rechnung_glade::rabatt_geaendert));
   rabatt_wert->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::rabatt_geaendert));
   zahlziel->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_zahlziel_activate));
   bezahlt->button_release_event.connect_after(SigC::slot(this, &auftrag_rechnung_glade::on_bezahlt_toggled));
   rtree_daten->leaf_selected.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rdaten_leaf_selected));
   rtree_daten->unselect_row.connect(SigC::slot(this, &auftrag_rechnung_glade::on_unselectrow_rtree));
   rng_notiz->changed.connect(SigC::slot(this, &auftrag_rechnung_glade::on_notiz_changed));
   rng_notiz_save->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_notiz_save_clicked));
   lief_uebernehmen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::lieferschein_uebernehmen));
   button_allopen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_allopen_clicked));
   button_lieferscheine_aufraumen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_lieferscheine_aufraumen_clicked));
   rtree_offen->unselect_row.connect(SigC::slot(this, &auftrag_rechnung_glade::on_unselectrow_rtree_offen));
   rtree_offen->leaf_selected.connect(SigC::slot(this, &auftrag_rechnung_glade::on_roffen_leaf_selected));
}

auftrag_rechnung_glade::~auftrag_rechnung_glade()
{  delete rng_WWaehrung;
   delete rngdatum;
   delete rngnr;
   delete lieferkunde;
   delete zahlziel;
   delete rtree_daten;
   delete lieferscheindatum;
   delete rtree_offen;
   delete gmm_data;
}
