#ifndef ALL_H
#define ALL_H
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...)
#endif

#define error(...) printf("%s %s:%d %s %m %s %s\n",__FILE__,__func__,__LINE__,__VA_ARGS__,__DATE__,__TIME__)
#include <stdio.h>
#include <getch.h>

typedef struct Student{
	char sname[20];
	unsigned char sex;
	char sid[9];
	char spwd[16];
	double cn;
	double math;
	double en;
}Student;

typedef struct Teacher{
	char tname[20];
	unsigned char sex;
	char tid[9];
	char tpwd[16];
}Teacher;

extern int sret;
extern int usret;
extern int tret;

extern FILE* sfile;
extern FILE* usfile;
extern FILE* tfile;

extern Student *sarr;
extern Student *usarr;
extern Teacher *tarr;

void init(void);
void main_view(void);
void end(void);
void anykey_continue(void);
void control_write(char* text);

#endif//ALL_H
