

#ifndef AUFTRRAG_DRUCKEN_LR_BASE
#define AUFTRRAG_DRUCKEN_LR_BASE

#include<Aux/Datum.h>
#include<string>
#include <Aux/multi_lang.h>
#include <stdio.h>

extern MultiL_Dict *mld;


class LR_Base
{
public:
   typedef enum typ {Lieferschein, Rechnung, Auftrag, Intern, Extern, Wareneingang, NICHTS}; 

private:
 typ t;
 bool rueckstand:1;

protected:
       bool gut:1;
       bool storno:1; 
       
public:
   void setRueckstand(bool r) { rueckstand=r;}
   bool Rueckstand() const { return rueckstand;}


  
    std::string typString() const { switch(t)
			{case Lieferschein : 
				return mld->MLT(MultiL_Dict::TXT_LIEFERSCHEIN) ;break;
                        case Wareneingang : 
				return "Wareneingang" ;break;				
			case Rechnung : 
				if(gut) return mld->MLT(MultiL_Dict::TXT_GUTSCHRIFT);
				else
				  {std::string ret=mld->MLT(MultiL_Dict::TXT_RECHNUNG);
				  if(storno)
				    ret+="("+mld->MLT(MultiL_Dict::TXT_STORNO)+")";
				  return ret;
				  }
				break;
			case Auftrag : 
			     if(rueckstand)
			        {char buf[200];
			         ManuProC::Datum heute_datum=ManuProC::Datum::today();
			         snprintf(buf,sizeof buf,mld->MLT(MultiL_Dict::PRINTF_RUECKSTAND).c_str(),
			         			heute_datum.c_str());
			         return std::string("~\\\\")+buf;	
				}
			     else
			     	return mld->MLT(MultiL_Dict::TXT_AUFTRAG);
			     break;     
			case Intern : return std::string("Intern"); break;
//			case Extern : return std::string("Bestellung \\small Nr."); break;
			case Extern : 
			     if(rueckstand)
			         {ManuProC::Datum heute_datum=ManuProC::Datum::today();
			          return std::string("~\\\\")+heute_datum.c_str()+" - R�ckstand zur Bestellung";
			         }
			     else			
				return std::string("Bestellung"); 
			     break;
			case NICHTS : default : return std::string("-");
			}
		}


public:
   typ Typ() const {return t;}
protected:

   LR_Base(typ _t,bool _r,bool _g, bool _s) 
   	:  t(_t), rueckstand(_r), gut(_g), storno(_s)  {}
   LR_Base(typ _t) 
   	:  t(_t), rueckstand(false), gut(false), storno(false)  {}   	
   bool gutschrift() const { return gut; }
   bool storniert() const { return storno; }
};

#endif
