CC=gcc
BIN=end
OBJ=main.o all.o teachers.o t_tools.o t_view.o master.o m_tools.o m_view.o students.o s_tools.o s_view.o
#FLAG=-Wall -Werror
FLAGD=-Wall -Werror -DDEBUG
STD=-std=gnu99
LINK=-lm

end:$(OBJ)
	$(CC) -o $(BIN) -DDEBUG $(OBJ)

main.o:main.c all.h
	$(CC) $(STD) $(FLAG) -c main.c

all.o:all.c all.h
	$(CC) $(STD) $(FLAG) -c all.c

teachers.o:teachers.c teachers.h
	$(CC) $(STD) $(FLAG) -c teachers.c
	
t_tools.o:t_tools.c t_tools.h
	$(CC) $(STD) $(FLAG) -c t_tools.c
		
t_view.o:t_view.c t_view.h
	$(CC) $(STD) $(FLAG) -c t_view.c

master.o:master.c master.h
	$(CC) $(STD) $(FLAG) -c master.c
	
m_tools.o:m_tools.c m_tools.h
	$(CC) $(STD) $(FLAG) -c m_tools.c
		
m_view.o:m_view.c m_view.h
	$(CC) $(STD) $(FLAG) -c m_view.c

students.o:students.c students.h
	$(CC) $(STD) $(FLAG) -c students.c
	
s_tools.o:s_tools.c s_tools.h
	$(CC) $(STD) $(FLAG) -c s_tools.c
		
s_view.o:s_view.c s_view.h
	$(CC) $(STD) $(FLAG) -c s_view.c



clean:
	rm $(BIN) $(OBJ)
