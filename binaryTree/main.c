#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	NODE* root = getRoot();
	
	add(2, root);
	add(3, root);
	add(1, root);
	
	print_inorder(stdout, root);
	print_preorder(stderr, root);
	
	return EXIT_SUCCESS;
	
}
