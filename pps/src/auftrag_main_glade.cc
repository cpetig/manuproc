// generated 2001/4/26 17:25:59 CEST by christof@puck.(none)
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.4
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
#include <gtk--/table.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/box.h>
#include <gtk--/frame.h>

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
      static GnomeUIInfo main_einstellungen_menu_uiinfo[] = 
      {        { GNOME_APP_UI_RADIOITEMS, 0, 0,  main_kndbez_uiinfo, 0, 0, GNOME_APP_PIXMAP_NONE, 0,  0, (GdkModifierType)0, 0 },
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
   }
   
   Gtk::Toolbar *toolbar1 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   endemain_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "beenden", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_EXIT)), 0, 0));
   erfassen_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "erfassen", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_PROPERTIES)), 0, 0));
   mainprint_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "drucken", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_PRINT)), 0, 0));
   mainreload_button = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "neu laden", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_REFRESH)), 0, 0));
   toolbar1->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   Gtk::Button *button21 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Lieferschein", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_BOOK_GREEN)), 0, 0));
   Gtk::Button *button22 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar1->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Rechnung", 0, 0, GTK_WIDGET(gnome_stock_pixmap_widget(GTK_WIDGET(toolbar1->gtkobj()), GNOME_STOCK_PIXMAP_BOOK_YELLOW)), 0, 0));
   Gtk::Label *label35 = manage(new class Gtk::Label("Prod. Prozess"));
   prozlist_scombo = new class SearchComboContent<int>();
   
   Gtk::Table *table7 = manage(new class Gtk::Table(1, 2, false));
   main_showtreebutton = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_APPLY));
   
   Gtk::Button *main_defaultattrbutton = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_CANCEL));
   Gtk::Table *table4 = manage(new class Gtk::Table(1, 2, false));
   maintree = new class MainTree(10);
   
   Gtk::ScrolledWindow *scrolledwindow2 = manage(new class Gtk::ScrolledWindow());
   Gtk::VBox *vbox3 = manage(new class Gtk::VBox(false, 0));
   Gtk::Frame *frame1 = manage(new class Gtk::Frame("Ansichtsbaum"));
   foot_statusbar = manage(new class Gtk::Statusbar());
   
   Gtk::VBox *vbox2 = manage(new class Gtk::VBox(false, 0));
   main_kndbez->set_show_toggle(true);
   main_intbez->set_active(true);
   main_intbez->set_show_toggle(true);
   toolbar1->set_space_size(5);
   toolbar1->set_tooltips(true);
   label35->set_usize(100, -1);
   label35->set_alignment(0, 0.5);
   label35->set_padding(0, 0);
   prozlist_scombo->set_usize(250, -1);
   table7->set_border_width(5);
   table7->attach(*label35, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table7->attach(*prozlist_scombo, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table4->attach(*main_showtreebutton, 0, 1, 0, 1, 0, 0, 0, 0);
   table4->attach(*main_defaultattrbutton, 1, 2, 0, 1, 0, 0, 0, 0);
   scrolledwindow2->set_policy(GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
   scrolledwindow2->add(*maintree);
   vbox3->pack_start(*table4, false, true, 0);
   vbox3->pack_start(*scrolledwindow2);
   frame1->set_label_align(0, 0);
   frame1->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame1->add(*vbox3);
   vbox2->pack_start(*main_menubar, false, false, 0);
   vbox2->pack_start(*toolbar1, false, false, 0);
   vbox2->pack_start(*table7, false, true, 0);
   vbox2->pack_start(*frame1);
   vbox2->pack_start(*foot_statusbar, false, false, 0);
   auftrag_main->set_usize(800, 600);
   auftrag_main->set_title("Auftragsbearbeitung");
   auftrag_main->set_policy(true, true, false);
   auftrag_main->add(*vbox2);
   main_menubar->show();
   toolbar1->show();
   label35->show();
   prozlist_scombo->show();
   table7->show();
   main_showtreebutton->show();
   main_defaultattrbutton->show();
   table4->show();
   maintree->show();
   scrolledwindow2->show();
   vbox3->show();
   frame1->show();
   foot_statusbar->show();
   vbox2->show();
   auftrag_main->show();
   beenden->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_beenden_activate));
   erfassen->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_erfassen_activate));
   neuladen->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_neuladen_activate));
   main_drucken->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_drucken_activate));
   abschreiben->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_abschreiben_activate));
   main_kndbez->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_kndbez_activate));
   main_intbez->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_intbez_activate));
   endemain_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_beenden_activate));
   erfassen_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_erfassen_activate));
   mainprint_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_mainprint_button_clicked));
   mainreload_button->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_neuladen_activate));
   button21->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_abschreiben_activate));
   button22->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_rechnung_activate));
   prozlist_scombo->activate.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_prozlistscombo_activate));
   prozlist_scombo->search.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_prozlistscombo_search));
   main_showtreebutton->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_showtreebutton_clicked));
   main_defaultattrbutton->clicked.connect(SigC::slot(static_cast<class auftrag_main*>(this), &auftrag_main::on_main_defaultattrbutton_clicked));
}

auftrag_main_glade::~auftrag_main_glade()
{   delete prozlist_scombo;
   delete maintree;
}
