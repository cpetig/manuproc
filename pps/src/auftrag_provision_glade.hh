// generated 2003/6/19 16:08:17 CEST by jacek@jaceksdell.(none)
// using glademm V2.0.0b
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/auftrag_provision.hh and./src/auftrag_provision.cc

#ifndef _AUFTRAG_PROVISION_GLADE_HH
#  define _AUFTRAG_PROVISION_GLADE_HH


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

#include <gnome--/dialog.h>
#include <gtk--/button.h>
#include "KundenBox2.hh"
#include <gtk--/entry.h>
#include "datewin.hh"
#include <gtk--/checkbutton.h>
#include <gtk--/spinbutton.h>
#include <gtk--/clist.h>
#include <gtk--/frame.h>

class auftrag_provision_glade : public Gnome::Dialog
{  
        
        GlademmData *gmm_data;
protected:
        class Gnome::Dialog *auftrag_provision;
        class KundenBox2 *prov_aufkunde;
        class Gtk::Entry *prov_aufnr;
        class datewin *prov_aufdatum;
        class Gtk::CheckButton *prov_enable;
        class KundenBox2 *prov_verkaeufer;
        class Gtk::SpinButton *prov_provsatz;
        class Gtk::Button *prov_apply;
        class Gtk::CList *prov_aufentries;
        class Gtk::Frame *verkprov_frame;
        
        auftrag_provision_glade();
        
        ~auftrag_provision_glade();
private:
        virtual void on_prov_ok_clicked() = 0;
        virtual void on_prov_cancel_clicked() = 0;
        virtual void on_prov_enable_toggled() = 0;
        virtual void on_prov_verk_activate() = 0;
        virtual void on_prov_provsatz_changed() = 0;
        virtual void on_prov_apply_clicked() = 0;
};
#endif
