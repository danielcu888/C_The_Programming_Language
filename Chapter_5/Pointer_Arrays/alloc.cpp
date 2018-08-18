/*
 * alloc.cpp
 *
 *  Created on: Feb 22, 2012
 *      Author: danielcumberbatch
 */

#include "alloc.h"
#include <stdio.h>

char *alloc(int n)
{
	if(allocp - allocbuf + n >= ALLOCSIZE)
		return NULL;
	allocp += n;
	return allocp - n;
}

void afree(char *p)
{
	if(p >= allocbuf && p - allocbuf >= ALLOCSIZE)
		return;

	allocp = p;
	for(char *i = p; i != allocbuf + ALLOCSIZE; ++i)
		*i = '\0';
}
