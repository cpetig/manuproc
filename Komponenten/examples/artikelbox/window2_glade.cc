// generated 2004/11/16 15:20:40 CET by christof@felix.petig.de
// using glademm V2.6.0_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- marc.glade
// for gtk 2.4.13 and gtkmm 2.4.5
//
// Please modify the corresponding derived classes in ././window2.cc


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
#include "window2_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/table.h>

window2_glade::window2_glade(
) : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *window2 = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::MenuItem *item1 = NULL;
   Gtk::MenuItem *item3 = NULL;
   Gtk::MenuItem *item4 = NULL;
   Gtk::Menu *item2_menu = Gtk::manage(new class Gtk::Menu());
   Gtk::MenuItem *item2 = NULL;
   Gtk::MenuItem *trennlinie1 = NULL;
   Gtk::MenuBar *menubar2 = Gtk::manage(new class Gtk::MenuBar());
   Gtk::Table *table1 = Gtk::manage(new class Gtk::Table(2, 2, false));
   
   item2_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("text3"));
   item3 = (Gtk::MenuItem *)&item2_menu->items().back();
   
   item2_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("text4"));
   item4 = (Gtk::MenuItem *)&item2_menu->items().back();
   
   menubar2->items().push_back(Gtk::Menu_Helpers::MenuElem("text1"));
   item1 = (Gtk::MenuItem *)&menubar2->items().back();
   
   menubar2->items().push_back(Gtk::Menu_Helpers::MenuElem("text2", *item2_menu));
   item2 = (Gtk::MenuItem *)&menubar2->items().back();
   
   menubar2->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie1 = (Gtk::MenuItem *)&menubar2->items().back();
   table1->set_row_spacings(0);
   table1->set_col_spacings(0);
   table1->attach(*menubar2, 0, 1, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   window2->set_title("window2");
   window2->set_modal(false);
   window2->property_window_position().set_value(Gtk::WIN_POS_NONE);
   window2->set_resizable(true);
   window2->property_destroy_with_parent().set_value(false);
   window2->add(*table1);
   item1->show();
   item3->show();
   item4->show();
   item2_menu->show();
   item2->show();
   trennlinie1->show();
   menubar2->show();
   table1->show();
   window2->show();
   item1->signal_activate().connect(SigC::slot(*this, &window2_glade::on_item1_activate), false);
   item3->signal_activate().connect(SigC::slot(*this, &window2_glade::on_item3_activate), false);
   item4->signal_activate().connect(SigC::slot(*this, &window2_glade::on_item4_activate), false);
}

window2_glade::~window2_glade()
{  delete gmm_data;
}
