#include "mpc_agent.hh"
#include <FetchIStream.h>
#include <itos.h>
#include <Datum.h>
#include <Transaction.h>
#include <MyMessage.h>

void mpc_agent::on_orderid_search(gboolean *cont,GtkSCContext context)
{
 try
   {  
    std::string squery("select aufid from auftrag where vknr=?");

    if(!orderid->get_text().empty())
      squery=squery+" and aufid like '"+orderid->get_text()+"%'";

    if(!kunde->get_value(KDBOX_NR).empty())
       squery+=std::string(" and kdnr=?");

    Query qu(squery);

    switch(context)
	{  
         case GTK_SEARCH_OPEN:
	 case GTK_SEARCH_REOPEN:
           {
	    qu << VERKNR;
            if(!kunde->get_value(KDBOX_NR).empty())
	      qu << kunde->get_value(KDBOX_NR);
	    // fall through
	   }

	 case GTK_SEARCH_FETCH:
	   // dont need idle loops here. It is rapid enouth from SQLite.
	   {
	    int aufid;
	    FetchIStream fi=qu.Fetch();
 	    while(fi.good())
	      {fi >> aufid;
	       orderid->add_item(itos(aufid),aufid);
	       fi=qu.Fetch();
	      }
	    *cont=false;
	    break;
	   }

	 case GTK_SEARCH_CLOSE:
           {
            break;
           }

	}
   }
  catch (SQLerror &e)
   {  std::cerr << e << '\n';
   }

}


void mpc_agent::artikel_clean()
{
 article_entry->reset();
 width_entry->reset();
 color_entry->reset();
 makeup_entry->reset();
 ean_entry->reset();
 
 article_entry->set_sensitive(true);
 width_entry->set_sensitive(true);
 color_entry->set_sensitive(true);
 makeup_entry->set_sensitive(true); 
 ean_entry->set_sensitive(true);
}

void mpc_agent::clear_order()
{
 orderid->reset();
 orderid->set_sensitive(true);
 label_orderdate->set_text("");
 artikel_clean();
 menge->set_value(0);
 order->clear();
}



void mpc_agent::load_order(int oid)
{
 std::string kdnr;
 ManuProC::Datum datum;

 Query("select kdnr,datum from auftrag where aufid=? and vknr=?")
	<< oid << VERKNR >> kdnr >> datum;
  
 label_orderdate->set_text(std::string("dated ")+datum.c_str());

 if(kunde->get_value(KDBOX_NR)!=kdnr)
   {kunde->set_value(KDBOX_NR,kdnr);
    on_activate_entry(KDBOX_NR);  
   }
 orderid->set_value(itos(oid),oid);
 orderid->set_sensitive(false);
}


int mpc_agent::create_new_order(int kdnr)
{
 ManuProC::Datum now(ManuProC::Datum::today());

 int new_aufid;

 try {
 Query("select coalesce(max(aufid),0)+1 from auftrag where vknr=?") 
	<< VERKNR >> new_aufid;

 Query q("insert into auftrag (aufid,kdnr,vknr,datum) values (?,?,?,?)");
 q << new_aufid << kdnr << VERKNR << now.to_iso();
 }
 catch(SQLerror &e)
 {
  MyMessage msg(e);
  msg.set_transient_for(*this);
  msg.run();
  return 0;
 }
 catch(ManuProC::Datumsfehler &d)
 {
  MyMessage msg(d);
  msg.set_transient_for(*this);
  msg.run();
  return 0;
 } 

 return new_aufid;

}


void mpc_agent::on_ean_entry_search(gboolean *cont,GtkSCContext context)
{  
}

void mpc_agent::on_article_entry_search(gboolean *cont,GtkSCContext context)
{
 try
   {  
    std::string squery("select distinct artnr from artikel");

    squery=squery+" where 1=? and artnr like '"+article_entry->get_text()+"%'";

    Query qu(squery);

    switch(context)
	{  
         case GTK_SEARCH_OPEN:
	 case GTK_SEARCH_REOPEN:
           {
	    qu << 1; // only to trigger a Query at this place;
	    // fall through
	   }

	 case GTK_SEARCH_FETCH:
	   // dont need idle loops here. It is rapid enouth from SQLite.
	   {
	    std::string artikel;
	    FetchIStream fi=qu.Fetch();
 	    while(fi.good())
	      {fi >> artikel;
	       article_entry->add_item(artikel,artikel);
	       fi=qu.Fetch();
	      }
	    *cont=false;
	    break;
	   }

	 case GTK_SEARCH_CLOSE:
           {
            break;
           }

	}
   }
  catch (SQLerror &e)
   {  std::cerr << e << '\n';
   }
  
}



void mpc_agent::on_width_entry_search(gboolean *cont,GtkSCContext context)
{
 try
   {  
    std::string squery("select distinct breite from artikel");

    squery=squery+" where 1=? and artnr = '"+article_entry->get_text()+"'";
    squery=squery+" and breite like '"+width_entry->get_text()+"%'";

    Query qu(squery);

    switch(context)
	{  
         case GTK_SEARCH_OPEN:
	 case GTK_SEARCH_REOPEN:
           {
	    qu << 1; // only to trigger a Query at this place;
	    // fall through
	   }

	 case GTK_SEARCH_FETCH:
	   // dont need idle loops here. It is rapid enouth from SQLite.
	   {
	    std::string artikel;
	    FetchIStream fi=qu.Fetch();
 	    while(fi.good())
	      {fi >> artikel;
	       width_entry->add_item(artikel,artikel);
	       fi=qu.Fetch();
	      }
	    *cont=false;
	    break;
	   }

	 case GTK_SEARCH_CLOSE:
           {
            break;
           }

	}
   }
  catch (SQLerror &e)
   {  std::cerr << e << '\n';
   }
  
}


void mpc_agent::on_color_entry_search(gboolean *cont,GtkSCContext context)
{
 try
   {  
    std::string squery("select distinct farbe from artikel");

    squery=squery+" where 1=? and artnr = '"+article_entry->get_text()+"'";
    squery=squery+" and breite = '"+width_entry->get_text()+"'";
    squery=squery+" and farbe like '"+color_entry->get_text()+"%'";

    Query qu(squery);

    switch(context)
	{  
         case GTK_SEARCH_OPEN:
	 case GTK_SEARCH_REOPEN:
           {
	    qu << 1; // only to trigger a Query at this place;
	    // fall through
	   }

	 case GTK_SEARCH_FETCH:
	   // dont need idle loops here. It is rapid enouth from SQLite.
	   {
	    std::string artikel;
	    FetchIStream fi=qu.Fetch();
 	    while(fi.good())
	      {fi >> artikel;
	       color_entry->add_item(artikel,artikel);
	       fi=qu.Fetch();
	      }
	    *cont=false;
	    break;
	   }

	 case GTK_SEARCH_CLOSE:
           {
            break;
           }

	}
   }
  catch (SQLerror &e)
   {  std::cerr << e << '\n';
   }
  
}


void mpc_agent::on_makeup_entry_search(gboolean *cont,GtkSCContext context)
{
 try
   {  
    std::string squery("select distinct aufmachung from artikel");

    squery=squery+" where 1=? and artnr = '"+article_entry->get_text()+"'";
    squery=squery+" and breite = '"+width_entry->get_text()+"'";
    squery=squery+" and farbe = '"+color_entry->get_text()+"'";
    squery=squery+" and aufmachung like '"+makeup_entry->get_text()+"%'";

    Query qu(squery);

    switch(context)
	{  
         case GTK_SEARCH_OPEN:
	 case GTK_SEARCH_REOPEN:
           {
	    qu << 1; // only to trigger a Query at this place;
	    // fall through
	   }

	 case GTK_SEARCH_FETCH:
	   // dont need idle loops here. It is rapid enouth from SQLite.
	   {
	    std::string artikel;
	    FetchIStream fi=qu.Fetch();
 	    while(fi.good())
	      {fi >> artikel;
	       makeup_entry->add_item(artikel,artikel);
	       fi=qu.Fetch();
	      }
	    *cont=false;
	    break;
	   }

	 case GTK_SEARCH_CLOSE:
           {
            break;
           }

	}
   }
  catch (SQLerror &e)
   {  std::cerr << e << '\n';
   }
  
}
