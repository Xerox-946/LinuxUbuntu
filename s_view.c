#include"s_view.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<getch.h>
#include "all.h"

void show_main(void)
{
  for(;;)
  {
	system("clear");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("================================================================================\n");
	printf("\t\t\t欢迎进入学生成绩查询系统！\n");
 	
 	char account[100]={}, key[100]={};
 	int i=0;
 	printf("\t\t\t请输入您的学号：");
 	for(;;)
 	{
 		int cnt=0;
 		scanf("%s",account);
 		for(i=0;i<sret;i++)
 		{
 			if( 0==strcmp(account,sarr[i].sid))
 			{
 				cnt++;
 				break;
 			}
 		}
 			if(cnt) break;
 			system("clear");
 			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
 			printf("\t\t\t帐号有误！请重新输入：");
 	}

 	
 		if((1==sarr[i].sex|| 2==sarr[i].sex))
 		{	
 			system("clear");
 			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
 			printf("\t\t\t请输入密码：");
 			scanf("%s",key);
 			int cnt=0;
 			while(cnt<3)
 			{
 				
 				if(0==strcmp(key,sarr[i].spwd))
 				{
 					cnt=0;
 					if(0==strcmp(key,"123456"))
 						{
 							show_first(i);
 							break;
 						}
 						else
 						{
 							show_tool(i);
 							break;
 						}
 				}
 				else
 				{
 					printf("\t\t密码输入有误，您还有%d次机会，请输入：",4-cnt);
 					scanf("%s",key);		
 				}
 			}
 			if(cnt>2)
 			{
 				sarr[i].sex+=2;
 			}
 		}
 		 if(sarr[i].sex >2 && sarr[i].sex<5)
 		{
 			printf("\t\t\t该帐号已锁定，请寻求老师解锁！\n");
 			anykey_continue();
 			break;
 		}
 		if(sarr[i].sex >10 && sarr[i].sex<15)
 		{
 			printf("\t\t\t该学生已退学！\n");
 			anykey_continue();
 			break;
 		}
 }

}
void show_first(int i)
{
  for(;;)
  {
  	system("clear");
  	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	char new_key[100]={};
		int t=0;
	printf("\t\t\t请输入您的新密码：");
	scanf("%s",new_key);
	if(strlen(new_key)>14)
	{
		printf("\t\t\t密码过长，重新输入：\n");
		anykey_continue();
	}
	else
	{
		char new_key2[100];
		for(;;)
		{
			printf("\t\t\t请再次输入密码：");
			scanf("%s",new_key2);
			if(0==strcmp(new_key,new_key2))
			{
				t++;
				strcpy(sarr[i].spwd,new_key);
				show_tool(i);
				break;
			}
			else
			{
				printf("\t\t\t输入有误！\n");
				anykey_continue();
			}
		}
			if(t) break;
	}
		
	}
}
void show_tool(int i)
{
	while(1){
		system("clear");
		printf("\t\t%s同学您好！欢迎进入学生成绩查询系统！\n",sarr[i].sname);
  		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t\t1、查询成绩\n");
		printf("\t\t\t2、修改密码\n");
		printf("\t\t\t3、查看个人信息\n");
		printf("\t\t\t4、退出学生系统\n");
	
		switch(getch())
		{
		case 49: search(i); break;
		case 50:change_pwd();break;
		case 51:personal_information();break;
		case 52:return;
		}
	}
}
