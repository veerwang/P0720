/*
 * =====================================================================================
 *
 *       Filename:  ShellCommand.cpp
 *
 *    Description:  Implementation of ShellCommand class
 *
 *        Version:  1.0
 *        Created:  2011年08月31日 20时42分21秒
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */
#include	<cstdio>
#include	<cstdlib>
#include	<cstring>

#include	"shellcommand.h"

ShellCommand::ShellCommand (const CHAR* version)
{
	m_Version = NULL;
	m_Version = new CHAR[10];
	sprintf(m_Version,"%s",version);
}

ShellCommand::~ShellCommand ()
{
	if ( m_Version != NULL ) delete[] m_Version;
	m_Version = NULL;
} 

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Help_Doc
 *  Description:  Program's help documentation 
 * =====================================================================================
 */
	void
ShellCommand::Help_Doc ( void )
{
	printf ( "=========================================\n" );
	printf ( "Usage: mytool [Switch]\n" );
	printf ( "\n" );
	printf ( "Switch:\n" );
	printf ( "--normal or no Switch:   Run Program in normal status.\n" );
	printf ( "--client:                Run Program as a net client.\n" );
	printf ( "--server:                Run Program as a net server.\n" );
	printf ( "--version:               Show the Version of the Programe.\n" );
	printf ( "--help:                  Show this message.\n" );
	printf ( "\n" );
	printf ( "Error report E-mail list:\n" );
	printf ( "                         kevin.wang2004@gmail.com\n" );
	printf ( "                         wangwei200431004@126.com\n" );
	printf ( "=========================================\n" );
}		/* -----  end of function Help_Doc  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Analyze 
 *  Description:  Analyze program switch 
 * =====================================================================================
 */
	ShellCommand::SHELLCOMMAND	
ShellCommand::Analyze ( INT32 argc, CHAR* argv[] )
{
	SHELLCOMMAND result = INVALID;
	CHAR* buf = NULL;
	buf = new CHAR[50];

	switch ( argc ) {
		case 1:	
			{
				system("clear");
				result = NORMAL;
				goto Exit;
				break;
			}
		case 2: 
			{
				if ( argv[1][0] != '-' )
				{
					system("clear");
					Help_Doc();
					result = INVALID;
					goto Exit;
				}
				else
				{
					sprintf(buf,"%s",argv[1]);
					if ( !strcmp(buf,"--normal") )
					{
						system("clear");
						result = NORMAL;
						goto Exit;
					}
					else if ( !strcmp(buf,"--server") )
					{
						system("clear");
						result = SERVER;
						goto Exit;
					}
					else if ( !strcmp(buf,"--client") )
					{
						system("clear");
						result = CLIENT;
						goto Exit;
					}
					else if ( !strcmp(buf,"--test") )
					{
						system("clear");
						result = TEST;
						goto Exit;
					}
					else if ( !strcmp(buf,"--version") )
					{
						system("clear");
						printf ( "\n" );
						printf("Version %s\n",m_Version);
						printf ( "\n" );
						result = INVALID;
						goto Exit;
					}
					else if ( !strcmp(buf,"--help") )
					{
						system("clear");
						Help_Doc();
						result = INVALID;
						goto Exit;
					}
					else
					{
						system("clear");
						Help_Doc();
						result = INVALID;
						goto Exit;
					}
				}
			}
			break;

		default:	
			Help_Doc();
			result = INVALID;
			goto Exit;
			break;
	}				/* -----  end switch  ----- */
Exit:
	delete[] buf;
	buf = NULL;
	return result;
}		/* -----  end of function Analyze ----- */
