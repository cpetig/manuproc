// generated 2002/11/22 18:14:41 CET by christof@puck.petig-baender.de
// using glademm V1.1.2a_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- kundendaten.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/dialogBestaetigen.hh and./src/dialogBestaetigen.cc

#ifndef _DIALOGBESTAETIGEN_GLADE_HH
#  define _DIALOGBESTAETIGEN_GLADE_HH

#include <gnome--/dialog.h>
#include <gtk--/entry.h>

class dialogBestaetigen_glade : public Gnome::Dialog
{  
protected:
        
        class Gnome::Dialog *dialogBestaetigen;
        class Gtk::Entry *neuekdnr;
        
        dialogBestaetigen_glade();
        
        ~dialogBestaetigen_glade();
private:
        virtual void newrng_ok() = 0;
        virtual void newrng_cancel() = 0;
};
#endif
