#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

//Header erstellen
MYLIST_HEADER *createmyList(void){
	MYLIST_HEADER *root = malloc(sizeof(MYLIST_HEADER));
	if(NULL == root)
		return root;
		
	root->Length=0;
	root->First=NULL;
	root->Last=NULL;
	return root;
}
//Element als erstes einfuegen
MYLIST* insertFirst(MYLIST_HEADER* root, void* data){
	MYLIST* node = malloc(sizeof(MYLIST));
	MYLIST* temp;
	
	if(NULL == node)
		return node;
	
	node->Data = data;
	node->Prev = NULL;
	root->Length = root->Length +1;
		
	if(NULL == root->First){
		root->First = node;
		root->Last = node;
		node->Next = NULL;
		return node;
	}else{
		temp = root->First;
		root->First = node;
		node->Next = temp;
		(node->Next)->Prev = node;
		return node;
	}
}
//Element als letztes einfuegen
MYLIST* insertLast(MYLIST_HEADER* root, void* data){
	MYLIST* node = malloc(sizeof(MYLIST));
	MYLIST* temp;
	
	if(NULL == node)
		return node;
	
	node->Data = data;
	node->Next = NULL;
	root->Length = root->Length +1;
	
	if(NULL == root->Last){
		root->First = node;
		root->Last = node;
		node->Prev = NULL;
		return node;
	}else{
		temp = root->Last;
		root->Last = node;
		node->Prev = temp;
		(node->Prev)->Next = node;
		return node;
	}
}
//Erstes Element loeschen
void* deleteFirst(MYLIST_HEADER* root){
	void* data = (root->First)->Data;
	
	MYLIST* temp = (root->First)->Next;
	free(root->First);
	root->First = temp;
	root->Length = root->Length -1;
	
	return data;
}
//Letztes Element loeschen
 void* deleteLast(MYLIST_HEADER* root){
 	void* data = (root->Last)->Data;
	
	MYLIST* temp = (root->Last)->Prev;
	free(root->Last);
	root->Last = temp;
	root->Length = root->Length -1;
	
	return data;
 }
//Liste in File abspeichern
void pr_MYLIST(MYLIST_HEADER* root, FILE* fp){
	
		MYLIST* ptr = root->First;
		
		while(NULL != ptr){
			fwrite(ptr, sizeof(MYLIST),1, fp);
			ptr = ptr->Next;
		}
	
}

void rm_MYLIST(MYLIST_HEADER* root){
	MYLIST* ptr = root->First;
	int i = 0;
	for(;i < root->Length;i=i+1){
	 	ptr = root->First;
		while(NULL != ptr->Next){
			ptr = ptr->Next;
		}
		free(ptr);
	}
	free(root);
}

MYLIST* get_entryMYLIST(MYLIST_HEADER* root, int index){
	MYLIST* ptr = root->First;
	int i = 0;
	
	while((i < index) && (NULL != ptr)){
		ptr = ptr->Next;
		i = i+1;
	}
	return ptr;
}


