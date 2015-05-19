#include <stdio.h>
#include <stdbool.h>

/*Binary search. Works for sorted array only. Complexity: O(log n) */

bool search(int needle, int haystack[], int size)
{
	// define upper and lower bounds
	int lower = 0;
	int upper = size - 1;

	// halve array until bounds overlap
	while (lower <= upper){
		// define middle
		int middle = (lower + upper) / 2;

		// if needle is at middle
		if (needle == haystack[middle]){
			return true;
		}
		else if (needle < haystack[middle]){

			upper = middle - 1;
		}
		else if (needle > haystack[middle]){
			lower = middle + 1;
		}
	}
	return false;
}

/*Bubble sort.
Compares each element in array to the next one, if the next is bigger than the previous,
swaps them. Sorts array in ascending order. Complexity O(n^2), if array is already sorted
the best case runtime is Ω(n).*/

void bubbleSort(int array[], int size)
{
	int counter;
	// do while swaps > 0, if swaps = 0, the array is already sorted and there's no need for 
	// further iterations
	do {

		// reset swaps to 0
		counter = 0;
		// iterate through entire array
		for (int i = 0; i<size - 1; i++){

			//if previous element is bigger than the next one
			if (array[i] > array[i + 1]){

				// swap them
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				// increment swaps
				counter++;
			}
		}

	} while (counter != 0);
}

/*Insertion sort
Data is divided into two parts: sorted and unsorted. One by one,
the unsorted values are inserted into their appropriate
positions in the sorted subarray. Complexity O(n^2), if array is already sorted
the best case runtime is Ω(n).*/

void insertionSort(int array[], int size)
{
	// iterate through unsorted part of array from l->r
	for (int i = 0; i < size - 1; i++){
		int element = array[i];
		int j = i;
		// iterate through sorted part of array from r->l
		// figure out where in sorted portion element should go
		while (j>0 && array[j - 1] > element){

			// shift sorted elements rightward
			array[j] = array[j - 1];
			j = j - 1;

			// insert element into sorted portion of array
			array[j] = element;
		}
	}
}

/* Selection sort
Data is divided into two parts: sorted and unsorted. One by one, the smallest
values remaining in the unsorted portion are selected and swapped over to the sorted portion of the array.
The expected runtime is Θ(n^2).*/


void selectionSort(int array[], int size){

	// for i = 1 to size - 1
	for (int i = 0; i < size - 1; i++){
		// start by setting min = i
		int min = i;
		// compare min to all other elements in unsorted subarray
		for (int j = i + 1; j < size; j++){
			// if you find an even smaller element, that is now min
			if (array[j] < array[min]){
				min = j;
			}
		}
		if (min != i){
			// swap to put min in correct position in sorted subarray
			int temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}
}

/*Merge sort
Divides an unsorted array in two and then sorts the two halves of that array recursively.
The expected runtime is Θ(n log n).*/

int temp[SIZE] = { 0 };

void merge(int array[], int start_1, int end_1, int start_2, int end_2)
{
	int length = end_2 - start_1 + 1;
	int index = start_1;

	// While there are elements in both subarrays
	while (start_1 <= end_1 && start_2 <= end_2)
	{

		// Compare numbers at the start of the subarrays
		if (array[start_1] <= array[start_2])
		{

			// Append smaller to merged array
			temp[index] = array[start_1];
			index++;
			start_1++;
		}
		else {
			temp[index] = array[start_2];
			index++;
			start_2++;
		}
	}

	// While elements remain in subarray 1 (but not subarray 2)
	while (start_1 <= end_1){
		// Append element to merged array
		temp[index] = array[start_1];
		start_1++;
		index++;
	}

	// While elements remain in subarray 2 (but not subarray 1)
	while (start_2 <= end_2){
		// Append element to merged array
		temp[index] = array[start_2];
		start_2++;
		index++;
	}
	// Copy newly sorted array over to original array
	for (int i = end_2, j = 0; j <= length; i--, j++)
	{
		array[i] = temp[i];
	}
}

void mergeSort(int array[], int start, int end)
{
	if (end > start)
	{
		int middle = (start + end) / 2;

		// sort left half
		sort(array, start, middle);

		// sort right half
		sort(array, middle + 1, end);

		// merge the two halves
		merge(array, start, middle, middle + 1, end);
	}
}