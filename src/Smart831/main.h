/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  Project common head file
 *
 *        Version:  1.0
 *        Created:  2011年08月31日 20时25分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  MAIN_INC
#define  MAIN_INC

#define VERSION "1.00"
/*-----------------------------------------------------------------------------
 * 	System standard head files 
 *-----------------------------------------------------------------------------*/
#include	<cstdlib>
#include	<cstdio>
/*-----------------------------------------------------------------------------
 *      System Data re-define 
 *-----------------------------------------------------------------------------*/
typedef unsigned char  		UCHAR;
typedef char                    CHAR;
typedef unsigned short          UINT16;
typedef short                   INT16;
typedef unsigned int            UINT32;
typedef int                     INT32;
typedef double                  DOUBLE;
typedef long long               INT64;
typedef unsigned long long      UINT64;
typedef bool                    BOOL;

/*-----------------------------------------------------------------------------
 *	Program Data define   
 *-----------------------------------------------------------------------------*/
typedef unsigned int		COLORT;

#ifdef _MAIN_FILE
#define EXTF
#else
#define EXTF extern
#endif

#endif   /* ----- #ifndef MAIN_INC  ----- */
