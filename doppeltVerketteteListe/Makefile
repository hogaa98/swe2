#Makefile

mylist: 			mylist.o main.o
				gcc -o mylist mylist.o main.o
mylist.o: mylist.c mylist.h
				gcc -c -Wall mylist.c
main.o: 	main.c mylist.h
				gcc -c -Wall main.c

