/* $Id: ArtikelBaum.h,v 1.9 2002/02/28 15:19:29 christof Exp $ */
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

#ifndef ARTIKELBAUM_H
#define ARTIKELBAUM_H

#include <Artikel/Prozess.h>
#include <Auftrag/AufEintragBase.h>
#include <string>
#include <vector>
#include <Aux/SQLerror.h>
#include <Artikel/ArtikelBase.h>
#include <Aux/fixedpoint.h>
#include <Aux/ppsInstanz.h>

// besserer Name: ArtikelZusammensetzung

class ArtikelBaum : public virtual ArtikelBase
{
        mutable int tiefe;
        static const int NoDepth=-1;
public:
	typedef fixedpoint<3> menge_t;
	typedef fixedpoint<5> faktor_t;
	struct RohArtikel
	{  ArtikelBase			rohartikel;
	   // in Einheit(rohartikel)/Einheit(ArtikelBase)
	   // ist ein Faktor
	   faktor_t	menge; 
	   
	   // eigentlich relativ uninteressant?
	   cH_Prozess		erzeugung;
	   
	   RohArtikel() : menge(0), 
	                  erzeugung(Prozess::default_id) 
	   {}
      RohArtikel(ArtikelBase _rohartikel,faktor_t _menge,Prozess::ID proz)
              :rohartikel(_rohartikel),menge(_menge),
               erzeugung(proz)
      {}

      bool operator==(const RohArtikel &b) const {return (*this).rohartikel==b.rohartikel;}
      bool operator<(const RohArtikel &b) const {return (*this).rohartikel<b.rohartikel;}

private:
	   // obsolete, compatibility only!
	   RohArtikel(const ArtikelBase &_altartikel,cH_Prozess proz)
	   	: rohartikel(_altartikel), 
	   	  menge(proz->getMtrProStk()), 
	   	  erzeugung(proz)
	   {}
	};
private:
	typedef std::vector<RohArtikel> zusammensetzung_t;
public:
	typedef zusammensetzung_t::const_iterator const_iterator;

private:
	zusammensetzung_t zusammensetzung;
        void gleiche_Faeden_summieren();

 	// cache
	typedef CacheStatic<ID,zusammensetzung_t> cache_t;
	static cache_t cache;

public:
 ArtikelBaum() : tiefe(NoDepth) {}
 ArtikelBaum(const ArtikelBase &stamp) : tiefe(NoDepth)
         {  setID(stamp.Id()); }

private:
// hier passiert alles, ungeschickter Name
 void setID(const ID &id) throw(SQLerror);

public:
 bool empty() const
 {  return zusammensetzung.empty(); }
 size_t size() const
 {  return zusammensetzung.size(); }
 const_iterator begin() const
 {  return zusammensetzung.begin(); }
 const_iterator end() const
 {  return zusammensetzung.end(); }

 static void UnCache(const ArtikelBase &stamp);

// Hrmpf, warum sind das keine Members?
// Weil sie dann mehr Datanbankzugriffe machen w�rden als n�tig, MAT
// F�r einen neuen Artikel:
 static void new_Artikel(ArtikelBase fuer_artikel,const RohArtikel& RA);
 static void delete_Artikel(ArtikelBase fuer_artikel,ArtikelBase von_artikel);
private:
 static void delete_from_zuordnung(ArtikelBase alt_artikel,ArtikelBase kind_artikel); 
 static void reduceChildren(const AufEintrag& AEB,const AufEintrag& oldAEB,AufEintragBase::mengen_t menge);
 static void create_in_zuordnung(ArtikelBase alt_artikel,ArtikelBase kind_artikel,fixedpoint<5> RohMenge); 

public:
 faktor_t Faktor(const ArtikelBase &kind) throw(SQLerror);
 int ArtikelBaum::Tiefe() const;

};

#endif
