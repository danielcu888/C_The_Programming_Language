/*
 * utility.c
 *
 *  Created on: Feb 23, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>
#include "string.h"
#include "utility.h"

int getLine(char *s, int lim)
{
	int i = 0, c;
	while(i++ < lim - 1 && (c = getchar()) != EOF && c != '\n')
			*s++ = c;
	//printf("getline::%d chars got.\n", i);
	return i;
}

int readlines(char **lineptr, int maxlines, char *buffer, int BUFFERSIZE)
{
	static const int MAXLEN = 100; //maximum length of line

	int len, nlines = 0;
	char *p = buffer, line[MAXLEN];

	while((len = getLine(line, MAXLEN)) > 1)
	{
		//printf("readlines::%d chars got.\n", len);
		//printf("readlines::%d lines got.\n", nlines);
		if(nlines >= maxlines || (p + len - buffer >= BUFFERSIZE))
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	}
	return nlines;
}

void writelines(char **lineptr, int nlines)
{
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

