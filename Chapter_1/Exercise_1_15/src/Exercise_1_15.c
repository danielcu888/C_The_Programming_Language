/*
 ============================================================================
 Name        : Exercise_1_15.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.15 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int lower = 0;
const int upper = 300;
const int step = 20;

float fahrToCel(int);

int main(int argc, char** argv)
{
	int fahr;
	for(fahr = upper; fahr >= lower; fahr -= step)
		printf("%3d %6.1f\n", fahr, fahrToCel(fahr));
	return 0;
}

float fahrToCel(int fahr)
{
	return (5.0/9.0)*(fahr -32);
}
