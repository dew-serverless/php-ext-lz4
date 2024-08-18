dnl config.m4 for extension lz4

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([lz4],
dnl   [for lz4 support],
dnl   [AS_HELP_STRING([--with-lz4],
dnl     [Include lz4 support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([lz4],
  [whether to enable lz4 support],
  [AS_HELP_STRING([--enable-lz4],
    [Enable lz4 support])],
  [no])

if test "$PHP_LZ4" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, LZ4_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-lz4 -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/lz4.h"  # you most likely want to change this
  dnl if test -r $PHP_LZ4/$SEARCH_FOR; then # path given as parameter
  dnl   LZ4_DIR=$PHP_LZ4
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for lz4 files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       LZ4_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$LZ4_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the lz4 distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-lz4 -> add include path
  dnl PHP_ADD_INCLUDE($LZ4_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-lz4 -> check for lib and symbol presence
  dnl LIBNAME=LZ4 # you may want to change this
  dnl LIBSYMBOL=LZ4 # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_LZ4_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your lz4 library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LZ4_DIR/$PHP_LIBDIR, LZ4_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_LZ4_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your lz4 library.])
  dnl ],[
  dnl   -L$LZ4_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(LZ4_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_LZ4, 1, [ Have lz4 support ])

  PHP_NEW_EXTENSION(lz4, lz4.c, $ext_shared)
fi
