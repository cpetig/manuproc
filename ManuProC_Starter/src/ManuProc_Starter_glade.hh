// generated 2004/6/8 16:35:47 CEST by jacek@jaceksdell.(none)
// using glademm V2.0.0.2
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/ManuProC_Starter/manuproc_starter.glade
// for gtk 2.2.4 and gtkmm 2.2.8
//
// Please modify the corresponding derived classes in ./src/ManuProc_Starter.hh and./src/ManuProc_Starter.cc

#ifndef _MANUPROC_STARTER_GLADE_HH
#  define _MANUPROC_STARTER_GLADE_HH


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
#include <gtkmm/button.h>

class ManuProc_Starter_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        class Gtk::Button *pps_start;
        class Gtk::Button *kunden_start;
        class Gtk::Button *lager_start;
        class Gtk::Button *artikel_start;
        class Gtk::Button *quit;
        
        ManuProc_Starter_glade();
        
        ~ManuProc_Starter_glade();
private:
        virtual void on_pps_start_clicked() = 0;
        virtual void on_kunden_start_enter() = 0;
        virtual void on_lager_start_clicked() = 0;
        virtual void on_artikel_start_clicked() = 0;
        virtual void on_quit_clicked() = 0;
};
#endif
