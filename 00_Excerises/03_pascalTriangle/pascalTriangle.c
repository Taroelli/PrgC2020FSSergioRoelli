#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void);
void PrintpascalTriangle(int tableLimit);

int space = 1;
int number = 1;

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
			PrintpascalTriangle(inputValue);
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
	printf("Usage: pascalTriangle wholeNumber\n\t \
 	wholeNumber: integer on the interval [1,20] \n");
}

void PrintpascalTriangle( int tableLimit)
{
	for (int i=0; i<tableLimit; i++) {
        for (space=1; space <= tableLimit-i; space++)
            printf("  ");
        for (int j=0; j<=i; j++) {
            if (j==0 || i==0)
                number = 1;
            else
                number=number*(i-j+1)/j;
            printf("%4d", number);
        }
        printf("\n");
    }
	


}




