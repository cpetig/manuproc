// $Id: Artikelpreis_sql.pgcc,v 1.19 2003/06/05 12:48:15 christof Exp $
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2006 Adolf Petig GmbH & Co. KG, written by Christof Petig
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


#include "Artikel/Artikelpreis.h"
#include <Artikel/ArtikelBezeichnung.h>
#include <Misc/CacheStatic.h>
#include <Artikel/ArtikelBaum.h>
#include <Artikel/Prozesspreis.h>
#include <Misc/Transaction.h>
#include <Misc/TraceNV.h>
#include <Kunde/PreisListe.h>
#include <Artikel/ArtikelStamm.h>

#include <unistd.h>
#include <sys/types.h>
#include <algo.h>
#include <functional>
#include <Misc/Event.h>

#if MPC_SIGC_VERSION < 0x120
#include <sigc++/func_slot.h>
#elif MPC_SIGC_VERSION >= 0x200
#include <sigc++/compatibility.h>
#endif

namespace // index_t and payload_t should not be globally visible
{

struct index_t
{  Kunde::ID liste;
   ArtikelBase::ID art;
   index_t(Kunde::ID l, ArtikelBase::ID a) : liste(l), art(a) {} 
   bool operator==(const index_t &b) const 
   { return liste==b.liste && art==b.art; }
   bool operator<(const index_t &b) const 
   { return liste<b.liste || (liste==b.liste && art<b.art); }
};

struct ExtPreis {Preis p; PreisListe::ID pl_parent;
		 ExtPreis(Preis _p, PreisListe::ID ppl)
			: p(_p), pl_parent(ppl) {}
		 ExtPreis() : pl_parent(PreisListe::none_id) {}
};



class Preis_lseq : public unary_function<std::pair<int,ExtPreis>,bool>
{
 int bestellmenge;
public:
 explicit Preis_lseq (const int m) : bestellmenge(m) {}
 bool operator() (const std::pair<int,ExtPreis> &p) const 
	{ return p.first <= bestellmenge; }
};

struct PreisMindMenge_NotFound : public std::exception
{
 int menge;
 ~PreisMindMenge_NotFound() throw() {}
 PreisMindMenge_NotFound(int m) : menge(m) {}
};


struct payload_t
{  
 typedef std::map<int,ExtPreis> Pmap;

   Pmap preis;
   bool errechnet;
   bool gefunden;
   payload_t(bool gef, bool e=true)
   	: errechnet(e), gefunden(gef) {}
   std::pair<int,ExtPreis> get_preis(int bestellmenge=1) 
				throw(PreisMindMenge_NotFound)
	{ Pmap::reverse_iterator p=find_if(preis.rbegin(),preis.rend(),
			Preis_lseq(bestellmenge));
	  if(p!=preis.rend()) return (*p);
	  else throw PreisMindMenge_NotFound(bestellmenge);
	}
   payload_t() : errechnet(false),gefunden(false) {}
};
}

typedef CacheStatic<index_t,payload_t> cache_t;

static cache_t cache;

static void PreisGeaendert_cb(const std::string &key, const std::string &value)
{  std::string::size_type komma=key.find(',');
   if (komma==std::string::npos) return;
   int liste=atoi(key.substr(0,komma).c_str());
   int artikel=atoi(key.substr(komma+1).c_str());
   Artikelpreis::UnCache(PreisListe::ID(liste),ArtikelBase(artikel));
}

static void callback_registrieren()
{  ManuProC::Event::connect("artikelpreis",SigC::slot(&PreisGeaendert_cb));
}

namespace {
struct dummy
{	dummy() { callback_registrieren(); }
};
}

static dummy dummy2;

Artikelpreis::Artikelpreis(const cH_PreisListe liste,const ArtikelBase &a,
				int bestellmenge)
	: errechnet(false), gefunden(false),
	  gefunden_in(ManuProcEntity<>::none_id),mindestmenge(1),
	  pl_parent(PreisListe::none_id)
{  ManuProC::Trace _t(trace_channel, __FUNCTION__, 
	NV("Liste",liste->Id()), NV("Artikel",a), NV("Menge",bestellmenge));
   payload_t *cached=cache.lookup(index_t(liste->Id(),a.Id()));
   if (cached) { try {
		 std::pair<int,ExtPreis> p=cached->get_preis(bestellmenge);
		 setPreis(a.Id(),p.second.p,liste->Id(),
				cached->errechnet);
		 mindestmenge=p.first;
	 	 gefunden=cached->gefunden;
		 pl_parent=p.second.pl_parent;
		 }
		 catch(PreisMindMenge_NotFound &p)
		   {gefunden=false;
	            std::cout << "MindMenge not found:"<<p.menge<<"\n";
 		    ManuProC::Trace(trace_channel,__FILELINE__,NV("cache",static_cast<const Preis&>(*this)));
		   }
 		 ManuProC::Trace(trace_channel,__FILELINE__,NV("cache",static_cast<const Preis&>(*this)));
		}
   else
   {
    std::string sel_preis=liste->getPreisSelClausel();
    PreisListe::ID plid=liste->RealId();
    
    std::string query("select 0 as priority,");
    query+=sel_preis+", mindestmenge, preismenge, kundennr"
	      	" from artikelpreise where (artikelid,kundennr)=(?,?)";
    if(liste->isDepending())
      {query+=" UNION "
              "(select 1 as priority,preis,mindestmenge,preismenge,kundennr"
              " from artikelpreise where (artikelid,kundennr)=("+
              itos(a.Id())+","+itos(liste->Id())+"))"
              " order by mindestmenge,priority";
      }
      
      Query q(query);	      	
      q << a.Id() << plid;
      payload_t pyl(!q.Result(), false);
      Query::Row is;
      int WAEHRUNG=Waehrung::default_id;
      if (!!liste->getWaehrung()) 
         WAEHRUNG=liste->getWaehrung()->Id();

      if (!q.Result())
      {  while ((q>>is).good())
         { geldbetrag_t PREIS;
      	   preismenge_t PREISMENGE;
           int MINDESTMENGE, PRIOR, PLSNR;
           is >> PRIOR >> PREIS >> Query::Row::MapNull(MINDESTMENGE,1) 
           	>> Query::Row::MapNull(PREISMENGE,1) >> PLSNR;
           is.ThrowIfNotEmpty(__FUNCTION__);
	  PreisListe::ID ppl=liste->isDepending() ? 
		(PRIOR==0 ? PLSNR : PreisListe::none_id) : PreisListe::none_id;
	  pyl.preis[MINDESTMENGE]=
		ExtPreis(Preis(PREIS,Waehrung::ID(WAEHRUNG),PREISMENGE),ppl);
	 }

	  try {
	  std::pair<int,ExtPreis> p=pyl.get_preis(bestellmenge);
	  setPreis(a.Id(),p.second.p,liste->Id(),false);
	  mindestmenge=p.first;
          pl_parent=p.second.pl_parent;
	  }
	  catch(PreisMindMenge_NotFound &p)
	    {
	     gefunden=false;
	     std::cout << "MindMenge not found:"<<p.menge<<"\n";
   	     ManuProC::Trace(trace_channel,__FILELINE__,NV("db",static_cast<const Preis&>(*this)));
	     cache.Register(index_t(liste->Id(),a.Id()), pyl);
	    }
	  ManuProC::Trace(trace_channel,__FILELINE__,NV("db",static_cast<const Preis&>(*this)));
      }
         
      cache.Register(index_t(liste->Id(),a.Id()), pyl);
   }
}

void Artikelpreis::UnCache(const PreisListe::ID liste,const ArtikelBase &ab)
{  ManuProC::Trace _t(trace_channel, __FUNCTION__, NV("liste",liste), NV("artikel",ab));
   cache.deregister(index_t(liste,ab.Id()));
};

Artikelpreis::Artikelpreis(const cH_Kunde &k,const ArtikelBase &a, 
				int bestellmenge)
	: errechnet(false), gefunden(false), 
	gefunden_in(ManuProcEntity<>::none_id), 
	pl_parent(ManuProcEntity<>::none_id)
{  Artikelpreis ap;

   for (std::list<std::pair<int,PreisListe::ID> >::const_iterator i=k->Preislisten().begin();
   	i!=k->Preislisten().end();++i)
   {  ap=Artikelpreis(cH_PreisListe(i->second),a,bestellmenge);
      if (ap.Gefunden()) { *this=ap; 
                pl_parent=ap.getParent();
                return; }
   }

   // oder f�r alle?   	
#ifdef PETIG_EXTENSIONS // errechnen
         Preis p;
         ArtikelBaum AB(a);
         for (ArtikelBaum::const_iterator i=AB.begin(); i!=AB.end(); ++i)
         {  p+= Prozesspreis(k->preisliste(), (*i).erzeugung->Id()) 
         	+ (*i).menge * Artikelpreis(k, (*i).rohartikel);
         }
         setPreis(a.Id(),p,ManuProcEntity<>::none_id,true);
#endif         
}


const Artikelpreis Artikelpreis::create(const PreisListe::ID liste,
		const Preis &p, const ArtikelBase &a,
		int mindmenge,
		std::vector<std::string> ins_all_komp,
	        const PreisListe::ID compare_with_pl,
		bool newstaffel) throw(SQLerror)
{
 int UID;
 int MINDESTMENGE=mindmenge;

 std::vector<int> to_insert; // Artikel, alter Preis


 if(ins_all_komp.size())
   {cH_ArtikelBezeichnung ab(a);
    cH_ExtBezSchema ebz=ab->getExtBezSchema();
    std::string query;
    std::string artbez_tabelle;
    artbez_tabelle=ebz->TableName();

    query="select id from "+artbez_tabelle+" where ";
    for(std::vector<std::string>::const_iterator s=ins_all_komp.begin();
	s!=ins_all_komp.end(); ++s)
	{ ExtBezSchema::BezKomp bk=(*ebz)[*s];
	   query+=bk.spaltenname+"='"+
	   ab->Komponente(bk.folgenr_in_sig,bk.signifikanz)+"' and ";
	}



    query+=" not exists (select true from artikelpreise p "
	"where "+artbez_tabelle+".id=p.artikelid and p.kundennr=?"
	" and p.mindestmenge=?)";

	// only those articles, which exist in this list
    if(compare_with_pl!=PreisListe::none_id)
     {
      ArtikelStamm as(a);
      if(as.Warengruppe()==ArtikelTyp::default_ID)
	{
         query+=" and exists (select true from artikelpreise p1 "
	   "where "+artbez_tabelle+".id=p1.artikelid and p1.kundennr="
	   +itos(compare_with_pl)+")";
	}
     }

    if(newstaffel) // no new articles; only new preisstaffel for existing
      query+=" and exists (select true from artikelpreise p "
	"where "+artbez_tabelle+".id=p.artikelid and p.kundennr=?)";

    Query qu(query); 
    qu << liste << mindmenge;

    if(newstaffel) qu << liste;

    qu.FetchArray(to_insert);
    
   }
 else
   {
   to_insert.push_back(a.Id());	
   }

 Transaction tr;
 
 UID=int(getuid());

 for(std::vector<int>::const_iterator i=to_insert.begin();
	i!=to_insert.end(); ++i)
   {
    Query("insert into preis_change_journal (artikelid,prlsnr,zeitpunkt,"
		"preis_alt,preis_neu,uid,mindestmenge) values "
		"(?,?,now(),null,?,?,?)")
	<< (*i) << liste << p.Wert() << UID << MINDESTMENGE;
    SQLerror::test(__FILELINE__);	


    cH_PreisListe pl(liste);

    std::string query("insert into ");
   
    query+=pl->ViewTabelle();
    query+=" (artikelid,kundennr,preis,preismenge,waehrung,mindestmenge) "
 		" values (?,?,?,?,?,?)";

    Query(query) << (*i) << liste << p.Wert() << p.PreisMenge() 
		 << p.getWaehrung()->Id() << MINDESTMENGE;
#warning 100 Code must go away, when ported to Postgresql > 7.2
    SQLerror::test(__FILELINE__,100);	
 }

 tr.commit();
  
 return Artikelpreis(cH_PreisListe(liste),a,mindmenge);
}


void Artikelpreis::changePreis(const Preis &p, int newmindmenge) throw(SQLerror)
{
 int ARTIKELID=artikel;
 geldbetrag_t PREIS_ALT;
 int UID;
 int MINDESTMENGE=mindestmenge;
 int NEWMINDMENGE=newmindmenge==0 ? mindestmenge : newmindmenge; 


 if(gefunden_in == PreisListe::none_id) return;

 UID=int(getuid());

 Transaction tr;

 Query("select preis from artikelpreise where "
	"artikelid=? and kundennr=? and mindestmenge=?")
	<< ARTIKELID << gefunden_in << MINDESTMENGE
	>> PREIS_ALT;

 const ArtikelBase abase(artikel);
 cH_ArtikelBezeichnung ab(abase);
 cH_ExtBezSchema ebz=ab->getExtBezSchema();
 std::string artbez_tabelle=ebz->TableName();

 std::string query("insert into preis_change_journal "
	"(artikelid,prlsnr,zeitpunkt,preis_alt,preis_neu,uid,mindestmenge) "
	"(select artikelid, ?, now(), preis, ?, ?, ? "
	"from artikelpreise where kundennr=? and "
	"mindestmenge=? and "
	"artikelid in "
	"(select a.id from "+artbez_tabelle+" a join "+
	artbez_tabelle+" b on ( ");

 std::string join_komponenten;
 for(ExtBezSchema::const_psigiterator bezit=ebz->psigbegin(true);
	bezit!=ebz->psigend(true); ++bezit)
    join_komponenten+="a."+bezit->spaltenname+"=b."+bezit->spaltenname+" and ";
#ifndef MABELLA_EXTENSIONS // kann man das wollen?
 assert(!join_komponenten.empty());
#endif 

 join_komponenten+=" b.id=?";
 query+=join_komponenten+")))";

 Query(query) << gefunden_in << p.Wert() << UID << NEWMINDMENGE
	<< gefunden_in << MINDESTMENGE 
	<< ARTIKELID;

 SQLerror::test(__FILELINE__);	
 

 cH_PreisListe pl(gefunden_in);
 
 query=std::string("update ");
 query+=pl->ViewTabelle();

 query+=std::string(" set preis=?,preismenge=?,waehrung=?,mindestmenge=? ")+
	"where kundennr=? and "
	"mindestmenge=? and artikelid in "
	"(select a.id from "+artbez_tabelle+" a join "+
	artbez_tabelle+" b on (	";

 query+=join_komponenten+"))";

 Query(query) << p.Wert() << p.PreisMenge() << p.getWaehrung()->Id() 
	<< NEWMINDMENGE
	<< gefunden_in << MINDESTMENGE 
	<< ARTIKELID;
#warning 100 Code must go away, when ported to Postgresql > 7.2
 SQLerror::test(__FILELINE__,100);	
 
 mindestmenge=NEWMINDMENGE;

 tr.commit();
 getPreis()=p;
}


//
// from_all_lists : l�scht in allen Listen. Allerdings nur in Verkaufs- bzw.
// Einkaufslisten
//
void Artikelpreis::remove(const cH_PreisListe liste,const ArtikelBase &a,
	std::vector<std::string> del_all_komp,
	int mindmenge, bool from_all_lists) throw(SQLerror)
{
 int ARTIKELID=a.Id();
 geldbetrag_t PREIS;
 int UID=getuid();
 int MINDESTMENGE=mindmenge;
 int PRLSNR=liste->Id();

// typedef std::pair<ArtikelBase::ID,int> UniqPreis; // artikel, mindestmenge

 std::vector<std::pair<UniqPreis,geldbetrag_t> > to_delete; // Artikel, alter Preis
 std::string query;
 std::string artbez_tabelle;

 if(!del_all_komp.empty())
   {cH_ArtikelBezeichnung ab(a);
    cH_ExtBezSchema ebz=ab->getExtBezSchema();
    artbez_tabelle=ebz->TableName();
    query="select id,mindestmenge,p.kundennr,preis from "+artbez_tabelle+" a join artikelpreise p "
	" on (id=artikelid ";

   if(!from_all_lists)
	query+=" and p.kundennr="+itos(liste->Id());

    if(MINDESTMENGE)
	query+=" and p.mindestmenge="+itos(MINDESTMENGE);

    query+=") join ku_preisliste pl on (pl.prlsnr=p.kundennr"
		" and pl.art=?) where ";
    for(std::vector<std::string>::const_iterator s=del_all_komp.begin();
	s!=del_all_komp.end(); ++s)
	{
	 ExtBezSchema::BezKomp bk=(*ebz)[*s];
	   query+=bk.spaltenname+"='"+
	   ab->Komponente(bk.folgenr_in_sig,bk.signifikanz)+"' and ";
	}
    query+=" true "; // damit am Ende kein einsames "and" stehen bleibt

    Query q(query);
    char art(liste->Art());
    q << art;
    q.FetchArray(to_delete);
    SQLerror::test(__FILELINE__);
   }
 else
   {
   std::string q="select artikelid,mindestmenge,kundennr,preis from artikelpreise where "
	"artikelid=? ";
   if(!from_all_lists)
	q+=" and kundennr="+itos(PRLSNR);

   if(MINDESTMENGE)
   	q+=" and mindestmenge="+itos(MINDESTMENGE);

   Query qu(q);
   qu << ARTIKELID;

   qu.FetchArray(to_delete);

   SQLerror::test(__FILELINE__);

//   to_delete.push_back(std::pair<int,geldbetrag_t>(ARTIKELID,PREIS));	
   }



 Transaction tr;

 for(std::vector<std::pair<UniqPreis,geldbetrag_t> >::const_iterator i=to_delete.begin();
	i!=to_delete.end(); ++i)
   {
    ARTIKELID=(*i).first.artid;
    PREIS=(*i).second;
    MINDESTMENGE=(*i).first.mindmenge;
    PRLSNR=(*i).first.plid;

    Query("insert into preis_change_journal (artikelid,prlsnr,zeitpunkt,"
   		"preis_alt,preis_neu,uid,mindestmenge) values "
   		"(?,?,now(),?,0.0,?,?)")
   		<< ARTIKELID << PRLSNR << PREIS << UID << MINDESTMENGE;
    SQLerror::test(__FILELINE__);	


    cH_PreisListe pl(PRLSNR);
 
    std::string query=std::string("delete from ");
    query+=pl->ViewTabelle();   	

    query+=" where (kundennr,artikelid,mindestmenge)=(?,?,?)";

    Query(query) << PRLSNR << ARTIKELID << MINDESTMENGE;

#warning 100 Code must go away, when ported to Postgresql > 7.2
    SQLerror::test(__FILELINE__,100);	
  }

 tr.commit();
 
}

Query::Row &operator>>(Query::Row &is,
	std::pair<Artikelpreis::UniqPreis,Preis::geldbetrag_t> &ag)
{  return is >> ag.first.artid >> ag.first.mindmenge
	>> ag.first.plid >> ag.second;
}

const UniqueValue::value_t Artikelpreis::trace_channel=ManuProC::Tracer::channels.get();
static ManuProC::Tracer::Environment trace_channel_e("DEBUG_PREIS",Artikelpreis::trace_channel);

void Artikelpreis::create_single(PreisListe::ID liste, const ArtikelBase &a, 
               const Preis &p,int mindestmenge) throw(SQLerror)
{  Transaction tr;
   Query("lock table artikelpreise in exclusive mode");
   try
   { Preis::geldbetrag_t alter_Preis;
     Query("select preis from artikelpreise where (kundennr,artikelid,mindestmenge)=(?,?,?)")
	<< liste << a.Id() << mindestmenge
	>> alter_Preis;
     Query("insert into preis_change_journal (artikelid,prlsnr,zeitpunkt,"
		"preis_alt,preis_neu,uid,mindestmenge) values "
		"(?,?,now(),?,?,?,?)")
	<< a.Id() << liste << alter_Preis << p.Wert()
	<< getuid() << mindestmenge;
     Query("update artikelpreise set preis=?, preismenge=?, waehrung=? "
   	"where (kundennr,artikelid,mindestmenge)=(?,?,?)")
   	<< p.Wert() << p.BezugsMenge() << p.getWaehrung()->Id() 
   	<< liste << a.Id() << mindestmenge;
   }
   catch (SQLerror &e)
   { if (e.Code()!=100) throw;
     Query("insert into preis_change_journal (artikelid,prlsnr,zeitpunkt,"
		"preis_alt,preis_neu,uid,mindestmenge) values "
		"(?,?,now(),null,?,?,?)")
	<< a.Id() << liste << p.Wert()
	<< getuid() << mindestmenge;
     Query("insert into artikelpreise "
   	"(preis,preismenge,waehrung,kundennr,artikelid,mindestmenge) "
   	"values (?,?,?,?,?,?)")
   	<< p.Wert() << p.BezugsMenge()
   	<< p.getWaehrung()->Id() << liste << a.Id() << mindestmenge;
   }
   Artikelpreis::UnCache(liste,a);
   ManuProC::Event::Event("artikelpreis",itos(liste)+","+itos(a.Id()));
   tr.commit();
}

std::vector<Artikelpreis> Artikelpreis::Bezugspreise(ArtikelBase const& a)
{ std::vector<Artikelpreis> result;
  static PreparedQuery pq("select kundennr,preis,preismenge,waehrung,mindestmenge "
      "from artikelpreise where artikelid=? "
      "order by preis/coalesce(preismenge,1)");
  Query q(pq);
  q << a;
  Query::Row r;
  while ((q>>r).good())
  { Artikelpreis x;
    x.gefunden=true;
    x.artikel=a.Id();
    r >> x.gefunden_in >> static_cast<Preis&>(x) >> x.mindestmenge;
    result.push_back(x);
  }
  return result;
}
