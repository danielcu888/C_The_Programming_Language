/*
 ============================================================================
 Name        : Exercise_1_8.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.8 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int num_blanks = 0;
	int num_tabs = 0;
	int num_newlines = 0;

	int c;
	while((c = getchar()) != EOF)
	{
		switch(c)
		{
		case ' ':
			++num_blanks;
			break;
		case '\t':
			++num_tabs;
			break;
		case '\n':
			++num_newlines;
			break;
		}
	}

	printf("number of blanks read = %d", num_blanks);
	printf("number of tabs read = %d", num_tabs);
	printf("number of new lines read = %d", num_newlines);

	return 0;
}
