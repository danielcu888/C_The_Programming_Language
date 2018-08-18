/*
 * getop.c
 *
 *  Created on: Mar 1, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>
#include "getop.h"
#include <ctype.h>

int getop(char *s)
{
	return (!isdigit(*s) && *s != '.') ? *s : NUMBER;
}
