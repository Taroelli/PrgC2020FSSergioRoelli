#include <stdio.h>

/* Binary Nuber Printer */




int main(void)
{
	//"User input"	
	int decimalnumber = 13;

	

	//some variables needed for calculation
	int divisionresult = decimalnumber;
	int rest = 0;

	printf("Initial Decimal %d\n", decimalnumber);
	printf("binary form 0b");

	while(divisionresult > 0 )
{
	rest = divisionresult%2;
	printf("%d", rest);
	divisionresult = divisionresult/2;
}
	printf("\n");		
}
