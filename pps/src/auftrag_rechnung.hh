/*  pps: ManuProC's ProductionPlanningSystem
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

// generated 2001/3/28 15:07:10 CEST by jacek@mimi.
// using glademm V0.5_11f_cvs
//
// newer (non customized) versions of this file go to auftrag_rechnung.hh_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _AUFTRAG_RECHNUNG_HH
#  include "auftrag_rechnung_glade.hh"
#  define _AUFTRAG_RECHNUNG_HH
#include "glademm_support.hh"

#include<Kunde/Kunde.h>

class auftrag_rechnung : public auftrag_rechnung_glade
{   
        friend class auftrag_rechnung_glade;
        void on_rng_close();
        void on_rng_neu();
        void on_rng_save();
        void on_rng_preview();
        void on_rng_print();
        void rngzeile_delete();
        void on_rngdate_activate();
        void on_rngnr_activate();
        void on_rngnr_search(int *_continue, GtkSCContext newsearch);
        void on_lieferkunde_activate();
        void on_selectrow_rechnung(int row, int col, GdkEvent* b);
        void on_unselectrow_rechnung(int row, int col, GdkEvent* b);
        void preis_activate();
        void lieferschein_uebernehmen();
        void on_selectrow_offlief(int row, int col, GdkEvent* b);
        void on_unselectrow_offlief(int row, int col, GdkEvent* b);        
        void Preis_setzen();
        void waehrung_geaendert();
	void rabatt_geaendert();

 TCListRowData *selectedrow_lief;
 TCListRowData *selectedrow_rng;
 cH_Kunde kunde;

public:
 auftrag_rechnung() : selectedrow_lief(NULL), selectedrow_rng(NULL),
			kunde(Kunde::none_id){}

};
#endif
