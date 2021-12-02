CFLAGS = -Wall -Wextra -pedantic -O2
CC = clang
INCLUDE = ./include
SRC = ./src
OBJS=main.o grafo.o

.PHONY: all main.o grafo.o

all: $(OBJS)
	${CC} ${CFLAGS} -I${INCLUDE} -o main.exe ${OBJS}

clean:
	-rm -f *.o 

grafo.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/grafo.c -o grafo.o

main.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/main.c -o main.o