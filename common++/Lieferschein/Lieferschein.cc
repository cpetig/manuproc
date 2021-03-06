/* $Id: Lieferschein.cc,v 1.59 2006/10/31 16:05:33 christof Exp $ */
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
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

#include"Lieferschein.h"
#include <Misc/Transaction.h>
#include <Misc/Query.h>
//#include <Instanzen/Produziert.h>
#include <unistd.h> 
#include <Misc/TraceNV.h>


#if __GNUC__ > 2 && defined (DPD_LIEFERSCHEINE)
	 const int Lieferschein::Fertig;
	 const int Lieferschein::Offen;
#endif


Lieferschein::Lieferschein(const LieferscheinBase &lsbase, const ManuProC::Datum &_lsdatum,
int _kdnr,int _rngid, int _paeckchen, int _pakete, const ManuProC::Datum &_geliefertam,
int _dpdlnr, LsArt la)
: LieferscheinBase(lsbase), lsdatum(_lsdatum), 
lsart(la), kunde(_kdnr), rngid(_rngid)
, geliefertam(_geliefertam)
#ifdef DPD_LIEFERSCHEINE
,dpdliefnr(_dpdlnr),paeckchen(_paeckchen),pakete(_pakete)
#endif
,notiz_valid(false)
,verknr(Kunde::none_id)
{
}

int Lieferschein::push_back(const ArtikelBase &artikel, int anzahl, 
		mengen_t mengeneinheit, int palette)
{  
   // Eine Instanz, die Lieferscheine schreibt, produziert auch selber (assert in ppsInstanz).
   // Wenn man einn Lieferschein schriebe, ohne da� diese Instanz 
   // selber produzierte, w�rde doppelt produziert werden.
   assert(Instanz()->Lieferschein());
   ManuProC::Trace _t(trace_channel, __FUNCTION__,NV("artikel",artikel),
           NV("anzahl",anzahl),NV("mengeneinheit",mengeneinheit),NV("palette",palette));

   Transaction tr;
   LieferscheinEntry LE=LieferscheinEntry::create(*this, artikel,0,0,palette);
   // damit der Code nicht 2x erscheint
   LE.lagerid=lagerid;
   assert(anzahl>=0 || lsart==LART_RUECK);
   assert(anzahl<=0 || lsart!=LART_RUECK);
   LE.changeMenge(anzahl,mengeneinheit,false);
   tr.commit();
   return LE.ZNr();
}

// fast das gleiche ...
int Lieferschein::push_back(const AuftragBase &restrict,
		const ArtikelBase &artikel, int anzahl, 
		mengen_t menge, int palette)
{
   assert(Instanz()->Lieferschein());
 ManuProC::Trace _t(trace_channel, __FUNCTION__,NV("restrict",restrict),
           NV("artikel",artikel),
           NV("Anzahl",anzahl),NV("Menge",menge),NV("Palette",palette));                     
 Transaction tr;          
   assert(anzahl>=0 || lsart==LART_RUECK);
   assert(anzahl<=0 || lsart!=LART_RUECK);
 LieferscheinEntry LE=LieferscheinEntry::create(*this, artikel, 0,0,palette);
 LE.lagerid=lagerid;
 LE.changeMenge(anzahl,menge,false,restrict);
 tr.commit();
 return LE.ZNr();
}

// fast das gleiche ...
int Lieferschein::push_back(AufEintrag &aufeintrag,
		const ArtikelBase &artikel, int anzahl, 
		mengen_t menge, int palette)
{
   assert(Instanz()->Lieferschein());
 ManuProC::Trace _t(trace_channel, __FUNCTION__,NV("AufEintrag",aufeintrag),
           NV("artikel",artikel),
           NV("Anzahl",anzahl),NV("Menge",menge),NV("Palette",palette));                     
   assert(anzahl>=0 || lsart==LART_RUECK);
   assert(anzahl<=0 || lsart!=LART_RUECK);
 Transaction tr;          
 LieferscheinEntry LE=LieferscheinEntry::create(*this, aufeintrag ,artikel, 0,0,palette);
 LE.lagerid=lagerid;
 LE.changeMenge(anzahl,menge,true);
 tr.commit();
 return LE.ZNr();
}

void Lieferschein::aufraumen() throw(SQLerror)
{
 Query("update lieferschein set rngid=0 where rngid is null "
// 		"and instanz=? "
 		"and not exists(select true from lieferscheinentry "
 		"where lieferscheinentry.lfrsid=lieferschein.lfrsid)");
//   	<< Instanz()->Id()
	;
 SQLerror::test(__FILELINE__,100);
}


void Lieferschein::closeLfrs()
{
 Query("update lieferschein set rngid=0 where rngid is null "
 		"and (instanz,lfrsid) = (?,?)") 
   	<< Instanz()->Id() << Id();
 Query("update lieferscheinentry set status=? where (instanz,lfrsid)=(?,?)"
	" and status=? ")
 	<< (AufStatVal)CLOSED << Instanz()->Id() << Id() <<
	   (AufStatVal)OPEN;
 SQLerror::test(__FILELINE__,100);
}


#ifdef DPD_LIEFERSCHEINE

void Lieferschein::setDPDlnr(int d) const throw(SQLerror)
{
 Query("update lieferschein set dpdliefnr=? where (instanz,lfrsid) = (?,?)") 
   	<< Query::NullIf(d,Offen) << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);
}

void Lieferschein::setPakete(const int p) throw(SQLerror)
{  
 Query("update lieferschein set pakete=? where (instanz,lfrsid) = (?,?)") 
   	<< p << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);
}

void Lieferschein::setPaeckchen(const int p) throw(SQLerror)
{  
 Query("update lieferschein set paeckchen=? where (instanz,lfrsid) = (?,?)") 
   	<< p << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);
}

void Lieferschein::setGewichtNetto(const fixedpoint<1> i) throw(SQLerror)
{  
 Query("update lieferschein set netto_kg=? where (instanz,lfrsid) = (?,?)") 
   	<< i << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);
}

void Lieferschein::setGewichtBrutto(const fixedpoint<1> i) throw(SQLerror)
{  
 Query("update lieferschein set brutto_kg=? where (instanz,lfrsid) = (?,?)")
   << i << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);
}


void Lieferschein::setDPDDatum() const throw(SQLerror)
{
 Query("update lieferschein set geliefertam=now() "
 	"where (instanz,lfrsid)=(?,?)") << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);
}
#endif

int Lieferschein::maxZnr() throw(SQLerror)
{
 return (Query("select max(zeile) from lieferscheinentry where "
 	"(instanz,lfrsid) = (?,?)") 
 	<< Instanz()->Id() << Id()
 	).FetchOneMap<int>();
}

const Preis::rabatt_t Lieferschein::AufRabatt() const throw(SQLerror)
{
 return (Query("select max(rabatt) from "
 	"auftrag a join lieferscheinentry e "
   	"on (refauftragid=auftragid and a.instanz=e.instanz) where "
   	"(e.instanz,e.lfrsid)=(?,?)") << Instanz()->Id() << Id()
   	).FetchOneMap<Preis::rabatt_t>();;
}

LieferscheinBase::mengen_t Lieferschein::StandardLaenge(const ArtikelBase artikel) throw (SQLerror)
{try 
 { return (Query("select menge from lieferscheinentry e join lieferschein l "
     "using (lfrsid,instanz) where artikelid=? " // "and l.instanz=? "
     "order by datum desc limit 1") << artikel.Id() /* << Instanz()->Id() */
   ).FetchOneMap<LieferscheinBase::mengen_t>();
 } catch (SQLerror &e)
 { return 0;
 }
}

const ManuProC::Datum Lieferschein::getMaxZahlziel() const throw(SQLerror)
{
 ManuProC::Datum d;

 Query("SELECT max(a.zahlungsziel) from "
 	"auftrag a join lieferscheinentry e "
   	"on (refauftragid=auftragid and a.instanz=e.instanz) "
   	"where (e.instanz,e.lfrsid)=(?,?)")
   	<< Instanz()->Id() << Id()
	>> Query::Row::MapNull(d,ManuProC::Datum());

 return d;
}

const std::string Lieferschein::Notiz() const throw(SQLerror)
{
 ManuProC::Trace _t(trace_channel, __FUNCTION__,Instanz(),Id());
 if(notiz_valid) return notiz;

 Query("select notiz from lieferschein where (instanz,lfrsid)=(?,?)")
 	<< Instanz()->Id() << Id()
 	>> Query::Row::MapNull(notiz);
 notiz_valid=true;
 return notiz;
}

void Lieferschein::Notiz(const std::string n) throw(SQLerror)
{
 ManuProC::Trace _t(trace_channel, __FUNCTION__,Instanz(),Id(),n);

 Query("update lieferschein set notiz=? where (instanz,lfrsid)=(?,?)")
 	<< n 
 	<< Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);

 notiz=n;
}

#ifdef MABELLA_EXTENSIONS
void Lieferschein::setVerknr(const Kunde::ID vknr) throw(SQLerror)
{
 Query("update lieferschein set verknr=? where"
	" (instanz,lfrsid)=(?,?)")
	<< Query::NullIf(vknr,Kunde::none_id)
	<< Instanz()->Id()
	<< Id();
 SQLerror::test(__FILELINE__);

 verknr=vknr;
}
#endif

void Lieferschein::setDatum(const ManuProC::Datum &d) throw(SQLerror)
{  
 Query("update lieferschein set geliefertam=? where "
 	"(instanz,lfrsid) = (?,?)") 
 	<< d << Instanz()->Id() << Id() ;
 SQLerror::test(__FILELINE__);
}

const UniqueValue::value_t LieferscheinBase::trace_channel=ManuProC::Tracer::channels.get();
static ManuProC::Tracer::Environment trace_channel_e("DEBUG_LIEFERSCHEIN",LieferscheinBase::trace_channel);

Lieferschein::Lieferschein(const cH_ppsInstanz& _instanz,int lid) throw(SQLerror)
: LieferscheinBase(_instanz,lid),kunde(Kunde::default_id), notiz_valid(false)
{

ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,_instanz,NV("LieferscheinId",lid)); 

 int KDNR;
 char LSART;

 std::string query="select coalesce(lsart,'L'), kundennr, date(datum), "
		   " rngid, date(coalesce(geliefertam,datum)) ";

#ifdef DPD_LIEFERSCHEINE
 query += ",paeckchen,pakete,dpdliefnr,brutto_kg,netto_kg,verknr ";
#endif

 query+=" from lieferschein where (instanz,lfrsid) = (?,?)";

 Query q(query);

 q << Instanz()->Id() << Id();
 SQLerror::test(__FILELINE__);

 Query::Row fi=q.Fetch();

 fi >> LSART >> KDNR
    >> lsdatum 
    >> Query::Row::MapNull(rngid,ManuProcEntity<>::none_id) 
    >> geliefertam
#ifdef DPD_LIEFERSCHEINE
    >> Query::Row::MapNull(paeckchen,0) 
    >> Query::Row::MapNull(pakete,0) 
    >> Query::Row::MapNull(dpdliefnr,ManuProcEntity<>::none_id)
    >> Query::Row::MapNull(brutto_kg,0)
    >> Query::Row::MapNull(netto_kg,0)
    >> Query::Row::MapNull(verknr,Kunde::none_id)
#endif
    ;

 lsart=(LsArt)LSART;
 kunde=cH_Kunde(KDNR);
}

Lieferschein::Lieferschein(const cH_ppsInstanz& _instanz,cH_Kunde k,
			int jahr, LsArt la) throw(SQLerror)
	: LieferscheinBase(_instanz,none_id), lsdatum(ManuProC::Datum::today()),
	  lsart(la),
          kunde(k),rngid(ManuProcEntity<>::none_id),
#ifdef DPD_LIEFERSCHEINE
 	  dpdliefnr(-1) ,paeckchen(),pakete(),
#endif
         notiz_valid(),verknr(Kunde::none_id)
{
ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,_instanz,NV("Kunde",k),NV("Jahr",jahr),NV("Art",la)); 

 if (!jahr) jahr=AuftragBase::aktuellesJahr();
 jahr%=100;

 Transaction tr;
  
 Query("lock table lieferschein in exclusive mode");
 
 Query("select max(lfrsid)+1 from lieferschein where lfrsid between ? and ?")
      << (jahr*AuftragBase::jahresmultiplikator) 
      << ((jahr+1)*AuftragBase::jahresmultiplikator-1)
      >> Query::Row::MapNull(lieferid,jahr*AuftragBase::jahresmultiplikator);
 
 Query("insert into lieferschein (instanz,lfrsid, kundennr) values (?,?,?)")
     << instanz->Id() << lieferid << kunde->Id();

 (Query("update lieferschein set notiz=(select lief_notiz from kunden "
        "where kundennr=?) where (instanz,lfrsid)=(?,?)")
        << kunde->Id() 
        << instanz->Id() << lieferid).Check100();

 if(la!=LART_NONE)
 { (Query("update lieferschein set lsart=? where (instanz,lfrsid)=(?,?)")
        << char(la) << instanz->Id() << lieferid).Check100();
 }
 rngid=ManuProcEntity<>::none_id;
 tr.commit();
}

const ManuProC::Datum Lieferschein::sent_at() const throw(SQLerror)
{
 ManuProC::Datum sent;
 Query("select sent_at from lieferschein where (instanz,lfrsid)=(?,?)")
	<< Instanz()->Id() << Id() >> sent;
 return sent;
}

const std::string Lieferschein::sent_to() const throw(SQLerror)
{
 std::string sent;
 Query("select sent_to from lieferschein where (instanz,lfrsid)=(?,?)") 
	<< Instanz()->Id() << Id() >> sent;
 return sent;
}

void Lieferschein::Set_sent_at() const throw(SQLerror)
{
 Query("update lieferschein set sent_at=now() where (instanz,lfrsid)=(?,?)") 
		<< Instanz()->Id() << Id();
}


void Lieferschein::Set_sent_to(const std::string t) const throw(SQLerror)
{
 Query("update lieferschein set sent_to=? where (instanz,lfrsid)=(?,?)")  
		<< t <<  Instanz()->Id() << Id();
}



