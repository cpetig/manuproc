// generated 2004/3/31 12:37:17 CEST by jacek@jaceksdell.(none)
// using glademm V2.0.0b
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/lieferscheinliste.cc

#include "config.h"
#include "lieferscheinliste_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <gtk--/scrolledwindow.h>
#include <libgnomeui/gnome-stock.h>
#include <gtk--/button.h>
#include <gtk--/toolbar.h>
#include <gtk--/radiobutton.h>
#include <gtk--/box.h>
#include <gtk--/menu.h>
#include <gtk--/menuitem.h>
#include <gtk--/frame.h>
#include <gtk--/table.h>
#include <gtk--/viewport.h>

lieferscheinliste_glade::lieferscheinliste_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *lieferscheinliste = this;
   Gtk::AccelGroup *lieferscheinliste_accgrp = Gtk::AccelGroup::create();
   gmm_data = new GlademmData(lieferscheinliste_accgrp);
   tree = new class SimpleTree(12, 10);
   
   Gtk::ScrolledWindow *scrolledwindow10 = manage(new class Gtk::ScrolledWindow());
   progressbar = manage(new class Gtk::ProgressBar());
   label_anzahl = manage(new class Gtk::Label("label81"));
   
   Gtk::Toolbar *toolbar11 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::RadioButton::Group _RadioBGroup_zeit;
   radiobutton_alle_zeit_von = manage(new class Gtk::RadioButton(_RadioBGroup_zeit, "Zeige vom Anfang", 0, 0.5));
   radiobutton_nur_zeit_von = manage(new class Gtk::RadioButton(_RadioBGroup_zeit, "Zeige vom", 0, 0.5));
   Wdatum_von = new class Datewin();
   
   Gtk::VBox *fixed2 = manage(new class Gtk::VBox(false, 0));
   Gtk::RadioButton::Group _RadioBGroup_zeit_2;
   radiobutton_alle_zeit_bis = manage(new class Gtk::RadioButton(_RadioBGroup_zeit_2, "bis heute", 0, 0.5));
   radiobutton_nur_zeit_bis = manage(new class Gtk::RadioButton(_RadioBGroup_zeit_2, "bis zum", 0, 0.5));
   Wdatum_bis = new class Datewin();
   
   Gtk::VBox *fixed4 = manage(new class Gtk::VBox(false, 0));
   date_cumulate = manage(new class Gtk::OptionMenu());
   
   Gtk::VBox *vbox12 = manage(new class Gtk::VBox(false, 0));
   Gtk::Frame *frame28 = manage(new class Gtk::Frame("Kummulieren"));
   Gtk::HBox *hbox19 = manage(new class Gtk::HBox(false, 0));
   Gtk::Frame *frame27 = manage(new class Gtk::Frame("Zeitraumauswahl"));
   Gtk::RadioButton::Group _RadioBGroup_artikel;
   radiobutton_alle_artikel = manage(new class Gtk::RadioButton(_RadioBGroup_artikel, "Zeige alle Artikel", 0, 0.5));
   radiobutton_nur_artikel = manage(new class Gtk::RadioButton(_RadioBGroup_artikel, "Zeige nur Artikel", 0, 0.5));
   first_komponent = manage(new class Gtk::CheckButton("nur Art.Nr. einschränken", 0, 0.5));
   
   Gtk::HBox *hbox18 = manage(new class Gtk::HBox(false, 0));
   artikelbox = new class ArtikelBox(1);
   
   Gtk::VBox *fixed1 = manage(new class Gtk::VBox(false, 0));
   Gtk::Frame *frame26 = manage(new class Gtk::Frame("Artikelauswahl"));
   Gtk::RadioButton::Group _RadioBGroup_kunde;
   radiobutton_alle_kunden = manage(new class Gtk::RadioButton(_RadioBGroup_kunde, "alle", 0, 0.5));
   radiobutton_nur_kunde = manage(new class Gtk::RadioButton(_RadioBGroup_kunde, "einen", 0, 0.5));
   radiobutton_kundengruppe = manage(new class Gtk::RadioButton(_RadioBGroup_kunde, "Gruppe", 0, 0.5));
   
   Gtk::HBox *hbox29 = manage(new class Gtk::HBox(false, 0));
   kundenbox = new class KundenBox2();
   kundengruppe = new class Optionmenu_Kundengruppe();
   
   Gtk::HBox *hbox30 = manage(new class Gtk::HBox(false, 0));
   Gtk::VBox *fixed3 = manage(new class Gtk::VBox(false, 0));
   Gtk::Frame *frame25 = manage(new class Gtk::Frame("Kundenauswahl"));
   Gtk::Table *table15 = manage(new class Gtk::Table(1, 3, false));
   Gtk::Viewport *viewport5 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow18 = manage(new class Gtk::ScrolledWindow());
   Gtk::Table *table14 = manage(new class Gtk::Table(5, 1, false));
   
   toolbar11->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Schließen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_EXIT)), 0));
   Gtk::Button *button_close = static_cast<Gtk::Button *>(toolbar11->tools().back()->get_widget());
   
   toolbar11->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Anzeigen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_SEARCH)), 0));
   Gtk::Button *button_show = static_cast<Gtk::Button *>(toolbar11->tools().back()->get_widget());
   
   toolbar11->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_PRINT)), 0));
   Gtk::Button *button_drucken = static_cast<Gtk::Button *>(toolbar11->tools().back()->get_widget());
   scrolledwindow10->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow10->add(*tree);
   label_anzahl->set_alignment(0,0.5);
   label_anzahl->set_padding(0,0);
   label_anzahl->set_justify(GTK_JUSTIFY_CENTER);
   label_anzahl->set_line_wrap(false);
   _tooltips.set_tip(*button_drucken, "Linker Mausknopf: Sichtbaren Bereich drucken. Rechter Mausknopf: Vorher Expandieren", "");
   toolbar11->set_space_size(5);
   toolbar11->set_tooltips(true);
   toolbar11->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   radiobutton_alle_zeit_von->set_flags(GTK_CAN_FOCUS);
   radiobutton_alle_zeit_von->set_mode(true);
   radiobutton_alle_zeit_von->set_active(true);
   radiobutton_nur_zeit_von->set_flags(GTK_CAN_FOCUS);
   radiobutton_nur_zeit_von->set_mode(true);
   radiobutton_nur_zeit_von->set_active(false);
   fixed2->pack_start(*radiobutton_alle_zeit_von, false, true, 0);
   fixed2->pack_start(*radiobutton_nur_zeit_von, false, true, 0);
   fixed2->pack_start(*Wdatum_von, false, true, 0);
   radiobutton_alle_zeit_bis->set_flags(GTK_CAN_FOCUS);
   radiobutton_alle_zeit_bis->set_mode(true);
   radiobutton_alle_zeit_bis->set_active(true);
   radiobutton_nur_zeit_bis->set_flags(GTK_CAN_FOCUS);
   radiobutton_nur_zeit_bis->set_mode(true);
   radiobutton_nur_zeit_bis->set_active(false);
   fixed4->pack_start(*radiobutton_alle_zeit_bis, false, true, 0);
   fixed4->pack_start(*radiobutton_nur_zeit_bis, false, true, 0);
   fixed4->pack_start(*Wdatum_bis);
   date_cumulate->set_flags(GTK_CAN_FOCUS);
   {  
      
      Gtk::Menu *_m(manage(new Gtk::Menu()));
      Gtk::MenuItem *_mi;
      _mi = manage(new Gtk::MenuItem("Datum"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)0);
      _mi = manage(new Gtk::MenuItem("Woche"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)1);
      _mi = manage(new Gtk::MenuItem("Monat"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)2);
      _mi = manage(new Gtk::MenuItem("Quartal"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)3);
      _mi = manage(new Gtk::MenuItem("Jahr"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)4);
      date_cumulate->set_menu(*_m);
      date_cumulate->set_history(0);
   }
   vbox12->pack_start(*date_cumulate, false, false, 0);
   frame28->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame28->set_label_align(0,0);
   frame28->add(*vbox12);
   hbox19->pack_start(*fixed2, false, true, 0);
   hbox19->pack_start(*fixed4, false, true, 0);
   hbox19->pack_start(*frame28, false, false, 0);
   frame27->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame27->set_label_align(0,0);
   frame27->add(*hbox19);
   radiobutton_alle_artikel->set_flags(GTK_CAN_FOCUS);
   radiobutton_alle_artikel->set_mode(true);
   radiobutton_alle_artikel->set_active(true);
   radiobutton_nur_artikel->set_flags(GTK_CAN_FOCUS);
   radiobutton_nur_artikel->set_mode(true);
   radiobutton_nur_artikel->set_active(false);
   first_komponent->set_flags(GTK_CAN_FOCUS);
   first_komponent->set_mode(true);
   first_komponent->set_active(true);
   hbox18->pack_start(*radiobutton_nur_artikel, false, false, 0);
   hbox18->pack_start(*first_komponent, false, false, 0);
   fixed1->pack_start(*radiobutton_alle_artikel, false, true, 0);
   fixed1->pack_start(*hbox18, false, true, 0);
   fixed1->pack_start(*artikelbox);
   frame26->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame26->set_label_align(0,0);
   frame26->add(*fixed1);
   radiobutton_alle_kunden->set_flags(GTK_CAN_FOCUS);
   radiobutton_alle_kunden->set_mode(true);
   radiobutton_alle_kunden->set_active(true);
   radiobutton_nur_kunde->set_flags(GTK_CAN_FOCUS);
   radiobutton_nur_kunde->set_mode(true);
   radiobutton_nur_kunde->set_active(false);
   radiobutton_kundengruppe->set_flags(GTK_CAN_FOCUS);
   radiobutton_kundengruppe->set_mode(true);
   radiobutton_kundengruppe->set_active(false);
   hbox29->pack_start(*radiobutton_nur_kunde, false, false, 0);
   hbox29->pack_start(*radiobutton_kundengruppe, false, false, 0);
   hbox30->pack_start(*kundenbox);
   hbox30->pack_start(*kundengruppe);
   fixed3->pack_start(*radiobutton_alle_kunden, false, true, 0);
   fixed3->pack_start(*hbox29, false, true, 0);
   fixed3->pack_start(*hbox30);
   frame25->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame25->set_label_align(0,0);
   frame25->add(*fixed3);
   table15->set_row_spacings(0);
   table15->set_col_spacings(0);
   table15->attach(*frame27, 2, 3, 0, 1, 0, 0, 0, 0);
   table15->attach(*frame26, 1, 2, 0, 1, 0, 0, 0, 0);
   table15->attach(*frame25, 0, 1, 0, 1, 0, 0, 0, 0);
   viewport5->set_shadow_type(GTK_SHADOW_NONE);
   viewport5->add(*table15);
   scrolledwindow18->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_NEVER);
   scrolledwindow18->add(*viewport5);
   table14->set_row_spacings(0);
   table14->set_col_spacings(0);
   table14->attach(*scrolledwindow10, 0, 1, 4, 5, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table14->attach(*progressbar, 0, 1, 2, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   table14->attach(*label_anzahl, 0, 1, 3, 4, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   table14->attach(*toolbar11, 0, 1, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   table14->attach(*scrolledwindow18, 0, 1, 1, 2, GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   lieferscheinliste->set_title("Lieferscheinliste");
   lieferscheinliste->set_default_size(800,600);
   lieferscheinliste->set_modal(false);
   lieferscheinliste->set_position(GTK_WIN_POS_NONE);
   lieferscheinliste->set_policy(true, true, false);
   lieferscheinliste->add_accel_group(*(gmm_data->getAccelGroup()));
   lieferscheinliste->add(*table14);
   tree->show();
   scrolledwindow10->show();
   progressbar->show();
   label_anzahl->show();
   toolbar11->show();
   radiobutton_alle_zeit_von->show();
   radiobutton_nur_zeit_von->show();
   Wdatum_von->show();
   fixed2->show();
   radiobutton_alle_zeit_bis->show();
   radiobutton_nur_zeit_bis->show();
   Wdatum_bis->show();
   fixed4->show();
   date_cumulate->show();
   vbox12->show();
   frame28->show();
   hbox19->show();
   frame27->show();
   radiobutton_alle_artikel->show();
   radiobutton_nur_artikel->show();
   first_komponent->show();
   hbox18->show();
   artikelbox->show();
   fixed1->show();
   frame26->show();
   radiobutton_alle_kunden->show();
   radiobutton_nur_kunde->show();
   radiobutton_kundengruppe->show();
   hbox29->show();
   kundenbox->show();
   hbox30->show();
   fixed3->show();
   frame25->show();
   table15->show();
   viewport5->show();
   scrolledwindow18->show();
   table14->show();
   lieferscheinliste->show();
   button_close->clicked.connect(SigC::slot(this, &lieferscheinliste_glade::on_button_close_clicked));
   button_show->clicked.connect(SigC::slot(this, &lieferscheinliste_glade::on_button_show_clicked));
   button_drucken->button_release_event.connect(SigC::slot(this, &lieferscheinliste_glade::on_button_drucken_button_release_event));
   radiobutton_alle_zeit_von->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_zeit_toggled));
   radiobutton_nur_zeit_von->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_zeit_toggled));
   Wdatum_von->activate.connect(SigC::slot(this, &lieferscheinliste_glade::datum_von_activate));
   radiobutton_alle_zeit_bis->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_zeit_2_toggled));
   radiobutton_nur_zeit_bis->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_zeit_2_toggled));
   Wdatum_bis->activate.connect(SigC::slot(this, &lieferscheinliste_glade::datum_bis_activate));
   radiobutton_alle_artikel->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_artikel_toggled));
   radiobutton_nur_artikel->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_artikel_toggled));
   artikelbox->activate.connect(SigC::slot(this, &lieferscheinliste_glade::artikelbox_activate));
   radiobutton_alle_kunden->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_kunde_toggled));
   radiobutton_nur_kunde->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_kunde_toggled));
   radiobutton_kundengruppe->toggled.connect(SigC::slot(this, &lieferscheinliste_glade::on_radiobutton_kunde_toggled));
   kundenbox->activate.connect(SigC::slot(this, &lieferscheinliste_glade::kundenbox_activate));
   kundengruppe->activate.connect(SigC::slot(this, &lieferscheinliste_glade::kundengruppe_activate));
}

lieferscheinliste_glade::~lieferscheinliste_glade()
{  delete tree;
   delete Wdatum_von;
   delete Wdatum_bis;
   delete artikelbox;
   delete kundenbox;
   delete kundengruppe;
   delete gmm_data;
}
