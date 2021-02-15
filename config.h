/* Modified for VM/370 CMS and GCC by Robert O'Hara, July 2010. */

/* The one version to rule them all! */
#define CMS_VERSION "0.9.11"
/*
#define CMS_VERSION "0.9.8"
#define CMS_VERSION "F0020"
#define __DEBUG__
*/

#include "rxmvs.h"

/* inc/config.h.  Generated from config.h.in by configure.  */

/* Align bytecode to DWORD */
#define ALIGN 1

/* Support of GREEK character set */
#undef GREEK

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Define to 1 if you have the `dup2' function. */
#undef HAVE_DUP2

/* Define to 1 if you have the <fcntl.h> header file. */
#undef HAVE_FCNTL_H

/* Define to 1 if you have the `getcwd' function. */
#undef HAVE_GETCWD

/* Define to 1 if you have the `gettimeofday' function. */
#undef HAVE_GETTIMEOFDAY

/* Define to 1 if you have the <history.h> header file. */
#undef HAVE_HISTORY_H

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the `dl' library (-ldl). */
#undef HAVE_LIBDL

/* Define to 1 if you have the `m' library (-lm). */
#undef HAVE_LIBM

/* Define to 1 if you have the `nsl' library (-lnsl). */
#undef HAVE_LIBNSL

/* Define if you have a readline compatible library */
#undef HAVE_LIBREADLINE

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if your system has a GNU libc compatible `malloc' function, andto 0 otherwise. */
#define HAVE_MALLOC 1

/* Define to 1 if you have the <malloc.h> header file. */
#undef HAVE_MALLOC_H

/* Define to 1 if you have the <memory.h> header file. */
#undef HAVE_MEMORY_H

/* Define to 1 if you have the `pow' function. */
#define HAVE_POW 1

/* Define to 1 if you have the `putenv' function. */
#undef HAVE_PUTENV

/* Define to 1 if you have the <readline.h> header file. */
#undef HAVE_READLINE_H

/* Define if your readline library has \`add_history' */
#undef HAVE_READLINE_HISTORY

/* Define to 1 if you have the <readline/history.h> header file. */
#undef HAVE_READLINE_HISTORY_H

/* Define to 1 if you have the <readline/readline.h> header file. */
#undef HAVE_READLINE_READLINE_H

/* Define to 1 if you have the `setenv' function. */
#undef HAVE_SETENV

/* Define to 1 if you have the `sqrt' function. */
#define HAVE_SQRT 1

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/timeb.h> header file. */
#undef HAVE_SYS_TIMEB_H

/* Define to 1 if you have the <sys/time.h> header file. */
#undef HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the <values.h> header file. */
#undef HAVE_VALUES_H

/* Define to the sub-directory in which libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Old MySQL version */
#undef OLD_MYSQL

/* Name of package */
#define PACKAGE "CMS-bREXX"

/* Define to the address where bug reports for this package should be sent. */
// #define PACKAGE_BUGREPORT "Vasilis.Vlachoudis@cern.ch"
#define PACKAGE_BUGREPORT "rpohara@msn.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "VM/370 bREXX Interpreter"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "CMS bREXX "CMS_VERSION

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "CMS-bREXX"

/* Define to the version of this package. */
#define PACKAGE_VERSION "CMS "CMS_VERSION

/* Remove the trailing CR from system commands */
#define RMLAST 1

/* mySQL static support */
#undef RXMYSQLSTATIC

/* RxCONIO support */
#undef RXCONIO

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Version number of package */
#define VERSION "CMS "CMS_VERSION

/* Enable debuging information */
/* #undef __DEBUG__ */

/* Enable profiling information */
/* #undef __PROFILE__ */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#undef inline

/* Define to rpl_malloc if the replacement function should be used. */
/* #undef malloc */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */
