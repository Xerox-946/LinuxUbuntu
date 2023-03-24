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
	for(int i=0;i<sret;i++)
	{
		if(sarr[i].sex<3)
		cnt++;
	}
	//计算总分
	printf("%d\n",cnt);
	for(int i=0 ;i<cnt;i++)
	{	
		for(int j=i;j<sret;j++)
			if(sarr[j].sex<3)
			{		
				score[i]=sarr[i].cn+sarr[i].math+sarr[i].en;
				sum_cn+=sarr[i].cn;
				sum_math+=sarr[i].math;
				sum_en+=sarr[i].en;
			}
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
		if(sarr[i].cn>max_cn) max_cn=sarr[i].cn;
		if(sarr[i].math>max_math) max_math=sarr[i].math;
		if(sarr[i].en>max_en) max_en=sarr[i].en;
	}
	//最低分
	for(int i=0;i<cnt;i++)
	{
		if(sarr[i].cn<min_cn) min_cn=sarr[i].cn;
		if(sarr[i].math<min_math) min_math=sarr[i].math;
		if(sarr[i].en<min_en) min_en=sarr[i].en;
	}
	//显示
	for(int i=0;i<cnt;i++)
	{
		printf("%s %s\n",sarr[n],rank[i]);
		if(0==strcmp(sarr[n].sname,rank[i])) 
		{
			system("clear");
			printf("\t\t\t您的排名是：%d",i);
			printf("\t\t语文   数学   英语\n");
			printf("\t最高分：");
			printf(" %ls   %ls   %ls\n",max_cn,max_math,max_en);
			printf("\t最低分：");
			printf(" %ls   %ls   %ls\n",min_cn,min_math,min_en);
			printf("\t平均分：");
			printf(" %ls   %ls   %ls\n",sum_cn/cnt+1,sum_math/cnt+1,sum_en/cnt+1);
			break;
		}
	}
	anykey_continue();
}
void change_pwd(void)
{
	
}
void personal_information(void)
{
	
}
