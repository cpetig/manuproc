// generated 2001/11/16 12:11:35 CET by thoma@Tiger.
// using glademm V0.6.2b_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/petig/cvs/jacek/pps/auftrag.glade
// for gtk 1.2.8 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/auftrag_main.cc

#include "config.h"
#include "auftrag_main.hh"
#include <libgnomeui/gnome-app.h>
#include <libgnomeui/gnome-app-helper.h>
#include <gdk/gdkkeysyms.h>
#include <libgnomeui/gnome-stock.h>
#include <libgnome/libgnome.h>
#include <gtk--/button.h>
#include <gtk--/toolbar.h>
#include <gtk--/label.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/wintext.xpm"
#include <gtk--/box.h>
#include "../pixmaps/print_image.xpm"
#include <gtk--/table.h>
#include <gtk--/frame.h>
#include "../pixmaps/configure.xpm"
#include <gtk--/adjustment.h>
#include <gtk--/viewport.h>
#include <gtk--/scrolledwindow.h>
#include "../pixmaps/delete_images.xpm"

auftrag_main_glade::auftrag_main_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   auftrag_main = this;
   main_menubar = manage(new class Gtk::MenuBar());
   {   
      
      static GnomeUIInfo main_datei_menu_uiinfo[] = 
      {        GNOMEUIINFO_MENU_EXIT_ITEM(0, 0), 
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo bearbeiten_menu_uiinfo[] = 
      {        { GNOME_APP_UI_ITEM, "Erfassen", 0,  0, 0, 0, GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_PROP,  0, (GdkModifierType)0, 0 },
	      { GNOME_APP_UI_ITEM, "Neuladen", 0,  0, 0, 0, GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_REFRESH,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_MENU_PRINT_ITEM(0, 0), 
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_ITEM, "Lieferscheine", 0,  0, 0, 0, GNOME_APP_PIXMAP_STOCK, GNOME_STOCK_MENU_SRCHRPL,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo main_kndbez_uiinfo[] = 
      {        { GNOME_APP_UI_ITEM, "Kundenbezeichnung", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      { GNOME_APP_UI_ITEM, "Interne Bezeichnung", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo kundenauftragsnummer_uiinfo[] = 
      {        { GNOME_APP_UI_ITEM, "Kundenauftragsnummer", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      { GNOME_APP_UI_ITEM, "Interne Auftragsnummer", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo kalenderwoche_uiinfo[] = 
      {        { GNOME_APP_UI_ITEM, "Kalenderwoche", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      { GNOME_APP_UI_ITEM, "Datum", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo kunden_name1_uiinfo[] = 
      {        { GNOME_APP_UI_ITEM, "Kunden Name", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      { GNOME_APP_UI_ITEM, "Kunden Nr.", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo materialbedarf_sortiert_nach_artikel_uiinfo[] = 
      {        { GNOME_APP_UI_ITEM, "Materialbedarf sortiert nach Artikel", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      { GNOME_APP_UI_ITEM, "Materialbedarf sortiert nach Menge", 0,  0, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo main_einstellungen_menu_uiinfo[] = 
      {        { GNOME_APP_UI_RADIOITEMS, 0, 0,  main_kndbez_uiinfo, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_RADIOITEMS, 0, 0,  kundenauftragsnummer_uiinfo, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_RADIOITEMS, 0, 0,  kalenderwoche_uiinfo, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_RADIOITEMS, 0, 0,  kunden_name1_uiinfo, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_SEPARATOR, 
	      { GNOME_APP_UI_RADIOITEMS, 0, 0,  materialbedarf_sortiert_nach_artikel_uiinfo, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
	      GNOMEUIINFO_END 
      };
      static GnomeUIInfo main_menubar_uiinfo[] = 
      {        GNOMEUIINFO_MENU_FILE_TREE(main_datei_menu_uiinfo),
	      GNOMEUIINFO_MENU_EDIT_TREE(bearbeiten_menu_uiinfo),
	      GNOMEUIINFO_MENU_SETTINGS_TREE(main_einstellungen_menu_uiinfo),
	      GNOMEUIINFO_END 
      };
      gnome_app_fill_menu(GTK_MENU_SHELL(main_menubar->gtkobj()), main_menubar_uiinfo, NULL, true, 0);
      beenden = Gtk::wrap(GTK_MENU_ITEM(main_datei_menu_uiinfo[0].widget));
      erfassen = Gtk::wrap(GTK_MENU_ITEM(bearbeiten_menu_uiinfo[0].widget));
      neuladen = Gtk::wrap(GTK_MENU_ITEM(bearbeiten_menu_uiinfo[1].widget));
      main_drucken = Gtk::wrap(GTK_MENU_ITEM(bearbeiten_menu_uiinfo[2].widget));
      trennlinie2 = Gtk::wrap(GTK_MENU_ITEM(bearbeiten_menu_uiinfo[3].widget));
      abschreiben = Gtk::wrap(GTK_MENU_ITEM(bearbeiten_menu_uiinfo[4].widget));
      main_kndbez = Gtk::wrap(GTK_RADIO_MENU_ITEM(main_kndbez_uiinfo[0].widget));
      main_intbez = Gtk::wrap(GTK_RADIO_MENU_ITEM(main_kndbez_uiinfo[1].widget));
      kundenauftragsnummer = Gtk::wrap(GTK_RADIO_MENU_ITEM(kundenauftragsnummer_uiinfo[0].widget));
      interne_auftragsnummer = Gtk::wrap(GTK_RADIO_MENU_ITEM(kundenauftragsnummer_uiinfo[1].widget));
      kalenderwoche = Gtk::wrap(GTK_RADIO_MENU_ITEM(kalenderwoche_uiinfo[0].widget));
      datum = Gtk::wrap(GTK_RADIO_MENU_ITEM(kalenderwoche_uiinfo[1].widget));
      kunden_name1 = Gtk::wrap(GTK_RADIO_MENU_ITEM(kunden_name1_uiinfo[0].widget));
      kunden_nr = Gtk::wrap(GTK_RADIO_MENU_ITEM(kunden_name1_uiinfo[1].widget));
      materialbedarf_sortiert_nach_artikel = Gtk::wrap(GTK_RADIO_MENU_ITEM(materialbedarf_sortiert_nach_artikel_uiinfo[0].widget));
      materialbedarf_sortiert_nach_menge = Gtk::wrap(GTK_RADIO_MENU_ITEM(materialbedarf_sortiert_nach_artikel_uiinfo[1].widget));
      trennlinie5 = Gtk::wrap(GTK_MENU_ITEM(main_einstellungen_menu_uiinfo[2].widget));
      trennlinie3 = Gtk::wrap(GTK_MENU_ITEM(main_einstellungen_menu_uiinfo[5].widget));
      trennlinie4 = Gtk::wrap(GTK_MENU_ITEM(main_einstellungen_menu_uiinfo[8].widget));
      trennlinie6 = Gtk::wrap(GTK_MENU_ITEM(main_einstellungen_menu_uiinfo[11].widget));
   }
   
   Gtk::Toolbar *toolbar1 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   endemain_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "beenden", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_EXIT)), 0, 0));
   erfassen_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "erfassen", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_PROPERTIES)), 0, 0));
   mainprint_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "drucken", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_PRINT)), 0, 0));
   mainreload_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "neu laden", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_REFRESH)), 0, 0));
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::Space());
   lieferschein_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Lieferschein", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_BOOK_GREEN)), 0, 0));
   rechnung_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Rechnung", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_BOOK_YELLOW)), 0, 0));
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   Gtk::Button *button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Auftr�ge", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_BOOK_BLUE)), 0, 0));
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::Space());
   togglebutton_material = Gtk::wrap((GtkToggleButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_TOGGLEBUTTON, 0, "Materialbedarf", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_CONVERT)), 0, 0));
   
   Gtk::Button *button_artikeleingabe = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Artikeleingabe", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_COLORSELECTOR)), 0, 0));
   Gtk::Label *label75 = manage(new class Gtk::Label("Auftragsnummer"));
   searchcombo_auftragid = new class SearchComboContent<int>();
   
   Gtk::Label *label85 = manage(new class Gtk::Label("Auftragsdatum"));
   Datum_instanz = new class Datewin();
   
   Gtk::Pixmap *pixmap3 = manage(new class Gtk::Pixmap(wintext_xpm));
   Gtk::Label *label84 = manage(new class Gtk::Label("Neuer Auftrag"));
   Gtk::HBox *hbox11 = manage(new class Gtk::HBox(false, 0));
   Gtk::Button *button_neue_anr = manage(new class Gtk::Button());
   Gtk::Pixmap *pixmap4 = manage(new class Gtk::Pixmap(print_image_xpm));
   Gtk::Label *label86 = manage(new class Gtk::Label("Drucken"));
   Gtk::HBox *hbox12 = manage(new class Gtk::HBox(false, 0));
   Gtk::Button *button_instanz_print = manage(new class Gtk::Button());
   Gtk::Table *table19 = manage(new class Gtk::Table(2, 4, false));
   Gtk::Frame *frame14 = manage(new class Gtk::Frame());
   Gtk::Pixmap *pixmap1 = manage(new class Gtk::Pixmap(configure_xpm));
   Gtk::Label *label82 = manage(new class Gtk::Label("Teilmenge"));
   Gtk::HBox *hbox8 = manage(new class Gtk::HBox(false, 0));
   togglebutton_geplante_menge = manage(new class Gtk::ToggleButton());
   
   Gtk::Adjustment *spinbutton_geplante_menge_adj = manage(new class Gtk::Adjustment(1, 1, 1e+07, 1, 10, 10));
   spinbutton_geplante_menge = manage(new class Gtk::SpinButton(*spinbutton_geplante_menge_adj, 1, 0));
   
   Gtk::Table *table20 = manage(new class Gtk::Table(1, 2, false));
   Gtk::Frame *frame13 = manage(new class Gtk::Frame());
   Gtk::Table *table18 = manage(new class Gtk::Table(1, 2, false));
   tree_neuer_auftrag = new class SimpleTree(4);
   
   Gtk::Viewport *viewport9 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow9 = manage(new class Gtk::ScrolledWindow());
   info_label_instanzen = manage(new class Gtk::Label("info text (etwas l�nger)"));
   table_instanzen = manage(new class Gtk::Table(3, 4, false));
   frame_instanzen = manage(new class Gtk::Frame("Materialbestellung"));
   
   Gtk::Label *label35 = manage(new class Gtk::Label("Prod. Prozess"));
   prozlist_scombo = new class SearchComboContent<int>();
   
   Gtk::Pixmap *pixmap2 = manage(new class Gtk::Pixmap(delete_images_xpm));
   Gtk::Label *label83 = manage(new class Gtk::Label("Auftrag erledigt"));
   Gtk::HBox *hbox10 = manage(new class Gtk::HBox(false, 0));
   Gtk::Button *button_auftrag_erledigt = manage(new class Gtk::Button());
   table_prod_prozess = manage(new class Gtk::Table(1, 4, false));
   maintree_s = new class SimpleTree(10, 8);
   
   Gtk::Viewport *viewport6 = manage(new class Gtk::Viewport());
   scrolledwindow_maintree_s = manage(new class Gtk::ScrolledWindow());
   
   Gtk::Frame *frame12 = manage(new class Gtk::Frame("Ansichtsbaum"));
   viewport_materialbedarf = manage(new class Gtk::Viewport());
   
   Gtk::ScrolledWindow *scrolledwindow11 = manage(new class Gtk::ScrolledWindow());
   frame_materialbedarf = manage(new class Gtk::Frame("Materialbedarf"));
   vpaned_an_mat = manage(new class Gtk::VPaned());
   
   Gtk::Table *table16 = manage(new class Gtk::Table(5, 1, false));
   toolbar1->set_space_size(5);
   toolbar1->set_tooltips(true);
   label75->set_alignment(0, 0.5);
   label75->set_padding(0, 0);
   searchcombo_auftragid->set_usize(150, -1);
   label85->set_alignment(0, 0.5);
   label85->set_padding(0, 0);
   pixmap3->set_alignment(0.5, 0.5);
   pixmap3->set_padding(0, 0);
   label84->set_alignment(0.5, 0.5);
   label84->set_padding(0, 0);
   hbox11->pack_start(*pixmap3);
   hbox11->pack_start(*label84, false, false, 0);
   button_neue_anr->set_usize(-1, 30);
   button_neue_anr->add(*hbox11);
   pixmap4->set_alignment(0.5, 0.5);
   pixmap4->set_padding(0, 0);
   label86->set_alignment(0.5, 0.5);
   label86->set_padding(0, 0);
   hbox12->pack_start(*pixmap4);
   hbox12->pack_start(*label86, false, false, 0);
   _tooltips.set_tip(*button_instanz_print, "Linker Knopf: Drucken, rechter Knopf: Vorschau", "");
   button_instanz_print->add(*hbox12);
   table19->set_col_spacings(5);
   table19->attach(*label75, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table19->attach(*searchcombo_auftragid, 0, 1, 1, 2, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table19->attach(*label85, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table19->attach(*Datum_instanz, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table19->attach(*button_neue_anr, 2, 3, 0, 2, GTK_FILL, 0, 5, 3);
   table19->attach(*button_instanz_print, 3, 4, 0, 2, GTK_FILL, 0, 5, 0);
   frame14->set_label_align(0, 0);
   frame14->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame14->add(*table19);
   pixmap1->set_alignment(0.5, 0.5);
   pixmap1->set_padding(0, 0);
   label82->set_alignment(0.5, 0.5);
   label82->set_padding(0, 0);
   hbox8->pack_start(*pixmap1);
   hbox8->pack_start(*label82, false, false, 0);
   _tooltips.set_tip(*togglebutton_geplante_menge, "Ist dieser Knopf NICHT gedr�ckt, so wird die komplette Menge verplant", "");
   togglebutton_geplante_menge->add(*hbox8);
   spinbutton_geplante_menge->set_usize(80, -1);
   spinbutton_geplante_menge->set_editable(true);
   table20->attach(*togglebutton_geplante_menge, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table20->attach(*spinbutton_geplante_menge, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, GTK_EXPAND, 0, 0);
   frame13->set_label_align(0, 0);
   frame13->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame13->add(*table20);
   table18->attach(*frame14, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table18->attach(*frame13, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 10, 0);
   viewport9->set_shadow_type(GTK_SHADOW_NONE);
   viewport9->add(*tree_neuer_auftrag);
   scrolledwindow9->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow9->add(*viewport9);
   info_label_instanzen->set_alignment(0, 0.5);
   info_label_instanzen->set_padding(0, 0);
   table_instanzen->attach(*table18, 0, 4, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table_instanzen->attach(*scrolledwindow9, 0, 4, 2, 3, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table_instanzen->attach(*info_label_instanzen, 0, 4, 0, 1, GTK_FILL, 0, 0, 0);
   frame_instanzen->set_label_align(0, 0);
   frame_instanzen->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_instanzen->add(*table_instanzen);
   label35->set_usize(100, -1);
   label35->set_alignment(0, 0.5);
   label35->set_padding(0, 0);
   prozlist_scombo->set_usize(250, -1);
   pixmap2->set_alignment(0.5, 0.5);
   pixmap2->set_padding(0, 0);
   label83->set_alignment(0.5, 0.5);
   label83->set_padding(0, 0);
   hbox10->pack_start(*pixmap2);
   hbox10->pack_start(*label83, false, false, 0);
   button_auftrag_erledigt->add(*hbox10);
   table_prod_prozess->set_border_width(5);
   table_prod_prozess->attach(*label35, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_prod_prozess->attach(*prozlist_scombo, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table_prod_prozess->attach(*button_auftrag_erledigt, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   viewport6->set_shadow_type(GTK_SHADOW_NONE);
   viewport6->add(*maintree_s);
   scrolledwindow_maintree_s->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow_maintree_s->add(*viewport6);
   frame12->set_label_align(0, 0);
   frame12->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame12->add(*scrolledwindow_maintree_s);
   viewport_materialbedarf->set_usize(-1, 70);
   viewport_materialbedarf->set_shadow_type(GTK_SHADOW_NONE);
   scrolledwindow11->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow11->add(*viewport_materialbedarf);
   frame_materialbedarf->set_usize(-1, 120);
   frame_materialbedarf->set_label_align(0, 0);
   frame_materialbedarf->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_materialbedarf->add(*scrolledwindow11);
   vpaned_an_mat->set_handle_size(10);
   vpaned_an_mat->set_gutter_size(1);
   vpaned_an_mat->set_position(167);
   vpaned_an_mat->pack1(*frame12, false, true);
   vpaned_an_mat->pack2(*frame_materialbedarf, true, true);
   table16->attach(*main_menubar, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table16->attach(*toolbar1, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table16->attach(*frame_instanzen, 0, 1, 4, 5, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table16->attach(*table_prod_prozess, 0, 1, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
   table16->attach(*vpaned_an_mat, 0, 1, 3, 4, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   auftrag_main->set_usize(800, 600);
   auftrag_main->set_title("Auftragsbearbeitung");
   auftrag_main->set_policy(true, true, false);
   auftrag_main->add(*table16);
   main_menubar->show();
   toolbar1->show();
   label75->show();
   searchcombo_auftragid->show();
   label85->show();
   Datum_instanz->show();
   pixmap3->show();
   label84->show();
   hbox11->show();
   button_neue_anr->show();
   pixmap4->show();
   label86->show();
   hbox12->show();
   button_instanz_print->show();
   table19->show();
   frame14->show();
   pixmap1->show();
   label82->show();
   hbox8->show();
   togglebutton_geplante_menge->show();
   spinbutton_geplante_menge->show();
   table20->show();
   frame13->show();
   table18->show();
   tree_neuer_auftrag->show();
   viewport9->show();
   scrolledwindow9->show();
   info_label_instanzen->show();
   table_instanzen->show();
   frame_instanzen->show();
   label35->show();
   prozlist_scombo->show();
   pixmap2->show();
   label83->show();
   hbox10->show();
   button_auftrag_erledigt->show();
   table_prod_prozess->show();
   maintree_s->show();
   viewport6->show();
   scrolledwindow_maintree_s->show();
   frame12->show();
   viewport_materialbedarf->show();
   scrolledwindow11->show();
   frame_materialbedarf->show();
   vpaned_an_mat->show();
   table16->show();
   auftrag_main->show();
   beenden->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_beenden_activate));
   erfassen->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_erfassen_activate));
   neuladen->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_neuladen_activate));
   main_drucken->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_drucken_activate));
   abschreiben->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_abschreiben_activate));
   main_kndbez->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_bezeichnung_activate));
   main_intbez->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_bezeichnung_activate));
   kundenauftragsnummer->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_kunden_anr_activate));
   interne_auftragsnummer->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_kunden_anr_activate));
   kalenderwoche->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_zeitdarstellung_activate));
   datum->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_zeitdarstellung_activate));
   kunden_name1->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_kundendarstellung_activate));
   kunden_nr->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_kundendarstellung_activate));
   materialbedarf_sortiert_nach_artikel->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_materialbedarf_sortiert));
   materialbedarf_sortiert_nach_menge->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_materialbedarf_sortiert));
   endemain_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_beenden_activate));
   erfassen_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_erfassen_activate));
   mainprint_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_mainprint_button_clicked));
   mainreload_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_neuladen_activate));
   lieferschein_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_abschreiben_activate));
   rechnung_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_rechnung_activate));
   button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_button_auftraege_clicked));
   togglebutton_material->toggled.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_togglebutton_material_toggled));
   button_artikeleingabe->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_button_artikeleingabe_clicked));
   searchcombo_auftragid->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_searchcombo_auftragid_activate));
   searchcombo_auftragid->search.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_searchcombo_auftragid_search));
   button_neue_anr->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_button_neue_anr_clicked));
   button_instanz_print->button_press_event.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_button_instanz_print_clicked));
   togglebutton_geplante_menge->toggled.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_togglebutton_geplante_menge_toggled));
   tree_neuer_auftrag->leaf_selected.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::tree_neuer_auftrag_leaf_selected));
   prozlist_scombo->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_prozlistscombo_activate));
   prozlist_scombo->search.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_prozlistscombo_search));
   button_auftrag_erledigt->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_button_auftrag_erledigt_clicked));
   maintree_s->leaf_selected.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_leaf_selected));
   maintree_s->unselect_row.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_unselect_row));
   maintree_s->node_selected.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_node_selected));
}

auftrag_main_glade::~auftrag_main_glade()
{   delete searchcombo_auftragid;
   delete Datum_instanz;
   delete tree_neuer_auftrag;
   delete prozlist_scombo;
   delete maintree_s;
}
