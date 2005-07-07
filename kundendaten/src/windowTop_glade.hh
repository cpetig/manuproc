// generated 2005/6/27 18:11:02 CEST by christof@vesta.petig-baender.de
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- kundendaten.glade
// for gtk 2.7.0 and gtkmm 2.6.3
//
// Please modify the corresponding derived classes in ./src/windowTop.hh and./src/windowTop.cc

#ifndef _WINDOWTOP_GLADE_HH
#  define _WINDOWTOP_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtkmm/accelgroup.h>

class GlademmData
{  
        
        Glib::RefPtr<Gtk::AccelGroup> accgrp;
public:
        
        GlademmData(Glib::RefPtr<Gtk::AccelGroup> ag) : accgrp(ag)
        {  
        }
        
        Glib::RefPtr<Gtk::AccelGroup>  getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtkmm/window.h>
#include <gtkmm/tooltips.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#include "Optionmenu_Kundengruppe.hh"
#include "WTelefon.hh"
#include <gtkmm/frame.h>
#include <gtkmm/entry.h>
#include "LandesBox.hh"
#include "SearchComboContent.hh"
#include <gtkmm/checkbutton.h>
#include <gtkmm/label.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/textview.h>
#include "datewin.hh"
#include "PersonenBox.hh"
#include "KundenBox2.hh"
#include <gtkmm/table.h>
#include "WWaehrung.hh"
#include "ZahlungsArtBox.hh"
#include <gtkmm/notebook.h>
#include "PreisBox.hh"
#include "SimpleTree.hh"
#include <gtkmm/treeview.h>

class windowTop_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
        Gtk::Tooltips _tooltips;
protected:
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * new_entry_button;
#else //
        class Gtk::Button * new_entry_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * clear_button;
#else //
        class Gtk::Button * clear_button;
#endif //
        class Optionmenu_Kundengruppe * gruppenwahl;
        class WTelefon * KundenTelefon;
        class Gtk::Frame * frame_kundenkontakt;
        class Gtk::Entry * entryFirma;
        class Gtk::Entry * entryPostanwVor;
        class Gtk::Entry * entryPostanwNach;
        class Gtk::Entry * entryHausNr;
        class Gtk::Entry * entryStrasse;
        class Gtk::Entry * entryOrt;
        class Gtk::Entry * entryPLZ;
        class Gtk::Entry * entryPostfach;
        class Gtk::Entry * entryPostfachPLZ;
        class LandesBox * landesbox;
        class Gtk::Entry * entryName2;
        class SearchComboContent<int> * scc_anrede;
        class Gtk::Entry * entryIdNr;
        class Gtk::Entry * entrySortiername;
        class Gtk::Frame * frame_adresse;
        class Gtk::CheckButton * kunden_status;
        class Gtk::Label * labelDetailStandEintrag;
        class Gtk::SpinButton * spinbutton_Flaeche;
        class Gtk::SpinButton * spinbutton_Mitarbeiter;
        class Gtk::SpinButton * spinbutton_Kundenumsatz;
        class Gtk::SpinButton * spinbutton_Planumsatz;
        class Gtk::SpinButton * spinbutton_Umsatz;
        class Gtk::Entry * entryVerein;
        class Gtk::TextView * textNotiz;
        class datewin * geburtstag;
        class Gtk::Entry * entry_eigene_kundennr;
        class Gtk::SpinButton * spinbutton_lieferantenkonto;
        class Gtk::SpinButton * spinbutton_debitorenkonto;
        class Gtk::SpinButton * spinbutton_gegenkonto;
        class Gtk::SpinButton * spinbutton_firmenpapier;
        class Gtk::SpinButton * spinbutton_weissespapier;
        class PersonenBox * scc_verkaeufer;
        class PersonenBox * betreuer;
        class KundenBox2 * extartbez;
        class KundenBox2 * rng_an;
        class Gtk::CheckButton * checkbuttonAuftrAdr;
        class Gtk::CheckButton * checkbuttonLieferAdr;
        class Gtk::CheckButton * checkbuttonRchngAdr;
        class Gtk::CheckButton * checkbutton_rng_an_postfach;
        class Gtk::CheckButton * ab_an_rngadresse;
        class KundenBox2 * lfr_an;
        class Gtk::Table * table_details;
        class Gtk::SpinButton * spinbutton_Rabatt;
        class Gtk::CheckButton * checkbutton_zeilenrabatt;
        class Gtk::SpinButton * spinbutton_einzugRabatt;
        class WWaehrung * Waehrung;
        class Gtk::CheckButton * checkbutton_entsorgung;
        class ZahlungsArtBox * zahlungsartbox;
        class Gtk::SpinButton * spinbutton_skontofrist2;
        class Gtk::SpinButton * spinbutton_skontofrist3;
        class Gtk::SpinButton * spinbutton_skontofrist1;
        class Gtk::SpinButton * spinbutton_skontosatz2;
        class Gtk::SpinButton * spinbutton_skontosatz3;
        class Gtk::SpinButton * spinbutton_skontosatz1;
        class Gtk::SpinButton * spinbutton_zahlungsfrist;
        class Gtk::Entry * entryBankKonto;
        class Gtk::Entry * entry_blz;
        class Gtk::Button * button_neue_bank;
        class Gtk::Entry * bankname_entry;
        class Gtk::CheckButton * checkbuttonBankeinzug;
        class Gtk::Entry * abi_entry;
        class Gtk::Entry * cab_entry;
        class Gtk::Button * riba_save;
        class Gtk::Button * riba_abbruch;
        class Gtk::Entry * bankname_italy;
        class Gtk::Entry * acc_entry;
        class Gtk::Entry * iban_entry;
        class Gtk::Button * iban_save;
        class Gtk::Button * iban_abbruch;
        class Gtk::Notebook * zahlverfahren_book;
        class Gtk::CheckButton * checkbutton_lieferung_frei_haus;
        class Gtk::Button * button_del_preisliste;
        class Gtk::Button * button_spreis_add;
        class PreisBox * SPreisBox;
        class SimpleTree * SonderPreislisteTree;
        class Gtk::CheckButton * preisautomatik;
        class Gtk::Frame * frame_preislisten;
        class Gtk::TreeView * clistPersonenListe;
        class Gtk::TextView * textPersonenFirmaNotiz;
        class WTelefon * KontaktPersonenTel;
        class Gtk::Button * button_kontakt_loeschen;
        class Gtk::Entry * entryPersonenPosition;
        class PersonenBox * KontaktPersonenBox;
        class Gtk::Table * table_kontaktperson;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * aufnotiz_save;
#else //
        class Gtk::Button * aufnotiz_save;
#endif //
        class Gtk::TextView * aufnotiz;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * liefnotiz_save;
#else //
        class Gtk::Button * liefnotiz_save;
#endif //
        class Gtk::TextView * liefnotiz;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * rngnotiz_save;
#else //
        class Gtk::Button * rngnotiz_save;
#endif //
        class Gtk::TextView * rngnotiz;
        class SimpleTree * alle_gruppen;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * gruppe_in;
#else //
        class Gtk::Button * gruppe_in;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * gruppe_out;
#else //
        class Gtk::Button * gruppe_out;
#endif //
        class SimpleTree * gewaehlte_gruppen;
        class Gtk::Notebook * notebook_main;
        class KundenBox2 * kundenauswahl;
        class Gtk::Label * label_speichern;
        
        windowTop_glade();
        
        ~windowTop_glade();
private:
        virtual void on_buttonBeenden_clicked() = 0;
        virtual void on_buttonNeu_clicked() = 0;
        virtual void on_clear_button_clicked() = 0;
        virtual void on_gruppenwahl_activate() = 0;
        virtual void on_KundenTelefon_activate(cH_Telefon element) = 0;
        virtual void on_KundenTelefon_remove(cH_Telefon element) = 0;
        virtual void scc_anrede_search(gboolean *cont,GtkSCContext context) = 0;
        virtual void on_kunden_status_toggled() = 0;
        virtual void scc_verkaeufer_reset() = 0;
        virtual void scc_verkaeufer_activate() = 0;
        virtual void on_betreuer_activate() = 0;
        virtual void on_ab_an_rngadresse_toggled() = 0;
        virtual void on_lfran_activate() = 0;
        virtual void on_button_neue_bank_clicked() = 0;
        virtual bool on_abi_entry_changed(GdkEventFocus *ev) = 0;
        virtual bool on_cab_entry_changed(GdkEventFocus *ev) = 0;
        virtual void on_riba_save_clicked() = 0;
        virtual void on_riba_abbruch_clicked() = 0;
        virtual bool on_acc_entry_changed(GdkEventFocus *ev) = 0;
        virtual bool on_iban_entry_changed(GdkEventFocus *ev) = 0;
        virtual void on_iban_save_clicked() = 0;
        virtual void on_iban_abbruch_clicked() = 0;
        virtual void on_zahlverfahren_book_switch_page(GtkNotebookPage *p0, guint p1) = 0;
        virtual void on_button_del_preisliste_clicked() = 0;
        virtual void on_button_spreis_add_clicked() = 0;
        virtual void on_SPreisListe_activate() = 0;
        virtual void on_spreis_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_spreis_unselect_row() = 0;
        virtual void on_preisautomatik_clicked() = 0;
        virtual void on_KontaktPersonTelefon_activate(cH_Telefon element) = 0;
        virtual void on_KontaktPersonTelefon_remove(cH_Telefon element) = 0;
        virtual void on_button_kontakt_loeschen_clicked() = 0;
        virtual void on_entryPersonenPosition_activate() = 0;
        virtual void on_kontakt_personen_box_activate() = 0;
        virtual void on_aufnotiz_save_clicked() = 0;
        virtual void on_aufnotiz_changed() = 0;
        virtual void on_liefnotiz_save_clicked() = 0;
        virtual void on_liefnotiz_changed() = 0;
        virtual void on_rngnotiz_save_clicked() = 0;
        virtual void on_rngnotiz_changed() = 0;
        virtual void on_selectrow_allegruppen(cH_RowDataBase leaf) = 0;
        virtual void on_unselectrow_allegruppen() = 0;
        virtual void on_gruppe_in_clicked() = 0;
        virtual void on_gruppe_out_clicked() = 0;
        virtual void on_selectrow_gewaehltegruppen(cH_RowDataBase leaf) = 0;
        virtual void on_unselectrow_gewaehltegruppen() = 0;
        virtual void on_notebook1_switch_page(GtkNotebookPage *p0, guint p1) = 0;
        virtual void kunden_activate() = 0;
        virtual void on_kunden_reset() = 0;
        virtual bool on_delete_event(GdkEventAny *ev) = 0;
};
#endif
