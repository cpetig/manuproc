// generated 2003/6/19 16:11:12 CEST by jacek@jaceksdell.(none)
// using glademm V2.0.0b
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/auftrag_provision.cc

#include "config.h"
#include "auftrag_provision_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <vector>
#include <libgnomeui/gnome-stock.h>
#include <gtk--/buttonbox.h>
#include <gtk--/frame.h>
#include <gtk--/box.h>
#include <gtk--/table.h>
#include <gtk--/label.h>
#include <gtk--/adjustment.h>
#include <gtk--/scrolledwindow.h>

auftrag_provision_glade::auftrag_provision_glade(
) : Gnome::Dialog("Provisionierung", std::vector<std::string>())
{  auftrag_provision = this;
   
   Gtk::AccelGroup *auftrag_provision_accgrp = Gtk::AccelGroup::create();
   gmm_data = new GlademmData(auftrag_provision_accgrp);
   auftrag_provision->append_button(GNOME_STOCK_BUTTON_OK);
   auftrag_provision->append_button(GNOME_STOCK_BUTTON_CANCEL);
   prov_aufkunde = new class KundenBox2();
   
   Gtk::Frame *frame49 = manage(new class Gtk::Frame("Kunde"));
   prov_aufnr = manage(new class Gtk::Entry());
   
   Gtk::Frame *frame47 = manage(new class Gtk::Frame("Nummer"));
   prov_aufdatum = new class datewin();
   
   Gtk::Frame *frame48 = manage(new class Gtk::Frame("vom"));
   Gtk::HBox *hbox28 = manage(new class Gtk::HBox(false, 0));
   Gtk::Table *table27 = manage(new class Gtk::Table(2, 2, false));
   Gtk::Frame *frame46 = manage(new class Gtk::Frame("Auftrag"));
   prov_enable = manage(new class Gtk::CheckButton("Provision gew�hren", 0, 0.5));
   prov_verkaeufer = new class KundenBox2();
   
   Gtk::Frame *frame51 = manage(new class Gtk::Frame("Verk�ufer"));
   Gtk::Label *label100 = manage(new class Gtk::Label("Provision setzten auf "));
   Gtk::Adjustment *prov_provsatz_adj = manage(new class Gtk::Adjustment(0, 0, 100, 1, 10, 10));
   prov_provsatz = manage(new class Gtk::SpinButton(*prov_provsatz_adj, 1, 2));
   
   Gtk::Label *label108 = manage(new class Gtk::Label("%"));
   prov_apply = Gtk::wrap((GtkButton*)gnome_stock_button(GNOME_STOCK_BUTTON_APPLY));
   
   Gtk::HBox *hbox27 = manage(new class Gtk::HBox(false, 0));
   prov_aufentries = manage(new class Gtk::CList(7));
   
   Gtk::ScrolledWindow *scrolledwindow17 = manage(new class Gtk::ScrolledWindow());
   Gtk::Frame *frame53 = manage(new class Gtk::Frame("Auftragspositionen"));
   Gtk::VBox *vbox22 = manage(new class Gtk::VBox(false, 0));
   Gtk::VBox *vbox21 = manage(new class Gtk::VBox(false, 0));
   Gtk::Frame *frame52 = manage(new class Gtk::Frame("Provisionierung"));
   Gtk::VBox *vbox20 = manage(new class Gtk::VBox(false, 0));
   verkprov_frame = manage(new class Gtk::Frame("Verk�ufer & Provision"));
   
   Gtk::VBox *vbox19 = manage(new class Gtk::VBox(false, 0));
   auftrag_provision->get_button(0)->set_flags(GTK_CAN_FOCUS);
   auftrag_provision->get_button(1)->set_flags(GTK_CAN_FOCUS);
   prov_aufkunde->set_sensitive(false);
   frame49->set_shadow_type(GTK_SHADOW_NONE);
   frame49->set_label_align(0,0);
   frame49->add(*prov_aufkunde);
   prov_aufnr->set_sensitive(false);
   prov_aufnr->set_flags(GTK_CAN_FOCUS);
   prov_aufnr->set_visibility(true);
   prov_aufnr->set_editable(false);
   prov_aufnr->set_text("");
   frame47->set_shadow_type(GTK_SHADOW_NONE);
   frame47->set_label_align(0,0);
   frame47->add(*prov_aufnr);
   prov_aufdatum->set_sensitive(false);
   frame48->set_shadow_type(GTK_SHADOW_NONE);
   frame48->set_label_align(0,0);
   frame48->add(*prov_aufdatum);
   hbox28->pack_start(*frame47, false, true, 0);
   hbox28->pack_start(*frame48, false, true, 0);
   table27->set_row_spacings(0);
   table27->set_col_spacings(0);
   table27->attach(*frame49, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table27->attach(*hbox28, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   frame46->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame46->set_label_align(0,0);
   frame46->add(*table27);
   prov_enable->set_flags(GTK_CAN_FOCUS);
   prov_enable->set_mode(true);
   prov_enable->set_active(true);
   frame51->set_shadow_type(GTK_SHADOW_NONE);
   frame51->set_label_align(0,0);
   frame51->add(*prov_verkaeufer);
   label100->set_alignment(0.5,0.5);
   label100->set_padding(0,0);
   label100->set_justify(GTK_JUSTIFY_CENTER);
   label100->set_line_wrap(false);
   prov_provsatz->set_usize(60,-1);
   prov_provsatz->set_flags(GTK_CAN_FOCUS);
   prov_provsatz->set_update_policy(GTK_UPDATE_ALWAYS);
   prov_provsatz->set_numeric(true);
   prov_provsatz->set_digits(2);
   prov_provsatz->set_wrap(false);
   prov_provsatz->set_snap_to_ticks(false);
   label108->set_alignment(0.5,0.5);
   label108->set_padding(0,0);
   label108->set_justify(GTK_JUSTIFY_CENTER);
   label108->set_line_wrap(false);
   prov_apply->set_sensitive(false);
   prov_apply->set_flags(GTK_CAN_FOCUS);
   prov_apply->set_relief(GTK_RELIEF_NORMAL);
   hbox27->pack_start(*label100, false, false, 0);
   hbox27->pack_start(*prov_provsatz, false, false, 0);
   hbox27->pack_start(*label108, false, false, 0);
   hbox27->pack_start(*prov_apply, false, false, 0);
   prov_aufentries->set_flags(GTK_CAN_FOCUS);
   prov_aufentries->set_column_title(0, "Zeilennr");
   prov_aufentries->set_column_justification(0, GTK_JUSTIFY_RIGHT);
   prov_aufentries->set_column_width(0, 80);
   prov_aufentries->set_column_title(1, "St�ck");
   prov_aufentries->set_column_justification(1, GTK_JUSTIFY_RIGHT);
   prov_aufentries->set_column_width(1, 80);
   prov_aufentries->set_column_title(2, "Artikel");
   prov_aufentries->set_column_width(2, 80);
   prov_aufentries->set_column_title(3, "Preis");
   prov_aufentries->set_column_justification(3, GTK_JUSTIFY_RIGHT);
   prov_aufentries->set_column_width(3, 80);
   prov_aufentries->set_column_title(4, "Rabatt");
   prov_aufentries->set_column_justification(4, GTK_JUSTIFY_RIGHT);
   prov_aufentries->set_column_width(4, 80);
   prov_aufentries->set_column_title(5, "Gesamtpreis");
   prov_aufentries->set_column_justification(5, GTK_JUSTIFY_RIGHT);
   prov_aufentries->set_column_width(5, 80);
   prov_aufentries->set_column_title(6, "Provisionssatz");
   prov_aufentries->set_column_justification(6, GTK_JUSTIFY_RIGHT);
   prov_aufentries->set_column_width(6, 80);
   prov_aufentries->set_selection_mode(GTK_SELECTION_EXTENDED);
   prov_aufentries->set_shadow_type(GTK_SHADOW_IN);
   prov_aufentries->column_titles_show();
   scrolledwindow17->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow17->add(*prov_aufentries);
   frame53->set_shadow_type(GTK_SHADOW_NONE);
   frame53->set_label_align(0,0);
   frame53->add(*scrolledwindow17);
   vbox22->pack_start(*frame53);
   vbox21->pack_start(*hbox27, false, true, 0);
   vbox21->pack_start(*vbox22);
   frame52->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame52->set_label_align(0,0);
   frame52->add(*vbox21);
   vbox20->pack_start(*frame51, false, true, 0);
   vbox20->pack_start(*frame52);
   verkprov_frame->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   verkprov_frame->set_label_align(0,0);
   verkprov_frame->add(*vbox20);
   vbox19->pack_start(*frame46, false, false, 0);
   vbox19->pack_start(*prov_enable, false, false, 0);
   vbox19->pack_start(*verkprov_frame);
   auftrag_provision->get_vbox()->set_homogeneous(false);
   auftrag_provision->get_vbox()->set_spacing(8);
   auftrag_provision->get_vbox()->pack_start(*vbox19, false, true, 0);
   auftrag_provision->set_title("Provisionierung");
   auftrag_provision->set_default_size(600,500);
   auftrag_provision->set_modal(true);
   auftrag_provision->set_position(GTK_WIN_POS_CENTER);
   auftrag_provision->set_policy(true, true, true);
   auftrag_provision->add_accel_group(*(gmm_data->getAccelGroup()));
   
   Gtk::HButtonBox *dialog_action_area4 = Gtk::wrap((GtkHButtonBox*)GNOME_DIALOG(auftrag_provision->gtkobj())->action_area);
   dialog_action_area4->set_spacing(8);
   dialog_action_area4->set_spacing(8);
   auftrag_provision->close_hides(false);
   prov_aufkunde->show();
   frame49->show();
   prov_aufnr->show();
   frame47->show();
   prov_aufdatum->show();
   frame48->show();
   hbox28->show();
   table27->show();
   frame46->show();
   prov_enable->show();
   prov_verkaeufer->show();
   frame51->show();
   label100->show();
   prov_provsatz->show();
   label108->show();
   prov_apply->show();
   hbox27->show();
   prov_aufentries->show();
   scrolledwindow17->show();
   frame53->show();
   vbox22->show();
   vbox21->show();
   frame52->show();
   vbox20->show();
   verkprov_frame->show();
   vbox19->show();
   auftrag_provision->show();
   auftrag_provision->get_button(0)->clicked.connect(SigC::slot(this, &auftrag_provision_glade::on_prov_ok_clicked));
   auftrag_provision->get_button(1)->clicked.connect(SigC::slot(this, &auftrag_provision_glade::on_prov_cancel_clicked));
   prov_enable->toggled.connect(SigC::slot(this, &auftrag_provision_glade::on_prov_enable_toggled));
   prov_verkaeufer->activate.connect(SigC::slot(this, &auftrag_provision_glade::on_prov_verk_activate));
   prov_provsatz->changed.connect(SigC::slot(this, &auftrag_provision_glade::on_prov_provsatz_changed));
   prov_apply->clicked.connect(SigC::slot(this, &auftrag_provision_glade::on_prov_apply_clicked));
}

auftrag_provision_glade::~auftrag_provision_glade()
{  delete prov_aufkunde;
   delete prov_aufdatum;
   delete prov_verkaeufer;
   delete gmm_data;
}
