#include <stdio.h>
#include <stdlib.h>
#include "bnode.h"
	

int main(void) {
	//Way 2, one pointer
	tnode* root = newNode(2);
	root->left = newNode(1);
	root->right = newNode(3); 
	//Way 1, three pointers
	tnode* root2 = newNode(3);
	tnode* rightnode = newNode(1);
	tnode* leftnode = newNode(2);
	root2->left = rightnode;
	root2->right = leftnode;

	//Way 3, using insert
	tnode* root3 = NULL;
	insert(root3, 2);
	insert(root3, 1);
	insert(root3, 3);
}