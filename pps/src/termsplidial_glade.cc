// generated 2002/9/4 11:48:27 CEST by christof@felix.petig.de
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/termsplidial.cc

#include "config.h"
#include "termsplidial.hh"
#include <gtk--/button.h>
#include <gtk--/box.h>
#include <gtk--/label.h>
#include <gtk--/adjustment.h>
#include <gtk--/table.h>

termsplidial_glade::termsplidial_glade(
)
{  
   
   Gtk::Dialog *termsplidial = this;
   Gtk::Button *okbutton = manage(new class Gtk::Button("OK"));
   Gtk::Button *cancbutton = manage(new class Gtk::Button("Abbruch"));
   termin_neu = manage(new class Gtk::Calendar());
   
   Gtk::Label *label2 = manage(new class Gtk::Label("Teilmenge"));
   Gtk::Label *label36 = manage(new class Gtk::Label("neuer Termin"));
   Gtk::Adjustment *menge_neu_adj = manage(new class Gtk::Adjustment(1, 1, 1e+06, 1, 10, 10));
   menge_neu = manage(new class Gtk::SpinButton(*menge_neu_adj, 1, 0));
   
   Gtk::Table *table1 = manage(new class Gtk::Table(2, 2, false));
   okbutton->set_usize(80,-1);
   okbutton->set_flags(GTK_CAN_FOCUS);
   okbutton->set_relief(GTK_RELIEF_NORMAL);
   cancbutton->set_flags(GTK_CAN_FOCUS);
   cancbutton->set_relief(GTK_RELIEF_NORMAL);
   termsplidial->get_action_area()->set_border_width(10);
   termsplidial->get_action_area()->set_homogeneous(true);
   termsplidial->get_action_area()->set_spacing(5);
   termsplidial->get_action_area()->pack_start(*okbutton, true, false, 0);
   termsplidial->get_action_area()->pack_start(*cancbutton, true, false, 0);
   termin_neu->set_flags(GTK_CAN_FOCUS);
   termin_neu->display_options((GtkCalendarDisplayOptions)(GTK_CALENDAR_SHOW_HEADING|GTK_CALENDAR_SHOW_DAY_NAMES|GTK_CALENDAR_SHOW_WEEK_NUMBERS|GTK_CALENDAR_WEEK_START_MONDAY));
   label2->set_usize(70,-1);
   label2->set_alignment(0,0.5);
   label2->set_padding(0,0);
   label2->set_justify(GTK_JUSTIFY_LEFT);
   label2->set_line_wrap(false);
   label36->set_usize(80,-1);
   label36->set_alignment(0,0.5);
   label36->set_padding(0,0);
   label36->set_justify(GTK_JUSTIFY_LEFT);
   label36->set_line_wrap(false);
   menge_neu->set_usize(100,-1);
   menge_neu->set_flags(GTK_CAN_FOCUS);
   menge_neu->set_update_policy(GTK_UPDATE_ALWAYS);
   menge_neu->set_numeric(true);
   menge_neu->set_digits(0);
   menge_neu->set_wrap(false);
   menge_neu->set_snap_to_ticks(false);
   table1->set_border_width(5);
   table1->set_row_spacings(5);
   table1->set_col_spacings(0);
   table1->attach(*termin_neu, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table1->attach(*label2, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table1->attach(*label36, 0, 1, 0, 1, GTK_EXPAND, 0, 0, 0);
   table1->attach(*menge_neu, 1, 2, 1, 2, 0, 0, 0, 0);
   termsplidial->get_vbox()->set_homogeneous(false);
   termsplidial->get_vbox()->set_spacing(0);
   termsplidial->get_vbox()->pack_start(*table1, false, true, 0);
   termsplidial->set_title("Termin splitten");
   termsplidial->set_modal(false);
   termsplidial->set_position(GTK_WIN_POS_NONE);
   okbutton->show();
   cancbutton->show();
   termin_neu->show();
   label2->show();
   label36->show();
   menge_neu->show();
   table1->show();
   termsplidial->show();
   okbutton->clicked.connect(SigC::slot(static_cast<class termsplidial*>(this), &termsplidial::on_okbutton_clicked));
   cancbutton->clicked.connect(SigC::slot(static_cast<class termsplidial*>(this), &termsplidial::on_cancbutton_clicked));
}

termsplidial_glade::~termsplidial_glade()
{  
}
