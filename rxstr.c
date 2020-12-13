/* Modified for VM/370 CMS and GCC by Robert O'Hara, July 2010. */
/*
 * $Id: rxstr.c,v 1.9 2008/07/15 07:40:25 bnv Exp $
 * $Log: rxstr.c,v $
 * Revision 1.9  2008/07/15 07:40:25  bnv
 * #include changed from <> to ""
 *
 * Revision 1.8  2006/01/26 10:27:57  bnv
 * Changed RxVar...Old() -> RxVar...Name()
 *
 * Revision 1.7  2003/10/30 13:16:28  bnv
 * Variable name change
 *
 * Revision 1.6  2003/01/30 08:22:37  bnv
 * HASHVALUE added
 *
 * Revision 1.5  2002/06/11 12:37:38  bnv
 * Added: CDECL
 *
 * Revision 1.4  2001/06/25 18:51:48  bnv
 * Header -> Id
 *
 * Revision 1.3  1999/11/26 13:13:47  bnv
 * Added: Windows CE support.
 * Changed: To use the new macros.
 *
 * Revision 1.2  1998/11/26 09:47:11  bnv
 * Changed: var 'match' in verify must be boolean
 *
 * Revision 1.1  1998/07/02 17:34:50  bnv
 * Initial revision
 *
 */

#ifdef __BORLANDC__
# include <dos.h>
#endif

#include <stdlib.h>
#include <string.h>

#include "lerror.h"
#include "lstring.h"

#include "rexx.h"
#include "rxdefs.h"
#include "interpre.h"
#include <cmssys.h>

/* --------------------------------------------------------------- */
/*  ABBREV(information,info[,length])                              */
/* --------------------------------------------------------------- */
/*  INDEX(haystack,needle[,start])                                 */
/* --------------------------------------------------------------- */
/*  FIND(string,phrase[,start])                                    */
/* --------------------------------------------------------------- */
/*  LASTPOS(needle,haystack[,start])                               */
/* --------------------------------------------------------------- */
/*  POS(needle,haystack[,start])                                   */
/* --------------------------------------------------------------- */
/*  WORDPOS(phrase,string[,start])                                 */
/* --------------------------------------------------------------- */
void __CDECL
R_SSoI(const int func) {
    long l;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 3))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    must_exist(2);
    get_oi0(3, l);

    switch (func) {
        case f_abbrev:
            Licpy(ARGR, Labbrev(ARG1, ARG2, l));
            break;

        case f_index:
            Licpy(ARGR, Lindex(ARG1, ARG2, l));
            break;

        case f_find:
            Licpy(ARGR, Lfind(ARG1, ARG2, l));
            break;

        case f_lastpos:
            Licpy(ARGR, Llastpos(ARG1, ARG2, l));
            break;

        case f_pos:
            Licpy(ARGR, Lpos(ARG1, ARG2, l));
            break;

        case f_wordpos:
            Licpy(ARGR, Lwordpos(ARG1, ARG2, l));
            break;

        default:
            (context->lstring_Lerror)(ERR_INTERPRETER_FAILURE, 0);
    } /* switch */
} /* R_SSoI */

/* --------------------------------------------------------------- */
/*  CENTRE(string,length[,pad])                                    */
/*  CENTER(string,length[,pad])                                    */
/* --------------------------------------------------------------- */
/*  JUSTIFY(string,length[,pad])                                   */
/* --------------------------------------------------------------- */
/*  LEFT(string,length[,pad])                                      */
/* --------------------------------------------------------------- */
/*  RIGHT(string,length[,pad])                                     */
/* --------------------------------------------------------------- */
void __CDECL
R_SIoC(const int func) {
    long l;
    char pad;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 3))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);

    must_exist(1);
    get_i0(2, l);
    get_pad(3, pad);

    switch (func) {
        case f_center:
            Lcenter(ARGR, ARG1, l, pad);
            break;

        case f_justify:
            Ljustify(ARGR, ARG1, l, pad);
            break;

        case f_left:
            Lleft(ARGR, ARG1, l, pad);
            break;

        case f_right:
            Lright(ARGR, ARG1, l, pad);
            break;

        default:
            (context->lstring_Lerror)(ERR_INTERPRETER_FAILURE, 0);
    } /* of switch */
} /* R_SIoC */

/* --------------------------------------------------------------- */
/*  B2X(string)                                                    */
/* --------------------------------------------------------------- */
/*  C2X(string)                                                    */
/* --------------------------------------------------------------- */
/*  GETENV(string)                                                 */
/* --------------------------------------------------------------- */
/*  LENGTH(string)                                                 */
/* --------------------------------------------------------------- */
/*  WORDS(string)                                                  */
/* --------------------------------------------------------------- */
/*  REVERSE(string)                                                */
/* --------------------------------------------------------------- */
/*  SYMBOL(name)                                                   */
/* --------------------------------------------------------------- */
/*  X2B(string)                                                    */
/* --------------------------------------------------------------- */
/*  X2C(string)                                                    */
/* --------------------------------------------------------------- */
/*  IMPORT( filename )                                             */
/*      loads a shared library or a rexx library                   */
/* --------------------------------------------------------------- */
/*  LOAD( filename )                                               */
/*      load a rexx file so it can be used as a library            */
/*      returns a return code from loadfile                        */
/*        "-1" when file is already loaded                         */
/*         "0" on success                                          */
/*         "1" on error opening the file                           */
/* ------------------------------------------------------ -------- */
/* -- WIN32_WCE -------------------------------------------------- */
/*  A2U(string)                                                    */
/* --------------------------------------------------------------- */
/*  U2A(string)                                                    */
/* --------------------------------------------------------------- */
void __CDECL
R_S(const int func) {
    Lstr str;
    int found;
    Context *context = (Context *) CMSGetPG();

    if (ARGN != 1) (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    L2STR(ARG1);

    switch (func) {
        case f_b2x:
            Lb2x(ARGR, ARG1);
            break;

        case f_c2x:
            Lc2x(ARGR, ARG1);
            break;

#if !defined(WCE) && !defined(__CMS__)
            case f_getenv: {
                char *env;
                LASCIIZ(*ARG1);
                env = getenv(LSTR(*ARG1));
                if (env)
                    Lscpy(ARGR, env);
                else LZEROSTR(*ARGR);
            }
                break;
#endif

        case f_length:
            Licpy(ARGR, LLEN(*ARG1));
            break;

        case f_words:
            Licpy(ARGR, Lwords(ARG1));
            break;

        case f_reverse:
            Lstrcpy(ARGR, ARG1);
            Lreverse(ARGR);
            break;

        case f_soundex:
            Lsoundex(ARGR, ARG1);
            break;

        case f_symbol:
            if (Ldatatype(ARG1, 'S') == 0) {
                Lscpy(ARGR, "BAD");
                return;
            }
            LINITSTR(str);
            Lfx(&str, LLEN(*ARG1));
            Lstrcpy(&str, ARG1);
            Lupper(&str);
            LASCIIZ(str);
            RxVarFindName((context->rexx_proc)[(context->rexx_rx_proc)].scope,
                          &str, &found);
            LFREESTR(str);
            if (found)
                Lscpy(ARGR, "VAR");
            else
                Lscpy(ARGR, "LIT");
            break;

        case f_x2b:
            Lx2b(ARGR, ARG1);
            break;

        case f_x2c:
            Lx2c(ARGR, ARG1);
            break;

#ifdef WCE
            case f_a2u:
             {
              size_t len = LLEN(*ARG1);
              Lfx(ARGR,2*len+2);
              LASCIIZ(*ARG1);
              mbstowcs((TCHAR*)(LSTR(*ARGR)), LSTR(*ARG1), len+1);
              LLEN(*ARGR) = 2*len;
              LTYPE(*ARGR) = LSTRING_TY;
             }
             break;

            case f_u2a:
             {
              size_t len = LLEN(*ARG1)/2;
              Lfx(ARGR,len);
              wcstombs(LSTR(*ARGR), (TCHAR*)(LSTR(*ARG1)), len);
              LLEN(*ARGR) = len;
              LTYPE(*ARGR) = LSTRING_TY;
             }
             break;
#endif
        case f_hashvalue:
            Licpy(ARGR, Lhashvalue(ARG1));
            break;

        case f_load:
        case f_import:
            Licpy(ARGR, RxLoadLibrary(ARG1));
            break;

        default:
            (context->lstring_Lerror)(ERR_INTERPRETER_FAILURE, 0);
    } /* switch */
} /* R_S */
/* --------------------------------------------------------------- */
/*  DELSTR(string,n[,length])                                      */
/* --------------------------------------------------------------- */
/*  DELWORD(string,n[,length])                                     */
/* --------------------------------------------------------------- */
/*  SUBWORD(string,n[,length])                                     */
/* --------------------------------------------------------------- */
void __CDECL
R_SIoI(const int func) {
    long n, l;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 3))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    get_i(2, n);
    get_oiv(3, l, -1);

    switch (func) {
        case f_delstr:
            Ldelstr(ARGR, ARG1, n, l);
            break;

        case f_delword:
            Ldelword(ARGR, ARG1, n, l);
            break;

        case f_subword:
            Lsubword(ARGR, ARG1, n, l);
            break;

        default:
            (context->lstring_Lerror)(ERR_INTERPRETER_FAILURE, 0);
    } /* switch */
} /* R_SIoI */

/* --------------------------------------------------------------- */
/*  INSERT(new,target[,[n][,[length][,pad]]])                      */
/* --------------------------------------------------------------- */
/*  OVERLAY(new,target[,[n][,[length][,pad]]])                     */
/* --------------------------------------------------------------- */
void __CDECL
R_SSoIoIoC(const int func) {
    long n, l;
    char pad;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 5))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    must_exist(2);
    get_oi0(3, n);
    get_oiv(4, l, -1);
    get_pad(5, pad);

    switch (func) {
        case f_insert:
            Linsert(ARGR, ARG1, ARG2, n, l, pad);
            break;

        case f_overlay:
            Loverlay(ARGR, ARG1, ARG2, n, l, pad);
            break;

        default:
            (context->lstring_Lerror)(ERR_INTERPRETER_FAILURE, 0);
    } /* switch */
} /* R_SSoIoIoC */

/* --------------------------------------------------------------- */
/*  CHANGESTR(searchstr,string,replacestr)                         */
/* --------------------------------------------------------------- */
void __CDECL
R_changestr() {
    Context *context = (Context *) CMSGetPG();
    if (ARGN != 3)
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    must_exist(2);
    must_exist(3);
    Lchangestr(ARGR, ARG1, ARG2, ARG3);
} /* R_changestr */

/* --------------------------------------------------------------- */
/*  COMPARE(string1,string2[,pad])                                 */
/* --------------------------------------------------------------- */
void __CDECL
R_compare() {
    char pad;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 3))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    must_exist(2);
    get_pad(3, pad);

    Licpy(ARGR, Lcompare(ARG1, ARG2, pad));
} /* R_compare */

/* --------------------------------------------------------------- */
/*  COPIES(string,n)                                               */
/* --------------------------------------------------------------- */
void __CDECL
R_copies() {
    long n;
    Context *context = (Context *) CMSGetPG();

    if (ARGN != 2)
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    must_exist(2);
    n = Lrdint(ARG2);
    if (n < 0) (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);

    Lcopies(ARGR, ARG1, n);
} /* R_copies */

/* --------------------------------------------------------------- */
/*  SUBSTR(string,n[,[length][,pad]])                              */
/* --------------------------------------------------------------- */
void __CDECL
R_substr() {
    long n, l;
    char pad;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 4))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);
    must_exist(1);
    get_i(2, n);
    get_oiv(3, l, -1);
    get_pad(4, pad);

    Lsubstr(ARGR, ARG1, n, l, pad);
} /* R_substr */

/* --------------------------------------------------------------- */
/*  STRIP(string[,[<"L"|"T"|"B">][,char]])                         */
/* --------------------------------------------------------------- */
void __CDECL
R_strip() {
    char action = 'B';
    char pad;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(1, ARGN, 3))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);

    must_exist(1);
    if (exist(2)) {
        L2STR(ARG2);
        action = (context->lstring_l2u)[(byte) LSTR(*ARG2)[0]];
    }
    get_pad(3, pad);
    Lstrip(ARGR, ARG1, action, pad);
} /* R_strip */

/* --------------------------------------------------------------- */
/*  TRANSLATE(string(,(tableo)(,(tablei)(,pad))))                  */
/* --------------------------------------------------------------- */
void __CDECL
R_translate() {
    char pad;
    PLstr tableo, tablei;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(1, ARGN, 4))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);

    must_exist(1);

    if (ARGN == 1) {
        Lstrcpy(ARGR, ARG1);
        Lupper(ARGR);
        return;
    }

    if (exist(2))
        tableo = ARG2;
    else
        tableo = NULL;

    if (exist(3))
        tablei = ARG3;
    else
        tablei = NULL;

    get_pad(4, pad);

    Ltranslate(ARGR, ARG1, tableo, tablei, pad);
} /* R_translate */

/* --------------------------------------------------------------- */
/*  VERIFY(string,reference[,[option][,start]])                    */
/* --------------------------------------------------------------- */
void __CDECL
R_verify() {
    bool match = FALSE;
    long start;
    Context *context = (Context *) CMSGetPG();

    if (!IN_RANGE(2, ARGN, 4))
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);

    must_exist(1);
    must_exist(2);
    if (exist(3)) {
        L2STR(ARG3);
        match = ((context->lstring_l2u)[(byte) LSTR(*ARG3)[0]] == 'M');
    }
    get_oi(4, start);
    Licpy(ARGR, Lverify(ARG1, ARG2, match, start));
} /* R_verify */

/* --------------------------------------------------------------- */
/*  COUNTSTR(target,string)                                        */
/* --------------------------------------------------------------- */
/*  PUTENV(var,value)                                              */
/* --------------------------------------------------------------- */
void __CDECL
R_SS(int type) {
    Context *context = (Context *) CMSGetPG();
    if (ARGN != 2)
        (context->lstring_Lerror)(ERR_INCORRECT_CALL, 0);

    must_exist(1);
    must_exist(2);
#ifndef WCE
    if (type == f_countstr)
#endif
        Licpy(ARGR, Lcountstr(ARG1, ARG2));
#ifndef WCE
    else {
        LASCIIZ(*ARG1);
        LASCIIZ(*ARG2);
# ifdef HAVE_SETENV
        Licpy(ARGR,setenv(LSTR(*ARG1),LSTR(*ARG2),TRUE));
# else
        {
            Lstr str;
            LINITSTR(str);
            Lstrcpy(&str, ARG1);
            Lcat(&str, "=");
            Lstrcpy(&str, ARG2);
            LASCIIZ(str);
#ifndef __CMS__
            Licpy(ARGR, putenv(LSTR(str)));
#endif
            LFREESTR(str);
        }
# endif
    }
#endif
} /* R_SS */
