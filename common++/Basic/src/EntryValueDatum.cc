/* $Id: EntryValueDatum.cc,v 1.3 2002/01/22 09:15:55 christof Exp $ */
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Christof Petig
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

#include <Aux/EntryValueDatum.h>
#include <typeinfo> // for bad_cast
#include <Aux/itos.h>

bool EntryValueDatum::operator==(const EntryValueBase &v) const
{  try
   {  const EntryValueDatum &b=dynamic_cast<const EntryValueDatum &>(v);
      return datum==b.datum;
   } catch (std::bad_cast &e)
   {  return false;
   }
}

bool EntryValueDatum::operator<(const EntryValueBase &v) const
{  try
   {  const EntryValueDatum &b=dynamic_cast<const EntryValueDatum &>(v);
      return datum<b.datum;
   } catch (std::bad_cast &e)
   {  return false;
   }
}

///////////////////////////////////////////////////////////////////////

bool EntryValueKalenderwoche::operator==(const EntryValueBase &v) const
{  try
   {  const EntryValueKalenderwoche &b=dynamic_cast<const EntryValueKalenderwoche &>(v);
      return datum==b.datum;
   } catch (std::bad_cast &e)
   {  return false;
   }
}

bool EntryValueKalenderwoche::operator<(const EntryValueBase &v) const
{  try
   {  const EntryValueKalenderwoche &b=dynamic_cast<const EntryValueKalenderwoche &>(v);
      return datum<b.datum;
   } catch (std::bad_cast &e)
   {  return false;
   }
}

const std::string EntryValueKalenderwoche::getStrVal() const
{
  int lieferwoche = datum.Woche();
  int lieferjahr = datum.Jahr();
  std::string lj=itos (lieferjahr).substr(2);
  return itos(lieferwoche)+"'"+lj;
}



