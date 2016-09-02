#include <stdio.h>

/** This is a block comment!
 * 
 */
int main(int argc, char const *argv[])
{
	//this is a one line comment
	int x,y;

  printf("Give me 2 numbers! \n");

	//read in user input
	scanf("%i %i",&x,&y);

	//print our results
	printf("X: %i \n",x+y);

	return 0;
}
