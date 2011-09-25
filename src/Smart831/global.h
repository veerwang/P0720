/*
 * =====================================================================================
 *
 *       Filename:  global.h
 *
 *    Description:  Manage all variables of project
 *
 *        Version:  1.0
 *        Created:  09/25/2011 08:51:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */
#ifndef  _GLOBAL_INC
#define  _GLOBAL_INC

#include	"main.h"

/*
 * =====================================================================================
 *        Class:  Global
 *  Description:  Manage all variables used by project 
 * =====================================================================================
 */
class Global
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Global ();                             /* constructor */
		~Global ();                            /* destructor */

		void init_default_value();
		BOOL save_value();
		BOOL load_value();
	protected:

	private:

}; /* -----  end of class Global  ----- */
#endif   /* ----- #ifndef _GLOBAL_INC  ----- */
