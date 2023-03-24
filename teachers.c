#include "teachers.h"
#include "t_view.h"
#include "all.h"
void teacher(void){
	int num=t_login();
	if(num>=0){
		while(1){
			t_view(num);
			int ch=getch();
			switch(ch){
				case '1':add_view();break;
				case '2':del_view();break;
				case '3':find_view();break;
				case '4':change_view();break;
				case '5':score_view();break;
				case '6':re_view();break;
				case '7':all_stu_view();break;
				case '8':all_unstu_view();break;
				case '9':return;break;	
			}
		}
	}else if(num==-2){
		printf("帐号已被锁定,请联系校长解锁!\n");
		anykey_continue();
	}else if(num==-1){
		printf("帐号已不存在!\n");
		anykey_continue();
	}
}
