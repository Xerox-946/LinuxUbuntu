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
	m_login_view();//重置完密码需要重新登陆
	
	
	
	
}
void m_reteacher_password(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	
	printf("请输入要重置密码的教师的工号");
	char d_id[9];
	fgets(d_id,11,stdin);
	control_write(d_id);
	int i=0;
	char new_password[16]="123456";
	while(i<tret)
	{
		if(strcmp((tarr+i)->tid,d_id)==0)
		{
			strcpy((tarr+i)->tpwd,new_password);
			fseek(tfile,sizeof(Teacher)*i,SEEK_SET);
			fwrite(tarr+i,sizeof(Teacher),1,tfile);	//两种思路，这种思路是更新到数组里面，然后再写入文件中。在增加删除的思路是写入文件中，再更新到数组中。
			fclose(tfile);				
			printf("修改成功\n");
			anykey_continue();
			return;
		}
		i++;
	}
	printf("没有找到此教师，请检查工号\n");
	anykey_continue();
	
}
void m_add_teacher(void)
{
	system("clear");
	char name[20];
	char id[9];
	long num=20190000+tret;
	sprintf(id,"%ld",num);
	
	Teacher t={.tpwd="123456"};
	printf("请依次输入老师姓名");
	fgets(name,21,stdin);
	control_write(name);
	printf("请输入性别，性别(1为男，2为女)");
	scanf("%hhu",&t.sex);
	strcpy(t.tid,id);
	strcpy(t.tname,name);
    tfile=fopen("teacher.bin","a+");
    if(NULL==tfile)
    {
    	error("fopen");
    	return;
    }
	fwrite(&t,sizeof(Teacher),1,tfile);
	printf("添加成功\n");
	fclose(tfile);
	tret++;
	tarr=realloc(tarr,sizeof(Teacher)*(tret+1));//更新数组大小
	up_tarr();//完成数组更新，使内容保持一致
	anykey_continue();
	
}
void m_del_teacher(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	if(NULL==tfile)
	{
		printf("还没有可以删除的教师信息\n");
		anykey_continue();
		return;
	}
	printf("请输入要删除的教师的工号");
	char d_id[9];
	fgets(d_id,10,stdin);
	control_write(d_id);
	int i=0;
	while(i<tret)
	{
		if(0==strcmp((tarr+i)->tid,d_id))
		{
			if((tarr+i)->sex<10)
			{
				(tarr+i)->sex=(tarr+i)->sex+10;
				printf("删除成功\n");
				fseek(tfile,sizeof(Teacher)*i,SEEK_SET);
				fwrite(tarr+i,sizeof(Teacher),1,tfile);
				fclose(tfile);
				up_tarr();//删除的时候会对文件内容进行修改，修改则要修改数组
			}
			else
			{
				printf("请检查教师是否不存在或者已经离职");
			}
			anykey_continue();
			return;
		}
		i++;
	}
	printf("没有找到该老师\n");
	anykey_continue();

}
void m_show_workteacher(void)
{
	system("clear");//展示不需要对文件进行操作，查看数组即可
	int i=0;
	while(i<tret)
	{
		if(((tarr+i)->sex)<10)
		{
			if(((tarr+i)->sex)%2==0)
				printf("老师姓名:%s 性别:女 工号%s\n",(tarr+i)->tname,(tarr+i)->tid);
			else
				printf("老师姓名:%s 性别:男 工号%s\n",(tarr+i)->tname,(tarr+i)->tid);
		}
		i++;
	}
	anykey_continue();
}
void m_show_fireteacher(void)
{
	system("clear");
	int i=0;
	while(i<tret)
	{
		if(((tarr+i)->sex)>10)
		{
			if(((tarr+i)->sex)%2==0)
				printf("老师姓名:%s 性别:女 工号%s\n",(tarr+i)->tname,(tarr+i)->tid);
			else
				printf("老师姓名:%s 性别:男 工号%s\n",(tarr+i)->tname,(tarr+i)->tid);
		}
		i++;
	}
	anykey_continue();
}
void m_open_teacher_count(void)
{
	system("clear");
	tfile=fopen("teacher.bin","r+");
	printf("请输入要解锁的教师的工号");
	char j_id[9];
	scanf("%s",j_id);
	int i=0;
	while(i<tret)
	{
		if(0==strcmp((tarr+i)->tid,j_id))
		{
			(tarr+i)->sex=(tarr+i)->sex%2;//用%2的好处是误解锁不会导致性别变成负数
			if((tarr+i)->sex==0)
			{
				(tarr+i)->sex=2;
			}
			fseek(tfile,sizeof(Teacher)*i,SEEK_SET);
			fwrite(tarr+i,sizeof(Teacher),1,tfile);
			fclose(tfile);
			printf("解锁成功\n");
			anykey_continue();
			return;
		}
		i++;
	}
	printf("没有此老师\n");
	anykey_continue();
	
}

void up_tarr(void)
{
	int i=0;
	tfile=fopen("teacher.bin","r+");
	if(NULL==tfile)
	{
		perror("fopen");
		return;
	}
	while(i<tret)
	{
		fread(tarr+i,sizeof(Teacher),1,tfile);
		i++;
	}
	fclose(tfile);
}
