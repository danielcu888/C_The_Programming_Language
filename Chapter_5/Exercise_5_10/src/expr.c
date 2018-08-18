/*
 * expr.c
 *
 *  Created on: Mar 1, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "getop.h"
#include "stack.h"

double expr(int argc, char *argv[])
{
	double op2;

	int i;
	for(i = 1; i != argc; ++i)
	{
		switch(getop(*(++argv)))
		{
		case NUMBER:
			push(atof(*argv));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if(op2 != 0)
				push(pop() / op2);
			else
				printf("error: zero denominator\n");
			break;
		default:
			printf("error: unknown command %s\n", *(argv-1));
			break;
		}

	}
	return pop();
}
