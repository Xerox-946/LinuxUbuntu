#include <stdlib.h>
#include "all.h"

FILE* sfile;
FILE* usfile;
FILE* tfile;
Student* sarr=NULL;
Student* usarr=NULL;
Teacher* tarr=NULL;
int sret;
int usret;
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
	/*for(int i=0;i<sret;i++){
		printf("%s %hhu %s %s\n",sarr[i].sname,sarr[i].sex,sarr[i].sid,sarr[i].spwd);
	}*/
	
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
	/*for(int i=0;i<tret;i++){
		printf("%s %hhu %s %s\n",tarr[i].tname,tarr[i].sex,tarr[i].tid,tarr[i].tpwd);
	}*/
	
	usarr=malloc(sizeof(Student));
	usfile=fopen("unstudent.bin","r+");
  if(NULL==usfile){
  	perror("fopen");
    return;
  }
  usret=0;
  do{
 		i=fread(usarr+usret,sizeof(Student),1,usfile);
    usret+=i;
    usarr=realloc(usarr,sizeof(Student)*(usret+1));
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
	rewind(usfile);
	fwrite(tarr,sizeof(Teacher),tret,tfile);
	fwrite(sarr,sizeof(Student),sret,sfile);
	fwrite(usarr,sizeof(Student),usret,usfile);
	fclose(tfile);
	fclose(sfile);
	fclose(usfile);
	free(tarr);
	free(sarr);
	free(usarr);
	tarr=NULL;
	sarr=NULL;
	usarr=NULL;
}

void anykey_continue(void)
{
 puts("请按任意键继续...");

 stdin->_IO_read_ptr = stdin->_IO_read_end;
 getch();
}

void control_write(char* text){
  int len=0;
  while(text[len]) len++;
  if(text[len-1]!='\n'){
    scanf("%*[^\n]"); 
    //从缓冲区中读取任意类型数据并丢弃直到遇到字符'\n'停止
    scanf("%*c");
    //从缓冲区中读取任意字符类型数据并丢弃
  }
  text[len-1]='\0';
}
//对密码进行加密
void pwdstr(char* str){
  int i=0;
  while(1){
    char ch=getch();
    switch(ch){
      case 127:
      if(i!=0){
      	printf("\b \b");
      	i--;
      	*(str+i)=0;
      }
      break;
      case 10:printf("\n");return;break;
      default:
        if(i<15){
          printf("*");
          *(str+i)=ch;
          i++;
        }
        break;
    }   
  }
}



