#include "binaryTree.h"

NODE* root = NULL;

NODE* getRoot(){
	return root;
}
NODE* add(int key, NODE* node){
	int flag = 1;	
	NODE* newNode = NULL;
	
	if(NULL == node)
		flag = 0;
	else if(NULL != search(key, node))
		return NULL;
	
	newNode = malloc(sizeof(NODE));
	newNode->Key = key;
	newNode->Left = NULL;
	newNode->Right = NULL;
	
	if(!flag)
		root = newNode;
		
	while(flag){
		if (key < node->Key){
			if(NULL == node->Left){
				node->Left = newNode;
				flag = 0;
			 } else
			  	node = node->Left;
			  
		}else {
			if(NULL == node->Right){
				node->Right = newNode;
				flag = 0;
			}else
				node = node->Right;
		}
	}
	return newNode;
}
NODE* search(int key, NODE* node){
	NODE* result = NULL;
	
	if(NULL == node)
		return NULL;
		
	if(key == node->Key)
		return node;
	else if(key > node->Key)
		if(NULL != (result=search(key, node->Right)))
			 return result;
		else
			return search(key, node->Left);
}
void print_preorder(FILE* fp, NODE* node){
	if (NULL == node || NULL == fp)
     return;
   fprintf (fp, "%d\n",node->Key);
   
   if (NULL != node->Left)
     print_preorder(fp, node->Left);
	 
   if (NULL != node->Right)
     print_preorder(fp, node->Right);
}
void print_inorder(FILE* fp, NODE* node){
	if (NULL == node || NULL == fp)
     return;
	 
   if (NULL != node->Left)
     print_inorder(fp, node->Left);
   fprintf (fp, "%d\n", node->Key);
   
   if (NULL != node->Right)
     print_inorder (fp, node->Right);
}
void print_postorder(FILE* fp, NODE* node){
	if(NULL == node || NULL == fp)
		return;
		
	if(NULL != node->Left)
		print_postorder(fp, node->Left);
		
	if(NULL != node->Right)
		print_postorder(fp, node->Right);
	fprintf(fp, "%d", node->Key);
}
