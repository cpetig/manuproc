// generated 2005/9/12 11:16:21 CEST by jacek@woody.mabella.de
// using glademm V2.10.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- auftrag.glade
// for gtk 1.2.10 and gtkmm 1.2.8
//
// Please modify the corresponding derived classes in ./src/petig_we.hh and./src/petig_we.cc

#ifndef _PETIG_WE_GLADE_HH
#  define _PETIG_WE_GLADE_HH


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
#include <gtk--/entry.h>

class petig_we_glade : public Gnome::Dialog
{  
        
        GlademmData *gmm_data;
protected:
        class Gtk::Entry * we_lfrsid;
        
        petig_we_glade();
        
        ~petig_we_glade();
private:
        virtual void on_petig_we_ok_clicked() = 0;
        virtual void on_petig_we_cancel_clicked() = 0;
};
#endif
