#include <stdlib.h>
#include <string.h>
#include "t_view.h"
#include "all.h"
#include "t_tools.h"
int t_login(void){
	system("clear");
	int count[100010]={};
	int i=0;
	while(count[i]!=3){
		char id[10]={};
		char pwd[17]={};
		printf("请输入教师工号:");
		fgets(id,10,stdin);
		control_write(id);
		for(int i=0;i<tret;i++){
			if(0==strcmp(tarr[i].tid,id)&&tarr[i].sex<3){
				if(0==strcmp(tarr[i].tpwd,"123456")){
					printf("您是第一次登录或被重置,密码为123456\n");
				}
			}
		}
		printf("请输入密码(最多15位):");
		fgets(pwd,17,stdin);
		control_write(pwd);
		for(i=0;i<tret;i++){
			if(tarr[i].sex<3&&strcmp(tarr[i].tid,id)==0){
				count[i]++;
				if(strcmp(tarr[i].tpwd,pwd)==0&&0==strcmp(tarr[i].tpwd,"123456")){
					return re_teacher_pwd(i);
				}else if(strcmp(tarr[i].tpwd,pwd)==0){
					return i;
				}
				break;
			}else if(tarr[i].sex>10&&strcmp(tarr[i].tid,id)==0){
				return -1;
			}else if(tarr[i].sex>=3&&strcmp(tarr[i].tid,id)==0){
				return -2;
			}
		}
		printf("登录失败请重新输入\n");
	}
	tarr[i].sex+=2;
	return -2;
}
void t_view(int num){
	debug("%s\n",__func__);
	system("clear");
	char welcome[100]={};
	sprintf(welcome,"\t\t欢迎登录学生成绩管理系统%s老师\n",tarr[num].tname);
	puts(welcome);
	puts("\t\t\t1.添加学生\n");
	puts("\t\t\t2.删除学生\n");
	puts("\t\t\t3.查找学生\n");
	puts("\t\t\t4.修改学生信息\n");
	puts("\t\t\t5.录入学生成绩\n");
	puts("\t\t\t6.重置学生\n");
	puts("\t\t\t7.显示所有在校学生\n");
	puts("\t\t\t8.显示所有退学学生\n");
	puts("\t\t\t9.退出教师界面\n");
}

void add_view(void){
	while(1){
		system("clear");
		puts("\t\t添加学生信息\n");
		puts("\t\t  1.单个添加\n");
		puts("\t\t  2.批量添加\n");
		puts("\t 	3.退出添加\n");
		int ch=getch();
		switch(ch){
			case '1':add_one();break;
			case '2':add_all();break;
			case '3':return;break;
		}
	}
}
void del_view(void){
	del_stu();
}
void find_view(void){
	while(1){
		system("clear");
		puts("\t\t\t查找学生信息\n");
		puts("\t\t  1.按学号查找\n");
		puts("\t\t  2.按姓名查找\n");
		puts("\t\t    3.退出查找\n");
		int ch=getch();
		switch(ch){
			case '1':find_stu_id();break;
			case '2':find_stu_name();break;
			case '3':return;break;
		}
	}
}
void change_view(void){
	while(1){
		system("clear");
		puts("\t\t\t修改学生信息\n");
		puts("\t\t  1.修改学生基本信息\n");
		puts("\t\t  2.修改学生成绩\n");
		puts("\t 	  3.退出修改\n");
		int ch=getch();
		switch(ch){
			case '1':change_stu_basic();break;
			case '2':change_stu_score();break;
			case '3':return;break;
		}
	}
}
void score_view(void){
	while(1){
		system("clear");
		puts("\t\t\t录入学生成绩信息\n");
		puts("\t\t\t  1.单个录入\n");
		puts("\t\t\t  2.批量录入\n");
		puts("\t\t	  3.退出录入\n");
		int ch=getch();
		switch(ch){
			case '1':score_stu_one();break;
			case '2':score_stu_all();break;
			case '3':return;break;
		}
	}
}
void re_view(void){
	re_stu();
}

void all_stu_view(void){
	all_stu();
}
void all_unstu_view(void){
	all_unstu();
}
