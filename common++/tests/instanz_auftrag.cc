// $Id: instanz_auftrag.cc,v 1.2 2002/01/07 16:23:09 christof Exp $
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2000 Adolf Petig GmbH & Co. KG, written by Malte Thoma
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

#include <iostream>
#include <Auftrag/AuftragFull.h>
#include <Kunde/Kunde.h>
#include <Aux/exception.h>
#include <Aux/dbconnect.h>
#include <Auftrag/AuftragsBaum.h>
//#include <Aux/ppsInstanz.h>

void showChildren(AufEintragBase2 AEB)
{
  AuftragsBaum AB(AEB,true);
  cout << "Self: "<<AEB.Instanz()<<' '<<AEB.Id()<<' '<<AEB.ZNr()<<' '<<'\n';
  for (AuftragsBaum::const_iterator i=AB.begin();i!=AB.end();++i)
   {
     cout <<i->AEB2.Instanz()<<' '<<i->AEB2.Id()<<' '<<i->AEB2.ZNr()
         <<' '<<cH_ArtikelBezeichnung(i->AB)->Bezeichnung()
         <<'\t'<<i->menge<<' '
         <<'\t'<<cH_ArtikelBezeichnung(i->AB)->Bezeichnung()<<' '
         <<cH_ppsInstanz(i->AEB2.Instanz())->Name()<<'\n';
   }
}

vector<AufEintragBase> showTest(Auftrag id)
{
   AuftragFull af(id);
   vector<AufEintragBase> VAEB;
   for (AuftragFull::const_iterator i=af.begin(); i!=af.end(); ++i)
    {  
      showChildren(*i);
      VAEB.push_back(*i);
    }
 return VAEB;
}


int main()
{  Petig::PrintUncaughtExceptions();
   Petig::dbconnect();
   
   AuftragBase id;
   {  Auftrag a=Auftrag(Auftrag::Anlegen(ppsInstanz::Kundenauftraege), Kunde::default_id);
      id=a;
      std::cout << "Auftrag " << a.Id() << '\n';
   
      Petig::Datum date(6,3,2010);
      int znr;
      znr=a.insertNewEntry(3000, date, 218843,UNCOMMITED,true);
      znr=a.insertNewEntry(2000, date, 218849,UNCOMMITED,true);
   }
   vector<AufEintragBase> VAEB=showTest(id);

   static const int TESTZEILE = 1;
   int znr=0;
//   Petig::Datum newdate(3,3,2100);
   for(vector<AufEintragBase>::iterator i=VAEB.begin();i!=VAEB.end();++i)
    {
      if(++znr==TESTZEILE)
       {
//         cout << "TEST f�r AEB: "<<i->Instanz()<<' '<<i->Id()<<' '<<i->ZNr()<<' '<<i->getStueck()<<'\n';
//           i->updateStk(10000,true); // Neue Menge 
//           i->updateLieferdatum(newdate); // Neues Lieferdatum
//           i->setStatus(OPEN); // Neuer Status
//           i->split(500,newdate); // Auftrag spliten            
       }
    }

   cout << "\n Nach dem Test:\n\n";
   showTest(id);
   Auftrag(id).setStatusAuftrag_(CLOSED);
   return 0;
}
