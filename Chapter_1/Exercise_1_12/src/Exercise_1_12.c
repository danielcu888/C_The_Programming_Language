/*
 ============================================================================
 Name        : Exercise_1_12.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.12 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

const int OUT = 0;
const int IN = 1;

int main(int argc, char** argv)
{
	int c, state;
	state = OUT;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			if(state == IN)
				printf("\n");
			state = OUT;
		}
		else
		{
			putchar(c);
			state = IN;
		}
	}
	return 0;
}
