// $Id$

#include <Misc/i18n.h>
#include "windowTop.hh"
#include "MyMessage.h"
#include <gtkmm/main.h>
#include <gtkmm/notebook.h>
#include <Kunde/Kundengruppe.h>
#include "kundendaten_aux.hh"
#include <DynamicEnums/DynamicConfig.h>

void windowTop::Model_Refresh(void *x)
{
 if(rabatt.matches(x))
   {if(kundendaten->Id()==Kunde::none_id) return;
    std::cout << "Rabatt set to:" << rabatt.get_value() << "\n";
    kundendaten->set_rabatt(rabatt.get_value());
    checkbutton_zeilenrabatt->grab_focus();
   }
    
}

void windowTop::on_notebook1_switch_page(GtkNotebookPage* page,guint pagenr)
{
  switch (enum_notebook(pagenr))
   {
     case PAGE_KUNDE          : if(kundendaten->Id()==Kunde::none_id)
                                 { frame_adresse->set_sensitive(false);
                                   frame_kundenkontakt->set_sensitive(false);
                                 }
                                break;
     case PAGE_ZAHLUNG		:
     case PAGE_DETAILS        : if(kundendaten->Id()==Kunde::none_id) 
                                   table_details->set_sensitive(false);
                                else show_details(); 
                                break;
     case PAGE_KONTAKTPERSON  : if(kundendaten->Id()==Kunde::none_id) 
                                   table_kontaktperson->set_sensitive(false);
                                else show_kontaktpersonen(); 
                                break; 
//     case PAGE_PERSON         : show_privatpersonen(); break; 
     case PAGE_NOTIZEN		: 
     	try { load_notizen(); }
        catch(SQLerror &e) { MyMessage *m=manage(new MyMessage()); m->Show(e);}
     	break;
     case PAGE_GRUPPEN: 
     	try { showGruppen(); }
        catch(SQLerror &e) { MyMessage *m=manage(new MyMessage()); m->Show(e);}
     	break;     	
   }
}

windowTop::windowTop(unsigned id)
: kundendaten(Kunde::none_id),person(Kunde::none_id),
   transaction("",false), 
   UpdateAdresse(Kunde::UpdateBitsAdresse(0)),
   UpdateFirma(Kunde::UpdateBitsFirma(0)), 
   UpdateBank(Kunde::UpdateBitsBank(0)), 
   UpdateSonst(Kunde::UpdateBitsSonst(0)),
// UpdatePerson(Person::UpdateBits(0)), 
   fire_enabled(true),
   allgrp(NULL),wahlgrp(NULL),bankid(0)
{
 clear_entrys();
 label_speichern->set_text("");
 setTitles();
 button_del_preisliste->set_sensitive(false);
 button_spreis_add->set_sensitive(false);
 

 gruppenwahl->set_value(Kundengruppe::default_ID);
 kundenauswahl->reset();
 kundenauswahl->EinschraenkenKdGr(gruppenwahl->get_value());
 kundenauswahl->setExpandStr1(true);
 kundenauswahl->setExpandStr2(true); 
 geburtstag->setLabel("");
 geburtstag->setExpandYear(false);

#ifdef HAS_ADDR_GROUP_Rechnungsadresse 
 rng_an->EinschraenkenKdGr(KundengruppeID::Rechnungsadresse);
#endif
#ifdef HAS_ADDR_GROUP_Lieferadresse
 lfr_an->EinschraenkenKdGr(KundengruppeID::Lieferadresse);
#endif

  betreuer->setExpandStr1(true);
  betreuer->setExpandStr2(true); 
#ifdef HAS_ADDR_GROUP_Personen  
  betreuer->set_gruppe(KundengruppeID::Personen);
  KontaktPersonenBox->set_gruppe(KundengruppeID::Personen);
#endif

 scc_verkaeufer->reset();
#ifdef HAS_ADDR_GROUP_Verkaeufer
 scc_verkaeufer->set_gruppe(KundengruppeID::Verkaeufer);
#endif 
 scc_verkaeufer->setExpandStr1(true);
 scc_verkaeufer->setExpandStr2(true); 

 connectFkt();

  KontaktStore=Gtk::ListStore::create(kontakt_cols);
  clistPersonenListe->set_model(KontaktStore);
  clistPersonenListe->append_column(_("Vorname"),kontakt_cols.name);
  clistPersonenListe->append_column(_("Name"),kontakt_cols.name2);
  clistPersonenListe->append_column(_("Position"),kontakt_cols.position);
  clistPersonenListe->get_selection()->signal_changed().connect(SigC::slot(*this, 
       &windowTop::on_clistPersonenListe_selection_changed));
  if (id!=unsigned(Kunde::none_id))
    laden(id);


 // initialize MVC components
  rabatt=0;
  ManuProC::Associationf2(*spinbutton_Rabatt).set_model(rabatt);
  rabatt.signal_changed().connect(SigC::slot(*this,&windowTop::Model_Refresh));
}

void windowTop::saveAll()
{
   try{
   if(UpdateAdresse!=0) kundendaten->update_e(UpdateAdresse);
   if(UpdateFirma!=0) kundendaten->update_e(UpdateFirma);
   if(UpdateBank!=0) kundendaten->update_e(UpdateBank);
   if(UpdateSonst!=0) kundendaten->update_e(UpdateSonst);
//   if (UpdatePerson!=0) update_person();
   
   clear_update_bits();
   
   }catch(SQLerror &e) { MyMessage *m=manage(new MyMessage()); m->Show(e);}
}

void windowTop::clear_update_bits()
{  UpdateAdresse=Kunde::UpdateBitsAdresse(0);
   UpdateFirma=Kunde::UpdateBitsFirma(0);
   UpdateBank=Kunde::UpdateBitsBank(0);
   UpdateSonst=Kunde::UpdateBitsSonst(0);
//   UpdatePerson=Person::UpdateBits(0);
}

bool windowTop::on_delete_event(GdkEventAny*)
{
 on_buttonBeenden_clicked();
 return true;
}


void windowTop::on_buttonBeenden_clicked()
{   
   kundenauswahl->grab_focus();
   saveAll();
   saveKundenKontakt();
//   update_person(); passiert in saveAll, CP
   Gtk::Main::instance()->quit();
}


   // Details


void windowTop::clear_entrys()
{   
   frame_adresse->set_sensitive(false);
   frame_kundenkontakt->set_sensitive(false);
   fire_enabled=false;
   
//   spinbuttonGruppenNr->set_value(0);
   entrySortiername->set_text("");
   entryPostanwVor->set_text("");
   entryPostanwNach->set_text("");
   entryPLZ->set_text("");
   entryOrt->set_text("");
   entryStrasse->set_text("");
   entryHausNr->set_text("");
   entryFirma->set_text("");
   entryPostfach->set_text("");
   entryPostfachPLZ->set_text("");
   entryIdNr->set_text("");
   KundenTelefon->clear();
//   entryTelefonNr->set_text("");
   landesbox->clear();

   // Details
   scc_verkaeufer->clear();
   scc_anrede->clear();
   betreuer->reset();
   spinbutton_Flaeche->set_value(0);
   spinbutton_Kundenumsatz->set_value(0);
   spinbutton_Planumsatz->set_value(0);
//   spinbutton_Rabatt->set_value(0);
   rabatt=0;

   spinbutton_Mitarbeiter->set_value(1);
   spinbutton_Umsatz->set_value(0);
   spinbutton_skontofrist1->set_value(0);
   spinbutton_skontosatz1->set_value(0);
   spinbutton_skontofrist2->set_value(0);
   spinbutton_skontosatz2->set_value(0);
   spinbutton_skontofrist3->set_value(0);
   spinbutton_skontosatz3->set_value(0);
   entryVerein->set_text("");
   spinbutton_einzugRabatt->set_value(0);
   entryBankKonto->set_text("");
   entry_blz->set_text("");
   extartbez->reset();
   rng_an->reset();
   lfr_an->reset();
   textNotiz->get_buffer()->erase(textNotiz->get_buffer()->begin(),textNotiz->get_buffer()->end());
   
   checkbutton_zeilenrabatt->set_active(false);
   checkbuttonBankeinzug->set_active(false);
   checkbuttonRchngAdr->set_active(false);
   checkbuttonLieferAdr->set_active(false);
   checkbutton_lieferung_frei_haus->set_active(true);
   
   kundendaten=H_Kunde(Kunde::none_id);
//   telefon.erase(telefon.begin(),telefon.end());

   ab_an_rngadresse->set_active(false);
   checkbutton_rng_an_postfach->set_active(false);

   clear_update_bits();
   fire_enabled=true;
   kunden_status->set_active(true);
   preisautomatik->set_active(false);

   iban_entry->set_text("");
   cab_entry->set_text("");
   abi_entry->set_text("");
   acc_entry->set_text("");
   bankname_italy->set_text("");
   iban_save->set_sensitive(false);
   iban_abbruch->set_sensitive(false);      
   riba_save->set_sensitive(false);
   riba_abbruch->set_sensitive(false);     
   zahlverfahren_book->set_current_page(PAGE_DTAUS); 
   
   aufnotiz->get_buffer()->erase(aufnotiz->get_buffer()->begin(),aufnotiz->get_buffer()->end());
   rngnotiz->get_buffer()->erase(rngnotiz->get_buffer()->begin(),rngnotiz->get_buffer()->end());
   liefnotiz->get_buffer()->erase(liefnotiz->get_buffer()->begin(),liefnotiz->get_buffer()->end());
   aufnotiz_save->set_sensitive(false);
   rngnotiz_save->set_sensitive(false);   
   liefnotiz_save->set_sensitive(false);   
   
   geburtstag->set_value(ManuProC::Datum());
   
}


void windowTop::setTitles()
{
 std::vector<std::string> preis;
 preis.push_back(_("Suchreihenfolge"));
 preis.push_back(_("Bezeichnung"));
 preis.push_back(_("Nr"));
 SonderPreislisteTree->setTitles(preis);
 
 std::vector<std::string> grp_titel(alle_gruppen->Cols());
 grp_titel[Data_Gruppe::GRP_ID]=_("Nr.");
 grp_titel[Data_Gruppe::GRP_OBID]=_("Obergruppe");
 grp_titel[Data_Gruppe::GRP_BEZ]=_("Gruppe");
 grp_titel[Data_Gruppe::GRP_KOMM]=_("Kommentar"); 
 alle_gruppen->setTitles(grp_titel); 
 gewaehlte_gruppen->setTitles(grp_titel);  
}

void windowTop::on_kunden_status_toggled()
{   
 if(kundendaten->getNummer()==Kunde::none_id) return;
 try{
 kundendaten->setAktiv(kunden_status->get_active());
 }
 catch(SQLerror &e)
 {
  MyMessage *m=manage(new MyMessage()); m->Show(e);
 }
}

void windowTop::on_preisautomatik_clicked()
{  
 if(kundendaten->getNummer()==Kunde::none_id) return;
 try{
 	kundendaten->Preisautomatik(preisautomatik->get_active());
    }
 catch(SQLerror &e)
 {
  MyMessage *m=manage(new MyMessage()); m->Show(e);
 }

}


void windowTop::on_gruppenwahl_activate()
{  
 kundenauswahl->reset();
 kundenauswahl->EinschraenkenKdGr(gruppenwahl->get_value());
 clear_entrys();
 notebook_main->set_current_page(PAGE_KUNDE);
}


void windowTop::on_riba_save_clicked()
{
#ifdef MABELLA_EXTENSIONS 
 try{
 kundendaten->setABI_CAB(abi_entry->get_text(),cab_entry->get_text(),
				acc_entry->get_text());
 abi_entry->set_text(kundendaten->getABI_Code(true));
 cab_entry->set_text(kundendaten->getCAB_Code());
 acc_entry->set_text(kundendaten->getRiBaACC());
 }  
 catch(SQLerror &e) { MyMessage *m=manage(new MyMessage()); m->Show(e); }   

 bankname_italy->set_text(kundendaten->getABIBankName());
 
 riba_save->set_sensitive(false);
 riba_abbruch->set_sensitive(false); 
#endif 
}

void windowTop::on_riba_abbruch_clicked()
{  
#ifdef MABELLA_EXTENSIONS 
 riba_save->set_sensitive(false);
 riba_abbruch->set_sensitive(false);
 
 try{
 abi_entry->set_text(kundendaten->getABI_Code());
 cab_entry->set_text(kundendaten->getCAB_Code());
 acc_entry->set_text(kundendaten->getRiBaACC());
 } 
 catch(SQLerror &e) 
  { if(e.Code()==100) 
      {
       abi_entry->set_text("");
       cab_entry->set_text("");
       acc_entry->set_text("");
       riba_save->set_sensitive(false);
       riba_abbruch->set_sensitive(false);       
       return; 
      }
   MyMessage *m=manage(new MyMessage()); m->Show(e); 
  } 
#endif
}

void windowTop::on_iban_abbruch_clicked()
{
#ifdef MABELLA_EXTENSIONS 
 iban_save->set_sensitive(false);
 iban_abbruch->set_sensitive(false);  

 try{iban_entry->set_text(kundendaten->getIBAN_Code());}
 catch(SQLerror &e) { MyMessage *m=manage(new MyMessage()); m->Show(e); } 
#endif
}

void windowTop::on_iban_save_clicked()
{  
#ifdef MABELLA_EXTENSIONS 
 try{
 kundendaten->setIBAN(iban_entry->get_text());
 iban_entry->set_text(kundendaten->getIBAN_Code(true));
 }
 catch(SQLerror &e) 
   { MyMessage *m=manage(new MyMessage()); m->Show(e); } 

 iban_save->set_sensitive(false);
 iban_abbruch->set_sensitive(false);
#endif
}

bool windowTop::on_acc_entry_changed(GdkEventFocus *e)
{
 riba_save->set_sensitive(true);
 riba_abbruch->set_sensitive(true);  
 return false;
}

bool windowTop::on_abi_entry_changed(GdkEventFocus *e)
{
 riba_save->set_sensitive(true);
 riba_abbruch->set_sensitive(true);  
 return false;
}

bool windowTop::on_cab_entry_changed(GdkEventFocus *e)
{  
 riba_save->set_sensitive(true);
 riba_abbruch->set_sensitive(true);  
 return false; 
}


bool windowTop::on_iban_entry_changed(GdkEventFocus *e)
{
 iban_save->set_sensitive(true);
 iban_abbruch->set_sensitive(true);    
 return false;  
}

void windowTop::on_zahlverfahren_book_switch_page(GtkNotebookPage *p0, guint pagenr)
{  
#ifdef MABELLA_EXTENSIONS 
 try{
 switch(enum_zahl_verfahren(pagenr))
   {
    case PAGE_DTAUS: break;
    case PAGE_RIBA:
    	 abi_entry->set_text(kundendaten->getABI_Code());
 	 cab_entry->set_text(kundendaten->getCAB_Code());
	 acc_entry->set_text(kundendaten->getRiBaACC());
 	 bankname_italy->set_text(kundendaten->getABIBankName());
 	 break;
    case PAGE_LCR:
   	 iban_entry->set_text(kundendaten->getIBAN_Code(true)); 	 
   	 break;
    default: return;
   }
 }
 catch(SQLerror &e) { if(e.Code()==100) return;
 	MyMessage *m=manage(new MyMessage()); m->Show(e); } 
#endif
 
}


/////////////////////////////////////////////////////////////////////////
// Extras
/////////////////////////////////////////////////////////////////////////

/*
void windowTop::on_button_neu_spl_nummer_clicked()
{
  unsigned int n=PreisListe::nextval();
  spinbutton_new_spreislist->set_value(n);
}

void windowTop::on_button_neue_spl_anlegen_clicked()
{
  std::string e=entry_new_spreislist_name->get_text();
  if(e=="") 
   { 
     label_speichern->set_text("FEHLER: Name muß eingegeben werden");
     return;
   }
 PreisListe::createPreisliste(spinbutton_new_spreislist->get_value_as_int(),e);
}
*/



void windowTop::on_aufnotiz_save_clicked()
{  
 if(kundendaten->getNummer()==Kunde::none_id) return; 
 
 kundendaten->setFixeNotiz(Kunde::AUF_NOTIZ,
 	aufnotiz->get_buffer()->get_text(aufnotiz->get_buffer()->begin(),aufnotiz->get_buffer()->end()));
 aufnotiz_save->set_sensitive(false); 
}

void windowTop::on_aufnotiz_changed()
{  
 aufnotiz_save->set_sensitive(true);
}

void windowTop::on_liefnotiz_save_clicked()
{  
 if(kundendaten->getNummer()==Kunde::none_id) return; 
 
 kundendaten->setFixeNotiz(Kunde::LIEF_NOTIZ,
 	liefnotiz->get_buffer()->get_text(liefnotiz->get_buffer()->begin(),liefnotiz->get_buffer()->end()));
 liefnotiz_save->set_sensitive(false); 
}

void windowTop::on_liefnotiz_changed()
{  
 liefnotiz_save->set_sensitive(true); 
}

void windowTop::on_rngnotiz_save_clicked()
{  
 if(kundendaten->getNummer()==Kunde::none_id) return; 
 
 kundendaten->setFixeNotiz(Kunde::RNG_NOTIZ,
 	rngnotiz->get_buffer()->get_text(rngnotiz->get_buffer()->begin(),rngnotiz->get_buffer()->end()));
 rngnotiz_save->set_sensitive(false); 
}

void windowTop::on_rngnotiz_changed()
{  
 rngnotiz_save->set_sensitive(true);
}

void windowTop::load_notizen()
{
 if(kundendaten->getNummer()==Kunde::none_id) return; 

 Gtk::TextBuffer::iterator pos=aufnotiz->get_buffer()->begin();
 std::string n;
 
 n=kundendaten->fixeNotiz(Kunde::AUF_NOTIZ);
 aufnotiz->get_buffer()->insert(pos,n);
 aufnotiz_save->set_sensitive(false);

 n=kundendaten->fixeNotiz(Kunde::RNG_NOTIZ); 
 pos=rngnotiz->get_buffer()->begin();
 rngnotiz->get_buffer()->insert(pos,n);
 rngnotiz_save->set_sensitive(false);
 
 n=kundendaten->fixeNotiz(Kunde::LIEF_NOTIZ);
 pos=liefnotiz->get_buffer()->begin();
 liefnotiz->get_buffer()->insert(pos,n);
 liefnotiz_save->set_sensitive(false); 
 
}


void windowTop::on_selectrow_allegruppen(cH_RowDataBase leaf)
{
 gruppe_in->set_sensitive(true);
 allgrp=const_cast<Data_Gruppe*>(dynamic_cast<const Data_Gruppe*>(&*leaf)); 
}

void windowTop::on_unselectrow_allegruppen()
{  
 gruppe_in->set_sensitive(false);
 allgrp=NULL;
}

void windowTop::on_selectrow_gewaehltegruppen(cH_RowDataBase leaf)
{  
 gruppe_out->set_sensitive(true);
 wahlgrp=const_cast<Data_Gruppe*>(dynamic_cast<const Data_Gruppe*>(&*leaf)); 
}

void windowTop::on_unselectrow_gewaehltegruppen()
{  
 gruppe_out->set_sensitive(false);
 wahlgrp=NULL;
}



void windowTop::on_lfran_activate()
{
   
}

void windowTop::on_gruppe_in_clicked()
{  
 if(kundendaten->Id()==Kunde::none_id) return;
 kundendaten->putInGrp(allgrp->GrpId());
 showGruppen(); 
 allgrp=NULL;
}

void windowTop::on_gruppe_out_clicked()
{  
 if(kundendaten->Id()==Kunde::none_id) return;
 kundendaten->pullFromGrp(wahlgrp->GrpId());
 showGruppen();
 wahlgrp=NULL; 
}


void windowTop::on_clear_button_clicked()
{
 on_gruppenwahl_activate();
}


void windowTop::on_ab_an_rngadresse_toggled()
{
 if(kundendaten->Id()==Kunde::none_id) return;
   kundendaten->AB_an_rngadresse(ab_an_rngadresse->get_active());  
}

void windowTop::scc_verkaeufer_reset()
{  

}

void windowTop::on_entryPersonenPosition_activate()
{  
}

#include "window_kundengruppen.hh"

void windowTop::gruppen_bearbeiten()
{ new window_kundengruppen(this,gruppenwahl->get_value());
}

void windowTop::laden(cH_Kunde const& k)
{ kundenauswahl->set_value(k->Id()); kunden_activate(); }
