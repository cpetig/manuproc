/*  Gtk--addons: a collection of gtk-- addons
 *  Copyright (C) 2001-2003 Adolf Petig GmbH & Co. KG, written by Christof Petig
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

// $Id: SigC2SlotEmu.h,v 1.1 2004/04/29 16:44:50 christof Exp $

#include <gtkmmconfig.h>

#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
// don't ask me why this does not work ...
//#  include <sigc++/compatibility.h>
namespace SigC
{  template <class T> 
    Slot0<void> slot(T &t, void (T::*p)()) { return sigc::mem_fun(t,p); }
   template <class T,class A> 
    Slot1<void,A> slot(T &t, void (T::*p)(A a)) 
    	{ return sigc::mem_fun(t,p); }
}
#endif
