#Makefile

fifo:		fifo.o mylist.o main.o
				gcc -o fifo fifo.o mylist.o main.o
mylist.o:	mylist.c mylist.h
				gcc -c -Wall mylist.c
main.o: 	main.c fifo.h
				gcc -c -Wall main.c
fifo.o:		fifo.c fifo.h mylist.h
				gcc -c -Wall fifo.c
