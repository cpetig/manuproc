// generated 2002/2/19 14:47:36 CET by christof@puck.petig-baender.de
// using glademm V0.6.2b
//
// some glademm convenience functions
//
// DO NOT EDIT THIS FILE !

#include "config.h"
#include "glademm_support.hh"

static std::map<const __STD::string,Gtk::Widget *> glademm_widgets;

Gtk::Widget * glademm_get_Widget(const __STD::string &name)
{   
   
   std::map<const __STD::string,Gtk::Widget *>::iterator i=glademm_widgets.find(name);
   if (i==glademm_widgets.end()) return 0;
   return (*i).second;
}

void glademm_set_Widget(const __STD::string &name, Gtk::Widget *val)
{   glademm_widgets[name]=val;
}