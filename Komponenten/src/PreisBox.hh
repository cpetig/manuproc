// $Id: PreisBox.hh,v 1.6 2004/11/16 14:09:02 christof Exp $
/*  libKomponenten: GUI components for ManuProC's libcommon++
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Jacek Jakubowski
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

// generated 2000/8/28 14:42:53 CEST by christof@puck.petig.de
// using glademm V0.5.9a
//
// newer (non customized) versions of this file go to PreisBox.hh_glade

// you might replace
//    class Foo : public Foo_glade { ... };
// by
//    typedef Foo_glade Foo;
// if you didn't make any modifications to the widget

#ifndef _PREISBOXX_HH
#  define _PREISBOXX_HH

#include <Kunde/PreisListe.h>
#include <IntStringBox.hh>
#include <BaseObjects/ManuProcEntity.h>

class PreisBox : public IntStringBox
{	

public:
	PreisBox(ManuProcEntity<>::ID __none_id=ManuProcEntity<>::none_id);
	void set_value(int i) ;
	
};
#endif
