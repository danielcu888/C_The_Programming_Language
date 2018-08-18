/*
 ============================================================================
 Name        : Exercise_5_7_b.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utility.h"
#include "qsort.h"
#include <stdio.h>

int main()
{
	static const int BUFFERSIZE = 10000;
	static const int MAXLINES = 5;

	int nlines;
	char buffer[BUFFERSIZE]; //stores all data
	char *lineptr[MAXLINES]; //stores pointers to data

	if((nlines = readlines(lineptr, MAXLINES, buffer, BUFFERSIZE)) > 0)
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else if(nlines == 0)
	{
		printf("You added no lines.\n");
		return 0;
	}
	else
	{
		printf("error: too many lines added.\n");
		return -1;
	}
}
