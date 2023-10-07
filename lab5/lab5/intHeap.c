#include <stdio.h>
#include <math.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
extern void push(int);

static int size = 0;
static int heapArr[100];

void printNodes(int heap[], int size){		
	for(int i = size-1; i >= size/2; i--){
		printf("<node id = '%d'>", heap[i]);
	}
	for(int k = 0; k < size/2-1; k++){
		printf("<node id = '%d'>", heap[k]);
	}
	for(int j = 0; j < size/2; j++)
		printf("</node>");
	for(int k = size/2-1; k < size/2; k++){
		printf("<node id = '%d'>", heap[k]);
	}
	for(int j = 0; j < size/2; j++)
		printf("</node>");
	printf("\n");
}

void insertionSort(){	

	int key, i, j;
	for(i = 0; i < size; i++){
		key = heapArr[i];
		j = i - 1;
		
		while(j >= 0 && key < heapArr[j]){
			heapArr[j+1] = heapArr[j];
			j--;
		}
		heapArr[j+1] = key;
	}
	printNodes(heapArr, size);
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	int biggestInt = heapArr[size-1];
	push(biggestInt);
	size--;
	return biggestInt;
	
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	heapArr[size] = thing2add;
	size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;
}
