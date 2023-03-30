#ifndef  MASTER_H
#define  MASTER_H

#include<stdio.h>
void m_init(void);//用来生成文件
void master(void);//启动校长
extern char m_count[20];//账户名
extern char m_pwd[16];//密码
FILE* mfile;

#endif//MASTER_H
