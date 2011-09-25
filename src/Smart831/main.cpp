/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Program entry file
 *
 *        Version:  1.0
 *        Created:  2011年08月31日 20时19分53秒
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  _MAIN_FILE
#define  _MAIN_FILE

#include	"main.h"
#include	"shellcommand.h"
#include	"graphic.h"

EXTF Graphic 	g;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  standard_function
 *  Description:  Main function entry point 
 * =====================================================================================
 */
	void
standard_function()
{
	g.init_module();
	g.show_fb_msg();
	g.setpixel(200,200,0xffffffff);
	g.release_module();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Program entry point 
 * =====================================================================================
 */
	int 
main( int argc,char* argv[] )
{
	ShellCommand sch(VERSION);
	ShellCommand::SHELLCOMMAND result = sch.Analyze( argc,argv );
	if ( result == ShellCommand::NORMAL )
	{
		standard_function();
	}
	return EXIT_SUCCESS;
}
#endif   /* ----- #ifndef __MAIN_FILE  ----- */
