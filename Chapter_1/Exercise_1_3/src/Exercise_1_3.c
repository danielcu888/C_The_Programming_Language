/*
 ============================================================================
 Name        : Exercise_1_3.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.3 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf(" F   |    C\n");
	printf("------------\n");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f%s%6.1f\n", fahr, "  |", celsius);
		fahr = fahr + step;
	}

	return 0;
}
