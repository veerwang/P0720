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
	struct timeval tv;
	tv.tv_sec  = 0;
	tv.tv_usec = 1;

	if ( setsockopt(m_socketfd,SOL_SOCKET,SO_RCVTIMEO,(CHAR *)&tv,sizeof(struct timeval)) == -1 )
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
/* 	BOOL flag = false;
 * 	if ( connect(m_socketfd,(struct sockaddr*)&m_Remote,sizeof(m_Remote)) != 0 )
 * 		flag = false;
 * 	else
 * 		flag = true;
 * 	return flag;
 */
}
