/*  pps: ManuProC's production planning system
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Malte Thoma
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

#include "FertigWarenLager.h"
#include <Misc/Transaction.h>
#include <Misc/TraceNV.h>


const unsigned int FertigWarenLager::default_lagerid=1;
const unsigned int FertigWarenLager::none_lagerid=-1;

std::pair<Zeitpunkt_new,int> FertigWarenLager::letzteInventur()
{
 
 Query q("select fw.datum, fw.bestand from "+tabelle+" fw where fw.datum="
	" (select max(lb.datum) from "+tabelle+" lb where lb.aktion=?"
	"  and lb.artikelid=fw.artikelid) and fw.artikelid=?");

 q << char(FertigWaren::eInventur) << fw.Artikel().Id();

 if(q.Result()==100)  
   {
      Zeitpunkt_new oldDate(ManuProC::Datum(1,1,1970));
      return std::pair<Zeitpunkt_new,int>(oldDate,0);
   }

 Zeitpunkt_new z;
 int bestand;

 q.Fetch() >> z >> bestand;

 return std::pair<Zeitpunkt_new,int>(z,bestand);

} 



int FertigWarenLager::Bestand(ManuProC::Datum date)
{
  std::pair<Zeitpunkt_new,int> inventur=letzteInventur(); 


  Query q("select coalesce(sum(menge),0) from "+tabelle+
	" where artikelid=? and datum > ? and datum <= "
	" (?||' 23:59:59')::timestamp and aktion != 'I'");

  q << fw.Artikel().Id()
    << inventur.first
    << date;

  int STK;
  q.Fetch() >> STK; 
 
  return STK + inventur.second ;
}

std::vector<class LagerInhalt> FertigWarenLager::LagerInhalt_
  		(const ArtikelBase& artikel) const
{
 std::string q="select artikelid,1,0,bestand,0 from artikel_bestand b";

 std::vector<class LagerInhalt> V;
 // Speichplatz sparen (portal)
 if (!artikel.valid()) 
 { Transaction tr; Query("LagerInhalt",q).FetchArray(V); }
 else (Query(q+" where b.artikelid=?") << artikel).FetchArray(V);
 return V;
}




void FertigWarenLager::Buchen(FertigWaren::e_buchen buchen,
		const ProductionContext &ctx) throw(LagerError)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,
	NV("buchen",int(buchen)),NV("artikel",fw.Artikel()),
	NV("menge",fw.Stk(buchen)),
     	NV("aktion",char(fw.Aktion())));
 assert(fw.Artikel().Id() != ArtikelBase::none_id);

 Zeitpunkt_new z;
 
 Query("select now()") >> z;

 Transaction tr;

#warning NO NEGATIV AMOUNT NOW
// we do not accept negativ amount from now on


// Wenn Bestand <0 sein w�rde und es war Auslagern, dann Exception 
// bei Einlagern ist es OK, weil man sonst nie von den negative Zahlen
// wegkommt, ohne eine komplette Inventur 
 int bestand=Bestand();
 if( ((bestand+fw.Stk(buchen))) < 0  &&
	buchen==FertigWaren::Raus
   )
   throw LagerError("NEGATIVER BESTAND !",fw.Artikel().Id());
   

 Query q("insert into "+tabelle+
      	" (artikelid,menge,datum,aktion,pid,lfrsid)"
        " values (?,?,?,?,?,?)");

  fw.setZeit(z);
  
 q << fw.Artikel().Id()
   << fw.Stk(buchen) 	// buchen (Rein, Raus) legt das Vorzeichen fest
   << fw.Zeit()
   << char(fw.Aktion())
   << fw.getUserID()
   << Query::NullIf(fw.Lfrsid(),ManuProcEntity<>::none_id);

 SQLerror::test(__FILELINE__);   

 if(buchen == FertigWaren::Rein)
   rein_ins_lager(fw.Artikel(),fw.Stk(FertigWaren::AsIs),
					ctx.fuer_auftrag,ctx);
 else
 if(buchen == FertigWaren::Raus)
   raus_aus_lager(fw.Artikel(),fw.Stk(FertigWaren::AsIs),
					ctx.fuer_auftrag,ctx);
 else
 if(buchen == FertigWaren::WiederRein)
   wiedereinlagern(fw.Artikel(), fw.Stk(FertigWaren::Rein));

 fw.setStk(fw.Stk(buchen));

 tr.commit();
}


void FertigWarenLager::Inventur() throw(LagerError)
{
  ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,
	NV("artikel",fw.Artikel()),
	NV("menge",fw.Stk(FertigWaren::Rein)),
     	NV("aktion",char(fw.Aktion())));
 assert(fw.Artikel().Id() != ArtikelBase::none_id);

 Zeitpunkt_new z;
 
 Query("select now()") >> z;

 Transaction tr;

 int alte_menge = Bestand();

 Query q("insert into  "+tabelle+
      	" (artikelid,menge,datum,aktion,pid,bestand)"
        " values (?,?,?,?,?,?)");

 fw.setZeit(z);
  
 int buchmenge=fw.Stk(FertigWaren::AsIs)-alte_menge;
  ManuProC::Trace(AuftragBase::trace_channel, "",NV1(alte_menge), NV1(buchmenge));
 fw.setBestand(fw.Stk(FertigWaren::AsIs));

#warning NO NEGATIV AMOUNT NOW
// we do not accept negativ mount from now on

 if(fw.Bestand()<0)
   throw LagerError("NEGATIVER BESTAND !",fw.Artikel().Id());

 q << fw.Artikel().Id()
   << buchmenge
   << fw.Zeit()
   << char(FertigWaren::eInventur)
   << fw.getUserID()
   << fw.Bestand();


 SQLerror::test(__FILELINE__);   


 if(buchmenge > 0)
   rein_ins_lager(fw.Artikel(),buchmenge,false);
 else if (buchmenge < 0)
   raus_aus_lager(fw.Artikel(),-buchmenge,false);

 fw.setStk(buchmenge);

 // refresh last_inventur from fast access
 Query("delete from last_inventur where artikelid=?")<<fw.Artikel().Id();
 Query("insert into last_inventur (artikelid,datum) ("
	" SELECT fw_lager_buchung.artikelid as artikelid, "
	"max(fw_lager_buchung.datum) AS datum FROM "
	" fw_lager_buchung WHERE fw_lager_buchung.aktion='I' "
	" and fw_lager_buchung.artikelid=? "
	" GROUP BY fw_lager_buchung.artikelid)")<<fw.Artikel().Id();

 tr.commit();
}

std::ostream &operator<<(std::ostream &o,const LagerError &e) throw()
{  o<<e.str();
   return o;
}

std::string LagerError::str() const throw()
{ std::string res=Text();
  if (ArtID()!=ArtikelBase::none_id)
      res+=": internal article ID "+itos(ArtID());
  return res;
}
