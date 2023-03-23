CC=gcc
BIN=end
OBJ=main.o all.o teachers.o t_tools.o t_view.o
FLAG=-Wall -Werror
FLAGD=-Wall -Werror -DDEBUG
STD=-std=gnu99
LINK=-lm

end:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)

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

clean:
	rm $(BIN) $(OBJ)
