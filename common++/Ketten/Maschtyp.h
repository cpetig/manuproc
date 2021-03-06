/* $Id: Maschtyp.h,v 1.5 2003/01/08 09:46:57 christof Exp $ */
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


#ifndef MASCHTYP_HH
#define MASCHTYP_HH
#include <string>
#include <Misc/SQLerror.h>

class Maschtyp
{	int gaenge;
	std::string typ;
public:
	Maschtyp(int g,const std::string t)
		: gaenge(g), typ(t)
	{}
	const std::string Typ() const throw()
	{  return typ;
	}
	int Gaenge() const throw()
	{  return gaenge;
	}
	static Maschtyp getMaschtyp(int m) throw(SQLerror);
};

#endif
