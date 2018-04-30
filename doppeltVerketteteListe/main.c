#include "mylist.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	MYLIST_HEADER *root=createmyList();
	int data = 1;
	int* ptr = NULL;
	FILE* fp = fopen("list.dat", "w");
	ptr = (int*) (insertFirst(root,&data))->Data;
	
	printf("%i\n",*ptr);
	
	data = data+1;
	ptr = (int*) (insertLast(root,&data))->Data;
	
	printf("%i\n",*ptr);
	ptr = (int*)(get_entryMYLIST(root, 1))->Data;
	printf("%i\n", *ptr);
	pr_MYLIST(root, fp);
	getchar();
	return EXIT_SUCCESS;
}

