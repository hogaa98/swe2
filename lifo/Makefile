#Makefile

lifo: lifo.o mylist.o main.o
				gcc -o lifo lifo.o mylist.o main.o
mylist.o: mylist.c mylist.h
				gcc -c -Wall mylist.c
main.o: main.c lifo.h
				gcc -c -Wall main.c
lifo.o: lifo.c lifo.h mylist.h
				gcc -c -Wall lifo.c
