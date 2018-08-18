/*
 ============================================================================
 Name        : Exercise_1_4.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.4 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;
	upper = 160;
	step = 20;

	celsius = lower;
	printf(" F   |    C\n");
	printf("------------\n");
	while(celsius <= upper)
	{
		fahr = celsius * (9.0/5.0) + 32;
		printf("%3.0f%s%6.1f\n", fahr, "  |", celsius);
		celsius = celsius + step;
	}

	return 0;
}
