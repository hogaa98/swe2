#include "mylist.h"

extern MYLIST_HEADER* createLIFO(void);
extern void* push(MYLIST_HEADER*, void* Data);
extern void* pop(MYLIST_HEADER*);
extern void* top(MYLIST_HEADER*);
extern int empty(MYLIST_HEADER*);
extern int length(MYLIST_HEADER*);
extern void delete(MYLIST_HEADER*);
