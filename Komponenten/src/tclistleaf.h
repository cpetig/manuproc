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

// $Id: tclistleaf.h,v 1.8 2001/04/20 07:10:54 christof Exp $

#ifndef KOMPONENTEN_TCLISTLEAF
#define KOMPONENTEN_TCLISTLEAF

#include"tclistrowdata.h"
#include"rowdata.h"
#include"treebase.h"

class TCListLeaf : public TCListRowData
{
protected:
 cH_RowDataBase leafdata;
 bool show;
  
public:

 TCListLeaf(int _seqnr, const cH_RowDataBase &v, int deep);
 void initTCL(TCListRow_API *api, TCListRow_API::iterator davor,
 			const TreeBase &tb,int deep);
 void initTCL(TCListRow_API *api, const TreeBase &tb,int deep);
 
 virtual void cumulate(const cH_RowDataBase &rd, int seqnr) const{};
 const cH_RowDataBase LeafData() const { return leafdata; }
 virtual void refreshSum(const TreeBase &tb) {};
};


#endif
