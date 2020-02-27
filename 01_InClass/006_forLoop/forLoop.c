#include <stdio.h>

int main(void)
{
	int sum = 0;
	int loopLimit = 5;
	for(int i = 1; i <= loopLimit; i++)
	{	sum = sum+i;
	}
	printf("Sum of numbers from 1 to %d equals %d\n", loopLimit, sum);

	return 0;
}

