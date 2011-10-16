/*
 * =====================================================================================
 *
 *       Filename:  graphic.cpp
 *
 *    Description:  implementation of graphic class
 *
 *        Version:  1.0
 *        Created:  2011年09月02日 20时44分27秒
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#include        <linux/fb.h> 
#include        <sys/types.h> 
#include        <sys/stat.h> 
#include        <sys/ioctl.h>
#include        <sys/mman.h>
#include        <fcntl.h> 
#include        <unistd.h> 

#include	"graphic.h"

Graphic::Graphic () : m_fgcolor(WHITE_FG) , m_bgcolor(BLACK_BG) , m_width(80) ,
	              m_height(25) , m_hscreen(-1) , m_bpp(8) , m_ptrscr(NULL)
{
}  /* -----  end of method Graphic::Graphic  (constructor)  ----- */

Graphic::~Graphic ()
{
	
}  /* -----  end of method Graphic::~Graphic (destructor)  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  void set_color
 *  Description:  set bg and fg color 
 * =====================================================================================
 */
	void
Graphic::set_color ( FGCOLOR fg,BGCOLOR bg )
{
	m_fgcolor = fg;
	m_bgcolor = bg;
	printf("\033[%d;%dm",fg,bg);
}		/* -----  end of function void set_color  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  void set_position
 *  Description:  set the cursor position 
 * =====================================================================================
 */
	void
Graphic::set_position ( INT32 x,INT32 y )
{
	printf ( "\033[%d;%dH",y,x );
}		/* -----  end of function void set_position  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disable_cursor
 *  Description:  Just as title showing 
 * =====================================================================================
 */
	void
Graphic::disable_cursor ( )
{
	printf("\033[?25l");
}		/* -----  end of function disable_cursor  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  enable_cursor
 *  Description:  Just as title showing 
 * =====================================================================================
 */
	void
Graphic::enable_cursor ( )
{
	printf("\033[?25h");
}		/* -----  end of function enable_cursor  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_module
 *  Description:  Init the environment for frame buffer drawing 
 * =====================================================================================
 */
	BOOL	
Graphic::init_module ( )
{
	struct fb_var_screeninfo screeninfo;
	struct fb_fix_screeninfo fxscreeninfo;
	m_hscreen = open("/dev/fb0", O_RDWR);
	if ( m_hscreen == -1 ) 
	{
      		perror("Unable to open frame buffer device /dev/fb0");
      		return false;
	}
	if ( ioctl( m_hscreen,FBIOGET_VSCREENINFO,&screeninfo )== -1 )
	{
      		perror("Unable to retrieve framebuffer information");
      		close( m_hscreen );
      		return false;
	}
	if ( ioctl( m_hscreen,FBIOGET_FSCREENINFO,&fxscreeninfo)== -1 )
	{
      		perror("Unable to retrieve framebuffer fix information");
      		close( m_hscreen );
      		return false;
	}
	m_width  = screeninfo.xres; /* get the screen width and height from system screen */
	m_height = screeninfo.yres;

	m_bpp    = screeninfo.bits_per_pixel;

	m_ptrscr = (UCHAR*) mmap(NULL, fxscreeninfo.smem_len, PROT_READ|PROT_WRITE, MAP_SHARED, m_hscreen, 0);
	if ( m_ptrscr == MAP_FAILED ) 
	{
      		perror("Unable to mmap frame buffer!");
      		close( m_hscreen );
      		return false;
	}

	return true;
}		/* -----  end of function init_module  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  release_module
 *  Description:  release frame buffer environment 
 * =====================================================================================
 */
	void
Graphic::release_module ( )
{
	munmap( m_ptrscr,m_width*m_height*(m_bpp>>3) );
	m_ptrscr = NULL;
	if( m_hscreen != -1 ) 
		close( m_hscreen );
}		/* -----  end of function release_module  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  setpixel
 *  Description:  set one pixel on screen 
 * =====================================================================================
 */
	void
Graphic::setpixel ( INT32 x,INT32 y,COLORT color )
{
	if ( (x<0) || (x>=m_width) || (y<0) || (y>=m_height) ) 
	    return;
	*(UINT32 *)( m_ptrscr + y * m_width + x ) = color;
}		/* -----  end of function setpixel  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  show_fb_msg
 *  Description:  Show frame buffer message on screen 
 * =====================================================================================
 */
	void
Graphic::show_fb_msg ( )
{
	printf ( "width=%d\n",m_width );
	printf ( "height=%d\n",m_height );
	printf ( "bpp=%d\n",m_bpp );
}		/* -----  end of function show_fb_msg  ----- */
