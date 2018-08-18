/*
 * utility.cpp
 *
 *  Created on: Feb 22, 2012
 *      Author: danielcumberbatch
 */

#include "utility.h"
#include "alloc.h"
#include <stdio.h>
#include <string.h>

const int MAXLEN = 1000;

int getLine(char *p, int lim)
{
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*p++ = c;
	*p = '\0';
	return i;
}

int readlines(char **lineptr, int maxlines)
{
	int len, nlines = 0;
	char *p, line[MAXLEN];

	while((len = getLine(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char **lineptr, int nlines)
{
	int i;
	for(i = 0; i != nlines; ++i)
		printf("%s\n", lineptr[i]);
}
