/*  Gtk--addons: a collection of gtk-- addons
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Christof Petig
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

// $Id: TeX.cc,v 1.15 2005/12/21 07:27:49 christof Exp $

#include <config.h>
#include <TeX.h>
#include <cassert>

std::ostream &TeX::Header(std::ostream &os, HeaderFlags fl)
{  // adjust default values
   if (fl.pagestyle=="empty") fl.footer=false;
   
   if (!fl.leftfoot.empty() || !fl.rightfoot.empty() 
       || !fl.leftheader.empty() || !fl.centerheader.empty() || !fl.rightheader.empty())
      fl.pagestyle="fancy";
   
   if (fl.pagestyle=="fancy")
   {  fl.footer=!fl.leftfoot.empty() || !fl.rightfoot.empty();
      fl.header=!fl.leftheader.empty() || !fl.centerheader.empty() || !fl.rightheader.empty();
   }

   // now output it
   os << "% created using $Id: TeX.cc,v 1.15 2005/12/21 07:27:49 christof Exp $\n";
   os << "\\documentclass["<< fl.ptsize << "pt";
   if (fl.a4) os << ",a4paper";
   if (fl.twocolumn) os << ",twocolumn";
   os << "]{article}\n";
   
   if (fl.utf8) 
#ifdef HAS_UTF8X
     os << "\\usepackage[utf8x]{inputenc}\n";
#else
     os << "\\usepackage{ucs}\n""\\usepackage[utf8]{inputenc}\n";
#endif
   else if (fl.latin1) os << "\\usepackage[latin1]{inputenc}\n";
   os << "\\usepackage{";
   if (fl.latin1 || fl.utf8) os << "t1enc,";
   if (fl.german) os << "german,";
   if (fl.longtable) os << "longtable,";
   if (fl.pagestyle=="fancy") os << "fancyheadings,";
   os << "vmargin}\n";
   if (fl.helvetica) 
#ifdef HAS_HELVETIC   
     os << "\\usepackage{helvetic}\n";
#else
     os << "\\renewcommand{\\sfdefault}{phv}\n";
#endif
   
   if (fl.packages.size()) os << "\\usepackage{" << fl.packages << "}\n";
   
   if (fl.helvetica) os << "\\renewcommand{\\rmdefault}{phv}\n";
   
   if (fl.landscape) os << "\\setpapersize[landscape]{A4}\n";

   if (!fl.headersize && fl.header) fl.headersize=fl.ptsize;
   
   os << "\\setmarginsrb{"<<fl.leftmargin<<"in}{"<<fl.topmargin<<"in}{"
   	<<fl.rightmargin<<"in}{"<<fl.bottommargin<<"in}{"
   	<<(fl.headersize)<<"pt}{"<<(fl.header?fl.ptsize:0)<<"pt}{"
   	<<(fl.footer?fl.ptsize:0)<<"pt}{"<<(fl.footer?fl.ptsize:0)<<"pt}\n";
   
   if (fl.pagestyle.size())
   {  os << "\\pagestyle{" << fl.pagestyle << "}\n";
   }
   if (fl.pagestyle=="fancy")
   {  os << "\\lfoot{" << fl.leftfoot << "}\\rfoot{" << fl.rightfoot << "}\n";
      os << "\\lhead{" << fl.leftheader << "}\\rhead{" << fl.rightheader << "}\n";
      os << "\\chead{" << fl.centerheader << "}\n";
   }
   
   if (fl.dense) os << "\\parindent0pt\n"
   			"\\parskip0pt\n";
   if (fl.preamble.size()) os << fl.preamble;
   if (fl.preamble_cb) (*fl.preamble_cb)(os,fl.user_data);
   os << "\\begin{document}\n";
   return os;
}

std::ostream &TeX::Footer(std::ostream &os)
{  return os << "\\end{document}\n";
}

bool TeX::TeX_uses_UTF8=true;

// this is a duplicate of c++/Aux/Ausgabe_neu.h
std::string TeX::string2TeX(const std::string &s, const StringFlags &fl) throw()
{  unsigned int i;
   bool in_line=false;
   std::string ret="";

   for (i = 0; i<s.size() ; i++)
   {  int value=(unsigned char)(s[i]);
      // UTF-8 wandeln
      if (TeX_uses_UTF8 && (value&0xf0)==0xe0 && i+2<s.size() && (s[i+1]&0xc0)==0x80 && (s[i+2]&0xc0)==0x80)
      {  ++i; 
         value=((value&0xf)<<12)|((s[i]&0x3f)<<6)|(s[i+1]&0x3f);
         ++i;
      }
      else if (TeX_uses_UTF8 && (value&0xe0)==0xc0 && i+1<s.size() && (s[i+1]&0xc0)==0x80)
      {  ++i; value=((value&0x1f)<<6)|(s[i]&0x3f);
      }
      switch (value)
      {	 case '&':
	 case '%':
	 case '{':
	 case '}':
	 case '[':
	 case ']':
	 case '#':
	 case '$':
	 case '_': in_line=true;
	    ret+='\\'; ret+=s[i];
	    break;
	 case '*':
	 case '<':
	 case '>':
	    in_line=true;
	    ret+=std::string("$")+s[i]+'$';
	    break;
	 case '"': in_line=true;
	    ret+="\\dq{}";
	    break;
	 case 160: in_line=true;
	    ret+=' ';
	    break;
	 case 0xb5: in_line=true;
	    ret+="$\\mu$";
	    break;
	 case 0xb2: in_line=true;
	    ret+="$^2$";
	    break;
	 case 0xb3: in_line=true;
	    ret+="$^3$";
	    break;
	 case '|':
	    if (fl.bar_means_newline)
	    {  if ((fl.at_least_one_non_space) && !in_line) ret+='~';
	       ret+="\\\\\n";
	       in_line=false;
	    }
	    else { ret+= std::string("$")+s[i]+"$"; in_line=true; }
	    break;
	 case ' ':
	    if (fl.convert_space_to_tilde)
	    {  ret+='~'; in_line=true; }
	    else { ret+= s[i]; in_line=true; }
	    break;
	 default:
	    if (value<0x80) // || value==(unsigned char)(s[i]))
	       ret+= s[i];
            else if (TeX_uses_UTF8) // UTF-8 2 byte
            {  if (value<0x800)
               { ret+=char(0xc0|((value>>6)&0x1f));
                 ret+=char(0x80|(value&0x3f));
               }
               else
               { assert(value<0x10000); // BMP ;-)
                 ret+=char(0xe0|((value>>12)&0xf));
                 ret+=char(0x80|((value>>6)&0x3f));
                 ret+=char(0x80|(value&0x3f));
               }
            }
            else ret+=char(value);
	    in_line=true;
	    break;
      }
   }
   if (!in_line && (fl.at_least_one_non_space)) ret+='~';
   return ret;
}

std::string TeX::scale(const std::string& is, unsigned int  maxlength, 
                       const std::string& scale, const bool use_string2TeX)
{
  std::string s;
  if(use_string2TeX)  s = TeX::string2TeX(is);
  else                s = is ;

  if (is.size() > maxlength) 
      return "\\resizebox*{"+scale+"}{1.5ex}{"+s+"}" ;
  return s;
}
