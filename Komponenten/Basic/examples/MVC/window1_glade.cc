// generated 2002/7/7 22:00:46 CEST by christof@puck.petig-baender.de
// using glademm V1.1.0d_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- mvc.glade
// for gtk 2.0.5 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/window1.cc

#include "config.h"
#include "window1.hh"
#include <gtk--/button.h>
#include <gtk--/box.h>

window1_glade::window1_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *window1 = this;
   intwidget = new class MVC_int_Widget(myint,0,100);
   stringwidget = new class MVC_string_Widget(mystring);
   
   Gtk::Button *button1 = manage(new class Gtk::Button("l�schen"));
   Gtk::VBox *vbox1 = manage(new class Gtk::VBox(false, 0));
   button1->set_flags(GTK_CAN_FOCUS);
   button1->set_relief(GTK_RELIEF_NORMAL);
   vbox1->pack_start(*intwidget);
   vbox1->pack_start(*stringwidget);
   vbox1->pack_start(*button1, false, false, 0);
   window1->set_title("window1");
   window1->set_modal(false);
   window1->set_position(GTK_WIN_POS_NONE);
   window1->add(*vbox1);
   intwidget->show();
   stringwidget->show();
   button1->show();
   vbox1->show();
   window1->show();
   intwidget->activate.connect_after(stringwidget->grab_focus.slot());
   stringwidget->activate.connect_after(intwidget->grab_focus.slot());
   button1->clicked.connect(SigC::slot(static_cast<class window1*>(this), &window1::loeschen));
}

window1_glade::~window1_glade()
{  delete intwidget;
   delete stringwidget;
}
