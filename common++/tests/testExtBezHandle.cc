// $Id: testExtBezHandle.cc,v 1.6 2003/01/08 09:46:58 christof Exp $
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


#include <ExtBezSchema/ExtBezSchemaHandle.h>
#include <Artikel/Prozess.h>
#include <Misc/dbconnect.h>

int main()
{  ManuProC::dbconnect_nt();
   cH_Prozess ph(Prozess::ID(1));
   cH_ExtBezSchema h(1);
   return 0;
}
