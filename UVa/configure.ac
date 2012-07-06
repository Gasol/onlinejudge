AC_PREREQ([2.69])
AC_INIT([uva_oj], [0.1], [gasol.wu@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/a100.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AM_PROG_CC_C_O
AM_PROG_AR

# Checks for libraries.
PKG_CHECK_MODULES([CHECK], [check >= 0.9.4])
AC_CHECK_LIB([m], [pow])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

LT_INIT
AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])
AC_OUTPUT
