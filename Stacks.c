#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the capacity of the stack
#define CAPACITY 10

typedef struct
{
	// storage for the elements in the stack
	char* strings[CAPACITY];

	// the number of elements currently in the stack
	int size;
}
stack;

// declare a stack (as a global variable)
stack s;

/**
* Puts a new element into the stack onto the "top" of the data structure
* so that it will be retrived prior to the elements already in the stack.
*/
bool push(char* str)
{
	// check if stack is at CAPACITY
	if (s.size < CAPACITY){
		// store element at tail
		s.strings[s.size] = str;
		// increment size
		s.size++;
		return true;
	}
	else {
		return false;
	}
}

/**
* Retrieves ("pops") the last ("top") element off of the stack, following
* the "last-in, first-out" (LIFO) ordering of the data structure. Reduces
* the size of the stack.
*/
char* pop(void)
{
	// check if there are elements to pop
	if (s.size == 0){
		return NULL;
	}
	else {
		// decrement size
		s.size--;
		// return last element
		return s.strings[s.size];
	}
}