#include <map>
#include <string>

#ifndef MULTI_LANG
#define MULTI_LANG


class MultiL_Dict
{
 int sprid;
 std::map<int,std::string> textmap;
 std::map<int,std::string> defaultmap; 

public:
 typedef enum {	TXT_RECHNUNG=1,
		TXT_AUFTRAG=2,
		TXT_VOM=3,
		TXT_DANKE_AUFTR=4,
		TXT_LIEF_FREI=5,
		TXT_WARE_ZOLL=6,
		TXT_BANKVERB=7,
		TXT_KONTO=8,		
		TXT_BANK=9,				
		TXT_SEITE=10,
		TXT_ZAHLUNG=11,
		PRINTF_ZAHLUNG1=12,
		PRINTF_ZAHLUNG2=13,		
		PRINTF_ZAHLUNG3=14,
		PRINTF_ZAHLUNG4=15,
		TXT_BETREUUNG=16,
		TXT_FRAU=17,
		TXT_TELEFON=18,
		TXT_TELEFAX=19,
		TXT_BESUCHTSIE=20,
		TXT_IHREKDNR=21,
		TXT_USTID=22,
		TXT_MENGE=23,
		TXT_ARTIKEL=24,
		TXT_BREITE=25,
		TXT_FARBE=26,
		TXT_AUFMACHUNG=27,
		TXT_BEZEICHNUNG=28,
		TXT_STUECK=29,
		TXT_RABATT=30,
		TXT_NETTO=31,
		TXT_BRUTTO=32,
		TXT_SUMME=33,
		TXT_GESAMT=34,
		TXT_UEBERTRAG=35,
		TXT_VORTRAG=36,
		TXT_AUFTRWERT=37,
		TXT_HERR=38,
		TXT_FIRMA=39,
		TXT_SIEERHIELTEN=40,
		TXT_UNSERESTNR=41,
		TXT_UNSEREAUFNR=42,
		TXT_UNSERELIEF=43,
		TXT_IHRAUFTRAG=44,
		TXT_LIEFERKW=45,
		TXT_LIEFERINFO=46,
		TXT_WERT=47,
		TXT_OFFEN=48,
		TXT_BTN=49,
		TXT_LIEFERWOCHE=50,
		PRINTF_RUECKSTAND=51,
		TXT_LIEFADRESSE=52,
		TXT_RNGADRESSE=53,
		PRINTF_LIEFBESTEHT1=54,
		PRINTF_LIEFBESTEHT2=55,
		TXT_PACKSPALLET=56,
		TXT_GEWBRUTTO=57,
		TXT_GEWNETTO=58,
		TXT_LIEFERSCHEIN=59,
		TXT_GUTSCHRIFT=60,
		TXT_EU_PREFERENZ=61,
		TXT_ODER=62,
		PRINTF_ZAHLUNG5=63,
		PRINTF_ZAHLUNG6=64,		
		TXT_MADEINGER=65,
		PRINTF_ZAHLUNG7=66,
		TXT_EU_WARE_ISRAEL=67,
		TXT_DEN=68,
		PRINTF_ZAHLUNG8=69,
		KARTENNR=70,
		KOLLEKTION=71,
		EAN_CODE=72,
		PRINTF_ZAHLUNG9=73,
		PRINTF_ZAHLUNG10=74,
		MWST=75,
		PREISDIFFERENZ=76,
		SEHR_GEEHRTE_DUH=77,
		SEHR_GEEHRTE_H=78,
		SEHR_VEREHRTE_F=79,
		TXT_STORNO=80,
		PRINTF_ZAHLUNG11=81,
		TXT_ANSPRECHPARTNER=82,
		IHR_ARTIKEL=83,
		BESTELLUNG=84,
		BESTELL_TEXT=85,
		EINKAUF_ABTLG=86,
		TXT_IHRE_LIEFERNR=87,
		TXT_ZWISCHENSUMME=88,
		PRINTF_ZAHLUNG12=89,
	     } LangTXT;

 MultiL_Dict(int sprache, int default_spr=1);
 MultiL_Dict() : sprid(-1) {}
 std::string MLT(const LangTXT textid, std::string def_string="UNKNOWN");
 bool valid() const { return sprid!=-1; }
 int getSprId() const { return sprid; }
};


#endif


