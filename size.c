#include "bnode.h"
//#include <stdlib.h>
#include <stdio.h>
/*
typedef struct 	bnode
{
	struct tnode* left;
	struct tnode* right;
	int 					data;
} 							tnode;

tnode* newNode(int _data) 
{
	tnode* node = malloc(sizeof(tnode));
	node->data = _data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

tnode* insert(tnode* root, int _data)
{
	if (root == NULL)
		return newNode(_data);
	int current_val = root->data;
	if (_data >= current_val)
		root->right = insert(root->right, _data);
	else
		root->left = insert(root->left, _data);
	return (root);
}
*/
int size(tnode* root)
{
	if (root == NULL)
		return (0);
	return (1 + size(root->left) + size(root->right));
}

int max_depth(tnode* root)
{
	if (root == NULL)
		return (0);
	int left_depth = max_depth(root->left);
	int right_depth = max_depth(root->right);
	return (1 + (left_depth >= right_depth ? left_depth : right_depth));
}

int min_value(tnode* root)
{
	if (root->left == NULL)
		return (root->data);
	return (min_value(root->left));
}

void inOrder(tnode* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%i", root->data);
		inOrder(root->right);
	}
}

void postOrder(tnode* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%i", root->data);
	}
}

int main()
{
	tnode* rootptr = NULL;
	rootptr = insert(rootptr, 4);
	rootptr = insert(rootptr, 2);
	rootptr = insert(rootptr, 5);
	rootptr = insert(rootptr, 1);
	rootptr = insert(rootptr, 3);
	//rootptr = insert(rootptr, 4);
	//rootptr = insert(rootptr, 4);
	//rootptr = insert(rootptr, 5);
	printf("%i\n", size(rootptr));
	printf("%i\n", max_depth(rootptr));
	printf("%i\n", min_value(rootptr));
	inOrder(rootptr);
	printf("\n");
	postOrder(rootptr);
}