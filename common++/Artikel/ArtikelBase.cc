/* $Id: ArtikelBase.cc,v 1.1 2002/11/22 15:58:20 christof Exp $ */
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

#include<Artikel/ArtikelBase.h>
#include<Artikel/ArtikelBezeichnung.h>

FetchIStream& operator>>(FetchIStream& is,ArtikelBase &AB)
{
  int a;
  is >> a;
  AB=ArtikelBase(a);
  return is;
}

std::ostream &operator<<(std::ostream &o,const ArtikelBase &a)
{
  o << cH_ArtikelBezeichnung(a)->Bezeichnung();
  return o;
}
