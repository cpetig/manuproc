// generated 2003/4/1 12:51:44 MEST by jacek@ijacek.jacek.de
// using glademm V1.1.3f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/auftrag_rechnung.hh and./src/auftrag_rechnung.cc

#ifndef _AUFTRAG_RECHNUNG_GLADE_HH
#  define _AUFTRAG_RECHNUNG_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtk--/accelgroup.h>

class GlademmData
{  
        
        Gtk::AccelGroup *accgrp;
public:
        
        GlademmData(Gtk::AccelGroup *ag) : accgrp(ag)
        {  
        }
        
        Gtk::AccelGroup * getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtk--/window.h>
#include <gtk--/tooltips.h>
#include <libgnomeui/gtkpixmapmenuitem.h>
#include <gtk--/menuitem.h>
#include <gtk--/menu.h>
#include <gtk--/menubar.h>
#include <gtk--/button.h>
#include <gtk--/checkbutton.h>
#include <gtk--/label.h>
#include <gtk--/radiobutton.h>
#include <gtk--/spinbutton.h>
#include <gtk--/table.h>
#include "WWaehrung.hh"
#include <gtk--/optionmenu.h>
#include "Datewin.hh"
#include "SearchComboContent.hh"
#include "KundenBox2.hh"
#include <gtk--/frame.h>
#include "SimpleTree.hh"
#include <gtk--/text.h>
#include <gtk--/entry.h>
#include <gtk--/box.h>

class auftrag_rechnung_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        Gtk::Tooltips _tooltips;
        class Gtk::Window *auftrag_rechnung;
        class Gtk::MenuBar *menubar3;
        class Gtk::MenuItem *pixmapmenuitem1;
        class Gtk::MenuItem *gutschrift;
        class Gtk::MenuItem *trennlinie11;
        class Gtk::MenuItem *storno;
        class Gtk::CheckButton *checkbutton_firmenpapier;
        class Gtk::CheckButton *checkbutton_kopie;
        class Gtk::CheckButton *checkbutton_ean_drucken;
        class Gtk::Label *label_auftragspreis;
        class Gtk::RadioButton *radiobutton_artikelpreis;
        class Gtk::RadioButton *radiobutton_auftragspreis;
        class Gtk::Label *label_artikelpreis;
        class Gtk::RadioButton *radiobutton_preiseingabe;
        class Gtk::SpinButton *spinbutton_preiseingabe;
        class Gtk::Table *table_preisvergleich;
        class Gtk::Button *button27;
        class Gtk::Button *preis_ergaenzen;
        class Gtk::Button *rngentry_del;
        class Gtk::Button *button_pr;
        class WWaehrung *rng_WWaehrung;
        class Gtk::OptionMenu *optionmenu_zahlart;
        struct optionmenu_zahlart
        {  enum enum_t 
	   {  Zahlungsart, 
	   };
        };
        class Datewin *rngdatum;
        class SearchComboContent<int> *rngnr;
        class Gtk::CheckButton *bezahlt;
        class Gtk::OptionMenu *rabatt_typ;
        struct rabatt_typ
        {  enum enum_t 
	   {  Rabatt, Zuschlag, 
	   };
        };
        class Gtk::SpinButton *rabatt_wert;
        class Datewin *zahlziel;
        class Gtk::Label *label_rechnung_ctl;
        class KundenBox2 *lieferkunde;
        class Gtk::Frame *frame_rechnung;
        class SimpleTree *rtree_daten;
        class Gtk::Text *rng_notiz;
        class Gtk::Button *rng_notiz_save;
        class Gtk::Frame *frame_rechnungsdaten;
        class Gtk::Entry *lieferscheinnr;
        class Gtk::Button *lief_uebernehmen;
        class Datewin *lieferscheindatum;
        class Gtk::Button *button_lieferscheine_aufraumen;
        class SimpleTree *rtree_offen;
        class Gtk::VBox *vbox_n_b_lieferscheine;
        
        auftrag_rechnung_glade();
        
        ~auftrag_rechnung_glade();
private:
        virtual void on_rng_close() = 0;
        virtual void on_gutschrift_activate() = 0;
        virtual void on_storno_activate() = 0;
        virtual void on_rng_neu() = 0;
        virtual void on_rng_save() = 0;
        virtual void on_rng_preview() = 0;
        virtual gint on_rng_print(GdkEventButton *ev) = 0;
        virtual void on_checkbutton_ean_drucken_clicked() = 0;
        virtual void Preis_ergaenzen() = 0;
        virtual void rngzeile_delete() = 0;
        virtual void Preis_setzen() = 0;
        virtual void waehrung_geaendert() = 0;
        virtual void optionmenu_zahlart_deactivate() = 0;
        virtual void on_rngdate_activate() = 0;
        virtual void on_rngnr_activate() = 0;
        virtual void on_rngnr_search(gboolean *cont,GtkSCContext context) = 0;
        virtual gint on_bezahlt_toggled(GdkEventButton *ev) = 0;
        virtual void rabatt_geaendert() = 0;
        virtual void on_zahlziel_activate() = 0;
        virtual void on_lieferkunde_activate() = 0;
        virtual void on_rdaten_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_unselectrow_rtree(gint row, gint column, GdkEvent *event) = 0;
        virtual void on_notiz_changed() = 0;
        virtual void on_notiz_save_clicked() = 0;
        virtual void lieferschein_uebernehmen() = 0;
        virtual void on_button_allopen_clicked() = 0;
        virtual void on_button_lieferscheine_aufraumen_clicked() = 0;
        virtual void on_unselectrow_rtree_offen(gint row, gint column, GdkEvent *event) = 0;
        virtual void on_roffen_leaf_selected(cH_RowDataBase leaf) = 0;
};
#endif
