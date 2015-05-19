#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//define a binary tree
typedef struct node
{
	int n;
	struct node* left;
	struct node* right;
}
node;

node* root;

bool search(node* root, int val)
{
	if (root == NULL){
		return false;
	}

	if (root->n == val){
		return true;
	}

	// if val is less than root->n
	// search left child
	else if (val < root->n){

		return search(root->left, val);
	}

	// if val is greater than root->n
	// search right child
	else {

		return search(root->right, val);
	}
}

/*Binary tree insertion
Inserts a node containing val into the tree pointed to by the global root variable.*/
bool insert(int val)
{
	// search for insertion point
	node* cur = root;
	node* prev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		if (cur->n < val)
		{
			cur = cur->right;
		}
		else if (cur->n > val)
		{
			cur = cur->left;
		}
		else
		{
			return false;
		}
	}

	// build new node
	node* new = malloc(sizeof(node));
	if (new == NULL)
	{
		return false;
	}
	new->n = val;
	new->left = NULL;
	new->right = NULL;

	// insert node
	if (prev->n > val)
	{
		prev->left = new;
	}
	else
	{
		prev->right = new;
	}

	return true;
}