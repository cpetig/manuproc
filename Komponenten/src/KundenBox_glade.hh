// generated 2005/12/19 18:18:37 CET by christof@vesta.petig-baender.de
// using glademm V2.10.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --noaccelerators Komponenten.glade
// for gtk 2.8.9 and gtkmm 2.8.2
//
// Please modify the corresponding derived classes in ././KundenBox.hh and././KundenBox.cc

#ifndef _KUNDENBOX_GLADE_HH
#  define _KUNDENBOX_GLADE_HH

#include <gtkmm/table.h>
#include <gtkmm/label.h>
#include "SearchCombo.hh"
#include "SearchComboContent.hh"

class KundenBox_glade : public Gtk::Table
{  
protected:
        
        class Gtk::Label * label_kdnr;
        class Gtk::Label * label_nam;
        class SearchCombo * kundennr;
        class SearchComboContent<Kunde::ID> * kundenname;
        
        KundenBox_glade();
        
        ~KundenBox_glade();
private:
        virtual void Kundennr_activate() = 0;
        virtual void Kundennr_search(gboolean *cont,GtkSCContext context) = 0;
        virtual void Name_activate() = 0;
        virtual void Name_search(gboolean *cont,GtkSCContext context) = 0;
};
#endif
