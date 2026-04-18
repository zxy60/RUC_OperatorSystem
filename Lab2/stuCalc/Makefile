CC=gcc
CFLAGS=-Wall -g

OBJ=main.o student.o stats.o

all: StuStats

StuStats: $(OBJ)
	$(CC) $(OBJ) -o StuStats

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

stats.o: stats.c student.h
	$(CC) $(CFLAGS) -c stats.c

clean:
	rm -f *.o StuStats
