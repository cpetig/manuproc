// generated 2003/4/9 8:41:54 CEST by christof@puck.petig-baender.de
// using glademm V1.1.3g_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- WinFileReq.glade
// for gtk 2.2.1 and gtkmm 2.2.0
//
// Please modify the corresponding derived classes in ./src/WinFileReq.hh and./src/WinFileReq.cc

#ifndef _WINFILEREQ_GLADE_HH
#  define _WINFILEREQ_GLADE_HH


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

#include <gtkmm/fileselection.h>

class WinFileReq_glade : public Gtk::FileSelection
{  
        
        GlademmData *gmm_data;
protected:
        
        WinFileReq_glade();
        
        ~WinFileReq_glade();
private:
        virtual void on_ok_button1_clicked() = 0;
        virtual void on_cancel() = 0;
};
#endif
