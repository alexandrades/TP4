all: tp

tp: main_bmh.o sa.o
	gcc -o bmh main_bmh.o sa.o
	rm -rf *.o
main_sa.o: main_bmh.c sa.h
	gcc -c main_bmh.c
sa.o: sa.c sa.h
	gcc -c sa.c 