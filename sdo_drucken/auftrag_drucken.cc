/*  pps: ManuProC's ProductionPlanningSystem
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Malte Thoma
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

#include <Aux/dbconnect.h>
#include "drucken.hh"
#include "getopt.h"
#include <Aux/itos.h>
#include "Configuration.h"

struct Configuration Configuration;

enum {EAN=256, COMBINE};

const static struct option options[]=
{{ "firma",  no_argument, NULL, 'f' },
 { "kopie",  no_argument, NULL, 'k' },  
 { "ean",  no_argument, NULL, EAN },  
 { "art",     required_argument,      NULL, 'a' }, 
 { "nr",     required_argument,      NULL, 'n' }, 
 { "print",     no_argument,      NULL, 'p' }, 
 { "instanz", required_argument,      NULL, 'i' }, 
 { "database", required_argument,      NULL, 'd' }, 
 { "dbhost", required_argument,      NULL, 'h' }, 
 { "combine-names", no_argument, NULL, COMBINE },
 { NULL,      0,       NULL, 0 }
};       


void usage(std::string n,bool toTeX,bool plot,bool firmenpapier,bool kopie,
   ppsInstanz::ID instanz,std::string database,std::string dbhost)
{
   std::cout << "$Id: auftrag_drucken.cc,v 1.1 2004/04/29 12:49:01 jacek Exp $\n\n"
              "USAGE:" << n << " -n <Nr> [-a <Auftrag|Rechnung|Lieferschein|Intern|Extern>] [-kft] [-i <Instanz>] [-d <Datenbank>]\n"
		"\n\t-t\t nur TeX file erzeugen ("<< (toTeX?"an":"aus")<< ")\n"
		"\t-p\t drucken ("<< (plot?"an":"aus")<< ")\n"
		"\t-a\t Aufrag(*), Rechnung, Lieferschein, Intern, Extern\n"
		"\t-n\t (A./R./L.)-Nummer (wichtig!)\n"
		"\t-f\t auf Firmenpapier ("<< (firmenpapier?"an":"aus")<< ")\n"
		"\t-f\t Kopien ("<< (kopie?"an":"aus")<< ")\n"
		"\t-i\t Instanz ausw�hlen ("<< instanz<< ")\n"
		"\t-d\t Datenbank ("<< database<< ")\n"
		"\t-h\t DbHost ("<< dbhost<< ")\n"
		"\t-R\t R�ckstand zum Auftrag\n"
		"\t--EAN\t Mit EAN-Code\n"
		"\t-Z\t Rechnung sortieren nach Zeilennr\n";
            exit(1);

}

bool sort_by_rownr=false;

int main (int argc, char *argv[])
{
 bool firmenpapier=false;
 bool kopie=false;
 LR_Base::typ was=LR_Base::Auftrag;
 bool plot=false;
 bool toTeX=false;
 bool rueckstand=false;
 bool ean_code=false;
 unsigned int auftragsnr = 0; 
 ppsInstanz::ID instanz = ppsInstanzID::Kundenauftraege;
 std::string database="";
 std::string dbhost="";
 bool combine=false;

 int opt;

 if(argc==1) usage(argv[0],toTeX,plot,firmenpapier,kopie,instanz,database,dbhost);

 while ((opt=getopt_long(argc,argv,"ftka:n:pi:d:RZ",options,NULL))!=EOF)
  { switch (opt)
    {  case 'f' : firmenpapier=true; break;
       case 'k' : kopie=true; break;
       case 'a' : if(std::string("Rechnung")==optarg) was=LR_Base::Rechnung;
		  else if(std::string("Lieferschein")==optarg) was=LR_Base::Lieferschein;
		  else if(std::string("Auftrag")==optarg) was=LR_Base::Auftrag;
		  else if(std::string("Intern")==optarg) was=LR_Base::Intern;
		  else if(std::string("Extern")==optarg) was=LR_Base::Extern;
		  else was=LR_Base::NICHTS;
		break;
       case 'n' : auftragsnr=atoi(optarg);break;
       case 'i' : instanz=(ppsInstanz::ID)atoi(optarg);break;
       case 'p' : plot=true;break;
	case 'd' : database=optarg;break; 
	case 'h' : dbhost=optarg;break; 
	case 't' : toTeX=true;break; 
	case 'R' : rueckstand=true; break;
	case EAN : ean_code=true; break;
	case COMBINE: Configuration.combine=true; break;
	case 'Z' : sort_by_rownr=true; break;
	case '?': usage(argv[0],toTeX,plot,firmenpapier,kopie,instanz,database,dbhost); break;
    }
  }                 
  try {
      ManuProC::Connection conn;
      conn.setDbase(database);
      conn.setHost(dbhost);
      ManuProC::dbconnect(conn);  

      LR_drucken l(was,auftragsnr,plot,firmenpapier,
			kopie,cH_ppsInstanz(instanz),
			toTeX,rueckstand,ean_code);
         
      ManuProC::dbdisconnect();
   } catch (SQLerror &e)
   {  std::cerr << e << '\n';
      return 1;
   }
   return 0;
}