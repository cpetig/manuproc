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

#include "auftragbase.h"
#include "AufEintrag.h"
#include <Aux/Ausgabe_neu.h>
#include <Auftrag/AuftragFull.h>
#include <Aux/EntryValueDatum.h>

const cH_EntryValue AufEintrag::getSeqValue(int seqnr) const
{

 switch(seqnr)
  {
#warning seqnr=bezkomptype for 1-4 (hack) 
#warning bloss weg mit diesem Code!
	case ART_SEQ :return (*artikel)[ART_SEQ];
          break;
	case BR_SEQ :return (*artikel)[BR_SEQ];
          break;
	case FB_SEQ :return (*artikel)[FB_SEQ];
          break;
	case AUFM_SEQ :return (*artikel)[AUFM_SEQ];
          break;
	case KW_SEQ : return cH_EntryValueDatum(lieferdatum);
	case AUFID_SEQ : return cH_EntryValueIntString(auftragid);
        case KNDNR_SEQ : return cH_EntryValueIntString(kdnr);
           // das sortiert so nie richtig ... lieber 2 Spalten
	case PROZ_SEQ : 
           {  if (prozess->Id())
              {  string res=prozess->getTyp()+" "+prozess->getText()+" "
              		+ getProzDat().c_str();
                 return cH_EntryValueIntString(res);
              }
              return cH_EntryValueIntString("");
           }
	default : return cH_EntryValue();
  }
}

ostream &operator<<(ostream &o,const AufEintrag &a)
{
 o 	<< a.getStueck() << "\t"
	<< a.getSeqValue(ART_SEQ)->getStrVal() << "\t"
	<< a.getSeqValue(BR_SEQ)->getStrVal() << "\t"
	<< a.getSeqValue(FB_SEQ)->getStrVal() << "\t"   
	<< a.getSeqValue(AUFM_SEQ)->getStrVal() << "\t"
	<< a.getMeter() << "\t";

 int rest=a.getRest();  	    	    
 if(rest>0) o << rest << "\t";	    	    	    	    
 else o << "" << "\t";
 o	<< Formatiere(a.GPreis().Wert(),2,0,".") << "\t";
 try {    
        Petig::Datum d(a.getLieferdatum());
	o << d.KW().Woche()<<"'"<<d.Jahr();
 } catch (Petig::Datumsfehler &e)
 {  o << "Fehler"; }
 o << '\t' << a.getEntryStatusStr() << '\t';
 try { o << a.LastEditDate().c_str();
 } catch (Petig::Datumsfehler &e)
 {  o << "Fehler"; }
 o << '\n';
 return o;
}

