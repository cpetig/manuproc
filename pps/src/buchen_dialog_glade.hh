// generated 2004/3/1 12:21:05 CET by jacek@jaceksdell.(none)
// using glademm V2.0.0b
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/jacek/cvs/pps/auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/buchen_dialog.hh and./src/buchen_dialog.cc

#ifndef _BUCHEN_DIALOG_GLADE_HH
#  define _BUCHEN_DIALOG_GLADE_HH


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
#include <gtk--/label.h>

class buchen_dialog_glade : public Gnome::Dialog
{  
        
        GlademmData *gmm_data;
protected:
        class Gnome::Dialog *buchen_dialog;
        class Gtk::Label *text;
        class Gtk::Label *text2;
        
        buchen_dialog_glade();
        
        ~buchen_dialog_glade();
};
#endif
