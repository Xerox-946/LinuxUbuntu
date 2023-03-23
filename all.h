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
	char spwd[15];
	double cn;
	double math;
	double en;
}Student;

typedef struct Teacher{
	char tname[20];
	unsigned char sex;
	char tid[9];
	char tpwd[15];
}Teacher;

extern int sret;
extern int tret;

extern FILE* sfile;
extern FILE* tfile;

extern Student *sarr;
extern Teacher *tarr;

void init(void);
void main_view(void);
void end(void);
void anykey_continue(void);

#endif//ALL_H
