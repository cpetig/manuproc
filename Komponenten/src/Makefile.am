# $Id: Makefile.am,v 1.65 2006/10/31 16:10:30 christof Exp $
AM_CXXFLAGS=@CXXFLAGS@  -DCOMPILE_KOMPONENTEN \
		@COMMONGTK2_INCLUDES@ @COMMONXX_INCLUDES@

%.cc: %.pgcc ; @ECPG@ -o $*.cc $<

LINKS= EingabeBox.cc EingabeBox.hh datewin.cc datewin.h \
	datewin_glade.cc datewin_glade.hh logwin.h \
	RowDataBase.h TreeRow.h \
	SimpleTreeModel.h SimpleTreeStore.h \
	treebase_data.h TreeViewUtility.h \
	bool_CheckButton.cc \
	int_SpinButton.cc string_Entry.cc \
	SimpleTreeModel.cc SimpleTreeStore.cc \
	GType_cH_EntryValue.cc SimpleTree.cc \
	bool_CheckMenuItem.cc char_Pixmap.cc \
	FlashingPixmap.cc LabelSpin.cc \
	MyWindow.cc MyScale.cc logwin.cc TreeViewUtility.cc \
	bool_properties.cc bool_ImageButton.cc \
	bool_CheckMenuItem.hh char_Pixmap.hh \
	FlashingPixmap.hh LabelSpin.hh MyWindow.hh MyScale.hh \
	bool_properties.hh bool_ImageButton.hh bool_CheckButton.hh \
	int_SpinButton.hh string_Entry.hh GType_cH_EntryValue.h \
	fixp_SpinButton.hh \
	SimpleTree.hh ModelWidgetConnection.h string_Label.cc \
	string_Label.hh Event.cc Association.h Association.cc \
	bvector_item_CheckMenuItem.hh SimpleTreeStore_test.cc \
	CellRendererSimpleTree.h CellRendererSimpleTree.cc \
	TreeModelDebug.cc TreeModelDebug.h SearchComboContent.hh \
	SearchCombo.hh MyMessage.h int_ImageButton.hh int_ImageButton.cc \
	IntStringBox.hh IntStringBox.cc IntStringBox_glade.cc \
	IntStringBox_sql.pgcc IntStringBox_gui.hh IntStringBox_glade.hh \
	IntStringBox_gui.cc IntStringPopup_glade.cc IntStringPopup_glade.hh \
	datewin_popup_glade.hh datewin_popup_glade.cc datewin_popup.hh \
	datewin_popup.cc OrderBox.cc BasicExcel.cpp BasicExcel.hpp

$(LINKS):
	ln -sf ../Basic/src/$@ .

include_HEADERS = datewin.h logwin.h \
	EingabeBox.hh ProzessBox.hh \
	ArtikelBox.hh datewin_glade.hh \
	Association.h TreeModelDebug.h
   
oldheaders=\
	KundenBox.hh KundenBox_glade.hh \
	   WWaehrung.hh WPreis.hh WAuftragStatus.hh \
   Optionmenu_Instanz.hh Artikel_Bestellen.hh \
   Optionmenu_Warengruppe.hh PPixmap.hh \
   Optionmenu_Einheit.hh PreisBox.hh WTelefon.hh \
   IntStringBox.hh PersonenBox.hh \
   LandesBox.hh KundenBox2.hh ZahlungsArtBox.hh

lib_LIBRARIES= libKomponenten.a

libKomponenten_a_SOURCES= \
	$(BUILT_SOURCES_L) \
	datewin.cc \
		logwin.cc EingabeBox.cc \
		datewin_glade.cc \
	IntStringBox.cc IntStringBox_glade.cc \
	bool_CheckButton.cc \
	int_SpinButton.cc string_Entry.cc \
	SimpleTreeModel.cc SimpleTreeStore.cc \
	GType_cH_EntryValue.cc SimpleTree.cc \
	bool_CheckMenuItem.cc char_Pixmap.cc \
	FlashingPixmap.cc LabelSpin.cc \
	MyWindow.cc MyScale.cc logwin.cc TreeViewUtility.cc \
	bool_properties.cc bool_ImageButton.cc \
	IntStringBox_gui.cc IntStringPopup_glade.cc \
	string_Label.cc Event.cc Association.cc \
        CellRendererSimpleTree.cc ArtikelBox.cc \
        KundenBox2.cc int_ImageButton.cc \
        Optionmenu_Instanz.cc Artikel_Bestellen.cc \
        Optionmenu_Einheit.cc WPreis.cc PreisBox.cc \
        Optionmenu_Kundengruppe.cc LandesBox.cc \
        Optionmenu_OberKundengruppe.cc \
        Optionmenu_AuftragLabel.cc Optionmenu_Lager.cc \
        VerfuegbarPixmap.cc \
        WTelefon_glade.cc WTelefon.cc ZahlungsArtBox.cc \
	PersonenBox.cc datewin_popup_glade.cc datewin_popup.cc \
	BasicExcel.cpp

BUILT_SOURCES_L= $(LINKS) \
	IntStringBox_sql.cc ArtikelBox_sql.cc AB_Breitensuche_sql.cc \
	StringBox_sql.cc Optionmenu_Warengruppe_sql.cc ProzessBox_sql.cc \
	WWaehrung_sql.cc WAuftragStatus_sql.cc


lateron2 = KundenBox_sql.cc 

BUILT_SOURCES=datewin.hh logwin.hh $(BUILT_SOURCES_L) 

# alias links
datewin.hh: datewin.h
	ln -sf datewin.h datewin.hh
logwin.hh: logwin.h
	ln -sf logwin.h logwin.hh
#SimpleTree.hh: treebase.h
#	ln -sf treebase.h SimpleTree.hh

install-data-hook:
	cd $(includedir) ; chmod g+w $(include_HEADERS)
	cd $(includedir) ; rm -f artikel_box_win.hh rohartikel_win.hh \
		rohartikel_win_glade.hh
	cd $(includedir) ; ln -s treebase.h SimpleTree.hh

CLEANFILES= *~ $(BUILT_SOURCES) $(LINKS)
