#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//The linked list is defined as:
typedef struct node
{
	int n;
	struct node* next;
} node;

//pointer to the first element of the list
node* head = NULL;

/*Linear search in linked list.*/

bool listLinearSearch(node* list, int val){

	//declare a pointer that points to the first node of the list
	node* ptr = list;

	//As long as ptr != NULL, we will dereference it and check to see if ptr->n is 
	//the value we are searching for. If so, the function returns true.
	while (ptr != NULL){
		if (ptr->n == val){
			return true;
		}

		//if val isn't found, progress to the next element in the list 
		//point ptr to the next node in the list
		ptr = ptr->next;
	}

	//if the value isn't found return false
	return false;
}



/*Prepend a new node containing int to the front of a singly linked list*/

void prepend(int i)
{
	// build new node
	node* new = malloc(sizeof(node));

	// initialize new node
	if (new != NULL){
		new->n = i;
		new->next = NULL;
	}
	// set the new node's next field to point to the first node in the list
	new->next = head;
	//set head to point to the new node
	head = new;
}

/* Append a new node to the end of the list*/

void append(int i)
{
	// build new node
	node* new = malloc(sizeof(node));

	if (new == NULL)
	{
		exit(1);
	}

	// initialize new node
	new->n = i;
	new->next = NULL;

	// traverse list with two pointers
	node* prev = NULL;
	for (node* cur = head; cur != NULL; cur = cur->next)
	{
		prev = cur;
	}

	// if the list is empty, prepend
	if (prev == NULL)
	{
		head = new;
	}

	// else add new node to end of list
	else
	{
		prev->next = new;
	}
}

/*Insert nodes into sorted list*/
void insert_sorted(int i)
{
	// build new node
	node* new = malloc(sizeof(node));
	if (new == NULL)
	{
		exit(1);
	}
	// initialize new node
	new->n = i;
	new->next = NULL;

	// traverse list with two pointers
	node* prev = NULL;
	for (node* cur = head; cur != NULL; cur = cur->next){
		// break if we find a value larger than i
		if (cur->n > i){
			break;
		}
		else {
			prev = cur;
		}
	}
	// if new belongs at head, prepend
	if (prev == NULL){
		new->next = head;
		head = new;
	}
	// else insert in middle or end
	else {
		new->next = prev->next;
		prev->next = new;
	}
}