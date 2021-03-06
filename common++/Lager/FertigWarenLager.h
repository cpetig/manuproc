// $Id: FertigWarenLager.h,v 1.27 2006/06/26 07:53:02 christof Exp $
/*  pps: ManuProC's production planning system
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
                
#ifndef _FERTIGWARENLAGER_HH
#  define _FERTIGWARENLAGER_HH

#include "FertigWaren.h"
#include "Lager.h"
#include <Misc/Query.h>


class LagerError : public std::exception
{
 std::string text;
 ArtikelBase::ID aid;
 
public:
 LagerError() throw() : text("unbekannter Lagerfehler"), aid(ArtikelBase::none_id) {}
 LagerError(const std::string t) throw() : text(t), aid(ArtikelBase::none_id) {}
 LagerError(const std::string t, const ArtikelBase::ID _id) throw() : 
 	text(t), aid(ArtikelBase::none_id) {}
 ~LagerError() throw() {}
 std::string Text() const throw() { return text; }
 ArtikelBase::ID ArtID() const throw() { return aid; }
 friend std::ostream &operator<<(std::ostream&,const LagerError &)
 					throw();
 std::string str() const throw();
 
};



class FertigWarenLager : public LagerBase
{
private:
   FertigWaren fw;

   void Buchen(FertigWaren::e_buchen e,const ProductionContext &ctx)
   							throw(LagerError);
   
   int lagerid;
   std::string bezeichnung;
   std::string tabelle;   
   std::string view_tabelle;      
   
   void initLager() 
   {
    Query("select bezeichnung,tabelle,bestand_view from lager"
       	    " where lagerid=?") << lagerid 
       		>> bezeichnung >> tabelle >> view_tabelle;
   }
   

public:
    static const unsigned int default_lagerid;
    static const unsigned int none_lagerid;    
    int Id() const { return lagerid; }

    const std::string Bezeichnung() const { return bezeichnung; }
    const std::string Tabelle() const { return tabelle; } 
    const std::string ViewTabelle() const { return view_tabelle; }   
    
#if defined MABELLA_EXTENSIONS && defined MANUPROC_DYNAMICENUMS_CREATED

   
      FertigWarenLager(const FertigWaren _fw, int lagid) :
      		LagerBase(ppsInstanzID::Fertigwarenlager),
      		fw(_fw),lagerid(lagid)  
      {
	initLager();
      }
      
      FertigWarenLager(int lagid) : 
      		LagerBase(ppsInstanzID::Fertigwarenlager),
      		fw(FertigWaren()), lagerid(lagid)
      {
       initLager();
      }
      
#else
      FertigWarenLager(const FertigWaren _fw) :
      		LagerBase(ppsInstanzID::None),
      		fw(_fw)  
      {}
      FertigWarenLager() : LagerBase(ppsInstanzID::None),
      		fw(FertigWaren()) {}

      FertigWarenLager(int lagid) : 
      		LagerBase(ppsInstanzID::None),
      		fw(FertigWaren()), lagerid(lagid)
      { }      		
#endif

   FertigWarenLager(const FertigWarenLager &l) :
   		LagerBase(static_cast<const LagerBase&>(l)),
   		fw(l.fw), lagerid(l.lagerid)
   	{}
   		

   ArtikelBase Artikel() const {return fw.Artikel();}
   std::pair<Zeitpunkt_new,int> letzteInventur();
   int Bestand(ManuProC::Datum date);
   int Bestand() { return Bestand(ManuProC::Datum::today()) ;}
   
  void Einlagern(const ProductionContext &ctx) {Buchen(FertigWaren::Rein,ctx);}
  void Auslagern(const ProductionContext &ctx) {Buchen(FertigWaren::Raus,ctx);}
  void WiederEinlagern() {Buchen(FertigWaren::WiederRein,ProductionContext());}
  void Inventur() throw(LagerError);
  const FertigWaren &getFertigWaren() const { return fw; }
  virtual std::vector<class LagerInhalt> LagerInhalt_(const ArtikelBase& artikel) const;
};


#endif
