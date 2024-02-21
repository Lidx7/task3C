CC = gcc
AR = ar
FLAGS = -Wall -g
SL_C = StrList.c
SL_H = StrList.h
MAIN = Main.c

StrList: Main.o StrList.o
	$(CC) $(FLAGS) -o StrList Main.o StrList.o

Main.o: $(MAIN) $(SL_H)
	$(CC) $(FLAGS) -c $(MAIN)

StrList.o: $(SL_C) $(SL_H)
	$(CC) $(FLAGS) -c $(SL_C)

all: StrList	

.PHONY: clean all

clean:
	rm -f *.o StrList