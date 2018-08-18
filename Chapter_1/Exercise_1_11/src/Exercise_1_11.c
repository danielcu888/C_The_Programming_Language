/*
 ============================================================================
 Name        : Exercise_1_11.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.11 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int IN = 1;
const int OUT = 0;


// To be tested using a text file
// with adjacent tabs, newlines, etc.

//Bugs most likely to be revealed by exposing
//assumption regarding what constitutes a word,
//e.g., hyphenated words may be counted as one
//word, but some may what to regard it as two.

int main(int argc, char** argv)
{
	int c, nw, nl, nc, state;
	state = OUT;

	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			{
				++nl;
				state = OUT;
			}
		else if(c == '\t' || c == ' ')
			state = OUT;
		else if(state == OUT)
		{
			++nw;
			state = IN;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
