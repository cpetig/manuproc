/* $Id: Rechnung.h,v 1.41 2006/11/16 15:31:35 christof Exp $ */
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 2000-2004 Adolf Petig GmbH & Co. KG
 *  		written by Jacek Jakubowski
 *  Copyright (C) 2006 Christof Petig
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

#ifndef RECHNUNG__
#define RECHNUNG__

#include"RechnungBase.h"
#include<Misc/Waehrung.h>
#include<Misc/SQLerror.h>
#include<Misc/Datum.h>
#include<Kunde/Kunde.h>
#include <vector>
#include "LieferscheinBase.h"
#include <Kunde/Zahlungsart.h>
#include <Misc/Handles.h>
#include <Auftrag/AufEintragBase.h>

#define ENTSSATZ	0.002
//#define MWSTPROZ	16 // kommt aus global_settings

class Preis;

class Rechnung : public RechnungBase
{
private:
 cH_Kunde kunde;
 RngArt rngart;
 ManuProC::Datum zahlziel;
 ManuProC::Datum rgdatum;
 cP_Waehrung waehrung;
 rabatt_t rabatt;
 cH_Zahlungsart zahlungsart;
 bool bezahlt;
 bool entsorgung;
 mutable std::string notiz;
 mutable bool notiz_valid;
 fixedpoint<5> kurs;  
 int einzug_refnr;
 int fibu_buchid;
 mutable fixedpoint<1> mwst_satz;
  
 void push_back(unsigned &lineno,ArtikelBase art,
		unsigned lfrsid,unsigned lfrsznr, int stk,
		mengen_t menge,const Preis &p, AufEintragBase::rabatt_t rabatt,
		fixedpoint<2> provsatz, const Preis &ek_preis);
public:
        
 Rechnung(ID rid) throw(SQLerror);
 Rechnung(const cH_Kunde k,int jahr=0) throw(SQLerror);
 Rechnung() : RechnungBase(none_id), kunde(Kunde::none_id), 
              rngart(RART_NONE), zahlziel(ManuProC::Datum::today()),
              rgdatum(ManuProC::Datum::today()),waehrung(0),
              rabatt(0),zahlungsart(Zahlungsart::none_id),bezahlt(false),
              entsorgung(false),notiz_valid(false),kurs(1)
#ifdef MABELLA_EXTENSIONS
		,einzug_refnr(0)
		,fibu_buchid(0)
#endif
               {} 

 const Kunde::ID KdNr() const {return kunde->Id();}
 const cH_Kunde getKunde() const { return kunde; }
 
// std::string RngArt() const {return rngart; } 
 const RngArt rngArt() const {return rngart; } 
 void setRngArt(const RngArt &art) throw(SQLerror);
// void convert_to_gutschrift(bool lager_buchung=false) throw(SQLerror);
 rabatt_t Rabatt() const { return rabatt; }

// don't know where is using this and i assume a bug in it. 
 geldbetrag_t Betrag(bool brutto=false) const throw(SQLerror);
 geldbetrag_t Endbetrag(bool with_update_on_db) const throw(SQLerror);
 cP_Waehrung getWaehrung() const { return waehrung; }
 void setzeWaehrung(const cP_Waehrung &w) throw(SQLerror);
 ExtBezSchema::ID getSchema() { return kunde->getSchemaId(); }
 bool Bezahlt() const { return bezahlt; }
 void setBezahlt(bool _bezahlt) throw(SQLerror);
 void setMwSt(const fixedpoint<1> _mwst=-1) const throw(SQLerror);
 fixedpoint<1> MwStSatz() const { return mwst_satz; }

 void addLieferschein(const LieferscheinBase &lfrs) throw(SQLerror);
 void deleteLieferschein(const LieferscheinBase &lfrs) throw(SQLerror);
 unsigned push_back(ArtikelBase art,int stk,mengen_t menge,
                         fixedpoint<2> provsatz=0);
 void erase(unsigned lineno);

 void setze_Rabatt(rabatt_t r) throw(SQLerror);
 const ManuProC::Datum getDatum() const { return rgdatum; }
 const ManuProC::Datum getZahlziel() const { return zahlziel; }
 void setze_Datum(ManuProC::Datum rgdatum) throw(SQLerror);
 void setze_Zahlziel(ManuProC::Datum zziel) throw(SQLerror);
 cH_Zahlungsart getZahlungsart() const {return zahlungsart;}
 void setze_Zahlungsart(cH_Zahlungsart z)   throw(SQLerror);
 bool Entsorgung() const { return entsorgung;}
 void setEntsorgung(bool ent) throw(SQLerror);
 const std::string Notiz() const throw(SQLerror);
 void Notiz(const std::string _notiz) throw(SQLerror);
 int getEinzugRefnr() const { return einzug_refnr; }
 int getFiBuBuchid() const { return fibu_buchid; } 
 void setFiBuBuchid(int fid) throw(SQLerror);
 int size() const throw(SQLerror);
 int sizeLS() const throw(SQLerror);
 const ManuProC::Datum sent_at() const throw(SQLerror);
 const std::string sent_to() const throw(SQLerror);
 void Set_sent_at() const throw(SQLerror);
 void Set_sent_to(const std::string t) const throw(SQLerror);
 

};

#endif
