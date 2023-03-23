#include <stdlib.h>
#include <string.h>
#include "t_view.h"
#include "all.h"
#include "t_tools.h"
int t_login(void){
	system("clear");
	int count=0;
	int i=0;
	while(count!=3){
		char id[9]={};
		char pwd[15]={};
		printf("请输入教师工号:");
		scanf("%s",id);
		printf("请输入密码:");
		scanf("%s",pwd);
		for(i=0;i<tret;i++){
			/*if(tarr[i].sex<10&&strcmp(tarr[i].tid,id)==0&&strcmp(tarr[i].tpwd,pwd)==0){
				return i;
			}else if(tarr[i].sex>10&&strcmp(tarr[i].tid,id)==0&&strcmp(tarr[i].tpwd,pwd)==0){
				return -1;
			}*/
			if(strcmp(tarr[i].tid,id)==0&&strcmp(tarr[i].tpwd,pwd)==0){
				return i;
			}
		}
		printf("登录失败请重新输入\n");
		count++;
	}
	tarr[i].sex*=10;
	return -2;
}
void t_view(int num){
	debug("%s\n",__func__);
	system("clear");
	char welcome[50]={};
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
		puts("\t\t添加学生\n");
		puts("\t\t  1.单个添加\n");
		puts("\t\t  2.批量添加\n");
		puts("\t\t 	3.退出添加\n");
		int ch=getch();
		switch(ch){
			case '1':add_one();break;
			case '2':add_all();break;
			case '3':return;break;
		}
	}
}
void del_view(void){


}
void find_view(void){

}
void change_view(void){

}
void score_view(void){

}
void re_view(void){

}
