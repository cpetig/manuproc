// generated 2003/4/7 12:58:01 CEST by christof@puck.petig-baender.de
// using glademm V1.1.3f
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/christof/cvs/common/Komponenten2/Basic/examples/MVC/mvc.glade
// for gtk 2.2.1 and gtkmm 2.2.0
//
// Please modify the corresponding derived classes in ././window1.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include "window1_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>

window1_glade::window1_glade(
) : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *window1 = this;
   gmm_data = new GlademmData(get_accel_group());
   intwidget = new class int_SpinButton(myint,0,100);
   stringwidget = new class string_Entry(mystring);
   boolwidget = new class bool_CheckButton(mybool,"an/aus");
   custom1 = new class bool_CheckButton(mybool2,"(in)aktiv");
   custom2 = new class bool_ImageButton(mybool3,auto_roll,hand_roll);
   label1 = Gtk::manage(new class Gtk::Label("label1"));
   
   Gtk::Adjustment *spinbutton1_adj = Gtk::manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   spinbutton1 = Gtk::manage(new class Gtk::SpinButton(*spinbutton1_adj, 1, 0));
   
   Gtk::Button *button1 = Gtk::manage(new class Gtk::Button("loeschen"));
   Gtk::Button *button2 = Gtk::manage(new class Gtk::Button("randomize"));
   Gtk::VBox *vbox1 = Gtk::manage(new class Gtk::VBox(false, 0));
   label1->set_alignment(0.5,0.5);
   label1->set_padding(0,0);
   label1->set_justify(Gtk::JUSTIFY_LEFT);
   label1->set_line_wrap(false);
   label1->set_use_markup(false);
   label1->set_selectable(false);
   spinbutton1->set_flags(Gtk::CAN_FOCUS);
   spinbutton1->set_update_policy(Gtk::UPDATE_ALWAYS);
   spinbutton1->set_numeric(false);
   spinbutton1->set_digits(0);
   spinbutton1->set_wrap(false);
   button1->set_flags(Gtk::CAN_FOCUS);
   button1->set_relief(Gtk::RELIEF_NORMAL);
   button2->set_flags(Gtk::CAN_FOCUS);
   button2->set_relief(Gtk::RELIEF_NORMAL);
   vbox1->pack_start(*intwidget);
   vbox1->pack_start(*stringwidget);
   vbox1->pack_start(*boolwidget);
   vbox1->pack_start(*custom1);
   vbox1->pack_start(*custom2);
   vbox1->pack_start(*label1, Gtk::PACK_SHRINK, 0);
   vbox1->pack_start(*spinbutton1, Gtk::PACK_SHRINK, 0);
   vbox1->pack_start(*button1, Gtk::PACK_SHRINK, 0);
   vbox1->pack_start(*button2, Gtk::PACK_SHRINK, 0);
   window1->set_title("window1");
   window1->set_modal(false);
   window1->property_window_position().set_value(Gtk::WIN_POS_NONE);
   window1->set_resizable(true);
   window1->property_destroy_with_parent().set_value(false);
   window1->add(*vbox1);
   intwidget->show();
   stringwidget->show();
   boolwidget->show();
   custom1->show();
   custom2->show();
   label1->show();
   spinbutton1->show();
   button1->show();
   button2->show();
   vbox1->show();
   window1->show();
   intwidget->signal_activate().connect(SigC::slot(*stringwidget, &Gtk::Widget::grab_focus), true);
   stringwidget->signal_activate().connect(SigC::slot(*intwidget, &Gtk::Widget::grab_focus), true);
   button1->signal_clicked().connect(SigC::slot(*this, &window1_glade::loeschen));
   button2->signal_clicked().connect(SigC::slot(*this, &window1_glade::randomize));
}

window1_glade::~window1_glade()
{  delete intwidget;
   delete stringwidget;
   delete boolwidget;
   delete custom1;
   delete custom2;
   delete gmm_data;
}
