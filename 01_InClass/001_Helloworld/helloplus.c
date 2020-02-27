#include <stdio.h>

//function prototypes
int test(void);

//global variables
int value = 0;

//main
int main(void)
{
	value = test();
	printf("testvalue: %d\n", value);
	return 0;
}
//implement functions
int test(void)
{
	int retVal = 99;
	return retVal;
}

