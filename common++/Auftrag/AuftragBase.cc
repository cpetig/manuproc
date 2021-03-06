// $Id: AuftragBase.cc,v 1.63 2006/06/26 07:53:01 christof Exp $
/*  pps: ManuProC's production planning system
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

#include <Misc/i18n.h>
#include <Auftrag/AuftragBase.h>
#include <Auftrag/Auftrag.h>
#include<stdio.h>
#include <Misc/Transaction.h>
#include<Misc/Changejournal.h>
#include <Auftrag/auftrag_status.h>
#include "AufEintrag.h"
#include <Artikel/ArtikelStamm.h>
#include <Auftrag/VerfuegbareMenge.h>
#include <Auftrag/AufEintragZu.h>
#include <Misc/TraceNV.h>
#include <Lager/Lager.h>
#include <Misc/Ausgabe_neu.h>

std::map<int, std::string> AuftragBase::labels;

std::string AuftragBase::str() const
{
  return instanz->Name().substr(0,4)+"="+itos(instanz->Id())+"."+itos(Id());
}

std::ostream &operator<<(std::ostream &o,const AuftragBase &a)
{
  return  o<<a.str();
}

const std::string AuftragBase::getStatusStr(AufStatVal a)
{
 switch(a)
   {case (AufStatVal)UNCOMMITED : 
       return Ausgabe_neu::TeX_uses_UTF8 ? _("unbestätigt") : "unbest\xe4tigt"; 
    case (AufStatVal)OPEN : return _("offen");
    case (AufStatVal)CLOSED : return _("fertig");
    case (AufStatVal)STORNO : return _("storno");
    case (AufStatVal)NOSTAT : break;
   }
 return "-";
}

const AuftragBase::ID AuftragBase::PlanId_for(const cH_ppsInstanz &instanz)
{
  if(instanz->LagerInstanz()) return AuftragBase::plan_auftrag_id;
  return AuftragBase::handplan_auftrag_id;
}

bool AuftragBase::editierbar() const
{
  if     (Id() == dispo_auftrag_id) return false;
  else if(Id() == plan_auftrag_id)  return false;
  else if(Id() == ungeplante_id)    return false;
  else if(Id() == none_id)          return false;
  return true;
}

// könnte eigentlich ersetzt werden IMHO
// wird aufgerufen von rein_ins_lager (+), ArtikelInternAbbestellen (-),
// 
void AuftragBase::dispo_auftrag_aendern(cH_ppsInstanz instanz,const ArtikelBase artikel,const mengen_t &menge,
         const ManuProC::Datum &datum,const AufEintragBase &kindAEB)
{
  ManuProC::Trace _t(trace_channel, __FUNCTION__,
     NV("Artikel",artikel),NV("Menge",menge));
   AuftragBase(instanz,AuftragBase::dispo_auftrag_id)
   	.BestellmengeAendern(menge,datum,artikel,OPEN,kindAEB);
}

#if __GNUC__ > 2  // fragt nicht ...
const AuftragBase::ID AuftragBase::handplan_auftrag_id,
	AuftragBase::dispo_auftrag_id,
	AuftragBase::plan_auftrag_id,
	AuftragBase::handplan_id,
	AuftragBase::dispo_id,
	AuftragBase::plan_id,
	AuftragBase::invalid_id,
	AuftragBase::none_id,
	AuftragBase::ungeplante_id;
#endif

const UniqueValue::value_t AuftragBase::trace_channel=ManuProC::Tracer::channels.get();
static ManuProC::Tracer::Environment trace_channel_e("DEBUG_AUFTRAG",AuftragBase::trace_channel);

bool AuftragBase::tolerate_inconsistency;

int AuftragBase::PassendeZeile(const ManuProC::Datum lieferdatum,const ArtikelBase& artikel,
  AufStatVal status) const throw(SQLerror)
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this,NV("Artikel",artikel),
         NV("LieferDatum",lieferdatum),NV("Status",status));
 mengen_t dummy=0;
 int znr=existEntry(artikel,lieferdatum,status,dummy);
 if(znr==none_id)
  { // spezieller Fall für unbestellte Lieferungen
    if (status==CLOSED && Id()==plan_auftrag_id)
       create_if_not_exists(OPEN);
    else
    {  assert(status==OPEN || Instanz()->Id()==ppsInstanzID::Kundenauftraege);
       // Auftrag anlegen, wenn noch nicht da
       create_if_not_exists(status);
    }
    Auftrag A(*this);
    AufEintragBase newaeb=A.push_back(0,lieferdatum,artikel,status,false);
    znr=newaeb.ZNr();
  }
 return znr;
}

// wird von ArtikelInternNachbestellen, dispo_auftrag_aendern verwendet
int AuftragBase::BestellmengeAendern(mengen_t deltamenge, 
  const ManuProC::Datum lieferdatum,const ArtikelBase& artikel,
  AufStatVal status,const AufEintragBase& altAEB) const throw(SQLerror)
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this,NV("Artikel",artikel),
         NV("Menge",deltamenge),NV("AltAEB",altAEB),
         NV("LieferDatum",lieferdatum),
         NV("Status",status));
 Transaction tr;
 Query::Execute("lock table auftragentry in exclusive mode");
 SQLerror::test(__FILELINE__);  

 bool kein_dispo= Id()!=dispo_auftrag_id;
 AufEintragBase NeuAEB(*this,PassendeZeile(lieferdatum,artikel,status));

 // ist die Reihenfolge hier wichtig?
 // rekursion nur falls kein DispoAuftrag
 AufEintrag(NeuAEB).MengeAendern(deltamenge,kein_dispo,
 	kein_dispo?altAEB:AufEintragBase());

 // dispo=> andere Richtung des Pfeils muss geändert werden 
 if (!kein_dispo && altAEB.valid())
      AufEintragZu(NeuAEB).Neu(altAEB,deltamenge);

  tr.commit();
  return NeuAEB.ZNr();
}

// aufid sollte string sein (es ist immerhin youraufnr gemeint)
AuftragBase::AuftragBase(cH_ppsInstanz _instanz, ID aufid,Kunde::ID kid) throw(SQLerror)
: instanz(_instanz),auftragid(none_id)
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this);
 Query("select auftragid,verknr from auftrag "
 	"where instanz=? and kundennr=? and youraufnr=?")
 	<< instanz->Id() << kid << aufid
 	>> auftragid >> Query::Row::MapNull(verknr,Kunde::none_id);;
}

ArgumentList &operator<<(ArgumentList &q, const AuftragBase &ab)
{  return q << ab.InstanzID() << ab.Id();
}

bool AuftragBase::Exists() const throw(SQLerror)
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this);
 return (Query("select exists(select true from auftrag "
 		"where (instanz,auftragid)=(?,?))").lvalue()
 	<< *this)
 	.FetchOne<bool>();
}

bool AuftragBase::create_if_not_exists(AufStatVal status,Kunde::ID kunde) const
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this,NV("Status",status),NV("Kunde",kunde));
  if(Exists()) return false;
  Query("insert into auftrag (instanz,auftragid,kundennr,stat) "
  	"values (?,?,?,?)").lvalue()
  	<< *this << kunde << status;
 SQLerror::test(__FILELINE__);
 return true;
}


void AuftragBase::setStatusAuftragBase(AufStatVal st) const throw(SQLerror)
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this,NV("Status",st));
 Query("update auftrag set stat=? where (instanz,auftragid)=(?,?)").lvalue()
 	<< st << *this;
 SQLerror::test(__FILELINE__"Status setzen");
}


void AuftragBase::setRabatt(const rabatt_t auftragsrabatt) const throw(SQLerror)
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this);
 Query("update auftrag set rabatt=? where (instanz,auftragid)=(?,?)").lvalue()
 	<< auftragsrabatt << *this;
 SQLerror::test(__FILELINE__"Rabatt setzen");
}

int AuftragBase::existEntry(const ArtikelBase& artikel, const ManuProC::Datum& lieferdatum,
                             AufStatVal status, mengen_t& menge_out) const throw()
{
 ManuProC::Trace _t(AuftragBase::trace_channel, __FUNCTION__,*this,
         NV("Artikel",artikel),NV("LieferDatum",lieferdatum),NV("Status",status));
   int ZEILENNR;
 try
 { static PreparedQuery pq("select zeilennr,bestellt from auftragentry "
	"where (instanz,auftragid)= (?,?) and "
        "lieferdate=? and artikelid=? and status=? limit 1");
   Query(pq)
        << *this << lieferdatum << artikel.Id() << status
        >> ZEILENNR >> menge_out;
   return ZEILENNR;
 } catch (SQLerror &e)
 {  return none_id;
 }
}

bool operator<(const AuftragBase &a, const AuftragBase &b)
{  return a.Instanz()<b.Instanz() || 
	(a.Instanz()==b.Instanz() && a.Id()<b.Id());
}

static ManuProC::Datum today=ManuProC::Datum::today();

int AuftragBase::aktuellesJahr()
{  return today.Jahr()%100;
}

void AuftragBase::setzeAktuellesJahr(int j)
{  today=ManuProC::Datum(1,1,j);
}

AuftragBase::mengen_t AuftragBase::Gesamtmenge(int stueck,const mengen_t &menge)
{  if (!menge) return stueck;
   else return stueck*menge;
}

std::string AuftragBase::ID2string(ID id)
{ return Formatiere((unsigned long)id,0,6,"","",'0');
}

template<>
const Oid Query::NullIf_s<AufStatVal>::postgres_type=Query::NullIf_s<int>::postgres_type;

#if defined(ENABLE_NLS)
namespace { struct gettext_init { gettext_init(); }; }
static gettext_init init;
gettext_init::gettext_init()
{
   bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
   bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
}
#endif
