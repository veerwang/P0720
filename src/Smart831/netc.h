/*
 * =====================================================================================
 *
 *       Filename:  netc.h
 *
 *    Description:  Manage of net client class head file
 *
 *        Version:  1.0
 *        Created:  09/25/2011 08:35:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  _NETC_INC
#define  _NETC_INC

#include	"netobj.h"
/*
 * =====================================================================================
 *        Class:  Netc
 *  Description:  Manage Net client class 
 * =====================================================================================
 */
class Netc : public Netobj
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Netc ();                             /* constructor */
		~Netc ();                            /* destructor */
	protected:
	private:
}; /* -----  end of class Netc  ----- */
#endif   /* ----- #ifndef _NETC_INC  ----- */
