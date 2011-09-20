/*
 * =====================================================================================
 *
 *       Filename:  ShellCommand.h
 *
 *    Description:  Analzye Shell Commmand from Shell
 *
 *        Version:  1.0
 *        Created:  2011年08月31日 20时38分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  _SHELLCOMMAND_INC
#define  _SHELLCOMMAND_INC
#include	"main.h"

/*
 * =====================================================================================
 *        Class:  Shellcommand
 *  Description:  Analyze the Shell command class 
 * =====================================================================================
 */
class ShellCommand
{
	public:
	typedef enum {
		INVALID    = 	0, 
		NORMAL     = 	1,
		TEST       = 	99,
	} SHELLCOMMAND;

	/* ====================  LIFECYCLE     ======================================= */
	ShellCommand (const CHAR* version);          /* constructor */
	~ShellCommand ();                            /* destructor  */
	/* ====================  ACCESSORS     ======================================= */
	public:
	ShellCommand::SHELLCOMMAND Analyze ( INT32 argc, CHAR* argv[] );

	private:
	void Help_Doc ();
	/* ====================  MUTATORS      ======================================= */

	/* ====================  OPERATORS     ======================================= */

	protected:
	/* ====================  DATA MEMBERS  ======================================= */

	private:
	/* ====================  DATA MEMBERS  ======================================= */
	CHAR* 		m_Version;

}; /* -----  end of class Shellcommand  ----- */
#endif   /* ----- #ifndef _SHELLCOMMAND_INC  ----- */
