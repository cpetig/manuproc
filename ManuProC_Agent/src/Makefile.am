# generated 2004/3/12 22:15:24 CET by jacek@jaceksdell.(none)
# using glademm V2.0.0b
#
# newer (non customized) versions of this file go to Makefile.am_new
bin_PROGRAMS = mpc_agent


if WINDOWS
#PORT_FILES=mpc_agent.rc
#LINK_OPTIONS=-mwindows -Wl,--enable-runtime-pseudo-reloc
LINK_OPTIONS= -Wl,--enable-runtime-pseudo-reloc
AM_CXXFLAGS = @KOMPONENTEN2_INCLUDES@ -Wall -g -O0 -mms-bitfields
#LINK_OBJS=mpc_agent.o
#WIN_INCLUDES=-I/usr/local/mingw/mingw32/include -I/usr/local/mingw/local/include/gdk
#mpc_agent.o: i586-mingw32msvc-windres mpc_agent.cc

else
PORT_FILES=
LINK_OPTIONS=
LINK_OBJS=   
WIN_INCLUDES=
AM_CXXFLAGS = @KOMPONENTEN2_INCLUDES@
endif


mpc_agent_SOURCES = \
	mpc_agent_glade.cc \
	mpc_agent.cc \
	mpc_internal.cc \
	kunden_selector.cc \
	kunden_selector_glade.cc \
	yes_no_dialog.cc yes_no_dialog_glade.cc \
	mpc_export.cc mpc_export_glade.cc

noinst_HEADERS = \
	mpc_agent_glade.hh \
	mpc_agent.hh \
	kunden_selector_glade.hh \
	kunden_selector.hh \
	yes_no_dialog.hh yes_no_dialog_glade.hh \
	mpc_export.hh mpc_export_glade.hh


AM_CPPFLAGS = @KOMPONENTEN2_INCLUDES@ $(WIN_INCLUDES) -I..
AM_LDFLAGS = @KOMPONENTEN2_LDFLAGS@ $(LINK_OPTIONS)

mpc_agent_LDADD = $(LINK_OBJS) @LIBS@ @KOMPONENTEN2_LIBS@ \
	-latkmm-1.6 -lpangomm-1.4 -lgdkmm-2.4 -lglibmm-2.4 -lsqlite3

