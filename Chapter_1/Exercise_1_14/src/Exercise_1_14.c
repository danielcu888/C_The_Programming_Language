/*
 ============================================================================
 Name        : Exercise_1_14.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.14 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int MAXVAL = 128;

int main(int argc, char** argv)
{
	int a[MAXVAL], i, c;
	for(i = 0; i != MAXVAL; ++i)
		a[i] = 0;

	while((c = getchar()) != 'z')
		++a[c];

	int max = 0;
	for(i = 1; i != MAXVAL; ++i)
	{
		if(a[i] > max)
			max = a[i];
	}

	while(max > 0)
	{
		for(i = 32; i != MAXVAL-1; ++i)
		{
			if(a[i] >= max)
				printf("|");
			else
				printf(" ");
		}
		printf("\n");
		--max;
	}

	for(i = 32; i != MAXVAL-1; ++i)
		printf("-");
	printf("\n");
	for(i = 32; i != MAXVAL-1; ++i)
		putchar(i);
	printf("\n");

	return 0;
}
