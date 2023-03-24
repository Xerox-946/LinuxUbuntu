#include "master.h"
#include <string.h>
#include "all.h"
#include <getch.h>
#include "m_view.h"



void m_init()
{
	
	char c[10];//测试指针的位置，因为打开都是在0位置，所以用一个数组判断文件是否为空
	
	mfile=fopen("master.bin","a+");
	if(NULL==mfile)
	{
		printf("\t\t\t系统错误");
		return;
	}
	//printf("\t\t\t%ld\n",ftell(mfile));//测试指针的位置
	if(0==fread(c,sizeof(c),1,mfile))
	{
		
		char p[6]="admin";
		char p_m[7]="123456";
		strcpy(m,p);
		strcpy(m_m,p_m);	
		fwrite(p,sizeof(p),1,mfile);		
		fwrite(p_m,sizeof(p_m),1,mfile);	
		//printf("\t\t\t%ld\n",ftell(mfile)); 测试指针的位置
		fclose(mfile);
		
	}
	else
	{
		rewind(mfile);
		fread(m,sizeof(m),1,mfile);
		fread(m_m,sizeof(m_m),1,mfile);
		fclose(mfile);
	}
	
	
	
}

void m_start(void)
{
	if(mfile==NULL)
	{
		return;
	}
	int i=m_login_view();
	if(1==i)
	{
		return;
	}
	else if(0==i)
	{
		m_newpassword_view();//新密码界面------------------------------
		i=m_login_view();
	}
	if(i==2)
	{
		m_success_view();
	}	
	printf("已退出");
}

