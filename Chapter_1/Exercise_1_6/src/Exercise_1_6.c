/*
 ============================================================================
 Name        : Exercise_1_6.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.6 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int c = getchar();
	printf("%f\n", (float)(c != EOF));
	printf("%f\n", (float)(c == EOF));
	return 0;
}
