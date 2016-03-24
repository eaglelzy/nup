#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(unp, 1.0, eagle.lzy@gmail.com)
AC_CONFIG_SRCDIR([config.h])
#AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h netinet/in.h stddef.h stdlib.h string.h strings.h sys/ioctl.h sys/param.h sys/socket.h sys/time.h syslog.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT64_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UID_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([alarm bzero dup2 gethostbyname gethostname gettimeofday select socket strchr strdup strerror uname])
AC_PROG_RANLIB

# AC_CONFIG_FILES([Makefile
#                  app/08/Makefile
#                  app/11/Makefile
#                  libs/Makefile])


AC_OUTPUT(Makefile
                 app/05/Makefile
                 app/06/Makefile
                 app/07/Makefile
                 app/08/Makefile
                 app/11/Makefile
                 libs/Makefile)
