/*
 * getch.c
 *
 *  Created on: Mar 1, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>

enum {BUFSIZE = 100};
int bufp = 0;
int buf[BUFSIZE];

int getch()
{
	return bufp == 0 ? getchar() : buf[--bufp];
}

void ungetch(int c)
{
	if(bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("error: buffer overflow!\n");
}

