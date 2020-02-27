#include <stdio.h>

int main(void)
{
	printf("Printing data type sizes... \n");

	printf("Size of char : 			%ld\n", sizeof(char));
	printf("Size of short : 		%ld\n", sizeof(short));
	printf("Size of int : 			%ld\n", sizeof(int));
	printf("Size of long : 			%ld\n", sizeof(long));
	printf("Size of long long : 		%ld\n", sizeof(long));
	printf("Size of float : 		%ld\n", sizeof(float));
	printf("Size of double :		%ld\n", sizeof(double));
	printf("Size of long double : 		%ld\n", sizeof(long double));
	
/* Ausgeben kompakter schrieben */
	printf("char %ld","short %ld", sizeof(char), sizeof(short));




	return 0;

}

