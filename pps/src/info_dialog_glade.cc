// generated 2004/10/20 10:46:15 CEST by christof@felix.petig.de
// using glademm V2.6.0_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/info_dialog.cc

#include "config.h"
#include "info_dialog_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <vector>
#include <libgnomeui/gnome-stock.h>
#include <gtk--/button.h>
#include <gtk--/buttonbox.h>
#include <gtk--/box.h>

info_dialog_glade::info_dialog_glade(
) : Gnome::Dialog()
{  
   
   Gnome::Dialog *info_dialog = this;
   Gtk::AccelGroup *info_dialog_accgrp = Gtk::AccelGroup::create();
   gmm_data = new GlademmData(info_dialog_accgrp);
   info_dialog->append_button(GNOME_STOCK_BUTTON_CLOSE);
   text = manage(new class Gtk::Label("Bitte Schlie�en"));
   info_dialog->get_button(0)->set_flags(GTK_CAN_FOCUS);
   text->set_alignment(0.5,0.5);
   text->set_padding(0,0);
   text->set_justify(GTK_JUSTIFY_CENTER);
   text->set_line_wrap(false);
   info_dialog->get_vbox()->set_homogeneous(false);
   info_dialog->get_vbox()->set_spacing(8);
   info_dialog->get_vbox()->pack_start(*text, false, false, 0);
   info_dialog->set_modal(true);
   info_dialog->set_position(GTK_WIN_POS_NONE);
   info_dialog->set_policy(false, false, false);
   info_dialog->add_accel_group(*(gmm_data->getAccelGroup()));
   
   Gtk::HButtonBox *dialog_action_area6 = Gtk::wrap((GtkHButtonBox*)GNOME_DIALOG(info_dialog->gtkobj())->action_area);
   dialog_action_area6->set_spacing(8);
   dialog_action_area6->set_spacing(8);
   info_dialog->close_hides(false);
   text->show();
   info_dialog->show();
}

info_dialog_glade::~info_dialog_glade()
{  delete gmm_data;
}
