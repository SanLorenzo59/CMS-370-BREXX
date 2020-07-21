/* Modified for VM/370 CMS and GCC by Robert O'Hara, July 2010. */
/*
 * $Id: charout.c,v 1.5 2008/07/15 07:40:54 bnv Exp $
 * $Log: charout.c,v $
 * Revision 1.5  2008/07/15 07:40:54  bnv
 * #include changed from <> to ""
 *
 * Revision 1.4  2002/06/11 12:37:15  bnv
 * Added: CDECL
 *
 * Revision 1.3  2001/06/25 18:49:48  bnv
 * Header changed to Id
 *
 * Revision 1.2  1999/11/26 09:53:28  bnv
 * Changed: To use the new macros.
 *
 * Revision 1.1  1998/07/02 17:17:00  bnv
 * Initial revision
 *
 */

#include "lstring.h"

/* ---------------- Lcharout ------------------- */
void __CDECL
Lcharout( FILEP f, const PLstr line, const long start )
{
  int l;
  if (start>=0) {
    l = FSEEK(f,start,SEEK_SET);
    if (l) Lerror(ERR_NOT_RANDOM_ACCESS,0);
  }

 Lwrite(f,line,FALSE);
} /* Lcharout */
