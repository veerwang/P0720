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
	sprintf(m_ip,"%s","192.168.1.120");
}  /* -----  end of method Netobj::Netobj  (constructor)  ----- */

Netobj::~Netobj ()
{
}  /* -----  end of method Netobj::Netobj  (constructor)  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_port
 *  Description:  set port of socket 
 * =====================================================================================
 */
void	Netobj::set_port(INT32 port)
{
	m_port = port;
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
void 	Netobj::set_ip(const CHAR* ip)
{
	sprintf(m_ip,"%s",ip);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_ip
 *  Description:  get the socket ip 
 * =====================================================================================
 */
void	Netobj::get_ip(CHAR* ip)
{
	sprintf(ip,"%s",m_ip);
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
	if ( inet_aton(m_ip,(struct in_addr *)&m_ipaddr.sin_addr.s_addr) == 0 )
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
