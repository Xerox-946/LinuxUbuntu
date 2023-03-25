#ifndef M_TOOLS_H
#define M_TOOLS_H

void m_reself_password(void);
void m_reteacher_password(void);
void m_add_teacher(void);
void m_del_teacher(void);
void m_show_workteacher(void);
void m_show_fireteacher(void);
void m_open_teacher_count(void);
void up_tarr(void);//现在想想，只是显示就要打开文件，对文件操作的太频繁，所以创造一个更新数组的操作，想从数组中直接读取

#endif
