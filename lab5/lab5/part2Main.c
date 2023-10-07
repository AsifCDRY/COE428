#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void insertionSort();
extern int heapDelete();
extern void addHeap(int);
extern void printNodes(int*, int);

int main(int argc, char * argv[])
{
  	int value, i = 0;
  	while (scanf("%d", &value) != EOF) {
    	addHeap(value);
		fprintf(stderr, "READING INPUT: %d\n", value);   	
		i++;
	}
	insertionSort();
	for(int j = 0; j < i; j++)
		printf("%d\n", heapDelete());
	printf("\n");
	for(int k = 0; k < i; k++)
		printf("%d\n", pop());
  	exit(0);
}
