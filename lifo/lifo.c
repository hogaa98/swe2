#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

MYLIST_HEADER* createLIFO(){
	return createmyList();
}

void* push(MYLIST_HEADER* root, void* data){
	return (insertFirst(root, data))->Data;
}

void* pop(MYLIST_HEADER* root){
	return deleteFirst(root);
}

void* top(MYLIST_HEADER* root){
	return (get_entryMYLIST(root,0))->Data;
}

int empty(MYLIST_HEADER* root){
	return !(root->Length);
}

int length(MYLIST_HEADER* root){
	return root->Length;
}

void delete(MYLIST_HEADER* root){
	rm_MYLIST(root);
}
