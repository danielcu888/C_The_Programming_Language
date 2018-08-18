/*
 ============================================================================
 Name        : Exercise_1_10.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.10 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		switch(c)
		{
		case '\t':
			printf("\\t");
			break;
		case '\b':
			printf("\\b");
			break;
		case '\\':
			printf("\\");
			break;
		default:
			putchar(c);
			break;
		}
	}
	return 0;
}
