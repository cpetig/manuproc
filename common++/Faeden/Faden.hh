// $Id: Faden.hh,v 1.11 2004/05/27 10:15:06 christof Exp $
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 2002 Adolf Petig GmbH & Co. KG
 *  written by Jacek Jakubowski, Christof Petig, Malte Thoma
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

#ifndef FADEN_HH
#define FADEN_HH

#include <string>
#include <vector>
#include <iterator>
#include <algo.h>
#include "Bindung.hh"
#include <Artikel/ArtikelBase.h>
#include <Aux/fixedpoint.h>
class Wiederholung;
class Webangaben;

struct Faden {
        int zeilennummer;
        unsigned anzahl;
        ArtikelBase material;
        Bindung bindung;
        int kettscheibe;

        unsigned max_kettlaenge;
        unsigned max_fadenzahl;
        bool verlaengern;
        unsigned ausn_gaenge,ausn_faeden,ausn_maxfd;
        unsigned ausn_gaenge2,ausn_maxfd2;
        
	friend std::ostream& operator<< (std::ostream&, const Faden&);
public:
	Faden (int zeilennr, unsigned int anzahl, ArtikelBase::ID, Bindung=Bindung());
	Faden() : zeilennummer(-1), anzahl(), kettscheibe(-1), 
		max_kettlaenge(), max_fadenzahl(), verlaengern(), 
		ausn_gaenge(), ausn_faeden(), ausn_maxfd(),
		ausn_gaenge2(), ausn_maxfd2()
	{}
	bool operator== (const Faden&) const;
	bool operator!= (const Faden&) const;
	int getAnzahl() const { return anzahl; }
	int displayBreite() const;
	ArtikelBase getMaterial() const { return material; }
	Bindung getBindung() const { return bindung; }
	void setAnzahl (const int z) { anzahl = z; }
   fixedpoint<5> get_Gewicht_kg_pro_km_Faden() const ;
   fixedpoint<5> get_Gewicht_kg_mal_anzschfaeden_pro_km_und_breite_mm_und_schussdichte_cm() const ;

   static void create(const ArtikelBase &artikel,const int znr,const int anzahl,
               const ArtikelBase &material,Bindung bindung=Bindung()) throw(SQLerror);
   static void create_wiederholung(const ArtikelBase &artikel, const Wiederholung &W) throw(SQLerror);
};

struct Wiederholung {
	unsigned int start, end, anzahl;
public:
	Wiederholung (const unsigned int s, const unsigned int e, const unsigned int a);
	bool operator== (const Wiederholung&) const;
	bool operator< (const Wiederholung&) const;
	unsigned int getStart() const { return start; }
	unsigned int getEnd() const { return end; }
	unsigned int getAnzahl() const { return anzahl; }
	void setStart (const unsigned int z) { start = z; }
	void setEnd (const unsigned int z) { end = z; }
	void setAnzahl (const unsigned int z) { anzahl = z; }
};

class Fadenliste {
	std::vector<Faden> liste;
	std::vector<Faden> sumliste;
	std::vector<Wiederholung> repliste;
	std::vector<unsigned int> repnumliste;
public:
	typedef std::vector<Faden>::const_iterator const_iterator;
	typedef std::vector<Faden>::iterator iterator;
	typedef std::vector<Faden>::const_iterator const_sumiterator;
	typedef std::vector<Wiederholung>::const_iterator const_repiterator;
	
	Fadenliste() : liste(), sumliste(), repliste(), repnumliste() {}
	void Load(const ArtikelBase &ab,const Bindungsliste &bindungsliste);
	void Load(const Webangaben &wa);
	
	const_iterator begin() const { return liste.begin(); }
	iterator begin() { return liste.begin(); }
	const_iterator end() const { return liste.end(); }
	iterator end() { return liste.end(); }
	const_sumiterator sumbegin() const { return sumliste.begin(); }
	const_sumiterator sumend() const { return sumliste.end(); }
	const_repiterator repbegin() const { return repliste.begin(); }
	const_repiterator repend() const { return repliste.end(); }
	
	int add (const Faden, const unsigned int);
	bool del (const unsigned int, unsigned  int&);
	bool rep_add (const unsigned int, const unsigned int, const unsigned int);
	bool rep_del (const unsigned int, const unsigned int);
	void erase();
	Faden getSumByIndex (const unsigned int i) const { return sumliste [i]; }
	size_t size() const { return liste.size(); }
	size_t sumsize() const { return sumliste.size(); }
	void print_out() const;
	
	void sort_sumliste();
	void EntfalteWiederholungen(std::vector<Faden> &liste_out) const;
private:
	void EntfalteWiederholungen_recurse(std::vector<Faden> &liste_out,
		const_repiterator ri,const_iterator i,
		const_iterator e,unsigned int index) const;
};

#endif
