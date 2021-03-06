// $Id: test_Bankauftrag.cc,v 1.7 2003/01/08 10:18:51 christof Exp $
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

#include <Misc/Ausgabe_neu.h>
#include <Bank/Bankauftrag.h>
#include <iostream.h>
#include <Misc/dbconnect.h>

void Ausgabetest()
{  std::cout << Formatiere(12345) << "\n";
   std::cout << Formatiere(12345,4) << "\n";
   std::cout << Formatiere(12345,2) << "\n";
   std::cout << Formatiere(12345678901234ULL,6) << "\n";
}

void Bankauftragtest()
{  std::string s0("EINZIEHER"),s1("BELASTETER"),s2("Zweck A"),s3("Zweck B"),
	s4("Auftraggeber");
   Bankauftrag a('G',33450000,s0,240044,"cat >out.tex");
   Zahlvorgang z(10010010,1234567,300000,false,s1,s2,s4);
   a<<z;
}

int main()
{ 
  Ausgabetest();
  ManuProC::dbconnect(); 
  Bankauftragtest();
   return 0;
}
