/* $Id: DefaultValues.h,v 1.2 2002/09/27 06:43:29 thoma Exp $ */
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

#include <DynamicEnums/DynamicEnums.h>


#define EIGENE_KUNDENID 1
//#define DEFAULT_INSTANZ 1 /* entspricht ppsInstanzID::Kundenauftraege; */

#ifdef MABELLA_EXTENSIONS
   #define DEFAULT_ARTIKELTYP   3
#elif defined PETIG_EXTENSIONS
   #define DEFAULT_ARTIKELTYP   0
#else
   #define DEFAULT_ARTIKELTYP   1
#endif

