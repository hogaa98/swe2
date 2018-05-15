#include <stdio.h>
#include <stdlib.h>

struct binary_tree_node{
	int Key;
	struct binary_tree_node *Left;
	struct binary_tree_node *Right;
};
typedef struct binary_tree_node NODE;

extern NODE* getRoot();
extern NODE* add(int, NODE*);
extern NODE* search(int, NODE*);
extern void print_preorder(FILE*, NODE*);
extern void print_inorder(FILE*, NODE*);
extern void print_postorder(FILE*, NODE*);
