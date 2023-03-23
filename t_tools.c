#include <stdlib.h>
#include <string.h>
#include "all.h"
#include "t_tools.h"
void add_one(void){
	system("clear");
	char name[20]={};
	char sex[5]={};
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
		strcpy(sarr[sret-1].sname,name);
		sprintf(sarr[sret-1].sid,"2023000%d",sid);
		sarr[sret-1].sex=tsex;
	}else{
		sid=atoi(sarr[sret-1].sid)+1;
		sret++;
		sarr=realloc(sarr,sizeof(Student)*(sret+1));
		sprintf(sarr[sret-1].sid,"%d",sid);
		strcpy(sarr[sret-1].sname,name);
		sarr[sret-1].sex=tsex;
	}
	printf("添加成功!\n");
	anykey_continue();
}
void add_all(void){

}
