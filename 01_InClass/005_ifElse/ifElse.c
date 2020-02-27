#include <stdio.h>

int main(void)
{
	int testValue = 0;
	int limitValue = 0;
	
	printf("Enter Value 1: ");
	scanf("%d", &testValue);
	
	printf("Enter Value 2: ");
	scanf("%d", &limitValue);

	if(testValue >= limitValue)
	{	printf("%d is bigger or equal to %d\n", testValue, limitValue);
	}
	else	
	{	printf("%d is less than %d\n", testValue, limitValue);
	}

	return 0;

}
