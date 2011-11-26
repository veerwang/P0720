/*
 * =====================================================================================
 *
 *       Filename:  basicio.cpp
 *
 *    Description:  Implementation of basicio class
 *
 *        Version:  1.0
 *        Created:  2011年11月26日 10时00分06秒
 *       Revision:  none 
 *       Compiler:  gcc-arm
 *
 *         Author:  kevin.wang (), kevin.wang2004@gmail.com
 *        Company:  Eddysun Xiamen
 *
 * =====================================================================================
 */
#include	<dirent.h>
#include	"basicio.h"

Basicio::Basicio()
{

}

Basicio::~Basicio()
{

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test
 *  Description:  
 * =====================================================================================
 */
void Basicio::test()
{
	DIR* dir;
	struct dirent* dirp;

	if ( (dir = opendir("/home/kevin")) == NULL )
	{
		printf("not");
	}
	else
	{
		while( (dirp=readdir(dir)) != NULL )
			printf("%s\n",dirp->d_name);
		closedir(dir);
	}
}
