/*
 * =====================================================================================
 *
 *       Filename:  netc.cpp
 *
 *    Description:  Implementation of net client class
 *
 *        Version:  1.0
 *        Created:  09/25/2011 08:40:21 PM
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */
#include	"netc.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Netc
 *      Method:  Netc
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
Netc::Netc ()
{
	sprintf(m_strserverip,"%s","192.168.1.1");
	m_tv.tv_sec  = 0;
	m_tv.tv_usec = 1;
}  /* -----  end of method Netc::Netc  (constructor)  ----- */

Netc::~Netc ()
{
}  /* -----  end of method Netc::Netc  (constructor)  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_socket_opt
 *  Description:  set socket operation for client
 * =====================================================================================
 */
BOOL Netc::set_socket_opt()
{
	INT32 on = 1;                           /* Enable the Port can't be reused */
	if ( setsockopt(m_socketfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1 )
	{
		perror("Set Sockopt error");
		close_socket();
		return false;
	}
	if ( setsockopt(m_socketfd,SOL_SOCKET,SO_RCVTIMEO,(CHAR *)&m_tv,sizeof(struct timeval)) == -1 )
	{
		perror("Set Sockopt error");
		close_socket();
		return false;
	}
	return true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  connect_server
 *  Description:  
 * =====================================================================================
 */
BOOL Netc::connect_server()
{
	BOOL flag = false;
	if ( connect(m_socketfd,(struct sockaddr*)&m_serveripaddr,sizeof(m_serveripaddr)) != 0 )
		flag = false;
	else
		flag = true;
	return flag;

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_server_ip
 *  Description:  set the ip addr of socket 
 * =====================================================================================
 */
BOOL 	Netc::set_server_ip(const CHAR* ip,BOOL enable)
{
	sprintf(m_strserverip,"%s",ip);
	if ( enable == false ) return true;
	bzero(&m_serveripaddr,sizeof(m_serveripaddr));
	m_serveripaddr.sin_family = AF_INET;
	m_serveripaddr.sin_port = htons(m_port);
	if ( inet_aton(m_strserverip,(struct in_addr *)&m_serveripaddr.sin_addr.s_addr) == 0 )
	{
		perror("Can't init server IP"); return false;
	}
	else
		return true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  poll_socket_status
 *  Description:  poll the socket status 
 * =====================================================================================
 */
Netc::NETSTA  Netc::poll_socket_status()
{
	INT32 ret;
	FD_ZERO(&m_rdfds);
	FD_SET(m_socketfd,&m_rdfds);
	ret = select(m_socketfd+1,&m_rdfds,NULL,NULL,&m_tv);
	if ( ret <= 0 )
		return Netc::NETNONE;
	else
	{
		if ( !FD_ISSET(m_socketfd,&m_rdfds) )
			return Netc::NETNONE;
		else
			return Netc::DATAIN;
	}
}
