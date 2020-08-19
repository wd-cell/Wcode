#include <stdio.h>
#include <string.h>
int main(void)
{
	char *p1 = "helloo";
	char *p2 = "hello";
	if(strcmp(p1 , p2) > 0)
		printf("bigger than zero \n");
	else if(strcmp(p1 , p2) == 0)
		printf("p1 and p2 is equal \n");
	else
		printf("smaller than zero\n");
	return 0 ; 
}

