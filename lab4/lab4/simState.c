#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    /* Personalized state machine: 
    	Current		0	1
     	   A		F	D
	   B		G	C
           C		H	F
	   D		E	A
    	   E		H	F
	   F		B	F
    	   G		A	C
	   H		D	G
    
    	Starting state is B
    */
	
    char initialStates[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char nextState0[] =	   {'F', 'G', 'H', 'E', 'H', 'B', 'A', 'D'};
    char nextState1[] =    {'D', 'C', 'E', 'A', 'F', 'F', 'C', 'G'};
    char prevState0[] =    {'G', 'F', '0', 'H', 'D', 'A', 'B', 'C'};
    char prevState1[] =    {'D', '0', 'B', 'A', 'C', 'E', 'H', '0'};
    char tempState;
    char tempNext;
    char garbage[8];
    char currentState = 'B';
    char command[6];
    int i, j = 0, initialStatesSize = 8, garSize = 8;

    printf("%c\n", currentState);
    
    while(fgets(command, 6, stdin)){
	if(command[0] == '0'){
	    for(i = 0; i < initialStatesSize; i++){
		if(currentState == initialStates[i]){
		    currentState = nextState0[i];
		    printf("%c\n", currentState);
		    break;
		}
	    }
	}
	
	else if(command[0] == '1'){
	    for(i = 0; i < initialStatesSize; i++){
		if(currentState == initialStates[i]){
		    currentState = nextState1[i];
		    printf("%c\n", currentState);
		    break;
		}
	    }
	}

	else if(command[0] == 'c'){
	    if(command[2] == '0'){
	    	for(i = 0; i < initialStatesSize; i++){
		    if(currentState == initialStates[i]){
			tempState = currentState;			
			tempNext = nextState0[i];			
			nextState0[i] = command[4];
			break;
		    }
		}
		for(i = 0; i < initialStatesSize; i++){
		    	if(initialStates[i] == command[4]){
			    prevState0[i] = tempState;
			    break;
			}
		}
		for(i = 0; i < initialStatesSize; i++){
		    	if(tempNext == initialStates[i]){
			    prevState0[i] = '0';
			    break;
			}
	    	}
	    }

	    if(command[2] == '1'){
	    	for(i = 0; i < initialStatesSize; i++){
		    if(currentState == initialStates[i]){			
			tempState = currentState;			
			tempNext = nextState1[i];			
			nextState1[i] = command[4];
			break;
		    }
		}
		for(i = 0; i < initialStatesSize; i++){
		    if(initialStates[i] == command[4])
			prevState1[i] = tempState;
		    if(tempNext == initialStates[i])
			prevState1[i] = '0';
		    break;
	    	}
	    }
    	}
	
	else if(command[0] == 'p'){
	    for(i = 0; i < initialStatesSize; i++)
		printf("%c %c %c\n", initialStates[i], nextState0[i], nextState1[i]);
	}

	else if(command[0] == 'g'){
	    for(i = 0; i < initialStatesSize; i++){
		if(prevState0[i] == '0' && prevState1[i] == '0'){
	 	    garbage[j] = initialStates[i];			
		    printf("Garbage: %c\n", garbage[j]);
		    j++;
		    break;
		}
		if(i == 7)
		    printf("No garbage\n");
	    }
	}
	
	else if(command[0] == 'd'){
		if((int)command[2] == NULL){
	    for(i = 0; i < garSize; i++){
		    for(j = 0; j < initialStatesSize; j++){
				if(garbage[i] == initialStates[j]){
					printf("Deleted %c\n", garbage[i]);
					garbage[i] = garbage[i+1];
					garSize--;
					for(int k = j; k < initialStatesSize; k++){				
						initialStates[k] = initialStates[k+1];
						nextState0[k] = nextState0[k+1];
						nextState1[k] = nextState1[k+1];
						prevState0[k] = prevState0[k+1];
						prevState0[k] = prevState0[k+1];
					}
					initialStatesSize--;
					break;
				}
				if(i == sizeof(garbage) - 1 && j == initialStatesSize - 1){
					printf("No states deleted\n");
					break;
				}
				if(garbage == NULL){
					printf("No states deleted\n");
					break;
				}
			}
		}
	}
	
	else if((int)command[2] != NULL){
		for(i = 0; i < initialStatesSize; i++){
			if(command[2] == initialStates[i]){
				if(command[2] == garbage[i]){
					printf("Deleted %c\n", garbage[i]);
					garbage[i] = garbage[i+1];
				for(int k = j; k < initialStatesSize; k++){				
					initialStates[k] = initialStates[k+1];
					nextState0[k] = nextState0[k+1];
					nextState1[k] = nextState1[k+1];
					prevState0[k] = prevState0[k+1];
					prevState0[k] = prevState0[k+1];
				}
				initialStatesSize--;
				break;
				}
				else if(i == initialStatesSize - 1)
					printf("Not deleted\n");
			}
			else if(i == initialStatesSize - 1)
				printf("Not deleted\n");
		}
	}
    }
    }
    exit(0);
}

