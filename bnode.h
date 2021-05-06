#include <stdlib.h>
typedef struct 	bnode
{
	struct bnode* left;
	struct bnode* right;
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