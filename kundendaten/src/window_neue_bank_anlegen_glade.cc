// generated 2005/6/24 11:37:58 CEST by christof@vesta.petig-baender.de
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- kundendaten.glade
// for gtk 2.7.0 and gtkmm 2.6.3
//
// Please modify the corresponding derived classes in ./src/window_neue_bank_anlegen.cc


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
#include "window_neue_bank_anlegen_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/table.h>

window_neue_bank_anlegen_glade::window_neue_bank_anlegen_glade(
) : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *window_neue_bank_anlegen = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Label *label11 = Gtk::manage(new class Gtk::Label("Bankname"));
   Gtk::Label *label12 = Gtk::manage(new class Gtk::Label("BLZ"));
   entry_bankname = Gtk::manage(new class Gtk::Entry());
   entry_blz = Gtk::manage(new class Gtk::Entry());
   
   Gtk::Button *button_uebernehmen = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-apply")));
   Gtk::Button *button_abbrechen = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-cancel")));
   Gtk::Table *table5 = Gtk::manage(new class Gtk::Table(2, 2, false));
   label_text = Gtk::manage(new class Gtk::Label("label13"));
   
   Gtk::Table *table4 = Gtk::manage(new class Gtk::Table(2, 2, false));
   label11->set_alignment(0,0.5);
   label11->set_padding(0,0);
   label11->set_justify(Gtk::JUSTIFY_CENTER);
   label11->set_line_wrap(false);
   label11->set_use_markup(false);
   label11->set_selectable(false);
   label12->set_alignment(0,0.5);
   label12->set_padding(0,0);
   label12->set_justify(Gtk::JUSTIFY_CENTER);
   label12->set_line_wrap(false);
   label12->set_use_markup(false);
   label12->set_selectable(false);
   entry_bankname->set_flags(Gtk::CAN_FOCUS);
   entry_bankname->set_visibility(true);
   entry_bankname->set_editable(true);
   entry_bankname->set_max_length(0);
   entry_bankname->set_text("");
   entry_bankname->set_has_frame(true);
   entry_bankname->set_activates_default(false);
   entry_blz->set_flags(Gtk::CAN_FOCUS);
   entry_blz->set_visibility(true);
   entry_blz->set_editable(true);
   entry_blz->set_max_length(0);
   entry_blz->set_text("");
   entry_blz->set_has_frame(true);
   entry_blz->set_activates_default(false);
   button_uebernehmen->set_flags(Gtk::CAN_FOCUS);
   button_uebernehmen->set_relief(Gtk::RELIEF_NORMAL);
   button_abbrechen->set_flags(Gtk::CAN_FOCUS);
   button_abbrechen->set_relief(Gtk::RELIEF_NORMAL);
   table5->set_row_spacings(0);
   table5->set_col_spacings(0);
   table5->attach(*button_uebernehmen, 0, 1, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 4, 5);
   table5->attach(*button_abbrechen, 1, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 5, 5);
   label_text->set_alignment(0,0.5);
   label_text->set_padding(0,0);
   label_text->set_justify(Gtk::JUSTIFY_CENTER);
   label_text->set_line_wrap(false);
   label_text->set_use_markup(false);
   label_text->set_selectable(false);
   table4->set_row_spacings(0);
   table4->set_col_spacings(0);
   table4->attach(*label11, 0, 1, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 5, 5);
   table4->attach(*label12, 0, 1, 2, 3, Gtk::FILL, Gtk::AttachOptions(), 5, 5);
   table4->attach(*entry_bankname, 1, 2, 1, 2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*entry_blz, 1, 2, 2, 3, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*table5, 0, 2, 3, 4, Gtk::AttachOptions(), Gtk::FILL, 0, 0);
   table4->attach(*label_text, 0, 2, 0, 1, Gtk::AttachOptions(), Gtk::AttachOptions(), 5, 6);
   window_neue_bank_anlegen->set_title("Neue Bank anlegen");
   window_neue_bank_anlegen->set_modal(false);
   window_neue_bank_anlegen->property_window_position().set_value(Gtk::WIN_POS_NONE);
   window_neue_bank_anlegen->set_resizable(true);
   window_neue_bank_anlegen->property_destroy_with_parent().set_value(false);
   window_neue_bank_anlegen->add(*table4);
   label11->show();
   label12->show();
   entry_bankname->show();
   entry_blz->show();
   button_uebernehmen->show();
   button_abbrechen->show();
   table5->show();
   label_text->show();
   table4->show();
   window_neue_bank_anlegen->show();
   entry_bankname->signal_activate().connect(SigC::slot(*this, &window_neue_bank_anlegen_glade::on_entry_bankname_activate), false);
   entry_blz->signal_activate().connect(SigC::slot(*this, &window_neue_bank_anlegen_glade::on_entry_blz_activate), false);
   button_uebernehmen->signal_clicked().connect(SigC::slot(*this, &window_neue_bank_anlegen_glade::on_button_uebernehmen_clicked), false);
   button_abbrechen->signal_clicked().connect(SigC::slot(*this, &window_neue_bank_anlegen_glade::on_button_abbrechen_clicked), false);
}

window_neue_bank_anlegen_glade::~window_neue_bank_anlegen_glade()
{  delete gmm_data;
}
