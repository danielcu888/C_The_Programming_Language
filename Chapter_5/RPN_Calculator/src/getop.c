/*
 * getop.c
 *
 *  Created on: Mar 1, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>
#include "getop.h"
#include <ctype.h>
#include "getch.h"

int getop(char s[])
{
	int i = 0, c;
	while((s[i] = c = getch()) == ' ' || c == '\t')
		;
	if(!isdigit(c) && c != '.')
		return c;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}
