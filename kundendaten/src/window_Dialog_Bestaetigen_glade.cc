// generated 2002/9/24 12:19:12 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- kundendaten.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/window_Dialog_Bestaetigen.cc

#include "config.h"
#include "window_Dialog_Bestaetigen.hh"
#include <libgnomeui/gnome-stock.h>
#include <gtk--/button.h>
#include <gtk--/table.h>

window_Dialog_Bestaetigen_glade::window_Dialog_Bestaetigen_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  window_Dialog_Bestaetigen = this;
   
   Gtk::Button *button_ok = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_OK));
   Gtk::Button *button_cancel = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_CANCEL));
   label_text = manage(new class Gtk::Label("label14"));
   
   Gtk::Table *table6 = manage(new class Gtk::Table(2, 3, false));
   button_ok->set_usize(100,-1);
   button_ok->set_flags(GTK_CAN_FOCUS);
   button_ok->set_relief(GTK_RELIEF_NORMAL);
   button_cancel->set_usize(100,-1);
   button_cancel->set_flags(GTK_CAN_FOCUS);
   button_cancel->set_relief(GTK_RELIEF_NORMAL);
   label_text->set_alignment(0,0.5);
   label_text->set_padding(0,0);
   label_text->set_justify(GTK_JUSTIFY_CENTER);
   label_text->set_line_wrap(false);
   table6->set_row_spacings(0);
   table6->set_col_spacings(0);
   table6->attach(*button_ok, 0, 1, 1, 2, GTK_FILL, 0, 5, 5);
   table6->attach(*button_cancel, 2, 3, 1, 2, GTK_FILL, 0, 5, 5);
   table6->attach(*label_text, 0, 3, 0, 1, 0, 0, 5, 5);
   window_Dialog_Bestaetigen->set_title("Bestštigen");
   window_Dialog_Bestaetigen->set_modal(true);
   window_Dialog_Bestaetigen->set_position(GTK_WIN_POS_NONE);
   window_Dialog_Bestaetigen->add(*table6);
   button_ok->show();
   button_cancel->show();
   label_text->show();
   table6->show();
   window_Dialog_Bestaetigen->show();
   button_ok->clicked.connect(SigC::slot(static_cast<class window_Dialog_Bestaetigen*>(this), &window_Dialog_Bestaetigen::on_button_ok_clicked));
   button_cancel->clicked.connect(SigC::slot(static_cast<class window_Dialog_Bestaetigen*>(this), &window_Dialog_Bestaetigen::on_button_cancel_clicked));
}

window_Dialog_Bestaetigen_glade::~window_Dialog_Bestaetigen_glade()
{  
}
