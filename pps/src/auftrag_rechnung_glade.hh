// generated 2006/3/9 16:53:33 CET by jacek@jaceksdell.(none)
// using glademm V2.10.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/Monotone/pps/auftrag.glade
// for gtk 2.8.6 and gtkmm 2.8.0
//
// Please modify the corresponding derived classes in ./src/auftrag_rechnung.hh and./src/auftrag_rechnung.cc

#ifndef _AUFTRAG_RECHNUNG_GLADE_HH
#  define _AUFTRAG_RECHNUNG_GLADE_HH


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
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/menubar.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#include <gtkmm/checkbutton.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#include <gtkmm/optionmenu.h>
#include "SearchComboContent.hh"
#include <gtkmm/label.h>
#include "WWaehrung.hh"
#include "KundenBox2.hh"
#include "datewin.hh"
#include <gtkmm/spinbutton.h>
#include <gtkmm/handlebox.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/expander.h>
#else //
#endif //
#include <gtkmm/radiobutton.h>
#include "SimpleTree.hh"
#include <gtkmm/textview.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>

class auftrag_rechnung_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        Gtk::Tooltips _tooltips;
        class Gtk::Window * auftrag_rechnung;
        class Gtk::ImageMenuItem * gutschrift;
        class Gtk::ImageMenuItem * storno;
        class Gtk::MenuBar * menubar3;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * button27;
#else //
        class Gtk::Button * button27;
#endif //
        class Gtk::CheckButton * checkbutton_ean_drucken;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * preis_ergaenzen;
#else //
        class Gtk::Button * preis_ergaenzen;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * rngentry_del;
#else //
        class Gtk::Button * rngentry_del;
#endif //
        class Gtk::OptionMenu * optionmenu_zahlart;
        struct optionmenu_zahlart
        {  enum enum_t 
	   {  Zahlungsart, 
	   };
        };
        class SearchComboContent<int> * rngnr;
        class Gtk::CheckButton * bezahlt;
        class Gtk::Label * label_rechnung_ctl;
        class WWaehrung * rng_WWaehrung;
        class KundenBox2 * lieferkunde;
        class datewin * rngdatum;
        class Gtk::OptionMenu * rabatt_typ;
        struct rabatt_typ
        {  enum enum_t 
	   {  Rabatt, Zuschlag, 
	   };
        };
        class datewin * zahlziel;
        class Gtk::SpinButton * rabatt_wert;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::Expander * frame_rechnung;
#else //
        class Gtk::HandleBox * frame_rechnung;
#endif //
        class Gtk::RadioButton * radiobutton_artikelpreis;
        class Gtk::Label * label_artikelpreis;
        class Gtk::RadioButton * radiobutton_auftragspreis;
        class Gtk::Label * label_auftragspreis;
        class Gtk::RadioButton * radiobutton_preiseingabe;
        class Gtk::SpinButton * spinbutton_preiseingabe;
        class Gtk::Button * button_pr;
        class SimpleTree * rtree_daten;
        class Gtk::Label * label_waehrung1;
        class Gtk::Label * label_waehrung2;
        class Gtk::SpinButton * rgbetrag_warenwert;
        class Gtk::SpinButton * rgbetrag_netto;
        class Gtk::Label * label_waehrung6;
        class Gtk::Label * label_waehrung7;
        class Gtk::SpinButton * rgbetrag_rabatt;
        class Gtk::SpinButton * rgbetrag_mwst;
        class Gtk::SpinButton * rgbetrag_endsumme;
        class Gtk::Label * label_waehrung3;
        class Gtk::Label * label_waehrung4;
        class Gtk::Label * label_waehrung5;
        class Gtk::SpinButton * rgbetrag_zusabs;
        class Gtk::SpinButton * rgbetrag_zwsumme;
        class Gtk::CheckButton * entsorgung;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::Expander * frame_betrag;
#else //
        class Gtk::HandleBox * frame_betrag;
#endif //
        class Gtk::TextView * rng_notiz;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * rng_notiz_save;
#else //
        class Gtk::Button * rng_notiz_save;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::Expander * expander_notiz;
#else //
        class Gtk::HandleBox * expander_notiz;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::Expander * frame_rechnungsdaten;
#else //
        class Gtk::HandleBox * frame_rechnungsdaten;
#endif //
        class Gtk::Entry * lieferscheinnr;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * button_lieferscheine_aufraumen;
#else //
        class Gtk::Button * button_lieferscheine_aufraumen;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::ToolButton * lief_uebernehmen;
#else //
        class Gtk::Button * lief_uebernehmen;
#endif //
        class datewin * lieferscheindatum;
        class SimpleTree * rtree_offen;
        class Gtk::VBox * vbox_n_b_lieferscheine;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
        class Gtk::Expander * expander_ls;
#else //
        class Gtk::HandleBox * expander_ls;
#endif //
        
        auftrag_rechnung_glade();
        
        ~auftrag_rechnung_glade();
private:
        virtual void on_rng_close() = 0;
        virtual void on_gutschrift_activate() = 0;
        virtual void on_storno_activate() = 0;
        virtual void on_provisionierung_activate() = 0;
        virtual void on_rng_neu() = 0;
        virtual void on_clear_all() = 0;
        virtual void on_rng_preview() = 0;
        virtual void on_rng_print() = 0;
        virtual void on_checkbutton_ean_drucken_clicked() = 0;
        virtual void Preis_ergaenzen() = 0;
        virtual void rngzeile_delete() = 0;
        virtual void optionmenu_zahlart_deactivate() = 0;
        virtual void on_rngnr_activate() = 0;
        virtual void on_rngnr_search(gboolean *cont,GtkSCContext context) = 0;
        virtual void on_bezahlt_toggled() = 0;
        virtual void waehrung_geaendert() = 0;
        virtual void on_lieferkunde_activate() = 0;
        virtual void on_lieferkunde_reset() = 0;
        virtual void on_rngdate_activate() = 0;
        virtual void rabatt_geaendert() = 0;
        virtual void on_zahlziel_activate() = 0;
        virtual void on_radiobutton_preiseingabe_toggled() = 0;
        virtual void Preis_setzen() = 0;
        virtual void on_rdaten_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_unselectrow_rtree() = 0;
        virtual void on_entsorgung_toggled() = 0;
        virtual void on_notiz_changed() = 0;
        virtual void on_notiz_save_clicked() = 0;
        virtual void on_button_allopen_clicked() = 0;
        virtual void on_button_lieferscheine_aufraumen_clicked() = 0;
        virtual void lieferschein_uebernehmen() = 0;
        virtual void on_unselectrow_rtree_offen() = 0;
        virtual void on_roffen_leaf_selected(cH_RowDataBase leaf) = 0;
};
#endif
