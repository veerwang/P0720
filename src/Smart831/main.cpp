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
#include 	"global.h"
#include	"shellcommand.h"
#include	"graphic.h"
#include	"netc.h"
#include	"nets.h"

EXTF Graphic 	g;
EXTF Global	global;

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
	g.setpixel(200,200,0x00ffffff);
	g.release_module();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  server_function
 *  Description:  do server fucntion 
 * =====================================================================================
 */
	void
server_function()
{
	Nets server;
	server.set_port(5300);
	server.set_ip("192.168.1.101");
	server.start_listen();

/* 	printf ( "%d\n",server.loop_socket_event() );
 */

	while( 1 )
	{
		if ( server.loop_socket_event() == Nets::NETMSG_CLIENTADD )
		{
			printf("client connect!");
		}
		else if ( server.loop_socket_event() == Nets::NETMSG_CLIENTREL )
		{
			printf("client release!");
			goto Exit;
		}
	}
Exit:
	server.shutdown_server();
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  client_function
 *  Description:  do client fucntion 
 * =====================================================================================
 */
	void
client_function()
{
	Netc client;
	client.set_ip("192.168.1.101",true);
	client.init_socket();
	client.set_port(5300,true);
	client.set_server_ip("192.168.1.101",true);
	client.set_socket_opt();
	while( !client.connect_server() )
	{
		printf ( "connecting\n" );
		usleep(500000);
	}
	client.close_socket();
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
	else if ( result == ShellCommand::SERVER )
	{
		server_function();
	}
	else if ( result == ShellCommand::CLIENT )
	{
		client_function();
	}
	return EXIT_SUCCESS;
}
#endif   /* ----- #ifndef __MAIN_FILE  ----- */
