#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

MYLIST_HEADER* createFIFO(){
	return createmyList();
}

void* put(MYLIST_HEADER* root, void* data){
	return (insertFirst(root, data))->Data;
}

void* get(MYLIST_HEADER* root){
	return deleteLast(root);
}

void* last(MYLIST_HEADER* root){
	return (get_entryMYLIST(root,0))->Data;
}

void* next(MYLIST_HEADER* root){
	return (get_entryMYLIST(root,(root->Length)-1))->Data;
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
