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
// newer (non customized) versions of this file go to auftrag_rechnung.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "auftrag_rechnung.hh"
#include<Aux/Ausgabe_neu.h>
#include<Aux/itos.h>
#include <Artikel/Artikelpreis.h>
#include <gtk--/menu.h>

#include"MyMessage.h"
extern MyMessage *meldung;

void auftrag_rechnung::on_rng_close()
{   
   destroy();
}

void auftrag_rechnung::on_rng_neu()
{   
 rechnung_liste->newRechnung(lieferkunde->get_value());
 rngnr->setContent(Formatiere(rechnung_liste->getRechnung().Id(),0,0,""),
			rechnung_liste->getRechnung().Id());
 // waehrung setzen etc.
}

void auftrag_rechnung::on_rng_save()
{   
}

void auftrag_rechnung::on_rng_preview()
{   
   string command = "auftrag_drucken Rechnung "+rngnr->get_text()+" Preview";
   system(command.c_str());
}

void auftrag_rechnung::on_rng_print()
{   
   string command = "auftrag_drucken Rechnung "+rngnr->get_text()+" Plot";
   system(command.c_str());
}

void auftrag_rechnung::rngzeile_delete()
{
 try{   
 if(selectedrow_rng)
   {const Rechnung &rg=rechnung_liste->getRechnung();
   if(!(rg.Bezahlt()))
	{
	 cH_Rg_RowData entry((dynamic_cast<TCListLeaf*>(selectedrow_rng))->LeafData());
	 const_cast<Rechnung&>(rg).deleteLieferschein(entry->LiefId());
	 on_rngnr_activate();
	}
   }
 }
 catch(SQLerror &e)
  {meldung->Show(e); return;}

 selectedrow_rng=NULL;
 rngentry_del->set_sensitive(false); 

}

void auftrag_rechnung::on_rngdate_activate()
{   

}

void auftrag_rechnung::on_rngnr_activate()
{try{ 
 rechnung_liste->clear();
 rechnung_liste->showRechnung(rngnr->Content());
 lieferkunde->set_value(rechnung_liste->getRechnung().KdNr());   
 offene_lieferscheine->setKunde(cH_Kunde(lieferkunde->get_value()));
 offene_lieferscheine->clear();
 offene_lieferscheine->showOffLief();
 if (*(rechnung_liste->getRechnung().getWaehrung())==Waehrung::EUR)
    rng_waehrung->set_history(rng_waehrung::Euro);
 else if (*(rechnung_liste->getRechnung().getWaehrung())==Waehrung::DM)
    rng_waehrung->set_history(rng_waehrung::DM);
 }
 catch(SQLerror &e) {meldung->Show(e);}
}

void auftrag_rechnung::on_lieferkunde_activate()
{
 offene_lieferscheine->setKunde(cH_Kunde(lieferkunde->get_value()));
 offene_lieferscheine->showOffLief();   
}

void auftrag_rechnung::preis_activate()
{   
}

void auftrag_rechnung::lieferschein_uebernehmen()
{   
 try{
 if(selectedrow_lief)
   {if (rechnung_liste->getRechnung().Id()<1) on_rng_neu();
   const Rechnung &rg=rechnung_liste->getRechnung();
   if(!(rg.Bezahlt()))
	{
	 cH_OffLief_RowData entry((dynamic_cast<TCListLeaf*>(selectedrow_lief))->LeafData());
	 const_cast<Rechnung&>(rg).addLieferschein(entry->Lief().Id());
	 on_rngnr_activate();
	}
   }
 }
 catch(SQLerror &e)
 {meldung->Show(e);return;}

}

void auftrag_rechnung::on_selectrow_rechnung(int row, int col, GdkEvent* b)
{
 TCListRow_API *tclapi=(TCListRow_API*)(rechnung_liste->get_row_data(row));
 selectedrow_rng=(TCListRowData*)(*tclapi).get_user_data();

 if(!selectedrow_rng->Leaf()) return;

 // es ging nicht mit dynamic_cast auf OffAuf_Leaf ??!!
 cH_Rg_RowData entry((dynamic_cast<TCListLeaf*>(selectedrow_rng))->LeafData());

 
 rngentry_del->set_sensitive(true); 
}
void auftrag_rechnung::on_unselectrow_rechnung(int row, int col, GdkEvent* b)
{
 selectedrow_rng=NULL;
 rngentry_del->set_sensitive(false); 
}


void auftrag_rechnung::on_selectrow_offlief(int row, int col, GdkEvent* b)
{
 TCListRow_API *tclapi=(TCListRow_API*)(offene_lieferscheine->get_row_data(row));
 selectedrow_lief=(TCListRowData*)(*tclapi).get_user_data();

 // es ging nicht mit dynamic_cast auf OffAuf_Leaf ??!!
 cH_OffLief_RowData entry((dynamic_cast<TCListLeaf*>(selectedrow_lief))->LeafData());

 lieferscheinnr->set_text(itos(entry->Lief().Id()));
 lieferscheindatum->set_value(entry->Lief().LsDatum()); 
 
 lief_uebernehmen->set_sensitive(true); 
}

void auftrag_rechnung::on_unselectrow_offlief(int row, int col, GdkEvent* b)
{
 selectedrow_lief=NULL;
 lieferscheinnr->set_text("");
 lieferscheindatum->set_value(Petig::Datum::today());  
 lief_uebernehmen->set_sensitive(false); 
}        

void auftrag_rechnung::Preis_setzen()
{  Rechnung &rg=rechnung_liste->getRechnung();
   for (Rechnung::iterator i=rg.begin();i!=rg.end();++i)
   {  Artikelpreis p(cH_Kunde(lieferkunde->get_value())->Preisliste(),i->ArtikelID());
      if (!!p)
      {  i->setzePreis(p.In(rg.getWaehrung()));
      }
   }
}

void auftrag_rechnung::waehrung_geaendert()
{  switch (rng_waehrung::enum_t(int(rng_waehrung->get_menu()->get_active()->get_user_data())))
   {  case rng_waehrung::DM: rechnung_liste->getRechnung().setzeWaehrung(Waehrung::DM);
   	 break;
      case rng_waehrung::Euro: rechnung_liste->getRechnung().setzeWaehrung(Waehrung::EUR);
   	 break;
   }
   // eigentlich alle Preise umrechnen .... Katastrophe
}
