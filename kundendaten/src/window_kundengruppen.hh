// $Id: window_kundengruppen.hh,v 1.2 2006/01/10 10:32:51 christof Exp $

#ifndef _WINDOW_KUNDENGRUPPEN_HH
#  include "window_kundengruppen_glade.hh"
#  define _WINDOW_KUNDENGRUPPEN_HH
class window_kundengruppen : public window_kundengruppen_glade
{	void on_gruppenwahl_activate();
        void neu();
        void loeschen();
        void entfernen();
        void add();
        void laden();
public:
  window_kundengruppen(int id);
};
#endif