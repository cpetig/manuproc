// generated 2003/3/19 12:54:50 MET by jacek@ijacek.jacek.de
// using glademm V1.1.3e_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/Artikeleingabe/artikeleingabe.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/Artikeleingabe.cc

#include "config.h"
#include "Artikeleingabe.hh"
#include <gtk--/button.h>
#include <libgnomeui/gnome-stock.h>
#include <gtk--/toolbar.h>
#include <gtk--/box.h>
#include <gtk--/frame.h>
#include <gtk--/table.h>
#include <gtk--/label.h>
#include "../src/stock_button_cancel.xpm"
#include <gtk--/adjustment.h>
#include <gtk--/separator.h>
#include <gtk--/scrolledwindow.h>

Artikeleingabe_glade::Artikeleingabe_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *Artikeleingabe = this;
   Gtk::Toolbar *toolbar1 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   label_warnung = manage(new class Gtk::Label(""));
   
   Gtk::HBox *hbox3 = manage(new class Gtk::HBox(false, 0));
   artikelbox = new class ArtikelBox(1);
   artikelbox_neu = new class ArtikelBox(1);
   was_tun = new class WasTun();
   standard_instanz = new class Optionmenu_Instanz(Optionmenu_Instanz::allesAnzeigen);
   
   Gtk::Frame *frame1 = manage(new class Gtk::Frame("Wird bestellt bei"));
   no_instanz = manage(new class Gtk::CheckButton("keine Instanz", 0, 0.5));
   standard_einheit = new class Optionmenu_Einheit();
   
   Gtk::Frame *frame2 = manage(new class Gtk::Frame("Einheit"));
   Gtk::Table *table6 = manage(new class Gtk::Table(4, 2, false));
   Gtk::Label *label13 = manage(new class Gtk::Label("Neu"));
   OM_Einheit = new class Optionmenu_Einheit();
   
   Gtk::Label *label18 = manage(new class Gtk::Label("Einheit"));
   eingabebox = new class EingabeBox();
   pixmap_edit = manage(new class Gtk::Pixmap(stock_button_cancel_xpm));
   
   Gtk::HBox *hbox2 = manage(new class Gtk::HBox(false, 0));
   Gtk::Frame *frame4 = manage(new class Gtk::Frame("Bezeichnung �ndern"));
   alias_warengruppe = new class Optionmenu_Warengruppe(1);
   alias_schema = new class KundenBox();
   alias_eingabe = new class EingabeBox();
   alias_pixmap = manage(new class Gtk::Pixmap(stock_button_cancel_xpm));
   
   Gtk::HBox *hbox1 = manage(new class Gtk::HBox(false, 2));
   Gtk::Frame *frame5 = manage(new class Gtk::Frame("gleicher Artikel in anderem Bezeichnungsschema"));
   Gtk::Label *label9 = manage(new class Gtk::Label("Wird bestellt bei"));
   Artikel_Bestellen_bei = new class Optionmenu_Instanz(Optionmenu_Instanz::allesAnzeigen);
   change_no_instanz = manage(new class Gtk::CheckButton("keine Instanz", 0, 0.5));
   show_in_prlist = manage(new class Gtk::CheckButton("in den Preislisten anzeigen", 0, 0.5));
   mindbest_check = manage(new class Gtk::CheckButton("pr�fen", 0, 0.5));
   
   Gtk::Adjustment *mindbestand_adj = manage(new class Gtk::Adjustment(0, 0, 100, 1, 10, 10));
   mindbestand = manage(new class Gtk::SpinButton(*mindbestand_adj, 1, 0));
   
   Gtk::HBox *hbox4 = manage(new class Gtk::HBox(false, 0));
   Gtk::Frame *frame6 = manage(new class Gtk::Frame("Mindestbestand"));
   Gtk::Table *table7 = manage(new class Gtk::Table(4, 4, false));
   Gtk::Label *label14 = manage(new class Gtk::Label("�ndern"));
   Gtk::Label *label4 = manage(new class Gtk::Label("entsteht aus  "));
   Gtk::VSeparator *vseparator3 = manage(new class Gtk::VSeparator());
   toolbar_loeschen = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   artikelboxb = new class Artikel_Bestellen();
   table_artikelherkunft = manage(new class Gtk::Table(2, 3, false));
   
   Gtk::Label *label15 = manage(new class Gtk::Label("Zusammensetzung"));
   Gtk::Label *label1 = manage(new class Gtk::Label("Zeige Artikel der Instanz"));
   checkbutton_offene_auftraege = manage(new class Gtk::CheckButton("Nur Artikel in offenen\n"
		"Auftr�gen anzeigen", 0, 0.5));
   optionmenu_instanz = new class Optionmenu_Instanz(Optionmenu_Instanz::allesAnzeigen);
   progressbar = manage(new class Gtk::ProgressBar());
   
   Gtk::Table *table9 = manage(new class Gtk::Table(3, 2, false));
   Gtk::Label *label16 = manage(new class Gtk::Label("�bersicht"));
   Gtk::Toolbar *toolbar2 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   artbox_verschmelzen = new class ArtikelBox(1);
   
   Gtk::Label *label11 = manage(new class Gtk::Label("(Dieser Artikel wird in den oben angegebenen Umbenannt)"));
   table_verschmelzen = manage(new class Gtk::Table(2, 2, false));
   
   Gtk::Table *table3 = manage(new class Gtk::Table(1, 3, false));
   Gtk::Label *label17 = manage(new class Gtk::Label(""));
   top_notebook = manage(new class Gtk::Notebook());
   tree = new class SimpleTree(MAXCOLUMN,0);
   
   Gtk::ScrolledWindow *scrolledwindow1 = manage(new class Gtk::ScrolledWindow());
   Gtk::VBox *vbox2 = manage(new class Gtk::VBox(false, 0));
   
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Beenden", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_EXIT)), 0));
   Gtk::Button *button_close = static_cast<Gtk::Button *>(toolbar1->tools().back()->get_widget());
   
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_PRINT)), 0));
   Gtk::Button *button_drucken = static_cast<Gtk::Button *>(toolbar1->tools().back()->get_widget());
   
   toolbar_loeschen->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("TEXT\n"
		"", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_NOT)), 0));
   button_artikel_delete = static_cast<Gtk::Button *>(toolbar_loeschen->tools().back()->get_widget());
   toolbar_loeschen->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar_loeschen->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Artikel\n"
		"wechsel", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_FORWARD)), 0));
   button_artikel_wechsel = static_cast<Gtk::Button *>(toolbar_loeschen->tools().back()->get_widget());
   
   toolbar2->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Verschmelzen", *Gtk::wrap(gnome_stock_pixmap_widget(GTK_WIDGET(gtkobj()), GNOME_STOCK_PIXMAP_CONVERT)), 0));
   Gtk::Button *button_verschmelzen = static_cast<Gtk::Button *>(toolbar2->tools().back()->get_widget());
   toolbar1->set_space_size(5);
   toolbar1->set_tooltips(true);
   toolbar1->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   label_warnung->set_alignment(0,0.5);
   label_warnung->set_padding(0,0);
   label_warnung->set_justify(GTK_JUSTIFY_CENTER);
   label_warnung->set_line_wrap(false);
   hbox3->pack_start(*toolbar1, false, false, 0);
   hbox3->pack_start(*label_warnung, false, false, 0);
   artikelbox->set_sensitive(false);
   standard_instanz->set_sensitive(false);
   frame1->set_shadow_type(GTK_SHADOW_NONE);
   frame1->set_label_align(0,0);
   frame1->add(*standard_instanz);
   no_instanz->set_flags(GTK_CAN_FOCUS);
   no_instanz->set_mode(true);
   no_instanz->set_active(true);
   frame2->set_shadow_type(GTK_SHADOW_NONE);
   frame2->set_label_align(0,0);
   frame2->add(*standard_einheit);
   table6->set_row_spacings(0);
   table6->set_col_spacings(0);
   table6->attach(*artikelbox_neu, 0, 2, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
   table6->attach(*was_tun, 0, 2, 0, 1, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table6->attach(*frame1, 0, 1, 2, 3, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table6->attach(*no_instanz, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table6->attach(*frame2, 1, 2, 2, 3, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   label13->set_alignment(0.5,0.5);
   label13->set_padding(0,0);
   label13->set_justify(GTK_JUSTIFY_CENTER);
   label13->set_line_wrap(false);
   label18->set_alignment(0,0.5);
   label18->set_padding(0,0);
   label18->set_justify(GTK_JUSTIFY_CENTER);
   label18->set_line_wrap(false);
   pixmap_edit->set_alignment(0.5,0.5);
   pixmap_edit->set_padding(0,0);
   hbox2->pack_start(*eingabebox);
   hbox2->pack_start(*pixmap_edit, false, true, 0);
   frame4->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame4->set_label_align(0,0);
   frame4->add(*hbox2);
   alias_pixmap->set_alignment(0.5,0.5);
   alias_pixmap->set_padding(0,0);
   hbox1->pack_start(*alias_warengruppe, false, true, 0);
   hbox1->pack_start(*alias_schema, false, true, 0);
   hbox1->pack_start(*alias_eingabe);
   hbox1->pack_start(*alias_pixmap, false, true, 0);
   frame5->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame5->set_label_align(0,0);
   frame5->add(*hbox1);
   label9->set_alignment(0,0.5);
   label9->set_padding(0,0);
   label9->set_justify(GTK_JUSTIFY_CENTER);
   label9->set_line_wrap(false);
   change_no_instanz->set_flags(GTK_CAN_FOCUS);
   change_no_instanz->set_mode(true);
   change_no_instanz->set_active(true);
   show_in_prlist->set_flags(GTK_CAN_FOCUS);
   show_in_prlist->set_mode(true);
   show_in_prlist->set_active(true);
   mindbest_check->set_flags(GTK_CAN_FOCUS);
   mindbest_check->set_mode(true);
   mindbest_check->set_active(true);
   mindbestand->set_flags(GTK_CAN_FOCUS);
   mindbestand->set_update_policy(GTK_UPDATE_ALWAYS);
   mindbestand->set_numeric(false);
   mindbestand->set_digits(0);
   mindbestand->set_wrap(false);
   mindbestand->set_snap_to_ticks(false);
   hbox4->pack_start(*mindbest_check, false, false, 0);
   hbox4->pack_start(*mindbestand);
   frame6->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame6->set_label_align(0,0);
   frame6->add(*hbox4);
   table7->set_row_spacings(0);
   table7->set_col_spacings(0);
   table7->attach(*OM_Einheit, 2, 3, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table7->attach(*label18, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table7->attach(*frame4, 0, 4, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
   table7->attach(*frame5, 0, 4, 3, 4, GTK_SHRINK|GTK_FILL, GTK_FILL, 0, 0);
   table7->attach(*label9, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table7->attach(*Artikel_Bestellen_bei, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table7->attach(*change_no_instanz, 0, 1, 0, 2, GTK_FILL, 0, 0, 0);
   table7->attach(*show_in_prlist, 3, 4, 0, 1, GTK_FILL, 0, 0, 0);
   table7->attach(*frame6, 3, 4, 1, 2, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   label14->set_alignment(0.5,0.5);
   label14->set_padding(0,0);
   label14->set_justify(GTK_JUSTIFY_CENTER);
   label14->set_line_wrap(false);
   label4->set_alignment(0,0.5);
   label4->set_padding(0,0);
   label4->set_justify(GTK_JUSTIFY_CENTER);
   label4->set_line_wrap(false);
   toolbar_loeschen->set_border_width(5);
   toolbar_loeschen->set_space_size(5);
   toolbar_loeschen->set_tooltips(true);
   toolbar_loeschen->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   table_artikelherkunft->set_row_spacings(0);
   table_artikelherkunft->set_col_spacings(0);
   table_artikelherkunft->attach(*label4, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikelherkunft->attach(*vseparator3, 1, 2, 0, 2, GTK_FILL, GTK_FILL, 3, 0);
   table_artikelherkunft->attach(*toolbar_loeschen, 2, 3, 0, 2, GTK_FILL, 0, 0, 0);
   table_artikelherkunft->attach(*artikelboxb, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   label15->set_alignment(0.5,0.5);
   label15->set_padding(0,0);
   label15->set_justify(GTK_JUSTIFY_CENTER);
   label15->set_line_wrap(false);
   label1->set_alignment(0,0.5);
   label1->set_padding(0,0);
   label1->set_justify(GTK_JUSTIFY_CENTER);
   label1->set_line_wrap(false);
   checkbutton_offene_auftraege->set_flags(GTK_CAN_FOCUS);
   checkbutton_offene_auftraege->set_mode(true);
   checkbutton_offene_auftraege->set_active(false);
   table9->set_row_spacings(0);
   table9->set_col_spacings(0);
   table9->attach(*label1, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table9->attach(*checkbutton_offene_auftraege, 0, 1, 0, 2, GTK_FILL, 0, 0, 0);
   table9->attach(*optionmenu_instanz, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table9->attach(*progressbar, 0, 2, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   label16->set_alignment(0.5,0.5);
   label16->set_padding(0,0);
   label16->set_justify(GTK_JUSTIFY_CENTER);
   label16->set_line_wrap(false);
   toolbar2->set_space_size(5);
   toolbar2->set_tooltips(true);
   toolbar2->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   label11->set_alignment(0,0.5);
   label11->set_padding(0,0);
   label11->set_justify(GTK_JUSTIFY_CENTER);
   label11->set_line_wrap(false);
   table_verschmelzen->set_row_spacings(0);
   table_verschmelzen->set_col_spacings(0);
   table_verschmelzen->attach(*toolbar2, 1, 2, 0, 2, 0, 0, 0, 0);
   table_verschmelzen->attach(*artbox_verschmelzen, 0, 1, 0, 1, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table_verschmelzen->attach(*label11, 0, 1, 1, 2, 0, GTK_SHRINK, 0, 0);
   table3->set_row_spacings(0);
   table3->set_col_spacings(0);
   table3->attach(*table_verschmelzen, 0, 3, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   label17->set_alignment(0.5,0.5);
   label17->set_padding(0,0);
   label17->set_justify(GTK_JUSTIFY_CENTER);
   label17->set_line_wrap(false);
   top_notebook->set_flags(GTK_CAN_FOCUS);
   top_notebook->set_show_tabs(true);
   top_notebook->set_show_border(true);
   top_notebook->set_tab_pos(GTK_POS_TOP);
   top_notebook->set_scrollable(false);
   top_notebook->popup_disable();
   top_notebook->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table6, *label13));
   top_notebook->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table7, *label14));
   top_notebook->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_artikelherkunft, *label15));
   top_notebook->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table9, *label16));
   top_notebook->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table3, *label17));
   scrolledwindow1->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow1->add(*tree);
   vbox2->pack_start(*hbox3, false, false, 0);
   vbox2->pack_start(*artikelbox, false, true, 0);
   vbox2->pack_start(*top_notebook, false, true, 0);
   vbox2->pack_start(*scrolledwindow1);
   Artikeleingabe->set_title("Artikeleingabe");
   Artikeleingabe->set_default_size(640,400);
   Artikeleingabe->set_modal(false);
   Artikeleingabe->set_position(GTK_WIN_POS_NONE);
   Artikeleingabe->add(*vbox2);
   toolbar1->show();
   label_warnung->show();
   hbox3->show();
   artikelbox->show();
   artikelbox_neu->show();
   was_tun->show();
   standard_instanz->show();
   frame1->show();
   no_instanz->show();
   standard_einheit->show();
   frame2->show();
   table6->show();
   label13->show();
   OM_Einheit->show();
   label18->show();
   eingabebox->show();
   pixmap_edit->show();
   hbox2->show();
   frame4->show();
   alias_warengruppe->show();
   alias_schema->show();
   alias_eingabe->show();
   alias_pixmap->show();
   hbox1->show();
   frame5->show();
   label9->show();
   Artikel_Bestellen_bei->show();
   change_no_instanz->show();
   show_in_prlist->show();
   mindbest_check->show();
   mindbestand->show();
   hbox4->show();
   frame6->show();
   table7->show();
   label14->show();
   label4->show();
   vseparator3->show();
   toolbar_loeschen->show();
   artikelboxb->show();
   table_artikelherkunft->show();
   label15->show();
   label1->show();
   checkbutton_offene_auftraege->show();
   optionmenu_instanz->show();
   progressbar->show();
   table9->show();
   label16->show();
   toolbar2->show();
   artbox_verschmelzen->show();
   label11->show();
   table_verschmelzen->show();
   label17->show();
   top_notebook->show();
   tree->show();
   scrolledwindow1->show();
   vbox2->show();
   Artikeleingabe->show();
   button_close->clicked.connect(SigC::slot(this, &Artikeleingabe_glade::on_button_close_clicked));
   button_drucken->clicked.connect(SigC::slot(this, &Artikeleingabe_glade::on_button_drucken_clicked));
   artikelbox->activate.connect(SigC::slot(this, &Artikeleingabe_glade::artikelbox_activate));
   artikelbox_neu->activate.connect(SigC::slot(this, &Artikeleingabe_glade::artikelbox_neu_activate));
   was_tun->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_was_tun_activate));
   standard_instanz->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_optionmenu_standardinstanz_activate));
   no_instanz->toggled.connect(SigC::slot(this, &Artikeleingabe_glade::on_no_instanz_toggled));
   standard_einheit->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_standard_einheit_activate));
   OM_Einheit->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_einheit_activate));
   eingabebox->activate.connect(SigC::slot(this, &Artikeleingabe_glade::eingabe_activate));
   alias_warengruppe->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_alias_warengruppe_activate));
   alias_schema->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_kunde_activate));
   alias_eingabe->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_alias_eingabe_activate));
   Artikel_Bestellen_bei->activate.connect(SigC::slot(this, &Artikeleingabe_glade::optionmenu_bestellen_bei_activate));
   change_no_instanz->toggled.connect(SigC::slot(this, &Artikeleingabe_glade::on_change_no_instanz_toggled));
   show_in_prlist->toggled.connect(SigC::slot(this, &Artikeleingabe_glade::on_show_in_prlist_toggled));
   mindbest_check->toggled.connect(SigC::slot(this, &Artikeleingabe_glade::on_mindbest_check_toggled));
   mindbestand->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_mindbestand_activate));
   button_artikel_delete->clicked.connect(SigC::slot(this, &Artikeleingabe_glade::on_button_artikel_delete_clicked));
   button_artikel_wechsel->clicked.connect(SigC::slot(this, &Artikeleingabe_glade::on_button_artikel_wechsel_clicked));
   artikelboxb->activate.connect(SigC::slot(this, &Artikeleingabe_glade::on_Artikel_Bestellen_activate));
   checkbutton_offene_auftraege->toggled.connect(SigC::slot(this, &Artikeleingabe_glade::on_checkbutton_offene_auftraege_toggled));
   optionmenu_instanz->activate.connect(SigC::slot(this, &Artikeleingabe_glade::optionmenu_instanz_activate));
   button_verschmelzen->clicked.connect(SigC::slot(this, &Artikeleingabe_glade::on_button_verschmelzen_clicked));
   artbox_verschmelzen->activate.connect(SigC::slot(this, &Artikeleingabe_glade::artikelbox_activate));
   top_notebook->switch_page.connect_after(SigC::slot(static_cast<class Artikeleingabe*>(this), &Artikeleingabe::on_notebook1_switch_page));
   tree->leaf_selected.connect(SigC::slot(this, &Artikeleingabe_glade::on_leaf_selected));
   tree->node_selected.connect(SigC::slot(this, &Artikeleingabe_glade::on_node_selected));
   tree->unselect_row.connect(SigC::slot(this, &Artikeleingabe_glade::on_unselect_row));
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
   delete optionmenu_instanz;
   delete artbox_verschmelzen;
   delete tree;
}
