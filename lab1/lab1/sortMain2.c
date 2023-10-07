#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
int main(int argc, char * argv[])
{
 	int data[100000]; /* Array of ints to sort */
 	int nDataItems; /* number of actual items in the array */ 
 	int i;
	int data2[100000];

 	/* Test data */
 	nDataItems = 4;
 	data[0] = 22;
 	data[1] = 42;
 	data[2] = 12;
 	data[3] = 32;
	
 	mySort(data, nDataItems);
	
 	/* Check that the data array is sorted. */
 	for(i = 0; i < nDataItems-1; i++) {
 		if (data[i] > data[i+1]) {
 		fprintf(stderr, "Sort error: data[%d] (= %d)"
 		  " should be <= data[%d] (= %d)- -aborting\n",
 		  i, data[i], i+1, data[i+1]);
 		exit(1);
 		}
 	}

    	fprintf(stderr, "I was invoked with the command: %s\n", argv[0]);
    	if (argc > 1) {
		for(i = 0; i < argc; i++) {
			data2[i] = atoi(argv[i]);
		}
		mySort(data2, argc);
        	fprintf(stderr, "The command line arguments are:\n");
        	for(i = 1; i < argc; i++) {
			fprintf(stderr, "   argv[%d] (as int): %d\n", i, data2[i]);
		}
		
		
    	}
	else {
		/* Print sorted array to stdout */
 		for(i = 0; i < nDataItems; i++) {
 			printf("%d\n", data[i]);
 		}
    	}
    	exit(0);
} 
