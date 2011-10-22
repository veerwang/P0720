/*
 * =====================================================================================
 *
 *       Filename:  nets.h
 *
 *    Description:  Manage the server of net class 
 *
 *        Version:  1.0
 *        Created:  09/24/2011 05:04:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  _NETS_INC
#define  _NETS_INC

#include	"netobj.h"
/*
 * =====================================================================================
 *        Class:  Nets
 *  Description:  Manage Net Server 
 * =====================================================================================
 */
class Nets : public Netobj
{
	public:
		typedef enum {
			NETMSG_NONE = 1,
			NETMSG_ERROR,
			NETMSG_DATA,
			NETMSG_BUFOV,
			NETMSG_CLIENTADD,
			NETMSG_CLIENTREL,
			NETMSG_CLIENTBECLOSED
		} NETMSG;
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Nets ();                             /* constructor */
		~Nets ();                            /* destructor */
		BOOL start_listen();
		void shutdown_server();
		NETMSG loop_socket_event();
		virtual BOOL set_socket_opt();
	protected:
		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  DATA MEMBERS  ======================================= */
		static const UINT32		m_MAXlistencount = 5;
		fd_set 				readfds;
		fd_set 				testfds;
		struct timeval 			m_Timeval;
}; /* -----  end of class Nets  ----- */
#endif   /* ----- #ifndef _NETS_INC  ----- */
