/*  pps: ManuProC's ProductionPlanningSystem
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
 *  Copyright (C) 2006 Christof Petig
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

#include "config.h"
#include "auftrag_rechnung.hh"
#include<Misc/Ausgabe_neu.h>
#include<Misc/itos.h>
#include <Artikel/Artikelpreis.h>
#include <gtkmm/menu.h>
#include "auftrag_rechnung_classes.h"
#include "MyMessage.h"
#include <Misc/dbconnect.h>
#include "ja_nein_frage.hh"
extern MyMessage *meldung;

#include <Misc/dbcapability.h>
extern DBCapability *dbcapability;
//extern ManuProC::Connection *Conn;
#include <Auftrag/AufEintrag.h>
#include <expander_hook.h>
#include <Lieferschein/RechnungVoll.h>
#include <Misc/i18n.h>
#include <Misc/ucompose.hpp>

#define MAX_DRUCK_ANZAHL	5

void auftrag_rechnung::on_rng_close()
{   
   timeout_connection.disconnect();
   delete this;
}

void auftrag_rechnung::on_rng_neu()
{   
 ja_nein_frage jnf(_("Wollen Sie jetzt wirklich eine neue Rechnung erstellen ?"));

 jnf.set_transient_for(*this);

 int ret=jnf.run();

 if(ret==Gtk::RESPONSE_YES)
  {
   if(lieferkunde->get_value()!=-1 && lieferkunde->get_value()!=0)
   {
    newRechnung(lieferkunde->get_value());
    rngnr->setContent(Formatiere((unsigned long)rechnung.Id(),0,6,"","",'0'),rechnung.Id());
    rngdatum->set_value(ManuProC::Datum::today());
    on_rngnr_activate();
   }
  else
   lieferkunde->grab_focus();
  }
}


void auftrag_rechnung::newRechnung(const Kunde::ID kid)
{
 try{ rechnung=Rechnung(cH_Kunde(kid)); }
 catch(SQLerror &e)
   {meldung->Show(e);}
  set_rtree_daten_content(rechnung.Id());
}

void auftrag_rechnung::on_rng_save()
{   
}

void auftrag_rechnung::on_rng_preview()
{   
   if (rngnr->get_text()=="") return;
   std::string optionen;
   if(checkbutton_ean_drucken->get_active()) optionen =" --ean ";
   
   std::string command = "auftrag_drucken -G -aRechnung -n"
         +rngnr->get_text() 
         +" -i"+itos(instanz->Id()) 
         +optionen ;
   system(command.c_str());
}

#ifdef MABELLA_EXTENSIONS
#define STD_MABELLA(x,y) (y)
#else
#define STD_MABELLA(x,y) (x)
#endif

void auftrag_rechnung::on_rng_print()
{   
   if (rngnr->get_text()=="") return;
//   std::string com="auftrag_drucken  -a Rechnung -n "+rngnr->get_text()+" -p -i "+itos(instanz->Id()) ;
   std::string opt_ean;
   if(checkbutton_ean_drucken->get_active())  opt_ean +=" --ean ";

   std::string com="auftrag_drucken -aRechnung -n"
         +rngnr->get_text()+" -i"+itos(instanz->Id())+opt_ean ;

     cH_Kunde k(rechnung.KdNr());
     std::string opt=" -Y";
     if (k->anzahl_ausdruck_firmenpapier()>0)
     {
#ifdef MABELLA_EXTENSIONS // wirklich???
      opt+=itos(k->anzahl_ausdruck_firmenpapier())+",0,";
#else
      opt+="1,"+itos(k->anzahl_ausdruck_firmenpapier()-1)+",";
#endif
     }
     else opt+="0,0,";
     opt+=itos(k->anzahl_ausdruck_weissespapier());
     system((com+opt).c_str());
}

void auftrag_rechnung::rngzeile_delete()
{
 try{   
   if(!(rechnung.Bezahlt()) && rechnung.getFiBuBuchid()==0)
	{
    try{
     cH_Data_Rechnung dt(rtree_daten->getSelectedRowDataBase_as<cH_Data_Rechnung>());
     RechnungEntry RE = dt->get_RechnungEntry();
     rechnung.deleteLieferschein(RE.Lfrs());
     if(rechnung.size()==0)
       rechnung.setVerknr(Kunde::none_id);
     } catch(...){}
	 on_rngnr_activate(); // neu anzeigen
   }
 }
 catch(SQLerror &e)
  {meldung->Show(e); return;}

 rngentry_del->set_sensitive(false); 
}

void auftrag_rechnung::on_rngdate_activate()
{   
 rechnung.setze_Datum(rngdatum->get_value());
 label_rechnung_ctl->set_text(_("Rechungsdatum geändert"));
 timeout_connection = Glib::signal_timeout().connect(SigC::slot(*this,&auftrag_rechnung::timeout),1000);
}

bool auftrag_rechnung::timeout()
{ 
   label_rechnung_ctl->set_text("");
   return 0; 
}
       

void auftrag_rechnung::redisplay()
{try{ 
  set_rtree_daten_content(rngnr->Content());
 }
 catch(SQLerror &e) {meldung->Show(e); return; }
 
 std::string gebucht;
 if(rechnung.getFiBuBuchid()>0) gebucht=_("gebucht in FiBu - ");
 if(rechnung.rngArt()==Rechnung::RART_GUT)
   {
     frame_rechnung->set_label(gebucht+_("Gutschrift"));
     frame_rechnungsdaten->set_label(_("Gutschriftsdaten"));
     set_title(_("Gutschrift"));
     gutschrift->set_sensitive(false);
   }
 else if(rechnung.rngArt()==Rechnung::RART_RNG)
   {
     frame_rechnung->set_label(gebucht+_("Rechnung"));
     frame_rechnungsdaten->set_label(_("Rechnungsdaten"));
     set_title(_("Rechnung"));
     gutschrift->set_sensitive(true);     
   }
 else if(rechnung.rngArt()==Rechnung::RART_STORNO)
   {
     frame_rechnung->set_label(gebucht+_("Rechnung (Storniert)"));
     frame_rechnungsdaten->set_label(_("Rechnungsdaten"));
     set_title(_("Rechnung"));
     gutschrift->set_sensitive(true);     
   }
 else 
   {
std::cout <<rechnung.rngArt()<<'\n';
     assert(!"Never get here\n");
   }
}


void auftrag_rechnung::clear_rng()
{
 rngnr->reset();
 rechnung=Rechnung();
 rabatt_wert->set_value(0);
 rngdatum->set_value(ManuProC::Datum::today());
 zahlziel->set_value(ManuProC::Datum());
 optionmenu_zahlart->set_history(0);
 rtree_daten->clear();
 bezahlt->set_active(false);
}

void auftrag_rechnung::on_rngnr_activate()
{try{
 redisplay();
 lieferkunde->set_value(rechnung.KdNr());   
 set_rtree_offen_content(lieferkunde->get_value());
 rng_WWaehrung->set_value(rechnung.getWaehrung());

 Rechnung::rabatt_t rabatt=rechnung.Rabatt();
 if (rabatt<0.0) { rabatt=-rabatt; rabatt_typ->set_history(rabatt_typ::Zuschlag); }
 else rabatt_typ->set_history(rabatt_typ::Rabatt);
 rabatt_wert->set_value(rabatt.as_float());
 rngdatum->set_value(rechnung.getDatum());
 zahlziel->set_value(rechnung.getZahlziel());
 optionmenu_zahlart->set_history(rechnung.getZahlungsart()->Id());

 rng_notiz->get_buffer()->set_text("");
 rng_notiz_save->set_sensitive(false);
 rng_notiz->get_buffer()->set_text(rechnung.Notiz());
 rng_notiz_save->set_sensitive(false);

 bezahlt->set_active(rechnung.Bezahlt());
 storno->set_sensitive(!bezahlt->get_active() &&
			rechnung.rngArt()==RechnungBase::RART_RNG);
//			rechnung.getFiBuBuchid()==0);
 gutschrift->set_sensitive(!bezahlt->get_active() &&
                           rechnung.getFiBuBuchid()==0);
 rngdatum->set_sensitive(rechnung.getFiBuBuchid()==0);
 optionmenu_zahlart->set_sensitive(rechnung.getFiBuBuchid()==0);
 rabatt_wert->set_sensitive(rechnung.getFiBuBuchid()==0);
 rabatt_typ->set_sensitive(rechnung.getFiBuBuchid()==0);
 rng_WWaehrung->set_sensitive(rechnung.getFiBuBuchid()==0);
 frame_betrag->set_sensitive(rechnung.getFiBuBuchid()==0);
 
 rtree_daten->show();
// vbox_n_b_lieferscheine->show();
 frame_rechnungsdaten->show(); 

 showBetraege(); 
 }
 catch(SQLerror &e) {meldung->Show(e);}
}


void auftrag_rechnung::showBetraege()
{
 bool as_brutto(true);
 if(rechnung.Valid())
   {
    Preis::geldbetrag_out brutto(rechnung.Betrag(as_brutto));
    if(brutto<0) brutto*=-1; // Gutschriften ohne Minus anzeigen
    rgbetrag_warenwert->set_value(brutto.as_float());
    as_brutto=false;
    Preis::geldbetrag_out netto(rechnung.Betrag(as_brutto));
    if(netto<0) netto*=-1; // Gutschriften ohne Minus anzeigen
     rgbetrag_netto->set_value(netto.as_float());

     Preis::geldbetrag_out rabatt(brutto-netto);
     rgbetrag_rabatt->set_value(rabatt.as_float());
     
     bool with_update_on_db=false;
     Preis::geldbetrag_out endnetto(rechnung.Endbetrag(with_update_on_db));
    if(endnetto<0) endnetto*=-1; // Gutschriften ohne Minus anzeigen

     Preis::geldbetrag_out zuschl(endnetto-netto);
     rgbetrag_zusabs->set_value(zuschl.as_float());
     rgbetrag_zwsumme->set_value(endnetto.as_float());

     Preis::geldbetrag_out mwst(0);
     if(rechnung.getKunde()->MwSt())
       mwst=(rechnung.MwStProz.as_float()/100.0)*endnetto.as_float();
     rgbetrag_mwst->set_value(mwst.as_float());

     rgbetrag_endsumme->set_value((mwst+endnetto).as_float());

     cP_Waehrung w(rechnung.getWaehrung());
     label_waehrung1->set_text(w->Kurzbezeichnung());
     label_waehrung2->set_text(w->Kurzbezeichnung());
     label_waehrung3->set_text(w->Kurzbezeichnung());
     label_waehrung4->set_text(w->Kurzbezeichnung());
     label_waehrung5->set_text(w->Kurzbezeichnung());
     label_waehrung6->set_text(w->Kurzbezeichnung());
     label_waehrung7->set_text(w->Kurzbezeichnung());
     entsorgung->set_active(rechnung.Entsorgung());
  }else
  {
    rgbetrag_warenwert->set_value(0);
     rgbetrag_netto->set_value(0);
     rgbetrag_rabatt->set_value(0);
     rgbetrag_zusabs->set_value(0);
     rgbetrag_zwsumme->set_value(0);
     rgbetrag_mwst->set_value(0);
     rgbetrag_endsumme->set_value(0);
     cP_Waehrung w(Waehrung::default_id);
     label_waehrung1->set_text(w->Kurzbezeichnung());
     label_waehrung2->set_text(w->Kurzbezeichnung());
     label_waehrung3->set_text(w->Kurzbezeichnung());
     label_waehrung4->set_text(w->Kurzbezeichnung());
     label_waehrung5->set_text(w->Kurzbezeichnung());
     label_waehrung6->set_text(w->Kurzbezeichnung());
     label_waehrung7->set_text(w->Kurzbezeichnung());  
     entsorgung->set_active(false);
  }
}

void auftrag_rechnung::on_lieferkunde_activate()
{
 clear_rng();
 cH_Kunde k(lieferkunde->get_value());
 
#ifndef MABELLA_EXTENSIONS
 if(lieferkunde->get_value() != k->Rngan())
    lieferkunde->set_value(k->Rngan());
#else
   checkbutton_ean_drucken->set_active(k->showEAN());   
#endif

 rng_WWaehrung->set_value(cH_Kunde(lieferkunde->get_value())->getWaehrung());

 try{
  set_rtree_offen_content(lieferkunde->get_value()) ;
 }catch(SQLerror &e) {meldung->Show(e);}
}

void auftrag_rechnung::preis_activate()
{   
}

bool auftrag_rechnung::checkVerkConsist(const cH_Lieferschein &chl)
{
#ifdef MABELLA_EXTENSIONS
 if(rechnung.getVerknr()!=Kunde::none_id)
   {if(rechnung.getVerknr()!=chl->getVerknr())
     { meldung->Show(_("Lieferscheine von verschiedenen Verkäufern dürfen nicht "
		"auf eine Rechnung; Bitte getrennte Rechnungen erstellen"));
       return false;
     }
   }
 else
  rechnung.setVerknr(chl->getVerknr());
#endif

 return true;
}

void auftrag_rechnung::lieferschein_uebernehmen()
{   
 try{
 if(rtree_offen->get_selection()->count_selected_rows())
   {if (rechnung.Id()<1) 
     {
      on_rng_neu();
      if(rechnung.Id()<1)
        return;
     }
   if(!(rechnung.Bezahlt()) && rechnung.getFiBuBuchid()==0)
	{
    try {
      cH_Data_RLieferoffen dt(rtree_offen->getSelectedRowDataBase_as<cH_Data_RLieferoffen>());

   	cH_Lieferschein chl(dt->get_Lieferschein()); 
      if(rechnung.Rabatt() != (chl->AufRabatt()) && 
         rechnung.Rabatt() != (Rechnung::rabatt_t)0)
           {meldung->Show(String::ucompose(_("Aufträge mit unterschiedlichen Rabatten\n"
           	"(Rechnung %1%% Lieferschein/Auftrag %2%%)\n"
           	"dürfen nicht auf eine Rechnung"),
           	Formatiere_short(rechnung.Rabatt()),Formatiere_short(chl->AufRabatt())));
            return;
           }
       else
         rechnung.setze_Rabatt(chl->AufRabatt());

	if(!checkVerkConsist(chl))
	  return;

// Versuch unterschiedliche Zahlungsziele zu handeln
#ifdef MABELLA_EXTENSIONS         
   ManuProC::Datum d(chl->getMaxZahlziel());
       if(d.valid())
         {
          if(zahlziel->get_value().valid())
            {if(zahlziel->get_value()<d)
              rechnung.setze_Zahlziel(d);
            }
          else 
            {rechnung.setze_Zahlziel(d);            
             zahlziel->set_value(d);
            }
           
          // Wenn Zahlungsziel schon vergangen, dann auf Standard setzten
	  // bzw. das Zahlungsziel löschen
            
          cH_Zahlungsart za(rechnung.getZahlungsart());
          if( ((zahlziel->get_value())<rechnung.getDatum())
		&& !za->getBankeinzug())
            {
//rechnung.setze_Zahlungsart(cH_Zahlungsart(Zahlungsart::default_Zahlart));
	     rechnung.setze_Zahlziel(za->getZahlungstermin(rechnung.getDatum()));	
	    }
	     // bei Bankeinzug und vergangener Valuta, sofort einziehen
          else if( ((zahlziel->get_value())<rechnung.getDatum())
		&& za->getBankeinzug())
	    rechnung.setze_Zahlziel(ManuProC::Datum());

         }
       else {
         cH_Zahlungsart za(rechnung.getZahlungsart());
         if(za->getBankeinzug() || za->FristMonate())
          if(!zahlziel->get_value().valid())
             {rechnung.setze_Zahlziel(za->getZahlungstermin(rechnung.getDatum()));
              zahlziel->set_value(za->getZahlungstermin(rechnung.getDatum()));
             }

         }
#endif         
             
       rechnung.addLieferschein(*chl);
   	 on_rngnr_activate();
      }
    catch(SQLerror &e) {meldung->Show(e);return;}
    catch(std::exception &e) {std::cerr << e.what();}
	}
   }
 }
 catch(SQLerror &e)
 {meldung->Show(e);return;}

}



void auftrag_rechnung::on_rdaten_leaf_selected(cH_RowDataBase d)
{
 if(rechnung.Valid())
   if(rechnung.getFiBuBuchid() > 0)
     return;

try{
  const Data_Rechnung *dt=dynamic_cast<const Data_Rechnung*>(&*d);
  rngentry_del->set_sensitive(true);

  // Preise
  RechnungEntry RE=dt->get_RechnungEntry();

  cH_Kunde liefknd(lieferkunde->get_value());
  cH_Kunde rngkd(liefknd->Rngan());

  Artikelpreis::UnCache(rngkd->preisliste(),RE.Artikel());
  label_artikelpreis->set_text(Formatiere(Artikelpreis(
          cH_PreisListe(rngkd->preisliste()),RE.Artikel(),RE.Stueck()).Wert()));
  spinbutton_preiseingabe->set_value(RE.getPreis().Wert().as_float());
  try{
    label_auftragspreis->set_text(Formatiere(RE.getAuftragsPreis().Wert()));
   }catch(AufEintrag::NoAEB_Error &e) 
      // Wenn kein Auftrag zu dieser Rechnungszeile existiert
    {  radiobutton_auftragspreis->hide();
       label_auftragspreis->hide();
       radiobutton_artikelpreis->set_active(true);
    }
  button_pr->set_sensitive(true);

  radiobutton_artikelpreis->set_sensitive(true);
  radiobutton_auftragspreis->set_sensitive(true);
  radiobutton_preiseingabe->set_sensitive(true);
  spinbutton_preiseingabe->set_sensitive(
  	radiobutton_preiseingabe->get_active()); 
 
}catch(std::exception &e) {std::cerr<<e.what();}


}

void auftrag_rechnung::on_unselectrow_rtree()
{
 rngentry_del->set_sensitive(false); 
 button_pr->set_sensitive(false);
 radiobutton_artikelpreis->set_sensitive(false);
 radiobutton_auftragspreis->set_sensitive(false);
 radiobutton_preiseingabe->set_sensitive(false);
 spinbutton_preiseingabe->set_value(0);
 spinbutton_preiseingabe->set_sensitive(false); 
 label_artikelpreis->set_text(Formatiere(fixedpoint<2>(0)));
 label_auftragspreis->set_text(Formatiere(fixedpoint<2>(0)));
}


/*
void auftrag_rechnung::on_selectrow_rechnung(int row, int col, GdkEvent* b)
{
 TCListRow_API *tclapi=(TCListRow_API*)(rechnung_liste->get_row_data(row));
 selectedrow_rng=(TreeRow*)(*tclapi).get_user_data();

 if(!selectedrow_rng->Leaf()) return;

 // es ging nicht mit dynamic_cast auf OffAuf_Leaf ??!!
 cH_Rg_RowData entry((dynamic_cast<TreeRow*>(selectedrow_rng))->LeafData());

 
 rngentry_del->set_sensitive(true); 
}
*/

void auftrag_rechnung::on_roffen_leaf_selected(cH_RowDataBase d)
{
 const Data_RLieferoffen *dt=dynamic_cast<const Data_RLieferoffen*>(&*d);

 if(!rechnung.Valid())
    {lieferkunde->set_value(dt->get_Lieferschein()->getKunde()->Id());
     lief_uebernehmen->set_sensitive(true);
    }
 else   
    lief_uebernehmen->set_sensitive(rechnung.getFiBuBuchid()==0);
    
 lieferscheinnr->set_text(itos(dt->get_Lieferschein()->Id()));   
 lieferscheindatum->set_value(dt->get_Lieferschein()->LsDatum());

}

/*
void auftrag_rechnung::on_selectrow_offlief(int row, int col, GdkEvent* b)
{
 TCListRow_API *tclapi=(TCListRow_API*)(offene_lieferscheine->get_row_data(row));
 selectedrow_lief=(TreeRow*)(*tclapi).get_user_data();

 // es ging nicht mit dynamic_cast auf OffAuf_Leaf ??!!
 cH_OffLief_RowData entry((dynamic_cast<TreeRow*>(selectedrow_lief))->LeafData());

 lieferscheinnr->set_text(itos(entry->Lief().Id()));
 lieferscheindatum->set_value(entry->Lief().LsDatum()); 
 
 lief_uebernehmen->set_sensitive(true); 
}
*/

void auftrag_rechnung::on_unselectrow_rtree_offen()
{
 lieferscheinnr->set_text("");
 lieferscheindatum->set_value(ManuProC::Datum::today());  
 lief_uebernehmen->set_sensitive(false); 
}        

void auftrag_rechnung::Preis_setzen()
{  
 ja_nein_frage jnf(_("Wollen Sie wirklich den Preis ändern?"));
  
 jnf.set_transient_for(*this);

 int ret=jnf.run();

 if(ret==Gtk::RESPONSE_NO) return;


  cH_Kunde liefknd(lieferkunde->get_value());
  cH_Kunde rngkd(liefknd->Rngan());

 try{
  const Data_Rechnung *dt=dynamic_cast<const Data_Rechnung*>(&*(rtree_daten->getSelectedRowDataBase()));
  RechnungEntry RE=dt->get_RechnungEntry();
  if(radiobutton_artikelpreis->get_active())
   {
     RE.setzePreis(Artikelpreis(cH_PreisListe(rngkd->preisliste()),RE.Artikel(),RE.Stueck()));
   }
  else if(radiobutton_auftragspreis->get_active())
   {
     RE.setzePreis(RE.getAuftragsPreis());
   }  
  else if(radiobutton_preiseingabe->get_active())
   {
     spinbutton_preiseingabe->update();
     fixedpoint<2> p=fixedpoint<2>(spinbutton_preiseingabe->get_value());
     RE.setzePreis(Preis(p,rechnung.getWaehrung(),RE.getPreis().PreisMenge()));
   }  
  redisplay();
 }catch(std::exception &e) {std::cerr << e.what()<<'\n';}
}

void auftrag_rechnung::Preis_ergaenzen()
{
  cH_Kunde liefknd(lieferkunde->get_value());
  cH_Kunde rngkd(liefknd->Rngan());  

   if(!rechnung.Valid()) return;
   RechnungVoll rg=rechnung.Id();
   for (RechnungVoll::iterator i=rg.begin();i!=rg.end();++i)
   {  if (!(i->getPreis()))
      {  Artikelpreis p(cH_PreisListe(rngkd->preisliste()),ArtikelBase(i->ArtikelID()),i->Stueck());
         if (!(!p))
         {  i->setzePreis(p.In(rg.getWaehrung(),p.PreisMenge()));
         }
      }
   }
   redisplay();
}

void auftrag_rechnung::waehrung_geaendert()
{
 rechnung.setzeWaehrung(rng_WWaehrung->get_enum());
 Preis_setzen();
}

void auftrag_rechnung::rabatt_geaendert()
{  
  if ( rechnung.Id()!=-1)
   {
    rabatt_wert->update();
    int plus_minus=(rabatt_typ::enum_t((long)(rabatt_typ->get_menu()->get_active()->get_data("user_data"))))==rabatt_typ::Rabatt?+1:-1;
    rechnung.setze_Rabatt(rabatt_wert->get_value()*plus_minus);
   }
}

void auftrag_rechnung::init()
{
  gtk_expander_hook_size_to_parent(expander_ls->gobj());

#ifdef MABELLA_EXTENSIONS
  preis_ergaenzen->hide();
//  std::string nuraktiv(" and coalesce(aktiv,true)=true");
//  lieferkunde->Einschraenkung(nuraktiv,true);
  lieferkunde->EinschraenkenKdGr(KundengruppeID::Auftragsadresse);      
  lieferkunde->setExpandStr1(true);
  lieferkunde->setExpandStr2(true);
  checkbutton_ean_drucken->show(); 
  button_lieferscheine_aufraumen->hide();
#endif
   set_tree_titles();
   fill_optionmenu_zahlungsart();
   optionmenu_zahlart->get_menu()->signal_deactivate().connect(SigC::slot(*static_cast<class auftrag_rechnung*>(this), &auftrag_rechnung::optionmenu_zahlart_deactivate));
   rngdatum->setLabel("");
   zahlziel->setLabel("");
   zahlziel->set_value(ManuProC::Datum());
   lieferscheindatum->setLabel("");
   rtree_daten->hide();
   storno->set_sensitive(false);   
   
// set GUI for DBCapabilities
 DBCapability::WhiteColumn wc("rechnung","bezahlt");

 bezahlt->set_sensitive(dbcapability->isWhite(DBCapability::ColAct(wc,DBCapability::UPDATE)) );
}

auftrag_rechnung::auftrag_rechnung(cH_ppsInstanz _instanz)
: instanz(_instanz)
{ init();
  on_button_allopen_clicked();
}

auftrag_rechnung::auftrag_rechnung(RechnungBase const& toload)
: instanz(ppsInstanzID::Kundenauftraege)
{ init();
  rngnr->set_value(itos(toload.Id()),toload.Id());
  on_rngnr_activate();
}

void auftrag_rechnung::set_tree_titles()
{
 std::vector<std::string> t1;
 t1.push_back(_("Zeile"));
 t1.push_back(_("Lieferschein"));
 t1.push_back(_("Artikel"));   
 t1.push_back(_("Stueck"));
 t1.push_back(_("Liefermenge"));
 t1.push_back(_("E-Preis"));
 t1.push_back(_("G-Preis"));
 rtree_daten->setTitles(t1);  

 std::vector<std::string> t2;
 t2.push_back(_("Kunde"));
 t2.push_back(_("Lieferschein"));
 t2.push_back(_("Liefersch.Datum"));
 t2.push_back(_("Lieferung an"));
 rtree_offen->setTitles(t2);
}


void auftrag_rechnung::set_rtree_daten_content(RechnungBase::ID rngid)
{
 RechnungVoll rechnungvoll(RechnungBase::none_id);
 try {
  if(rngid!=RechnungBase::none_id)
    { 
      rechnungvoll = RechnungVoll(rngid);
      rechnung=Rechnung(rngid); 
    }
  else  rechnung=Rechnung(RechnungBase::none_id);
  }
 catch(SQLerror &e) { meldung->Show(e); return; }

 std::vector<cH_RowDataBase> datavec;
 for( RechnungVoll::const_iterator i=rechnungvoll.begin();i!=rechnungvoll.end();++i)
  {
   datavec.push_back(new Data_Rechnung(*i));
  }
 
 rtree_daten->clear();
 rtree_daten->setDataVec(datavec);
 
}

void auftrag_rechnung::optionmenu_zahlart_deactivate()
{
  int z = long(optionmenu_zahlart->get_menu()->get_active()->get_data("user_data"));
  if (rechnung.Id()!=-1 && rechnung.Id()!=0)
     rechnung.setze_Zahlungsart(cH_Zahlungsart(z));
}


//void auftrag_rechnung::on_button_gutschrift_clicked()
//{
//  label_rechnung_ctl->set_text("Sicher? Diese Entscheidung kann nicht rückgängig gemacht werden.");
//  table_gutschrift_sicherheit->show();
//}

//void auftrag_rechnung::on_button_gutschrift_nein_clicked()
//{
//  label_rechnung_ctl->set_text("");
//  table_gutschrift_sicherheit->hide();
//}

//void auftrag_rechnung::on_button_gutschrift_ja_clicked()
//{
//
//}

void auftrag_rechnung::on_zahlziel_activate()
{
 try {
  if (rechnung.Id()!=-1 && rechnung.Id()!=0)
    rechnung.setze_Zahlziel(zahlziel->get_value());
  }
  
 catch(SQLerror &e) { meldung->Show(e); return; }    
}


void auftrag_rechnung::on_checkbutton_ean_drucken_clicked()
{
 cH_Kunde k(lieferkunde->get_value());
 
 if(k->Id() != Kunde::none_id)   
    {
     (const_cast<Kunde*>(&*k))->
     	showEAN(checkbutton_ean_drucken->get_active());
    }
}



void auftrag_rechnung::on_button_allopen_clicked()
{
  rechnung=Rechnung();
  lieferkunde->reset();
  frame_rechnungsdaten->hide();
  rngnr->reset();
  set_rtree_offen_content(Rechnung::none_id);
//  rtree_offen->set_tree_column_visibility(
//	rtree_offen->getStore()->IndexFromColumn(Data_RLieferoffen::KUNDE_SEQ),true);
}


void auftrag_rechnung::on_button_lieferscheine_aufraumen_clicked()
{
  try{
     Lieferschein::aufraumen();
     on_button_allopen_clicked();
  }catch(SQLerror &e) {meldung->Show(e);}
}



void auftrag_rechnung::on_notiz_changed()
{
  rng_notiz_save->set_sensitive(true);
}

void auftrag_rechnung::on_notiz_save_clicked()
{   
  if(rechnung.Id()!=Rechnung::none_id) 
     rechnung.Notiz(rng_notiz->get_buffer()->get_text());
  rng_notiz_save->set_sensitive(false);
}

void auftrag_rechnung::on_bezahlt_toggled()
{ 
 if(!bezahlt->sensitive()) return;

 DBCapability::WhiteColumn wc("rechnung","bezahlt");
 if(dbcapability->isWhite(DBCapability::ColAct(wc,DBCapability::UPDATE)) )
   {
    try{
    if(rechnung.Id()!=Rechnung::none_id)
      {rechnung.setBezahlt(bezahlt->get_active());

      }
    }
    catch(SQLerror &e){meldung->Show(e);
      bezahlt->set_active(bezahlt->get_active());
      }
   }   
 else
  {meldung->Show(_("keine Berechtigung"));
   bezahlt->set_active(bezahlt->get_active());
  }

 if(rechnung.rngArt()==RechnungBase::RART_RNG)
   storno->set_sensitive(!bezahlt->get_active());   

}

void auftrag_rechnung::on_radiobutton_preiseingabe_toggled()
{  
 spinbutton_preiseingabe->set_sensitive(radiobutton_preiseingabe->get_active());
}


void auftrag_rechnung::on_gutschrift_activate()
{
 ja_nein_frage d(_("Wollen Sie wirklich eine Gutschrift erstellen ?"));
 
 d.set_transient_for(*this);
 
 gint ret=d.run();
 
 if(ret==Gtk::RESPONSE_YES)
   {
    try{
    rechnung.setRngArt(Rechnung::RART_GUT);

    ja_nein_frage lag(_("Soll die Ware dem Lager zugebucht werden ?"));
    lag.set_transient_for(*this);
    ret=lag.run();

    rechnung.convert_to_gutschrift(ret==0);

    }
    catch(SQLerror &e) 
      {meldung->Show(e);
       redisplay();
      }
    redisplay();
   }
}

#include <Lieferschein/LieferscheinVoll.h>

void auftrag_rechnung::on_storno_activate()
{
 if(rechnung.Bezahlt())
   { meldung->Show(_("Die Rechnung ist bereits bezahlt und kann nicht"
		" storniert werden; Bitte eine Gutschrift erstellen,"));
    return;
   }

 ja_nein_frage jnf(String::ucompose(_("Wollen Sie wirklich die Rechnung %1 stornieren ?"),itos0pad(rechnung.Id(),6)));

 jnf.set_transient_for(*this);

 int ret=jnf.run();

 try {
 if(ret==Gtk::RESPONSE_YES)
   {rechnung.setRngArt(RechnungBase::RART_STORNO);
    on_rngnr_activate();
    storno->set_sensitive(false);
   }
 }
 catch(SQLerror &e) 
  { meldung->Show(e); }

 set_rtree_daten_content(rechnung.Id());
}


#include "auftrag_provision.hh"
void auftrag_rechnung::on_provisionierung_activate()
{
 if(rechnung.Id()==RechnungBase::none_id) return;
 
 RechnungVoll rv(rechnung.Id(),true);
 
 auftrag_provision ap(&rv);
 ap.set_transient_for(*this);
 ap.run();
}


void auftrag_rechnung::on_lieferkunde_reset()
{  
 clear_rng();
 lieferkunde->grab_focus();
 showBetraege();
}


void auftrag_rechnung::on_clear_all()
{  
 lieferkunde->reset();
}

void auftrag_rechnung::on_entsorgung_toggled()
{
 try{
   if(rechnung.Id()!=Rechnung::none_id)
    rechnung.setEntsorgung(entsorgung->get_active());
    showBetraege();
   }
 catch(SQLerror &e)
   {meldung->Show(e);
    entsorgung->set_active(!entsorgung->get_active());
   }  
}


