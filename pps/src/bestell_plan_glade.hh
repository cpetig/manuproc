// generated 2005/1/27 12:40:08 CET by jacek@jaceksdell.(none)
// using glademm V2.6.0_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/bestell_plan.hh and./src/bestell_plan.cc

#ifndef _BESTELL_PLAN_GLADE_HH
#  define _BESTELL_PLAN_GLADE_HH


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
#include <gtk--/button.h>
#include "ArtikelBox.hh"
#include <gtk--/entry.h>

class bestell_plan_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        class Gtk::Button * bp_quit;
        class Gtk::Button * prev_artikel;
        class Gtk::Button * next_artikel;
        class ArtikelBox * plan_artikel;
        class Gtk::Entry * bp_lagerbestand;
        class Gtk::Entry * bp_offauftraege;
        class Gtk::Entry * bp_verfuegbar;
        class Gtk::Entry * bp_bestellt;
        class Gtk::Entry * bp_mindbestand;
        class Gtk::Entry * bp_abv12m;
        class Gtk::Entry * bp_abv12m1;
        class Gtk::Entry * bp_abv12m2;
        class Gtk::Entry * bp_abv12m3;
        
        bestell_plan_glade();
        
        ~bestell_plan_glade();
private:
        virtual void on_bp_quit_clicked() = 0;
        virtual void on_prev_artikel_clicked() = 0;
        virtual void on_next_artikel_clicked() = 0;
        virtual void on_plan_artikel_activate() = 0;
};
#endif
