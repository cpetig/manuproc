/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 1998-2003 Adolf Petig GmbH & Co. KG
 *  written by Malte Thoma and Christof Petig
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

#include "steuerprogramm.hh"

#ifdef MANU_PROC_TEST
#include "AuftragsVerwaltung.hh"
#include "Check.hh"
#include <Lager/Lager.h>
#include <Auftrag/Auftrag.h>
#include <Misc/Trace.h>
#include <unistd.h>
// Lieferschein
#include <Lieferschein/Lieferschein.h>
//#include <Misc/inbetween.h>
#include "TestReihe.h"

static bool ManuProCTest(AufEintrag &AE)
{
      {// Planen des Einkaufs (Granulat, gr�n)
      Auftrag PA=Auftrag(Auftrag::Anlegen(EINKAUF),ManuProC::DefaultValues::EigeneKundenId);
      int znr=3;
      AufEintrag AEP((AufEintragBase(EINKAUF,AuftragBase::ungeplante_id,znr)));
      assert(AEP.Artikel()==ARTIKEL_GRANULAT_GRUEN);
      AufEintrag PAE(AEP.Planen(200,PA,PLANDATUM5));
      vergleichen(Check::Menge,"planen_granulat","Planen des Einkaufs(Granulat)","P");

      // Spezifischen Lieferschein schreiben
      Lieferschein liefs(EINKAUF,cH_Kunde(ManuProC::DefaultValues::EigeneKundenId));
      liefs.push_back(PAE, ARTIKEL_GRANULAT_GRUEN,1,200);
//unspezifisch   liefs.push_back(ARTIKEL_GRANULAT_GRUEN,1,200);
      vergleichen(Check::Menge|Check::Lieferschein,"liefern_granulat","Lieferung (bestimmt) Granulat","L");
      }

      {// Planen des Einkaufs (Metall)
      Auftrag PA=Auftrag(Auftrag::Anlegen(EINKAUF),ManuProC::DefaultValues::EigeneKundenId);
      int znr=4;
      AufEintrag AEP((AufEintragBase(EINKAUF,AuftragBase::ungeplante_id,znr)));
      assert(AEP.Artikel()==ARTIKEL_METALL);
      AufEintrag PAE(AEP.Planen(10,PA,PLANDATUM5));
      vergleichen(Check::Menge,"planen_metall","Planen des Einkaufs(Metall)","P2");


      // Unspezifischen Lieferschein schreiben
      Lieferschein liefs(EINKAUF,cH_Kunde(ManuProC::DefaultValues::EigeneKundenId));
      liefs.push_back(ARTIKEL_METALL,1,5);
      vergleichen(Check::Lieferschein|Check::Menge,"liefern_metall","Lieferung (unbestimmt) Metall","L2");
      }

      {// Planen der Gie�erei (ARTIKEL_GRIFF_ROT)
      Auftrag PA=Auftrag(Auftrag::Anlegen(GIESSEREI),ManuProC::DefaultValues::EigeneKundenId);
      int znr=1;
      AufEintrag AEP((AufEintragBase(GIESSEREI,AuftragBase::ungeplante_id,znr)));
      assert(AEP.Artikel()==ARTIKEL_GRIFF_ROT);
      AufEintrag PAE(AEP.Planen(500,PA,PLANDATUM5));
      vergleichen(Check::Menge,"planen_griff","Planen der Giesserei (Griff rot)","PG");


      // Unspezifischen Lieferschein schreiben
      Lieferschein liefs(GIESSEREI,cH_Kunde(ManuProC::DefaultValues::EigeneKundenId));
      liefs.push_back(ARTIKEL_GRIFF_ROT,500);
      vergleichen(Check::Lieferschein|Check::Menge,"liefern_griff","Lieferschein (Gie�erei) anlegen","LG");
      }

      {// Produktion in der Werkstatt ohne da� vorher etwas geplant wurde
      Lieferschein liefs(WERKSTATT,cH_Kunde(ManuProC::DefaultValues::EigeneKundenId));
      liefs.push_back(ARTIKEL_SCHRAUBENZIEHER_GELB,600);
      vergleichen(Check::Lieferschein|Check::Menge,"liefern_schraubendr","Produktion in der Werkstatt anlegen","LW");
      }

      {// Lieferscheinschreiben f�r das Schraubenzieherlager => auslagern
      Lieferschein liefs(SCHRAUBENZIEHERLAGER,cH_Kunde(ManuProC::DefaultValues::EigeneKundenId));
      liefs.push_back(ARTIKEL_SCHRAUBENZIEHER_ROT,450);
      vergleichen(Check::Lieferschein|Check::Menge,"auslagern","Lieferschein f�r das Rohwarenlager (auslagern)","LR");
      }

      {// Lieferscheinschreiben f�r den Kunden
      Lieferschein liefs(KUNDENINSTANZ,cH_Kunde(KUNDE));
      liefs.push_back(ARTIKEL_SORTIMENT_BUNT,450);
      vergleichen(Check::Lieferschein|Check::Menge,"ausliefern","Lieferschein f�r den Kunden","LK");
      }

      {// Lieferscheinschreiben f�r den Kunden  (�berlieferung)
      Lieferschein liefs(KUNDENINSTANZ,cH_Kunde(KUNDE));
      liefs.push_back(ARTIKEL_SORTIMENT_BUNT,60);
      vergleichen(Check::Lieferschein|Check::Menge,"ueberliefern","Lieferschein f�r den Kunden (�berlieferung)","LK�");
      }
   return true;
}

static TestReihe ManuProCTest_(&ManuProCTest,"ManuProC Test","MP");

static bool AutoProduktion()
{
      {
      Auftrag A=Auftrag(Auftrag::Anlegen(ppsInstanzID::Kundenauftraege),KUNDE);
      AufEintragBase aeb=A.push_back(10,DATUM,ArtikelBase(40),OPEN,true);
      vergleichen(Check::Menge,"ap_auftrag","Auftrag anlegen","");
      
      Lieferschein liefs(ppsInstanz::ID(41),cH_Kunde(ManuProC::DefaultValues::EigeneKundenId));
      int lznr=liefs.push_back(ArtikelBase(41),5);
      vergleichen(Check::Lieferschein|Check::Menge,"ap_liefern_prod","Lieferung Edukt","LE");

      LieferscheinEntryBase lsb(liefs,lznr);
      LieferscheinEntry(lsb).changeMenge(0,0,liefs,false);
      vergleichen(Check::Lieferschein|Check::Menge,"ap_liefern_weg","Lieferung Edukt zur�cknehmen","-E");
      
      Lieferschein liefs2(KUNDENINSTANZ,cH_Kunde(KUNDE));
      int lznr2=liefs2.push_back(ArtikelBase(40),5);
      vergleichen(Check::Lieferschein|Check::Menge,"ap_liefern","Lieferung Produkt","L");

      LieferscheinEntryBase lsb2(liefs2,lznr2);
      LieferscheinEntry(lsb2).changeMenge(0,0,liefs2,false);
      vergleichen(Check::Lieferschein|Check::Menge,"ap_zurueck","Lieferung Produkt zur�cknehmen","-");
      }
   return true;
}

static TestReihe AutoProduktion_(&AutoProduktion,"automatisches Produzieren","AP");

#endif
