/* $Id: DynEnums_default.h,v 1.10 2004/03/29 06:37:50 christof Exp $ */
/*  libcommonc++: ManuProC's main OO library
 *  Copyright (C) 2002 Adolf Petig GmbH & Co. KG
 *  written by Jacek Jakubowski, Christof Petig, Malte Thoma
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

// $Id: DynEnums_default.h,v 1.10 2004/03/29 06:37:50 christof Exp $

#ifndef MANUPROC_DYNAMICENUMS_H
#define MANUPROC_DYNAMICENUMS_H

namespace ManuProC {
 namespace DynamicEnums {
  namespace ArtikelTyp {
   enum enum_t {
    None=-1
   };
  }

  namespace Einheiten {
   enum enum_t {
    None=-1, St_=0
   };
  }

  namespace Prozesse {
   enum enum_t {
    None=0, Verarbeitung=1
   };
  }

  namespace Waehrung {
   enum enum_t {
    None=-1, EUR=1
   };
  }

  namespace Instanzen {
   enum enum_t {
    None=-1,Kundenauftraege=1
   };
  }
  
  namespace Kundengruppen {
   enum enum_t {
    None=-1
   };
  }
  
  namespace ArtikelTyp_Attributes {
   enum enum_t {
   };
  }

 }
}
#endif // MANUPROC_DYNAMICENUMS_H
