// $Id: class_auftrag_tree.hh,v 1.19 2006/08/09 15:36:51 christof Exp $

#include <DynamicEnums/DynamicConfig.h>
#include <Artikel/ArtikelMengeSumme.h>
#include <Misc/EntryValueDatum.h>
#include <Misc/EntryValueFixed.h>
#include <Misc/EntryValueIntString.h>
#include <Auftrag/AufEintragZu.h>
// die Definition sollte wirklich in ein .cc file !
#include <Misc/i18n.h>

std::ostream &operator<<(std::ostream &o, const ArtikelMenge &am);
std::ostream &operator<<(std::ostream &o, const ArtikelMengeSumme &ams);

class Data_auftrag : public RowDataBase
{
   const AufEintrag &AB ;
   const auftrag_main *AM ;
   mutable ArtikelMenge menge;
public:
   std::string departments; // Abteilungen
   int depth,max_depth;

public:
   Data_auftrag(const
 AufEintrag& ab, auftrag_main* am) :
      AB(ab),AM(am),menge(AB.Artikel(),AB.getRestStk().as_int()),
      depth(),max_depth()
   {}

    virtual cH_EntryValue Value(guint seqnr,gpointer gp) const
 { 
    switch (seqnr) {
      case auftrag_main::KUNDE : {
       if(AB.getKdNr()!=Kunde::default_id)
//       AM->get_Instanz()->Id()==ppsInstanzID::Kundenauftraege ||
//	  AM->get_Instanz()->ExterneBestellung())
        {
         if (AM->Kunden_nr_bool())
	   return cH_EntryValueIntString(AB.getKdNr()); 
	 cH_Kunde kd(AB.getKdNr());
	 if (AM->Kunden_mit_ort())
	   {
	    return cH_EntryValueIntString(kd->sortname()+"; "+kd->ort()); 
	   }
         else
	   return cH_EntryValueIntString(kd->sortname()); 
        }
       else
#ifdef HAS_STAGE_Einkauf
       if (AB.Instanz()->Id()==ppsInstanzID::Einkauf)
       { ArtikelStamm ast(AB.Artikel());
         ManuProcEntity<>::ID q=ast.Bezugsquelle();
         if (q!=ManuProcEntity<>::none_id) 
           return cH_EntryValueIntString(cH_Kunde(q)->sortname());
         return cH_EntryValue();
       }
       else
#endif
         return cH_EntryValue();
       }
      case auftrag_main::A1 ... auftrag_main::A4 : {
      	 ExtBezSchema::ID schema=1;
         if (!AM->interneNamen_bool()) schema = cH_Kunde(AB.getKdNr())->getSchemaId();
         cH_ArtikelBezeichnung artbez(AB.Artikel(),schema);
         return artbez->Komponente_als_EntryValue(seqnr-int(auftrag_main::A1));
         }
      case auftrag_main::LIEFERDATUM : {
         if (AM->Zeit_kw_bool())
            return cH_EntryValueKalenderwoche(AB.getLieferdatum().KW());
         else   
            return cH_EntryValueDatum(AB.getLieferdatum());
       }
      case auftrag_main::LETZTELIEFERUNG : {
          return cH_EntryValueDatum(AB.LetzteLieferung());
       }
      case auftrag_main::AUFTRAG : {
            if (AM->get_Instanz()->LagerInstanz())
            { switch (AB.Id())
              { case Auftrag::ungeplante_id: return cH_EntryValueIntString(_("fehlend"));
                case Auftrag::plan_id: return cH_EntryValueIntString(_("reserviert"));
                case Auftrag::dispo_id: return cH_EntryValueIntString(_("verfügbar"));
              }
            }
            std::string auftrag;
            if(AM->Kunden_anr_bool() && 
	       AM->get_Instanz()->Id()==ppsInstanzID::Kundenauftraege)
               auftrag =      AB.getYourAufNr() ;
            else                      
#ifdef MABELLA_EXTENSIONS            
	      if(AM->get_Instanz()->Id()==ppsInstanzID::Einkauf)
		{if(AM->Kunden_anr_bool())
		   auftrag = AB.getYourAufNr()+" - ";
		 auftrag += itos(AB.getAuftragid());
		}
	      else
#endif	      
                auftrag = itos(AB.getAuftragid()) ;

	    if(AB.getEntryStatus()==UNCOMMITED)
	      auftrag = "("+auftrag+")";
            return cH_EntryValueIntString(auftrag);}

      case auftrag_main::LETZTEPLANINSTANZ :{
            std::string s = cH_ppsInstanz(AB.LetztePlanInstanz())->shortName()+" ";
            if (AB.getProzDat().valid()) s+=AB.getProzDat().Short();
            return cH_EntryValueIntString(s);
         }
      case auftrag_main::VERARBEITUNG : {
         if (max_depth) 
           return cH_EntryValueIntString(itos(depth)+"/"+itos(max_depth));
         return cH_EntryValue();
#if 0         
         std::string verarbeitung;
         try {
            verarbeitung = AB.Planung();
         } catch (std::exception &e ) 
         { verarbeitung=e.what(); }
	 return cH_EntryValueIntString(verarbeitung);
#endif	 
	 }
#ifdef ANZEIGE_VON_STUECK_UND_METER_IN_PPS	 
      case auftrag_main::METER : 
         if (AM->Instanz()==ppsInstanzID::Einkauf)
            return cH_EntryValueIntString(menge.abgeleiteteMenge());
         else
         {ArtikelMenge::mengen_t m=menge.getMenge(EinheitID::m);
          if (!m) return cH_EntryValue();
          else return cH_EntryValueFixed<ManuProC::Precision::ArtikelMenge>(m);
         }
      case auftrag_main::STUECK : 
         if (AM->Instanz()==ppsInstanzID::Einkauf)
            return cH_EntryValueIntString(menge.Menge());
         else
         {ArtikelMenge::mengen_t m=menge.getMenge(Einheit::Stueck);
          if (!m) return cH_EntryValue();
          else return cH_EntryValueFixed<ManuProC::Precision::ArtikelMenge>(m);
         }
#else
      case auftrag_main::METER : 
      	  return cH_EntryValueIntString(menge.abgeleiteteMenge());
      case auftrag_main::STUECK : 
          return cH_EntryValueIntString(menge.Menge());
#endif
      case auftrag_main::INSTANZEN:
          return cH_EntryValueIntString(departments);
     }
   return cH_EntryValue();
 }

   AuftragBase::mengen_t offene_Stueck()const {return AB.getRestStk();}
   int get_aid() const {return AB.getAuftragid();} 
   int get_zeilennr() const {return AB.getZnr();} 
   __deprecated int get_Artikel_ID() const {return AB.Id();}
   ArtikelBase get_Artikel() const {return AB.Artikel();}
   ManuProC::Datum get_Lieferdatum() const {return AB.getLieferdatum();}
   std::string ProzessText() const {return AB.getProzess()->getTyp()+" "+AB.getProzess()->getText() ;}
   // wieso ist das hier veränderbar?
   AufEintrag& get_AufEintrag() const {return const_cast<AufEintrag&>(AB);}
   const ArtikelMenge getArtikelMenge() const { return menge; }
   void redisplayMenge(SimpleTree *maintree_s) const
    {  menge=ArtikelMenge(AB.Artikel(),AB.getRestStk().as_int());
       maintree_s->redisplay(this,auftrag_main::METER);
       maintree_s->redisplay(this,auftrag_main::STUECK);
    }
   void redisplayLetzePlanInstanz(SimpleTree *maintree_s) const
       {maintree_s->redisplay(this,auftrag_main::LETZTEPLANINSTANZ);}
};

struct cH_Data_auftrag : public Handle<const Data_auftrag>
{  cH_Data_auftrag(const Data_auftrag *r) : Handle<const Data_auftrag>(r){}
};


class Data_Node : public TreeRow
{
  ArtikelMengeSumme sum;

public:
 virtual void cumulate(const cH_RowDataBase &rd)
   {  const ArtikelMenge &am=rd.cast_dynamic<const Data_auftrag>()->getArtikelMenge();
      sum.cumulate(am);
   }
 virtual void deduct(const cH_RowDataBase &rd)
   {  const ArtikelMenge &am=rd.cast_dynamic<const Data_auftrag>()->getArtikelMenge();
      sum.deduct(am);
   }
  cH_EntryValue Value(guint index,gpointer gp) const
   {
    switch(index) 
      { 
#ifdef ANZEIGE_VON_STUECK_UND_METER_IN_PPS	 
      case auftrag_main::METER : 
         {ArtikelMengeSumme::mengen_t m=sum.Summe(EinheitID::m);
          if (!m) return cH_EntryValue();
          else return cH_EntryValueFixed<ManuProC::Precision::ArtikelMenge,double,long long>(m);
         }
      case auftrag_main::STUECK : 
         {ArtikelMengeSumme::mengen_t m=sum.Summe(Einheit::Stueck);
          if (!m) return cH_EntryValue();
          else return cH_EntryValueFixed<ManuProC::Precision::ArtikelMenge,double,long long>(m);
         }
#else
        case auftrag_main::METER : return cH_EntryValueIntString(sum.abgeleiteteMenge());
        case auftrag_main::STUECK : return cH_EntryValueIntString(sum.Menge());
#endif
        default : return cH_EntryValue();
      }
   }
   Data_Node(const Handle<const TreeRow> &suminit)
   { if (suminit) sum=suminit.cast_dynamic<const Data_Node>()->sum;
   }
 static Handle<TreeRow> create(const Handle<const TreeRow> &suminit)
   {  return new Data_Node(suminit);
   }

};

