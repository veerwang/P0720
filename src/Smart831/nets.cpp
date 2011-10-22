/*
 * =====================================================================================
 *
 *       Filename:  Nets.cpp
 *
 *    Description:  Implementation of Net server class
 *
 *        Version:  1.0
 *        Created:  09/24/2011 05:09:15 PM
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */
#include	"nets.h"

Nets::Nets ()
{
	m_Timeval.tv_usec = 30;
	m_Timeval.tv_sec  = 0;
}  /* -----  end of method Nets::Nets  (constructor)  ----- */

Nets::~Nets ()
{
}  /* -----  end of method Nets::Nets  (destructor)  ----- */
		
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  start_listen
 *  Description:  Star listen the net port 
 * =====================================================================================
 */
BOOL Nets::start_listen()
{
	init_socket();
	INT32 on=1;                       /* Enable the Port can't be reused */
	if ( setsockopt(m_socketfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1 ) 
		return false;
	if ( bind(m_socketfd,(struct sockaddr *)&m_ipaddr,sizeof(struct sockaddr)) == -1 ) 
		return false;
	if ( listen(m_socketfd,m_MAXlistencount) == -1 ) 
		return false;
	FD_ZERO(&readfds);
	FD_SET(m_socketfd,&readfds);
	return true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  close_server
 *  Description:  Close the net Server 
 * =====================================================================================
 */
void Nets::shutdown_server()
{
	close_socket();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  loop_socket_event
 *  Description:  deal with socket event 
 * =====================================================================================
 */
Nets::NETMSG Nets::loop_socket_event()
{
	INT32 result;
	INT32 nread;

	FD_ZERO(&testfds);
	testfds = readfds;

	result = select(FD_SETSIZE,&testfds,(fd_set *)0,
			(fd_set *)0, &m_Timeval);

	if ( result < 1 ) 
	{
		return NETMSG_ERROR;
	}

	for (INT32 fd=0;fd<FD_SETSIZE;fd++ )
	{
		if ( FD_ISSET(fd,&testfds) )
		{
			if ( fd == m_socketfd )
			{
/* 				bzero(&client,sizeof(client));
 * 				client_len = sizeof(client.clientaddr);
 * 				client.clientfd = accept(m_socketfd,(struct sockaddr *)&(client.clientaddr),
 * 						&client_len);
 * 				FD_SET(client.clientfd,&readfds);
 * 				m_vectorClient.push_back(client);
 */
				return NETMSG_CLIENTADD;
			}
			else
			{
				ioctl(fd,FIONREAD,&nread);
				if ( nread == 0 )
				{
					close(fd);
					FD_CLR(fd,&readfds);
/* 					int size = m_vectorClient.size();
 * 					for ( int i=0;i<size;i++ )
 * 					{
 * 						if ( m_vectorClient[i].clientfd == fd ) m_vectorClient.erase(m_vectorClient.begin()+i);
 * 					}
 */
					return NETMSG_CLIENTREL;
				}
				else
				{
/* 					int len  = MAXBUF - m_InputBuf.index; 
 * 					if ( len == 0 ) return NETMSG_BUFOV;
 * 					int tlen = read(fd,m_tmpBuf,len);
 * 					for ( int i=0;i<tlen;i++ )
 * 					{
 * 						m_InputBuf.buf[i] = m_tmpBuf[i]; 
 * 						m_InputBuf.index ++;
 * 					}
 */
					return NETMSG_DATA;
				}
			}
		}
	}
	return NETMSG_NONE;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_socket_opt
 *  Description:  set socket operation for server
 * =====================================================================================
 */
BOOL Nets::set_socket_opt()
{


}
