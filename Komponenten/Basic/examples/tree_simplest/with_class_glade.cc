// generated 2001/6/28 10:54:16 MEST by christof@petig.petig.de
// using glademm V0.6.2_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- tree.glade
// for gtk 1.2.9 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in .//with_class.cc

#include "config.h"
#include "with_class.hh"
#include <gtk--/list.h>
#include <gtk--/menu.h>
#include <gtk--/menubar.h>
#include <gtk--/box.h>

with_class_glade::with_class_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *with_class = this;
   Gtk::MenuItem *menuitem2 = manage(new class Gtk::MenuItem("Beenden"));
   Gtk::Menu *menu2 = manage(new class Gtk::Menu());
   Gtk::MenuItem *menuitem1 = manage(new class Gtk::MenuItem("Datei"));
   Gtk::MenuBar *menubar2 = manage(new class Gtk::MenuBar());
   treebase = new class TreeWithSums(6, 3);
   
   Gtk::VBox *vbox2 = manage(new class Gtk::VBox(false, 0));
   menu2->append(*menuitem2);
   menuitem1->set_submenu(*menu2);
   menubar2->append(*menuitem1);
   vbox2->pack_start(*menubar2, false, true, 0);
   vbox2->pack_start(*treebase);
   with_class->set_title("with_class");
   with_class->set_policy(true, true, false);
   with_class->add(*vbox2);
   menuitem2->show();
   menu2->show();
   menuitem1->show();
   menubar2->show();
   treebase->show();
   vbox2->show();
   with_class->show();
   menuitem2->activate.connect(SigC::slot(static_cast<class with_class*>(this), &with_class::on_Beenden_activate));
}

with_class_glade::~with_class_glade()
{   delete treebase;
}
