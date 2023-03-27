#include <stdlib.h>
#include <string.h>
#include "all.h"
#include "t_tools.h"
//添加学生
void add_stu(void){
	char name[20]={};
	char sex[5]={};
	char spwd[17]="123456";
	char tsex=0;
	printf("请输入学生姓名、性别:");
	scanf("%s %s",name,sex);
	if(0==strcmp(sex,"男")){
		tsex=1;
	}else{
		tsex=2;
	}
	int sid=1;
	if(sret==0){
		sret+=1;
		sprintf(sarr[sret-1].sid,"2023000%d",sid);
	}else{
		sid=atoi(sarr[sret-1].sid)+1;
		sret++;
		sarr=realloc(sarr,sizeof(Student)*(sret+1));
		sprintf(sarr[sret-1].sid,"%d",sid);
	}
	strcpy(sarr[sret-1].sname,name);
	sarr[sret-1].sex=tsex;
	strcpy(sarr[sret-1].spwd,spwd);
}
//添加单个学生
void add_one(void){
	system("clear");
	add_stu();
	printf("添加成功!\n");
	anykey_continue();
}
//批量添加学生
void add_all(void){
	system("clear");
	printf("请输入你要添加的学生个数:");
	int num=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		add_stu();
	}
	printf("添加成功%d条!\n",num);
	anykey_continue();
}
//批量文件添加学生
void add_all_file(void){
	system("clear");
	FILE* psfile=fopen("student_info.txt","r");
	if(NULL==psfile){
		printf("该文件不存在，请先创建!\n");
		anykey_continue();
		return;
	}
	int ret=0,cnt=0;
	while(1){
    char sex[5]={};
    int sid=1;
    char spwd[17]="123456";
    char sname[20]={};
    ret=fscanf(psfile,"姓名:%s 性别:%s\n",sname,sex);
		if(ret==-1) break;
		cnt++;
    if(sret==0){
			sret+=1;
			sprintf(sarr[sret-1].sid,"2023000%d",sid);
		}else{
			sid=atoi(sarr[sret-1].sid)+1;
			sret++;
			sarr=realloc(sarr,sizeof(Student)*(sret+1));
			sprintf(sarr[sret-1].sid,"%d",sid);
		}
		if(strcmp(sex,"男")){
			sarr[sret-1].sex=1;
		}else{
			sarr[sret-1].sex=2;
		}
		strcpy(sarr[sret-1].sname,sname);
		strcpy(sarr[sret-1].spwd,spwd);
  }
  fclose(psfile);
  if(cnt==0){
  	printf("文件内没有数据，请先添加数据!\n");
  	anykey_continue();
		return;
  }else{
  	printf("添加成功，新添加的学生信息数据如下：\n");
  	for(int i=sret-1;i>=sret-cnt;i--){
  		printf("学生姓名:%s 学号:%s 性别:%s\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女");
  	}
  	anykey_continue();
		return;
  }
}
//删除学生
void del_stu(void){
	system("clear");
	char sid[10]={};
	char resid[10]={};
	printf("请输入你要删除的学生学号:");
	fgets(sid,10,stdin);
	control_write(sid);
	for(int i=0;i<sret;i++){
		if(strcmp(sarr[i].sid,sid)==0&&sarr[i].sex<10){
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
			printf("确定删除请再次输入学号(3次输入错误删除失败):\n");
			int k=3;
			do{
				printf("确认学号:");
				fgets(resid,10,stdin);
				control_write(resid);
				if(strcmp(sid,resid)==0){
					printf("删除成功！\n");
					if(usret==0){
						usret+=1;
						usarr[usret-1]=sarr[i];
					}else{
						usret++;
						usarr=realloc(usarr,sizeof(Student)*(usret+1));
						usarr[usret-1]=sarr[i];
					}
					sarr[i].sex+=10;
					anykey_continue();
					return;
				}else{
					printf("输入不一致请重试！\n");
					bzero(resid,sizeof(resid));
					k--;
				}
			}while(k);			
		}
	}
	printf("未找到学号或删除失败！");
	anykey_continue();
	return;
}
//查找学生通过id
void find_stu_id(void){
	system("clear");
	char sid[10]={};
	printf("请输入你要查找的学生学号(支持模糊查询):");
	fgets(sid,10,stdin);
	control_write(sid);
	int count=0;
	for(int i=0;i<sret;i++){
		if(NULL!=strstr(sarr[i].sid,sid)&&sarr[i].sex<10){
			count++;
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
		}
	}
	if(count==0){
		printf("未找到学号！\n");
	}
	anykey_continue();
	return;
}
//查找学生通过姓名
void find_stu_name(void){
	system("clear");
	char sname[20]={};
	printf("请输入你要查找的学生姓名(支持模糊查询):");
	fgets(sname,10,stdin);
	control_write(sname);
	int count=0;
	for(int i=0;i<sret;i++){
		if(NULL!=strstr(sarr[i].sname,sname)&&sarr[i].sex<10){
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
			count++;
		}
	}
	if(count==0){
		printf("未找到姓名！\n");
	}
	anykey_continue();
	return;
}
//修改学生基本信息
void change_stu_basic(void){
	system("clear");
	char sid[10]={};
	char sname[20]={};
	char sex[5]={};
	printf("请输入你要修改的学生学号:");
	fgets(sid,10,stdin);
	control_write(sid);
	for(int i=0;i<sret;i++){
		if(0==strcmp(sarr[i].sid,sid)&&sarr[i].sex<10){
			printf("学生姓名:%s 学号:%s 性别:%s\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女");
			printf("学生姓名:");
			fgets(sname,10,stdin);
			control_write(sname);
			printf("学生性别:");
			scanf("%s",sex);
			unsigned char ssex=0;
			if(strcmp("男",sex)==0){
				ssex=1;
			}else{
				ssex=2;
			}
			strcpy(sarr[i].sname,sname);
			sarr[i].sex=ssex;
			printf("修改成功!");
			anykey_continue();
			return;
		}
	}
	printf("学号不存在！\n");
	anykey_continue();
	return;
}
//修改学生成绩
void change_stu_score(void){
	system("clear");
	char sid[10]={};
	printf("请输入你要修改的学生学号:");
	fgets(sid,10,stdin);
	control_write(sid);
	for(int i=0;i<sret;i++){
		if(0==strcmp(sarr[i].sid,sid)&&sarr[i].sex<10){
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
			do{
				double en=0; 
				printf("英语成绩:");
				scanf("%lf",&en);
				if(en<=100&&en>=0){
					sarr[i].en=en;
					break;
				}
				printf("英语成绩输入有误请重新输入!\n");
			}while(1);
			do{
				double cn=0; 
				printf("语文成绩:");
				scanf("%lf",&cn);
				if(cn<=100&&cn>=0){
					sarr[i].cn=cn;
					break;
				}
				printf("语文成绩输入有误请重新输入!\n");
			}while(1);
			do{
				double math=0; 
				printf("数学成绩:");
				scanf("%lf",&math);
				if(math<=100&&math>=0){
					sarr[i].math=math;
					break;
				}
				printf("数学成绩输入有误请重新输入!\n");
			}while(1);
			printf("修改成功!\n");
			anykey_continue();
			return;
		}
	}
	printf("学号不存在！");
	anykey_continue();
	return;
}
//录入单个学生成绩
void score_stu_one(void){
	system("clear");
	char sid[10]={};
	printf("请输入你要录入成绩的学生学号:");
	fgets(sid,10,stdin);
	control_write(sid);
	for(int i=0;i<sret;i++){
		if(0==strcmp(sarr[i].sid,sid)&&sarr[i].sex<10&&(sarr[i].en+sarr[i].cn+sarr[i].math)==0){
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
			do{
				double en=0; 
				printf("英语成绩:");
				scanf("%lf",&en);
				if(en<=100&&en>=0){
					sarr[i].en=en;
					break;
				}
				printf("英语成绩输入有误请重新输入!\n");
			}while(1);
			do{
				double cn=0; 
				printf("语文成绩:");
				scanf("%lf",&cn);
				if(cn<=100&&cn>=0){
					sarr[i].cn=cn;
					break;
				}
				printf("语文成绩输入有误请重新输入!\n");
			}while(1);
			do{
				double math=0; 
				printf("数学成绩:");
				scanf("%lf",&math);
				if(math<=100&&math>=0){
					sarr[i].math=math;
					break;
				}
				printf("数学成绩输入有误请重新输入!\n");
			}while(1);
			printf("录入成功!\n");
			anykey_continue();
			return;
		}else if(0==strcmp(sarr[i].sid,sid)&&sarr[i].sex<10){
			printf("该学生已有成绩,如要修改请前往修改信息处修改！\n");
			anykey_continue();
			return;
		}
	}
	printf("学号不存在！\n");
	anykey_continue();
	return;
}
//批量录入学生成绩
void score_stu_all(void){
	system("clear");
	char upsid[10]={};
	char downsid[10]={};
	printf("请输入要录入成绩的学号起始位置(已有成绩的学号会被跳过)\n");
	int uid=0;
	int did=0;
	do{
		printf("请输入学号开始位置:");
		fgets(upsid,10,stdin);
		control_write(upsid);
		printf("请输入学号结束位置:");
		fgets(downsid,10,stdin);
		control_write(downsid);
		uid=atoi(upsid);
		did=atoi(downsid);
	}while(uid>did);
	int k=0;
	for(int i=0;i<sret;i++){
		if(strcmp(sarr[i].sid,upsid)==0){
			k=i;
		}
	}
	for(int i=k;i<sret;i++){
		if(sarr[i].sex<10&&(sarr[i].en+sarr[i].cn+sarr[i].math)==0){
			printf("学生姓名:%s 学号:%s 性别:%s\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女");
			do{
				double en=0; 
				printf("英语成绩:");
				scanf("%lf",&en);
				if(en<=100&&en>=0){
					sarr[i].en=en;
					break;
				}
				printf("英语成绩输入有误请重新输入!\n");
			}while(1);
			do{
				double cn=0; 
				printf("语文成绩:");
				scanf("%lf",&cn);
				if(cn<=100&&cn>=0){
					sarr[i].cn=cn;
					break;
				}
				printf("语文成绩输入有误请重新输入!\n");
			}while(1);
			do{
				double math=0; 
				printf("数学成绩:");
				scanf("%lf",&math);
				if(math<=100&&math>=0){
					sarr[i].math=math;
					break;
				}
				printf("数学成绩输入有误请重新输入!\n");
			}while(1);
			printf("录入成功!\n");
		}
		if(0==strcmp(sarr[i].sid,downsid)){
			printf("全部录入完成！\n");
			anykey_continue();
			return;
		}
	}
	printf("学号不存在！\n");
	anykey_continue();
	return;
}
//批量文件录入学生成绩
void score_all_file(void){
	system("clear");
	printf("批量录入学生成绩，如果不存在学号直接掠过\n");
	FILE* ssfile=fopen("student_score.txt","r");
	if(NULL==ssfile){
		printf("该文件不存在，请先创建!\n");
		anykey_continue();
		return;
	}
	int ret=0,j=0;
	int cnt[100010]={};
	while(1){
    char sid[17]={};
    double en=0,cn=0,math=0;
    ret=fscanf(ssfile,"学号:%s 英语成绩:%lf 语文成绩:%lf 数学成绩:%lf\n",sid,&en,&cn,&math);
		if(ret==-1) break;
    for(int i=0;i<sret;i++){
    	if(0==strcmp(sid,sarr[i].sid)&&sarr[i].sex<10){
    		cnt[i]++;
    		sarr[i].en=en;
    		sarr[i].cn=cn;
    		sarr[i].math=math;
    	}
    }
    j++;
  }
  fclose(ssfile);
  if(j==0){
  	printf("文件内没有数据，请先添加数据!\n");
  	anykey_continue();
		return;
  }else{
  	printf("添加成功，新添加的学生成绩数据如下：\n");
  	for(int i=0;i<sret;i++){
  		if(cnt[i]!=0){
  			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
  		}
  	}
  	anykey_continue();
		return;
  }
}
//重置学生密码
void re_stu(void){
	system("clear");
	char sid[10]={};
	printf("重置密码的同时解锁了学生帐号！\n");
	printf("请输入要重置的学生学号:");
	fgets(sid,10,stdin);
	control_write(sid);
	for(int i=0;i<sret;i++){
		if(strcmp(sid,sarr[i].sid)==0&&sarr[i].sex<10){
			if(sarr[i].sex%2==0){
				sarr[i].sex=2;			
			}else{
				sarr[i].sex=1;
			}
			strcpy(sarr[i].spwd,"123456");
			printf("重置成功！");
			anykey_continue();
			return;
		}
	}
	printf("学号不存在！\n");
	anykey_continue();
	return;
}
//显示所有在校学生
void all_stu(void){
	system("clear");
	if(sret==0){
		printf("暂无入学学生！\n");
		anykey_continue();
		return;
	}
	for(int i=0;i<sret;i++){
		if(sarr[i].sex<10){
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
		}
	}
	anykey_continue();
	return;
}
//显示所有退学学生
void all_unstu(void){
	system("clear");
	if(usret==0){
		printf("暂无退学学生！\n");
		anykey_continue();
		return;
	}
	for(int i=0;i<sret;i++){
		if(sarr[i].sex>=10){
			printf("学生姓名:%s 学号:%s 性别:%s 语文成绩:%.1lf 英语成绩:%.1lf 数学成绩:%.1lf\n",sarr[i].sname,sarr[i].sid,1==sarr[i].sex%2?"男":"女",sarr[i].cn,sarr[i].en,sarr[i].math);
		}
	}
	anykey_continue();
	return;
}
//强制修改教师密码
int re_teacher_pwd(int num){
	system("clear");
	char pwd1[17]={};
	char pwd2[17]={};
	printf("强制修改密码!\n");
	do{
		printf("请输入新的密码(密码最长不超过15位):");
		pwdstr(pwd1);
		if(strcmp(pwd1,"123456")==0){
			printf("输入密码不可再是123456请重输!\n");
			bzero(pwd1,sizeof(pwd1));
			continue;
		}
		printf("请再次输入新的密码:");
		pwdstr(pwd2);
		if(strcmp(pwd1,pwd2)==0){
			printf("修改密码成功!\n");
			strcpy(tarr[num].tpwd,pwd1);
			anykey_continue();
			return num;
		}else{
			printf("密码输入不一致!\n");
		}
	}while(1);	
}
