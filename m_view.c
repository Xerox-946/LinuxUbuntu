#include<stdio.h>
#include "m_view.h"
#include <string.h>
#include "master.h"
#include "getch.h"
#include "m_tools.h"
#include <stdlib.h>
#include "all.h"


//函数之间的衔接,用返回值判断是否是第一次进入
int m_login_view(void)
{
	
	char my_m[20]={};//用户名
	char m_password[16]={};//输入的密码
	
	
	char arr2[16]="123456";//判断是否是第一次进入
	while(1)
	{
		system("clear");
		if(!strcmp(arr2,m_pwd))
		{
			printf("密码为初始密码\n");
			printf("请输入校长账户名");
			fgets(my_m,22,stdin);	//数组长度要比用户名长两个字节，因为在fgets会接收回车键
			control_write(my_m);
			printf("请输入校长密码");
<<<<<<< HEAD
			pwdstr(m_password,15);
=======
			pwdstr(m_password);
>>>>>>> fc11bc3d8c6964a1dc64379e65a731d9c277098e
	
			if(strcmp(m_count,my_m)!=0)
			{
				printf("账户名有误,请重新输入\n");
				anykey_continue();
			}
			else if(strcmp(m_password,m_pwd)!=0)
			{
				printf("密码有误，请重新输入\n");
				anykey_continue();
			}
			else
			{
				printf("登录成功\n");
				anykey_continue();
				return 0;//第一次登录
			}
		
		}
		else
		{
			printf("请输入校长账户名");
			fgets(my_m,22,stdin);
			control_write(my_m);
<<<<<<< HEAD
			printf("请输入校长密码");
			
			pwdstr(m_password,15);
		if(strcmp(m,my_m)!=0)
		{
			printf("账户名有误\n");
			anykey_continue();
=======
			printf("请输入校长密码");	
			pwdstr(m_password);
			if(strcmp(m_count,my_m)!=0)
			{
				printf("账户名有误\n");
				anykey_continue();
>>>>>>> fc11bc3d8c6964a1dc64379e65a731d9c277098e
			
			}
			else if(strcmp(m_password,m_pwd)!=0)
			{
				printf("密码有误\n");
				anykey_continue();
		
			}
			else
			{
				printf("登录成功\n");
				anykey_continue();
				return 2;//不是第一次登录
			}
		
		
		}
		
		
	}
	

}

void m_success_view()
{
	while(1)
	{
		system("clear");
		printf("\t\t欢迎登录学生管理系统校长操作界面\n\n");
		printf("\t\t\t按1重置密码\n\n");
		printf("\t\t\t按2重置教师密码\n\n");
		printf("\t\t\t按3添加教师\n\n");
		printf("\t\t\t按4删除教师\n\n");
		printf("\t\t\t按5显示所有在职教师\n\n");
		printf("\t\t\t按6显示所有离职教师\n\n");
		printf("\t\t\t按7解锁教师帐号\n\n");
		printf("\t\t\t按8退出登录\n\n");

		int i=getch();
		switch(i)
		{
		case '1':m_reself_password();break;
		case '2':m_reteacher_password();break;
		case '3':m_add_teacher();break;
		case '4':m_del_teacher();break;
		case '5': m_show_workteacher();break;
		case '6':m_show_fireteacher();break;
		case '7':m_open_teacher_count();break;
		case '8':return; break;
		}
	}	
}


void m_newpassword_view()
{
	char m_newpassword[16]={};//新密码
	char m_newpassword2[16]={};//密码的二次确认
	int i=1;
	system("clear");
	printf("请设置新的密码");
		while(i)
		{
			pwdstr(m_newpassword,15);
			printf("%s\n",m_newpassword);
			printf("请再输入一遍新的密码");
			pwdstr(m_newpassword2,15);
			printf("%s\n",m_newpassword2);
			if(0==strcmp(m_newpassword2,m_newpassword))
			{
				strcpy(m_pwd,m_newpassword);
				printf("密码设置成功,请重新登录\n");
				i=0;
			}
			else
			{
				system("clear");
				printf("两次密码输入不一致,请重新输入");
			}
		}
		anykey_continue();
		mfile=fopen("master.bin","r+");
		if(mfile==NULL)
		{
			perror("fopen");
			return;
		}
		fwrite(m_count,sizeof(m_count),1,mfile);
		fwrite(m_pwd,sizeof(m_pwd),1,mfile);
		fclose(mfile);
}


