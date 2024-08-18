PHP_ARG_WITH([lz4],
  [for lz4 support],
  [AS_HELP_STRING([--with-lz4],
    [Include lz4 support (requires lz4 >= 1.9.2)])])

if test "$PHP_LZ4" != "no"; then
  PKG_CHECK_MODULES([LIBLZ4], [liblz4 >= 1.9.2])

  PHP_EVAL_LIBLINE($LIBLZ4_LIBS, LZ4_SHARED_LIBADD)
  PHP_EVAL_INCLINE($LIBLZ4_CFLAGS)

  PHP_SUBST(LZ4_SHARED_LIBADD)

  AC_DEFINE(HAVE_LZ4, 1, [ Have lz4 support ])

  PHP_NEW_EXTENSION(lz4, lz4.c, $ext_shared)
fi
