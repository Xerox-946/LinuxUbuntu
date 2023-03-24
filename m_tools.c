#include "m_tools.h"
#include "master.h"
#include "all.h"
#include<stdio.h>
#include "m_view.h"
#include <string.h>
#include <stdlib.h>

void m_reself_password(void)
{
	m_newpassword_view();
	
	
	
	
}
void m_reteacher_password(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	
	printf("\t\t\t请输入要修改密码的教师的工号\n");
	char d_id[16];
	scanf("%s",d_id);
	printf("\t\t\t请输入新密码");
	char new_password[7];
	scanf("%s",new_password);
	int i=0;
	while(i<tret)//结构体作为变量，能否直接赋值或者把另一个结构体的值赋给一个结构体
	{
		fread(tarr+i,sizeof(Teacher),1,tfile);
		i++;
	}
	i=0;
	while(i<tret)
	{
		if(0==strcmp((tarr+i)->tid,d_id))
		{
			strcpy((tarr+i)->tpwd,new_password);
			break;
		}
		i++;
	}
	fseek(tfile,sizeof(Teacher)*i,SEEK_SET);
	fwrite(tarr+i,sizeof(Teacher),1,tfile);
	
	fclose(tfile);
	
	
}
void m_add_teacher(void)
{
	system("clear");
	char name[20];
	char id[16];
	long num=20190000+tret;
	sprintf(id,"%ld",num);
	
	Teacher t={.tpwd="123456"};
	printf("\t\t\t请依次输入老师性别，姓名\n");
	scanf("%hhu",&t.sex);//这里是否会产生缓存区问题
	scanf("%s",name);
	strcpy(t.tid,id);
	strcpy(t.tname,name);
    tfile=fopen("teacher.bin","a+");
	fwrite(&t,sizeof(Teacher),1,tfile);
	fclose(tfile);
	tret++;//================添加两次报错严重,因为数组一开始只有一个结构体的大小
	tarr=realloc(tarr,sizeof(Teacher)*(tret+1));
	
}
void m_del_teacher(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	printf("\t\t\t请输入要删除的教师的工号\n");
	char d_id[9];
	scanf("%s",d_id);
	int i=0;
	while(i<tret)
	{
		fread(tarr+i,sizeof(Teacher),1,tfile);
		i++;
	}
	i=0;
	while(i<tret)
	{
		if(0==strcmp((tarr+i)->tid,d_id))
		{
			(tarr+i)->sex=(tarr+i)->sex+10;
			break;
		}
		i++;
	}
	fseek(tfile,sizeof(Teacher)*i,SEEK_SET);
	fwrite(tarr+i,sizeof(Teacher),1,tfile);
	fclose(tfile);

}
void m_show_workteacher(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	
	int tret1=tret;
	
	while(tret1>0)
	{
		fread(tarr+tret1-1,sizeof(Teacher),1,tfile);
		tret1--;
	}
	while(tret1<tret)
	{
	if(((tarr+tret1)->sex==1) || ((tarr+tret1)->sex==2) || ((tarr+tret1)->sex==3)  || ((tarr+tret1)->sex==4))
	{
	
	printf("\t\t\t%s %d %s %s\n",(tarr+tret1)->tname,(tarr+tret1)->sex,(tarr+tret1)->tid,(tarr+tret1)->tpwd);
	}
	tret1++;
	}
	fclose(tfile);
	anykey_continue();
}
void m_show_fireteacher(void)
{
	//system("clear");
	tfile=fopen("teacher.bin","r+");
	
	int tret1=tret;
	
	while(tret1>0)
	{
		fread(tarr+tret1-1,sizeof(Teacher),1,tfile);
		tret1--;
	}
	while(tret1<tret)
	{
	if(((tarr+tret1)->sex==11) || ((tarr+tret1)->sex==12))
	{
	printf("\t\t\t%s %d %s %s\n",(tarr+tret1)->tname,(tarr+tret1)->sex,(tarr+tret1)->tid,(tarr+tret1)->tpwd);
	}
	tret1++;
	}

	fclose(tfile);
	anykey_continue();
}
void m_open_teacher_count(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	printf("\t\t\t请输入要解锁的教师的工号\n");
	char j_id[9];
	scanf("%s",j_id);
	int i=0;
	while(i<tret)
	{
		fread(tarr+i,sizeof(Teacher),1,tfile);
		i++;
	}
	i=0;
	while(i<tret)
	{
		if(0==strcmp((tarr+i)->tid,j_id))
		{
			(tarr+i)->sex=(tarr+i)->sex%2;
			if((tarr+i)->sex==0)
			{
				(tarr+i)->sex=2;
			}
			break;
		}
		i++;
	}
	fseek(tfile,sizeof(Teacher)*i,SEEK_SET);
	fwrite(tarr+i,sizeof(Teacher),1,tfile);
	fclose(tfile);
}
