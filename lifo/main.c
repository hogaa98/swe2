#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

int main(){
	MYLIST_HEADER* root = createLIFO();
	int data = 1;
	int*ptr = &data;
	
	push(root, ptr);
	data = data +1;
	push(root, ptr);
	
	ptr = pop(root);
	printf("%d\n",*ptr);
	ptr = top(root);
	
	printf("%d\n", empty(root));
	printf("%d\n", length(root));
	
	delete(root);
	getchar();
	return EXIT_SUCCESS;
}
