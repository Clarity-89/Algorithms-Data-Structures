#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the capacity of the queue
#define CAPACITY 10

// a queue
typedef struct
{
	// the index of the first element in the queue
	int head;

	// storage for the elements in the queue
	char* strings[CAPACITY];

	// the size of the queue
	int size;
}
queue;

// declare a queue (as a global variable)
queue q;

/**
* Puts a new element into the queue into the "end" of the data structure
* so that it will be retrived after the other elements already in the
* queue.
*/
bool enqueue(char* str)
{
	// check if size is less than CAPACITY
	if (q.size == CAPACITY){
		return false;
	}
	else {
		// store element at tail
		q.strings[(q.head + q.size) % CAPACITY] = str;

		// increment size
		q.size++;
	}
	return true;
}

/**
* Retrieves ("dequeues") the first element in the queue, following the
* the "first-in, first-out" (FIFO) ordering of the data structure.
* Reduces the size of the queue and adjusts the head to the next element.
*/
char* dequeue(void)
{
	// check if there are elements to dequeue
	if (q.size == 0){
		return NULL;
	}
	else {
		//store original head
		int originalHead = q.head;
		// reposition head
		q.head = (q.head + 1) % CAPACITY;
		// decrement size
		q.size--;
		// return element at original head
		return q.strings[originalHead];
	}

}