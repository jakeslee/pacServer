#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(PAC Server, 1.0.0, jakeslee66@gmail.com)
AC_CONFIG_SRCDIR([src/socklib.h])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([netdb.h netinet/in.h stdlib.h strings.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_WAIT3
AC_CHECK_FUNCS([bzero gethostbyname gethostname socket])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
