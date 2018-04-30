#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main(){
	MYLIST_HEADER* root = createFIFO();
	int data = 3;
	int*ptr = &data;
	
	put(root, ptr);
	data = data +3;
	put(root, ptr);
	
	ptr = next(root);
	printf("%d\n",*ptr);
	ptr = last(root);
	printf("%d\n",*ptr);
	printf("%d\n", empty(root));
	printf("%d\n", length(root));
	
	delete(root);
	getchar();
	return EXIT_SUCCESS;
}
