CFLAGS = -Wall -Wextra -pedantic -O2
CC = gcc
INCLUDE = ./include
SRC = ./src
OBJS=main.o kruskal.o file_reader.o grafo.o

.PHONY: all main.o kruskal.o file_reader.o grafo.o

all: $(OBJS)
	${CC} ${CFLAGS} -I${INCLUDE} -o main.exe ${OBJS}

debug: CFLAGS = -DDEBUG -g

debug: CC = gcc

debug: all

clean:
	-rm -f *.o 

grafo.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/grafo.c -o grafo.o

file_reader.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/file_reader.c -o file_reader.o

kruskal.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/kruskal.c -o kruskal.o

main.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/main.c -o main.o