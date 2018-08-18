/*
 ============================================================================
 Name        : Exercise_1_13.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.13 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int MAX_LENGTH = 10;
const int OUT = 0;
const int IN = 1;

int main()
{
	int c, i, state, count;
	int lengths[MAX_LENGTH];
	for(i = 0; i != MAX_LENGTH; ++i)
		lengths[i] = 0;

	state = OUT;
	count  = 0;

	while((c = getchar()) != 'q')
	{
		if(c == '\n' || c == ' ' || c == '\t')
		{
			if(state == IN)
				{
					if(count >= MAX_LENGTH)
						count = MAX_LENGTH - 1;
					++lengths[count];
					count = 0;
				}
			state = OUT;
		}
		else
		{
			++count;
			state = IN;
		}
	}

	int max = 0;
	for(i = 1; i != MAX_LENGTH; ++i)
	{
		if(lengths[i] > max)
			max = lengths[i];
	}

	while(max > 0)
	{
		for(i = 1; i != MAX_LENGTH; ++i)
			if(lengths[i] >= max)
				printf(" | ");
			else
				printf("   ");
		printf("\n");
		--max;
	}

	for(i = 1; i != MAX_LENGTH; ++i)
		printf("---");
	printf("\n");
	for(i = 1; i != MAX_LENGTH; ++i)
		printf(" %d ", i);
	printf("\n");

	return 0;
}
