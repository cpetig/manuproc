/*  pps: ManuProC's ProductionPlanningSystem
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


#include<tclistnode.h>

class Lief_Node : public TCListNode
{
 mutable float sumgeliefert;
 
public:
 
 virtual void cumulate(const cH_RowDataBase &rd, int seqnr) const;
 virtual const vector<string> getColEntries(int cols);
 virtual void resetSumValues(gpointer p);
 virtual const string getSumCol(int col);
  
 Lief_Node::Lief_Node(int _seqnr, const cH_RowDataBase &v, int deep);
 float SumGeliefert() const { return sumgeliefert; }

};
