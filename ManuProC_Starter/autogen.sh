#!/bin/sh
# generated 2004/5/7 15:30:30 CEST by jacek@jaceksdell.(none)
# using glademm V2.0.0b

if test ! -f install-sh ; then touch install-sh ; fi

MAKE=`which gnumake`
if test ! -x "$MAKE" ; then MAKE=`which gmake` ; fi
if test ! -x "$MAKE" ; then MAKE=`which make` ; fi
HAVE_GNU_MAKE=`$MAKE --version|grep -c "Free Software Foundation"`

if test "$HAVE_GNU_MAKE" != "1"; then 
echo Using non GNU Make at $MAKE
else
echo Found GNU Make at $MAKE ... good.
fi

echo This script runs configure and make...
echo You did remember necessary arguments for configure, right?

if test ! -x `which aclocal`  
then echo you need autoconfig and automake to generate the Makefile
fi
if test ! -x `which automake`  
then echo you need automake to generate the Makefile
fi

aclocal
libtoolize --force --copy
tar cvzf backup.tgz configure.in Makefile.am ChangeLog
gettextize
tar xvzf backup.tgz
if test ! -e po/Makevars
then cp po/Makevars.template po/Makevars
fi
if test ! -e po/LINGUAS
then touch po/LINGUAS
fi
autoheader
automake --add-missing --copy --gnu
autoconf
./configure $* && $MAKE
