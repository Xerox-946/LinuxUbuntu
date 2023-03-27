#include <string.h>
#include <stdlib.h>
#include"s_tools.h"
#include"all.h"
#include"s_view.h"

void search(int n)
{
	double score[1000]={};
	char rank[1000][20]={};
	double sum_cn=0,sum_math=0,sum_en=0;
	double max_cn=0,max_math=0,max_en=0;
	double min_cn=200,min_math=200,min_en=200;
	int cnt=0;
	Student std[1000]={};
	for(int i=0;i<sret;i++)
	{
		if(sarr[i].sex<3)
		{	
			std[cnt]=sarr[i];
			cnt++;
		}
	}
	//计算总分
	printf("%d\n",cnt);
	for(int j=0 ;j<cnt;j++)
	{		
		score[j]=std[j].cn+std[j].math+std[j].en;
		sum_cn+=std[j].cn;
		sum_math+=std[j].math;
		sum_en+=std[j].en;
			
	}
	//排名
	for(int i=0;i<cnt-1;i++)
	{
		int max=i;
		for(int j=i+1;j<cnt;j++)
		{
			if(score[j]>score[max])
			{
				max=j;
			}
		}
		strcpy(rank[i],sarr[max].sname);
	}
	//最高分
	for(int i=0;i<cnt;i++)
	{
		if(std[i].cn>max_cn) max_cn=std[i].cn;
		if(std[i].math>max_math) max_math=std[i].math;
		if(std[i].en>max_en) max_en=std[i].en;
	}
	//最低分
	for(int i=0;i<cnt;i++)
	{
		if(std[i].cn<min_cn) min_cn=std[i].cn;
		if(std[i].math<min_math) min_math=std[i].math;
		if(std[i].en<min_en) min_en=std[i].en;
	}
	//显示
	for(int i=0;i<cnt;i++)
	{
		if(0==strcmp(sarr[n].sname,rank[i])) 
		{
			system("clear");
			printf("\t\t\t您的排名是：%d\n",i+1);
			printf("\t\t语文   数学   英语\n");
			printf("\t最高分：");
			printf(" %lf   %lf   %lf\n",max_cn,max_math,max_en);
			printf("\t最低分：");
			printf(" %lf   %lf   %lf\n",min_cn,min_math,min_en);
			printf("\t平均分：");
			printf(" %lf   %lf   %lf\n",sum_cn/cnt,sum_math/cnt,sum_en/cnt);
			break;
		}
	}
	anykey_continue();
}
void change_pwd(int n)
{
	for(;;)
	{
		system("clear");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t请输入原密码：");
		char old_key[100]={};
		pwdstr(old_key);
		if(0==strcmp(old_key,sarr[n].spwd))
		{
			
			char new_key[100]={};
			int judge = 1;
			while(judge)
			{
				system("clear");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\t\t请输入新密码：");
				pwdstr(new_key);
				if(strlen(new_key)<16)
				{
					printf("\n\t\t请再次输入确认：");
					char check_again[100]={};
					pwdstr(check_again);
					if(0==strcmp(new_key,check_again))
					{
						strcpy(sarr[n].spwd,new_key);
						printf("\t\t修改成功！\n");
						anykey_continue();
						judge=0;
					}
					else
					{
						printf("\t\t输入错误，请重新尝试！");
						anykey_continue();
					}
				}
				else
				{
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\t\t密码过长请重新输入！");
					anykey_continue();
				}
			}
			break;
		}
		else
		{
			printf("\t\t密码输入错误，请重新尝试！\n");
			anykey_continue();
		}
	}
}
void personal_information(int n)
{
	system("clear");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t学生姓名:%s\n",sarr[n].sname);
	printf("\t学号:%s\n",sarr[n].sid);
	printf("\t性别:%s\n",1==sarr[n].sex%2?"男":"女");
	printf("\t语文成绩:%.1lf\n",sarr[n].cn);
	printf("\t英语成绩:%.1lf\n",sarr[n].en);
	printf("\t数学成绩:%.1lf\n",sarr[n].math);
	anykey_continue();
}
