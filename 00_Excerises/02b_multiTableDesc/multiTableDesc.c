#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void);
void PrintMultiTable(int tableLimit);


int main(int argc, char *argv[])
{
	int inputValue = 0;
	if (argc !=2)
	{
		PrintUsageMessage();
		return 0;
	}
	else
	{
		inputValue = atoi(argv[1]);
		if (inputValue >= 1 && inputValue <= 20)
		{
			PrintMultiTable(inputValue);
		}
		else
		{
			// no valid number
			PrintUsageMessage();
			return 0;
		}
	}
	return 0;
}	



//-------------------------------------
void PrintUsageMessage(void)
{
	printf("Usage: multiTable wholeNumber\n\t \
 	wholeNumber: integer on the interval [1,20]");
}

void PrintMultiTable( int tableLimit)
{
	for( int i = 1; i <= tableLimit; i++)
	{
		for ( int j = tableLimit; j >= 1; j--)
		{
			printf("%d\t", i*j);
		}
		printf("\n");
	}
}




