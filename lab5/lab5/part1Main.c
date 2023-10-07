#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *  pop();
extern void push(char * );

int main(int argc, char * argv[])
{
  	int ch, i = 0, j = 0, input;
	char toPush[100];
	char toPop[100];
	char* pushed;
	while ((ch = getchar()) != EOF) {
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
    		continue;
    	if(ch == '<')		
			input = ch;
		if(isalpha(ch) && input == '<'){
			while(ch != '>'){
				toPush[i] = ch;
				i++;
				ch = getchar();
			}
			pushed = (char*)(malloc(sizeof(char*)));
			strcpy(pushed, toPush);
			push(pushed);
			printf("Pushed %s\n", pushed);
			for(int i = 0; i < sizeof(toPush); i++)			
				toPush[i] = NULL;
		}
		if(ch == '/' && input == '<')
			input = ch;
		if(isalpha(ch) && input == '/'){		
			while(ch != '>'){
				toPop[j] = ch;
				j++;
				ch = getchar();
			}
			toPop[0] = '\0';
			if(strcmp(pop(), toPop) != 0){
				printf("An error has occurred. Popped does not match tags\n");
				exit(1);
			}
			else
				printf("Popped\n");
		}
  	}
  	exit(0);
}
