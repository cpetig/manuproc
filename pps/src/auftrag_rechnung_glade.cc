// generated 2005/5/2 16:28:11 CEST by jacek@jaceksdell.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/auftrag_rechnung.cc

#include "config.h"
#include "auftrag_rechnung_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <libgnomeui/gnome-app.h>
#include <libgnomeui/gnome-app-helper.h>
#include <libgnomeui/gnome-stock.h>
#include <libintl.h>
#include <libgnome/libgnome.h>
#include <gtk--/button.h>
#include <gtk--/table.h>
#include <gtk--/toolbar.h>
#include <gtk--/label.h>
#include <gtk--/menu.h>
#include <gtk--/menuitem.h>
#include <gtk--/adjustment.h>
#include <gtk--/radiobutton.h>
#include <gtk--/box.h>
#include <gtk--/frame.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/paned.h>

auftrag_rechnung_glade::auftrag_rechnung_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  auftrag_rechnung = this;
   
   Gtk::AccelGroup *auftrag_rechnung_accgrp = Gtk::AccelGroup::create();
   gmm_data = new GlademmData(auftrag_rechnung_accgrp);
   menubar3 = manage(new class Gtk::MenuBar());
   checkbutton_firmenpapier = manage(new class Gtk::CheckButton("Firmenpapier", 0, 0.5));
   checkbutton_kopie = manage(new class Gtk::CheckButton("Kopie", 0, 0.5));
   checkbutton_ean_drucken = manage(new class Gtk::CheckButton("EAN", 0, 0.5));
   
   Gtk::Table *table17 = manage(new class Gtk::Table(3, 1, false));
   Gtk::Toolbar *toolbar7 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Label *label66 = manage(new class Gtk::Label("W�hrung"));
   Gtk::Label *label87 = manage(new class Gtk::Label("Zahlung"));
   optionmenu_zahlart = manage(new class Gtk::OptionMenu());
   rngdatum = new class Datewin();
   rngnr = new class SearchComboContent<int>();
   
   Gtk::Label *label72 = manage(new class Gtk::Label("Kunde"));
   Gtk::Label *label60 = manage(new class Gtk::Label("Rg. Nr."));
   Gtk::Label *label61 = manage(new class Gtk::Label("Rg. Datum"));
   bezahlt = manage(new class Gtk::CheckButton("bezahlt", 0, 0.5));
   rabatt_typ = manage(new class Gtk::OptionMenu());
   
   Gtk::Adjustment *rabatt_wert_adj = manage(new class Gtk::Adjustment(0, 0, 100, 1, 10, 10));
   rabatt_wert = manage(new class Gtk::SpinButton(*rabatt_wert_adj, 1, 2));
   
   Gtk::Label *label98 = manage(new class Gtk::Label("Valuta"));
   zahlziel = new class Datewin();
   
   Gtk::Table *table23 = manage(new class Gtk::Table(2, 2, false));
   label_rechnung_ctl = manage(new class Gtk::Label(""));
   lieferkunde = new class KundenBox2();
   rng_WWaehrung = new class WWaehrung(WWaehrung::KURZ);
   
   Gtk::Table *table10 = manage(new class Gtk::Table(4, 4, false));
   frame_rechnung = manage(new class Gtk::Frame("Rechnung"));
   
   Gtk::RadioButton::Group _RadioBGroup_artaufpreis;
   radiobutton_artikelpreis = manage(new class Gtk::RadioButton(_RadioBGroup_artaufpreis, "Preislistenpreis", 0, 0.5));
   label_artikelpreis = manage(new class Gtk::Label("0,00"));
   
   Gtk::HBox *hbox24 = manage(new class Gtk::HBox(false, 0));
   radiobutton_auftragspreis = manage(new class Gtk::RadioButton(_RadioBGroup_artaufpreis, "Auftrag", 0, 0.5));
   label_auftragspreis = manage(new class Gtk::Label("0,00"));
   
   Gtk::HBox *hbox25 = manage(new class Gtk::HBox(false, 0));
   radiobutton_preiseingabe = manage(new class Gtk::RadioButton(_RadioBGroup_artaufpreis, "Eingabe", 0, 0.5));
   
   Gtk::Adjustment *spinbutton_preiseingabe_adj = manage(new class Gtk::Adjustment(0, 0, 10000, 0.1, 10, 10));
   spinbutton_preiseingabe = manage(new class Gtk::SpinButton(*spinbutton_preiseingabe_adj, 1, 2));
   
   Gtk::HBox *hbox26 = manage(new class Gtk::HBox(false, 0));
   button_pr = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_APPLY));
   
   Gtk::HBox *hbox23 = manage(new class Gtk::HBox(false, 0));
   Gtk::Frame *frame34 = manage(new class Gtk::Frame("Preis �berschreiben mit ..."));
   rtree_daten = new class SimpleTree(7, 3);
   
   Gtk::ScrolledWindow *scrolledwindow19 = manage(new class Gtk::ScrolledWindow());
   Gtk::VBox *vbox17 = manage(new class Gtk::VBox(false, 0));
   rng_notiz = manage(new class Gtk::Text());
   
   Gtk::ScrolledWindow *scrolledwindow13 = manage(new class Gtk::ScrolledWindow());
   Gtk::Toolbar *toolbar15 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::HBox *hbox20 = manage(new class Gtk::HBox(false, 0));
   Gtk::Frame *frame29 = manage(new class Gtk::Frame("Notiz"));
   Gtk::VPaned *vpaned1 = manage(new class Gtk::VPaned());
   frame_rechnungsdaten = manage(new class Gtk::Frame("Rechnungsdaten"));
   
   Gtk::Label *label111 = manage(new class Gtk::Label("Warenwert"));
   label_waehrung1 = manage(new class Gtk::Label("-"));
   label_waehrung2 = manage(new class Gtk::Label("-"));
   
   Gtk::Adjustment *rgbetrag_warenwert_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_warenwert = manage(new class Gtk::SpinButton(*rgbetrag_warenwert_adj, 1, 2));
   
   Gtk::Label *label112 = manage(new class Gtk::Label("Betrag"));
   Gtk::Adjustment *rgbetrag_netto_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_netto = manage(new class Gtk::SpinButton(*rgbetrag_netto_adj, 1, 2));
   
   Gtk::Label *label113 = manage(new class Gtk::Label("- Rabatt"));
   Gtk::Label *label114 = manage(new class Gtk::Label("+ MwSt."));
   Gtk::Label *label115 = manage(new class Gtk::Label("Endbetrag"));
   label_waehrung6 = manage(new class Gtk::Label("-"));
   label_waehrung7 = manage(new class Gtk::Label("-"));
   
   Gtk::Adjustment *rgbetrag_rabatt_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_rabatt = manage(new class Gtk::SpinButton(*rgbetrag_rabatt_adj, 1, 2));
   
   Gtk::Adjustment *rgbetrag_mwst_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_mwst = manage(new class Gtk::SpinButton(*rgbetrag_mwst_adj, 1, 2));
   
   Gtk::Adjustment *rgbetrag_endsumme_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_endsumme = manage(new class Gtk::SpinButton(*rgbetrag_endsumme_adj, 1, 2));
   
   Gtk::Label *label116 = manage(new class Gtk::Label("Zus./Abs."));
   Gtk::Label *label117 = manage(new class Gtk::Label("Summe"));
   label_waehrung3 = manage(new class Gtk::Label("-"));
   label_waehrung4 = manage(new class Gtk::Label("-"));
   label_waehrung5 = manage(new class Gtk::Label("-"));
   
   Gtk::Adjustment *rgbetrag_zusabs_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_zusabs = manage(new class Gtk::SpinButton(*rgbetrag_zusabs_adj, 1, 2));
   
   Gtk::Adjustment *rgbetrag_zwsumme_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   rgbetrag_zwsumme = manage(new class Gtk::SpinButton(*rgbetrag_zwsumme_adj, 1, 2));
   
   Gtk::Table *table28 = manage(new class Gtk::Table(7, 3, false));
   Gtk::Frame *frame54 = manage(new class Gtk::Frame("Rechnungsbetrag"));
   Gtk::HBox *hbox33 = manage(new class Gtk::HBox(false, 0));
   Gtk::VBox *vbox14 = manage(new class Gtk::VBox(false, 0));
   lieferscheinnr = manage(new class Gtk::Entry());
   lieferscheindatum = new class Datewin();
   
   Gtk::Label *label63 = manage(new class Gtk::Label("Liefer.Nr."));
   Gtk::Label *label71 = manage(new class Gtk::Label("Liefer. Datum"));
   Gtk::Toolbar *toolbar14 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Toolbar *toolbar8 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Table *table11 = manage(new class Gtk::Table(1, 7, false));
   rtree_offen = new class SimpleTree(4, 4);
   
   Gtk::ScrolledWindow *scrolledwindow7 = manage(new class Gtk::ScrolledWindow());
   vbox_n_b_lieferscheine = manage(new class Gtk::VBox(false, 0));
   
   Gtk::Frame *frame9 = manage(new class Gtk::Frame("nicht berechnete Lieferscheine"));
   Gtk::VBox *vbox13 = manage(new class Gtk::VBox(false, 0));
   {  static GnomeUIInfo menuitem1_menu_uiinfo[] = 
      {       GNOMEUIINFO_MENU_CLOSE_ITEM(0, 0), 
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo bearbeiten1_menu_uiinfo[] = 
      {       { GNOME_APP_UI_ITEM, "Gutschrift", 0,  0, 0, 0, GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_PREF,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_ITEM, "Storno", 0,  0, 0, 0, GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_TRASH,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_ITEM, "Provisionierung", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo menubar3_uiinfo[] = 
      {       GNOMEUIINFO_MENU_FILE_TREE(menuitem1_menu_uiinfo),
	      GNOMEUIINFO_MENU_EDIT_TREE(bearbeiten1_menu_uiinfo),
	      GNOMEUIINFO_END 
      };
      gnome_app_fill_menu(GTK_MENU_SHELL(menubar3->gtkobj()), menubar3_uiinfo, gmm_data->getAccelGroup()->gtkobj(), true, 0);
      pixmapmenuitem1 = Gtk::wrap(GTK_MENU_ITEM(menuitem1_menu_uiinfo[0].widget));
      gutschrift = Gtk::wrap(GTK_MENU_ITEM(bearbeiten1_menu_uiinfo[0].widget));
      trennlinie11 = Gtk::wrap(GTK_MENU_ITEM(bearbeiten1_menu_uiinfo[1].widget));
      storno = Gtk::wrap(GTK_MENU_ITEM(bearbeiten1_menu_uiinfo[2].widget));
      trennlinie13 = Gtk::wrap(GTK_MENU_ITEM(bearbeiten1_menu_uiinfo[3].widget));
      rngprovision = Gtk::wrap(GTK_MENU_ITEM(bearbeiten1_menu_uiinfo[4].widget));
   }
   
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
   
   toolbar15->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("speichern", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SAVE)), 0));
   rng_notiz_save = static_cast<Gtk::Button *>(toolbar15->tools().back()->get_widget());
   
   toolbar14->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("offene Liefer.", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_BOOK_OPEN)), 0));
   Gtk::Button *button_allopen = static_cast<Gtk::Button *>(toolbar14->tools().back()->get_widget());
   
   toolbar14->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("leere Liefer. aufr�umen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_CLEAR)), 0));
   button_lieferscheine_aufraumen = static_cast<Gtk::Button *>(toolbar14->tools().back()->get_widget());
   
   toolbar8->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Liefer. �bernehmen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_ATTACH)), 0));
   lief_uebernehmen = static_cast<Gtk::Button *>(toolbar8->tools().back()->get_widget());
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
   bezahlt->set_flags(GTK_CAN_FOCUS);
   bezahlt->set_mode(true);
   bezahlt->set_active(false);
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
   label98->set_alignment(0,0.5);
   label98->set_padding(0,0);
   label98->set_justify(GTK_JUSTIFY_CENTER);
   label98->set_line_wrap(false);
   table23->set_row_spacings(0);
   table23->set_col_spacings(0);
   table23->attach(*rabatt_typ, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table23->attach(*rabatt_wert, 1, 2, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table23->attach(*label98, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table23->attach(*zahlziel, 1, 2, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   label_rechnung_ctl->set_alignment(0,0.5);
   label_rechnung_ctl->set_padding(0,0);
   label_rechnung_ctl->set_justify(GTK_JUSTIFY_LEFT);
   label_rechnung_ctl->set_line_wrap(false);
   table10->set_row_spacings(0);
   table10->set_col_spacings(0);
   table10->attach(*label66, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table10->attach(*label87, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table10->attach(*optionmenu_zahlart, 3, 4, 0, 1, GTK_FILL, 0, 0, 0);
   table10->attach(*rngdatum, 1, 2, 2, 3, 0, GTK_FILL, 0, 0);
   table10->attach(*rngnr, 1, 2, 1, 2, 0, 0, 0, 0);
   table10->attach(*label72, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table10->attach(*label60, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table10->attach(*label61, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table10->attach(*bezahlt, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table10->attach(*table23, 2, 4, 2, 4, GTK_FILL, 0, 0, 0);
   table10->attach(*label_rechnung_ctl, 1, 2, 3, 4, GTK_FILL, 0, 0, 0);
   table10->attach(*lieferkunde, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table10->attach(*rng_WWaehrung, 3, 4, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   frame_rechnung->set_border_width(5);
   frame_rechnung->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_rechnung->set_label_align(0,0);
   frame_rechnung->add(*table10);
   radiobutton_artikelpreis->set_sensitive(false);
   radiobutton_artikelpreis->set_flags(GTK_CAN_FOCUS);
   radiobutton_artikelpreis->set_mode(true);
   radiobutton_artikelpreis->set_active(true);
   label_artikelpreis->set_alignment(0.5,0.5);
   label_artikelpreis->set_padding(0,0);
   label_artikelpreis->set_justify(GTK_JUSTIFY_CENTER);
   label_artikelpreis->set_line_wrap(false);
   hbox24->pack_start(*radiobutton_artikelpreis, false, false, 0);
   hbox24->pack_start(*label_artikelpreis, false, false, 0);
   radiobutton_auftragspreis->set_sensitive(false);
   radiobutton_auftragspreis->set_flags(GTK_CAN_FOCUS);
   radiobutton_auftragspreis->set_mode(true);
   radiobutton_auftragspreis->set_active(false);
   label_auftragspreis->set_alignment(0.5,0.5);
   label_auftragspreis->set_padding(0,0);
   label_auftragspreis->set_justify(GTK_JUSTIFY_CENTER);
   label_auftragspreis->set_line_wrap(false);
   hbox25->pack_start(*radiobutton_auftragspreis, false, false, 0);
   hbox25->pack_start(*label_auftragspreis, false, false, 0);
   radiobutton_preiseingabe->set_sensitive(false);
   radiobutton_preiseingabe->set_flags(GTK_CAN_FOCUS);
   radiobutton_preiseingabe->set_mode(true);
   radiobutton_preiseingabe->set_active(false);
   spinbutton_preiseingabe->set_usize(70,-1);
   spinbutton_preiseingabe->set_sensitive(false);
   spinbutton_preiseingabe->set_flags(GTK_CAN_FOCUS);
   spinbutton_preiseingabe->set_update_policy(GTK_UPDATE_ALWAYS);
   spinbutton_preiseingabe->set_numeric(false);
   spinbutton_preiseingabe->set_digits(2);
   spinbutton_preiseingabe->set_wrap(false);
   spinbutton_preiseingabe->set_snap_to_ticks(false);
   hbox26->pack_start(*radiobutton_preiseingabe, false, false, 0);
   hbox26->pack_start(*spinbutton_preiseingabe, false, false, 0);
   button_pr->set_sensitive(false);
   button_pr->set_relief(GTK_RELIEF_NORMAL);
   hbox23->pack_start(*hbox24, false, false, 30);
   hbox23->pack_start(*hbox25, false, false, 30);
   hbox23->pack_start(*hbox26, false, false, 30);
   hbox23->pack_start(*button_pr, true, false, 0);
   frame34->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame34->set_label_align(0,0);
   frame34->add(*hbox23);
   scrolledwindow19->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow19->add(*rtree_daten);
   vbox17->pack_start(*frame34, false, false, 0);
   vbox17->pack_start(*scrolledwindow19);
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
   vpaned1->pack1(*vbox17, false, true);
   vpaned1->pack2(*frame29, true, true);
   frame_rechnungsdaten->set_border_width(3);
   frame_rechnungsdaten->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_rechnungsdaten->set_label_align(0,0);
   frame_rechnungsdaten->add(*vpaned1);
   label111->set_alignment(1,0.5);
   label111->set_padding(3,0);
   label111->set_justify(GTK_JUSTIFY_CENTER);
   label111->set_line_wrap(false);
   label_waehrung1->set_usize(25,-1);
   label_waehrung1->set_alignment(0,0.5);
   label_waehrung1->set_padding(0,0);
   label_waehrung1->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung1->set_line_wrap(false);
   label_waehrung2->set_alignment(0,0.5);
   label_waehrung2->set_padding(0,0);
   label_waehrung2->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung2->set_line_wrap(false);
   rgbetrag_warenwert->set_usize(80,-1);
   rgbetrag_warenwert->set_sensitive(false);
   rgbetrag_warenwert->set_flags(GTK_CAN_FOCUS);
   rgbetrag_warenwert->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_warenwert->set_numeric(true);
   rgbetrag_warenwert->set_digits(2);
   rgbetrag_warenwert->set_wrap(false);
   rgbetrag_warenwert->set_snap_to_ticks(false);
   label112->set_alignment(1,0.5);
   label112->set_padding(3,0);
   label112->set_justify(GTK_JUSTIFY_CENTER);
   label112->set_line_wrap(false);
   rgbetrag_netto->set_usize(80,-1);
   rgbetrag_netto->set_sensitive(false);
   rgbetrag_netto->set_flags(GTK_CAN_FOCUS);
   rgbetrag_netto->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_netto->set_numeric(true);
   rgbetrag_netto->set_digits(2);
   rgbetrag_netto->set_wrap(false);
   rgbetrag_netto->set_snap_to_ticks(false);
   label113->set_alignment(1,0.5);
   label113->set_padding(3,0);
   label113->set_justify(GTK_JUSTIFY_CENTER);
   label113->set_line_wrap(false);
   label114->set_alignment(1,0.5);
   label114->set_padding(2,0);
   label114->set_justify(GTK_JUSTIFY_CENTER);
   label114->set_line_wrap(false);
   label115->set_alignment(1,0.5);
   label115->set_padding(3,0);
   label115->set_justify(GTK_JUSTIFY_CENTER);
   label115->set_line_wrap(false);
   label_waehrung6->set_alignment(0,0.5);
   label_waehrung6->set_padding(0,0);
   label_waehrung6->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung6->set_line_wrap(false);
   label_waehrung7->set_alignment(0,0.5);
   label_waehrung7->set_padding(0,0);
   label_waehrung7->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung7->set_line_wrap(false);
   rgbetrag_rabatt->set_usize(80,-1);
   rgbetrag_rabatt->set_sensitive(false);
   rgbetrag_rabatt->set_flags(GTK_CAN_FOCUS);
   rgbetrag_rabatt->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_rabatt->set_numeric(true);
   rgbetrag_rabatt->set_digits(2);
   rgbetrag_rabatt->set_wrap(false);
   rgbetrag_rabatt->set_snap_to_ticks(false);
   rgbetrag_mwst->set_usize(80,-1);
   rgbetrag_mwst->set_sensitive(false);
   rgbetrag_mwst->set_flags(GTK_CAN_FOCUS);
   rgbetrag_mwst->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_mwst->set_numeric(true);
   rgbetrag_mwst->set_digits(2);
   rgbetrag_mwst->set_wrap(false);
   rgbetrag_mwst->set_snap_to_ticks(false);
   rgbetrag_endsumme->set_usize(80,-1);
   rgbetrag_endsumme->set_sensitive(false);
   rgbetrag_endsumme->set_flags(GTK_CAN_FOCUS);
   rgbetrag_endsumme->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_endsumme->set_numeric(true);
   rgbetrag_endsumme->set_digits(2);
   rgbetrag_endsumme->set_wrap(false);
   rgbetrag_endsumme->set_snap_to_ticks(false);
   label116->set_alignment(1,0.5);
   label116->set_padding(3,0);
   label116->set_justify(GTK_JUSTIFY_CENTER);
   label116->set_line_wrap(false);
   label117->set_alignment(1,0.5);
   label117->set_padding(3,0);
   label117->set_justify(GTK_JUSTIFY_CENTER);
   label117->set_line_wrap(false);
   label_waehrung3->set_alignment(0,0.5);
   label_waehrung3->set_padding(0,0);
   label_waehrung3->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung3->set_line_wrap(false);
   label_waehrung4->set_alignment(0,0.5);
   label_waehrung4->set_padding(0,0);
   label_waehrung4->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung4->set_line_wrap(false);
   label_waehrung5->set_alignment(0,0.5);
   label_waehrung5->set_padding(0,0);
   label_waehrung5->set_justify(GTK_JUSTIFY_CENTER);
   label_waehrung5->set_line_wrap(false);
   rgbetrag_zusabs->set_usize(80,-1);
   rgbetrag_zusabs->set_sensitive(false);
   rgbetrag_zusabs->set_flags(GTK_CAN_FOCUS);
   rgbetrag_zusabs->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_zusabs->set_numeric(true);
   rgbetrag_zusabs->set_digits(2);
   rgbetrag_zusabs->set_wrap(false);
   rgbetrag_zusabs->set_snap_to_ticks(false);
   rgbetrag_zwsumme->set_usize(80,-1);
   rgbetrag_zwsumme->set_sensitive(false);
   rgbetrag_zwsumme->set_flags(GTK_CAN_FOCUS);
   rgbetrag_zwsumme->set_update_policy(GTK_UPDATE_ALWAYS);
   rgbetrag_zwsumme->set_numeric(true);
   rgbetrag_zwsumme->set_digits(2);
   rgbetrag_zwsumme->set_wrap(false);
   rgbetrag_zwsumme->set_snap_to_ticks(false);
   table28->set_row_spacings(0);
   table28->set_col_spacings(0);
   table28->attach(*label111, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung1, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung2, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table28->attach(*rgbetrag_warenwert, 1, 2, 0, 1, 0, 0, 0, 0);
   table28->attach(*label112, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table28->attach(*rgbetrag_netto, 1, 2, 2, 3, 0, 0, 0, 0);
   table28->attach(*label113, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table28->attach(*label114, 0, 1, 5, 6, GTK_FILL, 0, 0, 0);
   table28->attach(*label115, 0, 1, 6, 7, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung6, 2, 3, 5, 6, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung7, 2, 3, 6, 7, GTK_FILL, 0, 0, 0);
   table28->attach(*rgbetrag_rabatt, 1, 2, 1, 2, 0, 0, 0, 0);
   table28->attach(*rgbetrag_mwst, 1, 2, 5, 6, 0, 0, 0, 0);
   table28->attach(*rgbetrag_endsumme, 1, 2, 6, 7, 0, 0, 0, 0);
   table28->attach(*label116, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table28->attach(*label117, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung3, 2, 3, 2, 3, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung4, 2, 3, 3, 4, GTK_FILL, 0, 0, 0);
   table28->attach(*label_waehrung5, 2, 3, 4, 5, GTK_FILL, 0, 0, 0);
   table28->attach(*rgbetrag_zusabs, 1, 2, 3, 4, 0, 0, 0, 0);
   table28->attach(*rgbetrag_zwsumme, 1, 2, 4, 5, 0, 0, 0, 0);
   frame54->set_usize(180,-1);
   frame54->set_border_width(3);
   frame54->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame54->set_label_align(0,0);
   frame54->add(*table28);
   hbox33->pack_start(*frame_rechnungsdaten);
   hbox33->pack_start(*frame54, false, true, 0);
   vbox14->pack_start(*toolbar7, false, false, 0);
   vbox14->pack_start(*frame_rechnung, false, false, 0);
   vbox14->pack_start(*hbox33);
   lieferscheinnr->set_usize(100,-1);
   lieferscheinnr->set_flags(GTK_CAN_FOCUS);
   lieferscheinnr->set_visibility(true);
   lieferscheinnr->set_editable(false);
   lieferscheinnr->set_text("");
   label63->set_alignment(0,0.5);
   label63->set_padding(0,0);
   label63->set_justify(GTK_JUSTIFY_LEFT);
   label63->set_line_wrap(false);
   label71->set_alignment(0,0.5);
   label71->set_padding(0,0);
   label71->set_justify(GTK_JUSTIFY_CENTER);
   label71->set_line_wrap(false);
   toolbar14->set_space_size(5);
   toolbar14->set_tooltips(true);
   toolbar14->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   lief_uebernehmen->set_sensitive(false);
   _tooltips.set_tip(*lief_uebernehmen, "Kompletten Auftrag in Lieferschein �bernehmen", "");
   toolbar8->set_space_size(5);
   toolbar8->set_tooltips(true);
   toolbar8->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   table11->set_border_width(5);
   table11->set_row_spacings(0);
   table11->set_col_spacings(1);
   table11->attach(*lieferscheinnr, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table11->attach(*lieferscheindatum, 3, 4, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table11->attach(*label63, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table11->attach(*label71, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table11->attach(*toolbar14, 6, 7, 0, 1, GTK_FILL, 0, 0, 0);
   table11->attach(*toolbar8, 4, 5, 0, 1, GTK_FILL, 0, 0, 0);
   scrolledwindow7->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow7->add(*rtree_offen);
   vbox_n_b_lieferscheine->pack_start(*table11, false, true, 0);
   vbox_n_b_lieferscheine->pack_start(*scrolledwindow7);
   frame9->set_border_width(5);
   frame9->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame9->set_label_align(0,0);
   frame9->add(*vbox_n_b_lieferscheine);
   vbox13->pack_start(*menubar3, false, false, 0);
   vbox13->pack_start(*vbox14, false, true, 0);
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
   toolbar7->show();
   label66->show();
   label87->show();
   optionmenu_zahlart->show();
   rngdatum->show();
   rngnr->show();
   label72->show();
   label60->show();
   label61->show();
   bezahlt->show();
   rabatt_typ->show();
   rabatt_wert->show();
   label98->show();
   zahlziel->show();
   table23->show();
   label_rechnung_ctl->show();
   lieferkunde->show();
   rng_WWaehrung->show();
   table10->show();
   frame_rechnung->show();
   radiobutton_artikelpreis->show();
   label_artikelpreis->show();
   hbox24->show();
   radiobutton_auftragspreis->show();
   label_auftragspreis->show();
   hbox25->show();
   radiobutton_preiseingabe->show();
   spinbutton_preiseingabe->show();
   hbox26->show();
   button_pr->show();
   hbox23->show();
   frame34->show();
   rtree_daten->show();
   scrolledwindow19->show();
   vbox17->show();
   rng_notiz->show();
   scrolledwindow13->show();
   toolbar15->show();
   hbox20->show();
   frame29->show();
   vpaned1->show();
   frame_rechnungsdaten->show();
   label111->show();
   label_waehrung1->show();
   label_waehrung2->show();
   rgbetrag_warenwert->show();
   label112->show();
   rgbetrag_netto->show();
   label113->show();
   label114->show();
   label115->show();
   label_waehrung6->show();
   label_waehrung7->show();
   rgbetrag_rabatt->show();
   rgbetrag_mwst->show();
   rgbetrag_endsumme->show();
   label116->show();
   label117->show();
   label_waehrung3->show();
   label_waehrung4->show();
   label_waehrung5->show();
   rgbetrag_zusabs->show();
   rgbetrag_zwsumme->show();
   table28->show();
   frame54->show();
   hbox33->show();
   vbox14->show();
   lieferscheinnr->show();
   lieferscheindatum->show();
   label63->show();
   label71->show();
   toolbar14->show();
   toolbar8->show();
   table11->show();
   rtree_offen->show();
   scrolledwindow7->show();
   vbox_n_b_lieferscheine->show();
   frame9->show();
   vbox13->show();
   auftrag_rechnung->show();
   pixmapmenuitem1->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_close));
   gutschrift->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_gutschrift_activate));
   storno->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_storno_activate));
   rngprovision->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_provisionierung_activate));
   button23->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_close));
   button24->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_neu));
   button25->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_save));
   button26->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_preview));
   button27->button_press_event.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rng_print));
   checkbutton_ean_drucken->clicked.connect_after(SigC::slot(this, &auftrag_rechnung_glade::on_checkbutton_ean_drucken_clicked));
   preis_ergaenzen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::Preis_ergaenzen));
   rngentry_del->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::rngzeile_delete));
   optionmenu_zahlart->get_menu()->deactivate.connect(SigC::slot(this, &auftrag_rechnung_glade::optionmenu_zahlart_deactivate));
   rngdatum->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rngdate_activate));
   rngnr->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rngnr_activate));
   rngnr->search.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rngnr_search));
   bezahlt->button_release_event.connect_after(SigC::slot(this, &auftrag_rechnung_glade::on_bezahlt_toggled));
   rabatt_typ->get_menu()->deactivate.connect(SigC::slot(this, &auftrag_rechnung_glade::rabatt_geaendert));
   rabatt_wert->activate.connect_after(SigC::slot(this, &auftrag_rechnung_glade::rabatt_geaendert));
   zahlziel->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_zahlziel_activate));
   lieferkunde->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::on_lieferkunde_activate));
   rng_WWaehrung->activate.connect(SigC::slot(this, &auftrag_rechnung_glade::waehrung_geaendert));
   radiobutton_preiseingabe->toggled.connect(SigC::slot(this, &auftrag_rechnung_glade::on_radiobutton_preiseingabe_toggled));
   button_pr->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::Preis_setzen));
   rtree_daten->leaf_selected.connect(SigC::slot(this, &auftrag_rechnung_glade::on_rdaten_leaf_selected));
   rtree_daten->unselect_row.connect(SigC::slot(this, &auftrag_rechnung_glade::on_unselectrow_rtree));
   rng_notiz->changed.connect(SigC::slot(this, &auftrag_rechnung_glade::on_notiz_changed));
   rng_notiz_save->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_notiz_save_clicked));
   button_allopen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_allopen_clicked));
   button_lieferscheine_aufraumen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::on_button_lieferscheine_aufraumen_clicked));
   lief_uebernehmen->clicked.connect(SigC::slot(this, &auftrag_rechnung_glade::lieferschein_uebernehmen));
   rtree_offen->unselect_row.connect(SigC::slot(this, &auftrag_rechnung_glade::on_unselectrow_rtree_offen));
   rtree_offen->leaf_selected.connect(SigC::slot(this, &auftrag_rechnung_glade::on_roffen_leaf_selected));
}

auftrag_rechnung_glade::~auftrag_rechnung_glade()
{  delete rngdatum;
   delete rngnr;
   delete zahlziel;
   delete lieferkunde;
   delete rng_WWaehrung;
   delete rtree_daten;
   delete lieferscheindatum;
   delete rtree_offen;
   delete gmm_data;
}
