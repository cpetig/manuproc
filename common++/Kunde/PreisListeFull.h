// $Id: PreisListeFull.h,v 1.14 2003/03/31 15:38:17 jacek Exp $
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


#ifndef KUNDE_PREISLISTEFULL_HH
#define KUNDE_PREISLISTEFULL_HH

#include<Misc/SQLerror.h>
#include<Kunde/PreisListe.h>
#include<Artikel/ArtikelBase.h>
#include <Artikel/Preis.h>
#include <Artikel/ArtikelTyp.h>
#include<map>

class Artikelpreis;

class PreisListeFull : public PreisListe
{
private:
 std::map<ArtikelBase::ID,Preis> preise;
 
public:
  PreisListeFull(ID id, bool art_in_list=true, 
  		ArtikelTyp at=ArtikelTyp::default_ID) throw(SQLerror);
  PreisListeFull() {}
  const std::map<ArtikelBase::ID,Preis> &Preise() const { return preise; }
};


#endif
