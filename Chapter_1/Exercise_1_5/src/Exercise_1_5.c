/*
 ============================================================================
 Name        : Exercise_1_4.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.5 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int lower = 0;
const int upper = 300;
const int step = 20;

int main(int argc, char** argv)
{
	int fahr;
	for(fahr = upper; fahr >= lower; fahr -= step)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr -32));
	return 0;
}
