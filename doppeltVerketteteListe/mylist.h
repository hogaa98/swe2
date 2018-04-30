// doppelt verkettete Liste HEADER
#include <stdio.h>
//SLIST KNOTEN
struct myList{
	void* Data;
	struct myList *Next;
	struct myList *Prev;
};
typedef struct myList MYLIST;

//KOPF KNOTEN mit Listenlaenge
struct myList_Header{
	int Length;
	MYLIST *First, *Last;
};
typedef struct myList_Header MYLIST_HEADER;

extern MYLIST_HEADER* createmyList(void);
extern MYLIST* insertFirst(MYLIST_HEADER*, void*);
extern MYLIST* insertLast(MYLIST_HEADER*, void*);
extern void* deleteFirst(MYLIST_HEADER*);
extern void* deleteLast(MYLIST_HEADER*);
extern void pr_MYLIST(MYLIST_HEADER*, FILE*);
extern void rm_MYLIST(MYLIST_HEADER*);
extern MYLIST* get_entryMYLIST(MYLIST_HEADER*, int);
