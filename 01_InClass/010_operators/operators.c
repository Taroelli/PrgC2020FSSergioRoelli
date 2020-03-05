#include <stdio.h>

int main(void)
{
// Initialisierung
	short largeShort =32760;
	int numerator = 19;	
	int denominator = 5;
	int result = 0;
	float e = 2.718281828f;
	double dblNominator = 12.8;

//Operations

	largeShort = largeShort+12345;
	printf("largeShort = %d \n", largeShort);

	result = numerator / denominator;
	printf("result = %d \n", result);

	
	printf("e++ = %f ", ++e); printf("		++e! \n");
	printf("e-- = %f ", --e);printf("		achtung 2.7 + 1 und dann -1 ist 2.7! \n");


	printf("dblNominator = %f \n",  dblNominator);
	printf("Modulus nicht möglich bei double! \n");
	

	


	



	return 0;
}
