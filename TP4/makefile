all: tp

tp: main_sa.o main_bmh.o main_bmhs.o sa.o
	gcc -o sa main_sa.o sa.o
	gcc -o bmh main_bmh.o sa.o
	gcc -o bmhs main_bmhs.o sa.o
	rm -rf *.o

main_sa.o:main_sa.c sa.h
	gcc -c main_sa.c

main_bmh.o: main_bmh.c sa.h
	gcc -c main_bmh.c

main_bmhs.o: main_bmhs.c sa.c
	gcc -c main_bmhs.c

sa.o: sa.c sa.h
	gcc -c sa.c