// $Id: ArtikelBezeichnung.h,v 1.5 2001/10/01 12:55:40 christof Exp $
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


#ifndef ARTIKELBEZEICHNUNG_H
#define ARTIKELBEZEICHNUNG_H

#include <Artikel/ArtikelBase.h>
#include <Aux/EntryValueIntString.h>
#include <Kunde/Kunde.h>
#include <vector>
#include <string>
#include <ExtBezSchema/ExtBezSchemaHandle.h>

class cH_ArtikelBezeichnung;

class ArtikelBezeichnung : public virtual ArtikelBase, protected HandleContent
{	friend class const_Handle<ArtikelBezeichnung>;
	friend class cH_ArtikelBezeichnung;
public:
	typedef std::vector<cH_EntryValue>::const_iterator const_iterator;

	class const_sigiterator
	{	typedef const_sigiterator self;
		ExtBezSchema::const_sigiterator actual,end;
		const ArtikelBezeichnung &container;
	public:
		const_sigiterator(ExtBezSchema::const_sigiterator a,
				ExtBezSchema::const_sigiterator e,
				const ArtikelBezeichnung &ab)
		: actual(a), end(e), container(ab)
		{}
		const_sigiterator(ExtBezSchema::const_sigiterator e,
				const ArtikelBezeichnung &ab)
		: actual(e), end(e), container(ab)
		{}
		self &operator++()
		{  ++actual; return *this; }
		self operator++(int)
		{  self tmp=*this;
		   ++(*this);
		   return tmp;
		}
		bool operator==(const const_sigiterator &b) const
		{  return actual==b.actual;
		}
		bool operator!=(const const_sigiterator &b) const
		{  return actual!=b.actual;
		}
		// damit bin ich noch nicht gluecklich, wegen der notwendigen
		// 2. Indirektion, vielleicht sollte ein const EntryValueBase&
		// zurueckgegeben werden ?
		// Untersuchen bezueglich Reference Count etc.
		const cH_EntryValue operator*() const;
		// geht nicht da temporary
//		const cH_EntryValue *operator->() const;
		
		const ExtBezSchema::BezKomp &BezKomp() const
		{  return *actual;
		}
	};
	
private:
 	cH_ExtBezSchema schema;
	std::vector<cH_EntryValue> value;

public:
 ArtikelBezeichnung(const ArtikelBase &artikel,
 	const ExtBezSchema::ID schema=ExtBezSchema::default_id) throw();
 ArtikelBezeichnung() : schema(ExtBezSchema::default_id) {}

/// Artikel zu der externen Bezeichnung f�r einen Kunden erzeugen 
/// (ID nach Bezeichnung ermitteln)
/// Vorsicht: Der Artikeltyp muss stimmen!
 ArtikelBezeichnung(int signifikanz, const std::vector<cH_EntryValue> &values, const cH_ExtBezSchema &schema) throw(SQLerror);

 std::string Bezeichnung(int signifikanz=1, char separator=0,int felder=-1) const throw();
 std::string Komponente(int feldnr,int signifikanz=1) const throw();
 
 void setzeExtBezSchema(const cH_ExtBezSchema &schema) throw(SQLerror);
 const cH_ExtBezSchema getExtBezSchema() const throw()
 {  return schema;
 }

// bloedes Konzept !!! eine Map waere besser als dieser HACK (erhoehen um 1)
// bitte so nicht mehr verwenden
 const_sigiterator begin() const
 {  return sigbegin(1);
 }
 const_sigiterator end() const
 {  return sigend(1);
 }
 size_t size() const
 {  return sigsize(1);
 }
 size_t sigsize(int signifikanz=1) const
 {  return schema->sigsize(signifikanz);
 }
 const_sigiterator sigbegin(int signifikanz=1) const
 {  return const_sigiterator(schema->sigbegin(signifikanz),
 	schema->sigend(signifikanz),*this);
 }
 const_sigiterator sigend(int signifikanz=1) const
 {  return const_sigiterator(schema->sigend(signifikanz),*this);
 }
 // Zuweisung nicht sinnvoll !? daher const,
 // this might be not the right function for you, use sigbegin()/sigend() !
 const cH_EntryValue operator[](int feld) const throw(SQLerror)
 {  return feld<(int)value.size()?value[feld]:cH_EntryValueIntString("?"); }
 
 void setID(const ArtikelBase::ID &id) throw(SQLerror)
 {  *this=ArtikelBezeichnung(id,schema->Id()); }

// deprecated
 ArtikelBezeichnung(const ArtikelBase &artikel,const cH_ExtBezSchema &schema) throw();
};

class cH_ArtikelBezeichnung : public const_Handle<ArtikelBezeichnung>
{	// cache
	struct cache_key
	{  ExtBezSchema::ID sid;
	   ArtikelBase::ID aid;
	   
	   cache_key(const ExtBezSchema::ID &s,const ArtikelBase::ID &a)
	   : sid(s), aid(a) {}
	   bool operator<(const cache_key &b) const
	   {  return sid<b.sid || (sid==b.sid && aid<b.aid); }
	};
	typedef CacheStatic<cache_key,cH_ArtikelBezeichnung> cache_t;
	static cache_t cache;
	
	cH_ArtikelBezeichnung(const ArtikelBezeichnung *b)
		: const_Handle<ArtikelBezeichnung>(b) {}
//	friend cache_t::stl_type;
	friend class std::map<cache_key, cH_ArtikelBezeichnung>;
	cH_ArtikelBezeichnung() {}

public:
	// please use variant 2
	cH_ArtikelBezeichnung(const ArtikelBase &artikel,const cH_ExtBezSchema &schema) throw(SQLerror);
	// recommended variant!
	cH_ArtikelBezeichnung(const ArtikelBase &artikel,const ExtBezSchema::ID id=ExtBezSchema::default_id) throw(SQLerror);

/// Artikel zu der externen Bezeichnung f�r einen Kunden erzeugen 
/// (ID nach Bezeichnung ermitteln)
	cH_ArtikelBezeichnung(int signifikanz, const std::vector<cH_EntryValue> &values, const cH_ExtBezSchema &schema) throw(SQLerror)
		: const_Handle<ArtikelBezeichnung>(new ArtikelBezeichnung(signifikanz,values,schema))
	{}
/// default ctor
	class Default {};
	// call it like: cH_ArtikelBezeichnung(cH_ArtikelBezeichnung::Default());
	cH_ArtikelBezeichnung(const Default &d) 
		: const_Handle<ArtikelBezeichnung>(new ArtikelBezeichnung())
	{}
};

#endif
