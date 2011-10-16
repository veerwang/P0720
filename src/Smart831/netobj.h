/*
 * =====================================================================================
 *
 *       Filename:  netobj.h
 *
 *    Description:  Basic class of net sets such as Netc Nets 
 *
 *        Version:  1.0
 *        Created:  2011年10月16日 09时19分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  _NETOBJ_INC
#define  _NETOBJ_INC

/*-----------------------------------------------------------------------------
 *  Socket program used head file
 *-----------------------------------------------------------------------------*/
#include 	<sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <vector>
#include	<string.h>
#include 	<unistd.h>
/*-----------------------------------------------------------------------------
 *  System used head file 
 *-----------------------------------------------------------------------------*/
#include	"main.h"

/*
 * =====================================================================================
 *        Class:  Netobj
 *  Description:  
 * =====================================================================================
 */
class Netobj
{
	public:
	/* ====================  LIFECYCLE     ======================================= */
		Netobj ();                             /* constructor */
		~Netobj ();                            /* destructor */
		/*-----------------------------------------------------------------------------
		 *  socket operation sets
		 *-----------------------------------------------------------------------------*/
		BOOL	init_socket();
		void 	close_socket();
		/*-----------------------------------------------------------------------------
		 *  port operation
		 *-----------------------------------------------------------------------------*/
		void 	set_port(INT32 port);
		INT32 	get_port(void);
		/*-----------------------------------------------------------------------------
		 *  ip addr operation
		 *-----------------------------------------------------------------------------*/
		void 	set_ip(const CHAR *);
		void	get_ip(CHAR*);
	protected:
		struct sockaddr_in 		     m_ipaddr;
		INT32 				     m_socketfd;

		UINT32				     m_port;
		CHAR				     m_ip[30];
	private:

}; /* -----  end of class Netobj  ----- */
#endif   /* ----- #ifndef _NETOBJ_INC  ----- */
