// $Id: Zeitpunkt.cc,v 1.5 2002/05/09 12:46:00 christof Exp $
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


#include <Aux/Zeitpunkt_new.h>
#include <iostream>

#define TEST(x) std::cout << (x) << " = " << Zeitpunkt_new(x) << '\n'
#define TEST2(x) Zeitpunkt_new(x).write(PostgresTimestamp(buf,sizeof buf)); std::cout << (x) << " wrote " << buf << '\n'

int main()
{  char buf[40];
   TEST("2001-1-1");
   TEST("31.12.2001");
   TEST("20010819");
   TEST("2001-1-1 1:1:1");
   TEST("2001-2-3 4:5:6.7");
   TEST("2001-2-3 4:5:6+2");
   TEST("2001-2-3 4:5:6.7+2");
   TEST("2001-02-13 14:45:56.709213+02");
   TEST("20001231160002170809");
   TEST2("20001231160002170809");
   TEST2("31.12.2001");
   TEST2("2001-2-3 4:5:6.7");
   TEST2("2001-2-3 4:5:6.7+2");
   return 0;
}
