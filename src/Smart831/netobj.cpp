/*
 * =====================================================================================
 *
 *       Filename:  netobj.cpp
 *
 *    Description:  implementation of netobj class
 *
 *        Version:  1.0
 *        Created:  2011年10月16日 09时23分17秒
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */
#include	"netobj.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Netobj
 *      Method:  Netobj
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
Netobj::Netobj () : m_port(5300) , m_socketfd(-1)
{
	sprintf(m_strip,"%s","192.168.1.120");
}  /* -----  end of method Netobj::Netobj  (constructor)  ----- */

Netobj::~Netobj ()
{
}  /* -----  end of method Netobj::Netobj  (constructor)  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_port
 *  Description:  set port of socket 
 *  	 enable:  true:    enable immediately
 *  	          false:   unable immediately
 * =====================================================================================
 */
void	Netobj::set_port(INT32 port,BOOL enable)
{
	m_port 			= 	port;
	if ( enable == true )
		m_ipaddr.sin_port	= 	htons(m_port);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_port
 *  Description:  get the port of socket 
 * =====================================================================================
 */
INT32	Netobj::get_port()
{
	return m_port;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_ip
 *  Description:  set the ip addr of socket 
 * =====================================================================================
 */
BOOL 	Netobj::set_ip(const CHAR* ip,BOOL enable)
{
	sprintf(m_strip,"%s",ip);

	if ( enable == false ) return true;

	if ( inet_aton(m_strip,(struct in_addr *)&m_ipaddr.sin_addr.s_addr) == 0 )
	{
		perror("Can't init server IP"); return false;
	}
	else
		return true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_ip
 *  Description:  get the socket ip 
 * =====================================================================================
 */
void	Netobj::get_ip(CHAR* ip)
{
	sprintf(ip,"%s",m_strip);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Socket
 *  Description:  Initiate the Net parameters such as IP listen port ect. 
 * =====================================================================================
 */
BOOL	Netobj::init_socket()
{
	BOOL result = false;
	bzero(&m_ipaddr,sizeof(m_ipaddr));
	m_ipaddr.sin_family 	=	AF_INET;
	m_ipaddr.sin_port	= 	htons(m_port);
	if ( inet_aton(m_strip,(struct in_addr *)&m_ipaddr.sin_addr.s_addr) == 0 )
		return result;

	m_socketfd = socket(AF_INET,SOCK_STREAM,0);
	if ( m_socketfd == -1 ) { return false; }

	result = true;
	return result;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  close_socket
 *  Description:  close the socket connection 
 * =====================================================================================
 */
void 	Netobj::close_socket()
{
	if ( m_socketfd != -1 )
		close(m_socketfd);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_socket_opt
 *  Description:  set socket operation for client or server
 * =====================================================================================
 */
BOOL	Netobj::set_socket_opt()
{
	INT32 on = 1;                           /* Enable the Port can't be reused */
	if ( setsockopt(m_socketfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1 )
	{
		perror("Set Sockopt error");
		close_socket();
		return false;
	}
	return true;
}
