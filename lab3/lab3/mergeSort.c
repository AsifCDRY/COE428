#include "mySort.h"
#include "metrics.h"

void merge(int array[], int first, int middle, int last){
	int copyFirst = first;
	int copyMid = middle;
	int leftLength = (middle - first) + 1;
	int rightLength = last - middle;
	int i = 0, j = 0, k = first;

	int L[leftLength], R[rightLength];

	for(int g = 0; g < leftLength; g++){
		myCopy(&array[copyFirst], &L[g]);	// L[g] = array[copyFirst];
		copyFirst++;
	}
	for(int h = 0; h < rightLength; h++){
		myCopy(&array[copyMid + 1], &R[h]);	// R[h] = array[copyMid + 1];
		copyMid++;
	}

	while(i < leftLength && j < rightLength){
		if(myCompare(R[j], L[i]) >= 0){		// L[i] <= R[j]
			myCopy(&L[i], &array[k]);		// array[k] = L[i];
			i++;
		}
		else{
			myCopy(&R[j], &array[k]);		// array[k] = R[j];
			j++;
		}
		k++;
	}
	while(myCompare(leftLength, i) > 0){	// i < leftLength
		myCopy(&L[i], &array[k]);			// array[k] = L[i];
		i++;
		k++;
	}
	while(myCompare(rightLength, j) > 0){	// j < rightLength
		myCopy(&R[j], &array[k]);			// array[k] = R[j];
		j++;
		k++;
	}
}

void mySort(int array[], unsigned int first, unsigned int last)
{
	if(myCompare(last, first) > 0){
	   int mid = (first + last)/2;
	   mySort(array, first, mid);
	   mySort(array, mid + 1, last);
	   merge(array, first, mid, last);
	}
}
