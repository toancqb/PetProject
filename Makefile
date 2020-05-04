SHELL = /bin/sh

OBJS = main.o FileInput.o  StringProcess.o Operator.o
CFLAG = -Wall -g
CC = gcc
INCLUDE = 
LIBS = -lm

main:${OBJS}
	${CC} ${CFLAG} ${INCLUDE} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o

fclean:
	rm -f *.o main

.c.o:
	${CC} ${CFLAG} ${INCLUDE} -c $<
