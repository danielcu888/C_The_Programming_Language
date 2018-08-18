/*
 * stack.c
 *
 *  Created on: Mar 1, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>
#include "stack.h"

enum {MAXVAL = 100};

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack overflow, can't push %g\n", f);
	return;
}

double pop()
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty");
		return 0.0;
	}
}
