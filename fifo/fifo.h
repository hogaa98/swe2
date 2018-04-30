#include "mylist.h"

extern MYLIST_HEADER* createFIFO(void);
extern void* put(MYLIST_HEADER*, void* Data);
extern void* get(MYLIST_HEADER*);
extern void* last(MYLIST_HEADER*);
extern void* next(MYLIST_HEADER*);
extern int empty(MYLIST_HEADER*);
extern int length(MYLIST_HEADER*);
extern void delete(MYLIST_HEADER*);
