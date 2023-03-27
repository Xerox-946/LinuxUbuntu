#include<stdio.h>
#include "m_view.h"
#include <string.h>
#include "master.h"
#include "getch.h"
#include "m_tools.h"
#include <stdlib.h>
#include "all.h"


//函数之间的衔接----------------------------------
int m_login_view(void)
{
	
	//char m_m[]="123456";//系统中存的密码
	//char m[]="admin";//系统中存的用户名
	char my_m[7]={};//用户名
	char m_password[7]={};//输入的密码
	
	
	char arr2[7]="123456";//判断是否是第一次进入
	while(1)
	{
		system("clear");
		if(!strcmp(arr2,m_m))
		{
			printf("初始密码是123456\n");
	
			printf("请输入校长账户名");
			fgets(my_m,7,stdin);	
			control_write(my_m);
			printf("请输入校长密码");
			//printf("%s\n",m_password);
			pwdstr(m_password);
			printf("%s\n",m_password);
	
			if(strcmp(m,my_m)!=0)
			{
				printf("账户名有误,请重新输入\n");
				anykey_continue();
			}
			else if(strcmp(m_password,m_m)!=0)
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
			fgets(my_m,7,stdin);	//这里要大两个数字，因为回车也会被接收
			control_write(my_m);
			printf("请输入校长密码");
			
			pwdstr(m_password);
		if(strcmp(m,my_m)!=0)
		{
			printf("账户名有误\n");
			anykey_continue();
			
		}
		else if(strcmp(m_password,m_m)!=0)
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
	
	//scanf("%s",m_m);
	//m_login_view();
}

void m_success_view()
{
while(1){
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
//	getch();//这是把回车读入了getch()之中
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
	char m_newpassword[7];//新密码
	char m_newpassword2[7];//密码的二次确认
	int i=1;
	system("clear");
	printf("请设置新的六位数密码");
		while(i)
		{
			pwdstr(m_newpassword);
			printf("请再输入一遍新的密码");
			pwdstr(m_newpassword2);
			if(0==strcmp(m_newpassword2,m_newpassword))
			{
				strcpy(m_m,m_newpassword);
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
		fwrite(m,sizeof(m),1,mfile);
		fwrite(m_m,sizeof(m_m),1,mfile);
		fclose(mfile);
}


