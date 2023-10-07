#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
	int i, j, key;

		for(i = first + 1; i <= last; i++) {
		   myCopy(&array[i], &key);
		   j = i-1;
		
			while(j >= 0 && myCompare(array[j], key) > 0){ 	//j >= 0 && array[j] > key
			   mySwap(&array[j+1], &array[j]);
			   j--;
			}
		myCopy(&key, &array[j+1]);
		}	
}
