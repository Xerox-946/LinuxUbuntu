#include "all.h"
#include "teachers.h"
#include "students.h"
#include <getch.h>
#include "master.h"
int main(){
	init();
	while(1){
		main_view();
		char ch=getch();
		switch(ch){
			case '1':student();break;
			case '2':teacher();break;
			case '3':master();break;
		}
		if(ch=='4'){
			break;
		}
	}
	end();
}
