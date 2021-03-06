/*  pps: ManuProC's ProductionPlanningSystem
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
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

#include <gtkmm/main.h>
#include "auftrag_main.hh"
#include "auftrag_bearbeiten.hh"
#include "auftragbase.h"
#include <Misc/exception.h>
#include <Misc/dbconnect.h>
#include "MyMessage.h"
#include <Misc/Trace.h>
#include <Misc/dbcapability.h>
#include <Misc/Event.h>
#include <Misc/Query.h>
#include <config.h>

MyMessage *meldung;
auftrag_main *auftragmain;
ManuProC::Connection *Conn;
DBCapability *dbcapability;
bool load_list=true; 	// Wenn false, dann auf keinen Fall die Liste beim
			// Start laden, da die ISDN Leitung zu langsam ist

void RC_close(void);
char **env;

int main(int argc, char **argv, char **envp)
{  
 Conn = new ManuProC::Connection();
 int i;
 env=envp;

#if 0 // disabled to use gle
 while ((i = getopt(argc, argv, "h:d:s")) != EOF)
 switch (i)
   {  case 'h':
         Conn->setHost(optarg);
         break;
      case 'd':
         Conn->setDbase(optarg);
         break;
      case 's':
	 load_list=false;
	 break;
      default : break;
   }
#endif

#if defined(ENABLE_NLS)
   bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
   bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
   textdomain (GETTEXT_PACKAGE);
#endif ///* ENABLE_NLS*/
   Gtk::Main m(argc, argv);
 ManuProC::PrintUncaughtExceptions();

// ManuProC::Tracer::Enable(ManuProC::Tracer::Auftrag);
 
 meldung = new MyMessage();
 try{ 
 ManuProC::dbconnect(*Conn); 
 Query ("set names 'utf-8'");
 dbcapability=new DBCapability();
 }
 catch(SQLerror &e)
  { meldung->Show(e);
    return 1;
  }
  
  
// cH_ppsInstanz instanz(ppsInstanzID::Kundenauftraege);
// if (argc-optind>1) instanz=cH_ppsInstanz(ppsInstanz::ID(atoi(argv[optind])));

  auftragmain = new auftrag_main();
  ManuProC::Event::connect_glib();

weiter:

// meines Wissens geht das gar nicht ... CP Feb02
 try{ m.run();}
   catch(SQLerror &e) {meldung->Show(e); goto weiter;}

 catch(ManuProC::Datumsfehler &df)
   {std::cout << df;}
  
 delete auftragmain;
 ManuProC::dbdisconnect_nt(Conn->Dbase());

#ifdef MABELLA_EXTENSIONS
 RC_close();
#endif

 delete meldung;
 delete Conn;
 return 0;
}


