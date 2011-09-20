/*
 * =====================================================================================
 *
 *       Filename:  graphic.h
 *
 *    Description:  Class do the screen event
 *
 *        Version:  1.0
 *        Created:  2011年09月02日 20时43分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */

#ifndef  _GRAPHIC_INC
#define  _GRAPHIC_INC

#include	"main.h"
/*
 * =====================================================================================
 *        Class:  Graphic
 *  Description:  implementation of  
 * =====================================================================================
 */
class Graphic
{
	public:
	/*-----------------------------------------------------------------------------
	 * backgound color 
	 * black	red	green	yellow	blue	purple	lightblue	white
	 * 40		41	42	43	44	45	46		47
	 *
	 * front color
	 * black	red	green	yellow	blue	purple	lightblue	white
	 * 30		31	32	33	34	35	36		37
	 *-----------------------------------------------------------------------------*/
	typedef enum{
		BLACK_FG 	= 	30,
		RED_FG 	 	= 	31,
		GREEN_FG 	= 	32,
		YELLOW_FG 	= 	33,
		BLUE_FG 	= 	34,
		PURPLE_FG 	= 	35,
		LIGHTBLUE_FG 	= 	36,
		WHITE_FG 	= 	37,
	} FGCOLOR;

	typedef enum{
		BLACK_BG 	= 	40,
		RED_BG 	 	= 	41,
		GREEN_BG 	= 	42,
		YELLOW_BG 	= 	43,
		BLUE_BG 	= 	44,
		PURPLE_BG 	= 	45,
		LIGHTBLUE_BG 	= 	46,
		WHITE_BG 	= 	47,
	} BGCOLOR;

	/* ====================  LIFECYCLE     ======================================= */
	Graphic ();                             /* constructor */
	~Graphic ();                            /* destructor */
	/*-----------------------------------------------------------------------------
	 *  Console Cursor Control Function Setsc
	 *-----------------------------------------------------------------------------*/
	void set_color(FGCOLOR fg,BGCOLOR bg);
	void set_position(INT32 x,INT32 y);
	void disable_cursor();
	void enable_cursor();
	/*-----------------------------------------------------------------------------
	 *  Frame Buffer Control Function Sets
	 *-----------------------------------------------------------------------------*/
	BOOL init_module();
	void release_module();
	void setpixel(INT32 x,INT32 y,COLORT color);
	void show_fb_msg();

	/* ====================  ACCESSORS     ======================================= */

	/* ====================  MUTATORS      ======================================= */

	/* ====================  OPERATORS     ======================================= */

	protected:
	/* ====================  DATA MEMBERS  ======================================= */

	private:
	/* ====================  DATA MEMBERS  ======================================= */
	FGCOLOR			m_fgcolor;
	BGCOLOR			m_bgcolor;
	/*-----------------------------------------------------------------------------
	 *  frame buffer used functions sets
	 *-----------------------------------------------------------------------------*/
	INT32			m_hscreen;
	INT32			m_width;
	INT32			m_height;
	INT32			m_bpp;
	UCHAR*			m_ptrscr;


}; /* -----  end of class Graphic  ----- */
#endif   /* ----- #ifndef _GRAPHIC_INC  ----- */
