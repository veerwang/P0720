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
		enum NETSTA { 
			    	NETNONE  = 0,
			      	DATAIN   = 1 
		            };
		/* ====================  LIFECYCLE     ======================================= */
		Netc ();                             /* constructor */
		~Netc ();                            /* destructor */
		virtual BOOL set_socket_opt();
		BOOL	connect_server();
		BOOL 	set_server_ip(const CHAR* ip,BOOL enable);
		NETSTA  poll_socket_status();
	protected:
	private:
		struct  sockaddr_in 		     m_serveripaddr;
		CHAR				     m_strserverip[30];
		struct timeval 			     m_tv;
}; /* -----  end of class Netc  ----- */
#endif   /* ----- #ifndef _NETC_INC  ----- */
