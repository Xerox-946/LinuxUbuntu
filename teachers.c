#include "teachers.h"
#include "t_view.h"
#include "all.h"
void teacher(void){
	int num=t_login();
	if(num!=-2){
		while(1){
			t_view(num);
			printf("%d\n",sret);
			int ch=getch();
			switch(ch){
				case '1':add_view();break;
				case '9':return;break;	
			}
		}
	}else{
		printf("帐号已被锁定,请联系校长解锁!\n");
		anykey_continue();
	}
}
