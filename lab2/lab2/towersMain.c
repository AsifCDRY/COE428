#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc > 1) {
        n = atoi(argv[1]);
	if (argc > 2){				//if there are more than 1 cmd line arguments
	   from = atoi(argv[2]);
	   dest = atoi(argv[3]);
	}
    }
    if(n <= 0 || from <= 0 || dest <= 0){	//for incorrect n, from and dest numbers
	fprintf(stderr, "Please enter valid disc, initial location, and destination numbers");
	exit(1);
    }
    towers(n, from, dest);
    exit(0);
}

