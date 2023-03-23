#include <stdlib.h>
#include "all.h"

FILE* sfile;
FILE* tfile;
Student* sarr=NULL;
Teacher* tarr=NULL;
int sret;
int tret;
void init(void){
	//学生数组初始化
	debug("%s\n",__func__);
	sarr=malloc(sizeof(Student));
	sfile=fopen("student.bin","r+");
  if(NULL==sfile){
  	perror("fopen");
    return;
  }
  sret=0;
  int i=0;
  do{
 		i=fread(sarr+sret,sizeof(Student),1,sfile);
    sret+=i;
    sarr=realloc(sarr,sizeof(Student)*(sret+1));
	}while(i);
	
	//教师数组初始化
	tarr=malloc(sizeof(Teacher));
	tfile=fopen("teacher.bin","r+");
  if(NULL==tfile){
  	perror("fopen");
    return;
  }
  tret=0;
  do{
 		i=fread(tarr+tret,sizeof(Teacher),1,tfile);
    tret+=i;
    tarr=realloc(tarr,sizeof(Teacher)*(tret+1));
	}while(i);
}
void main_view(void){
	system("clear");
	debug("%s\n",__func__);
	puts("\t\t\t学生成绩管理系统\n");
	puts("\t\t\t   1.学生登录\n");
	puts("\t\t\t   2.教师登录\n");
	puts("\t\t\t   3.校长登录\n");
	puts("\t\t\t   4.退出系统\n");
}
void end(void){
	debug("%s\n",__func__);
	rewind(tfile);
	rewind(sfile);
	fwrite(tarr,sizeof(Teacher),tret,tfile);
	fwrite(sarr,sizeof(Student),sret,sfile);
	fclose(tfile);
	fclose(sfile);
	free(tarr);
	free(sarr);
	tarr=NULL;
	sarr=NULL;
}

void anykey_continue(void)
{
 puts("请按任意键继续...");

 stdin->_IO_read_ptr = stdin->_IO_read_end;
 getch();
}

