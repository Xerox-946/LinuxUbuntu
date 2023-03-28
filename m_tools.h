#ifndef M_TOOLS_H
#define M_TOOLS_H

void m_reself_password(void);//重置校长自己的密码

void m_reteacher_password(void);//重置老师的密码

void m_add_teacher(void);//添加老师

void m_del_teacher(void);//删除老师

void m_show_workteacher(void);//显示所有工作的老师

void m_show_fireteacher(void);//显示所有离职的老师

void m_open_teacher_count(void);//解锁老师账户

void up_tarr(void);//只是显示就要打开文件关闭文件，对文件操作的太频繁，所以创造一个更新数组的操作，显示可以从数组中直接读取

#endif
