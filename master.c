#include "master.h"
#include <string.h>
#include "all.h"
#include <getch.h>
#include "m_view.h"



void m_init()
{
	
	char c[10];//测试指针的位置，因为打开时，文件指针都是在0位置，所以用一个数组判断文件是否为空
	
	mfile=fopen("master.bin","a+");
	if(NULL==mfile)
	{
		perror("fopen");
		anykey_continue();
		return;
	}
	if(0==fread(c,sizeof(c),1,mfile))//文件为空则导入数据
	{
		
		char p[7]="admin";
		char p_m[7]="123456";
		strcpy(m,p);
		strcpy(m_m,p_m);	
		fwrite(p,sizeof(p),1,mfile);		
		fwrite(p_m,sizeof(p_m),1,mfile);	
		fclose(mfile);
		
	}
	else//文件非空则写入数组
	{
		rewind(mfile);
		fread(m,sizeof(m),1,mfile);
		fread(m_m,sizeof(m_m),1,mfile);
		fclose(mfile);
	}
	
	
	
}

void master(void)
{
	m_init();
	if(mfile==NULL)//判定是什么状态回来的，如果是提前return回来，那么是出现错误，不应该往下执行.正常关闭后mfike指向-1
	{
		fclose(mfile);
		return;
	}
	int i=m_login_view();
	if(0==i)
	{
		m_newpassword_view();//新密码界面
	}
	else
	{
		m_success_view();//成功登陆界面
	}	
	tfile=fopen("teacher.bin","r+");//为了减少文件的读取次数，只有关键的校长操作用到了即时存储，教师和学生在系统关闭后才会存储数据。为了让文件打开关闭一致，所以需要在最后再打开文件
	
}

