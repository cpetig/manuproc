// $Id: Artikelpreis.h,v 1.3 2001/05/10 16:31:37 christof Exp $
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Christof Petig
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


#ifndef ARTIKELPREIS_HH
#define ARTIKELPREIS_HH
#include <Artikel/Preis.h>
#include <Kunde/Kunde.h>
#include <Artikel/ArtikelBase.h>

namespace ArtikelMisc { class ProzessListe; };

class Artikelpreis : public Preis
{
	Preis &getPreis()
	{  return *(Preis*)this; }
	void init(const ArtikelMisc::ProzessListe &pl);
	// cH_Kunde weg !
	Artikelpreis(const cH_Kunde &liste,const ArtikelBase &a)
	{  *this=Artikelpreis(liste->Id(),a);
	}
public:
	const Preis &getPreis() const
	{  return *(Preis*)this; }
	Artikelpreis(const Kunde::ID liste,const ArtikelBase &a);
	Artikelpreis(const ArtikelMisc::ProzessListe &pl)
	{  init(pl); }
	void setPreis(const Preis &p)
	{  getPreis()=p; }
};
#endif
