/*
 ============================================================================
 Name        : RPN_Calculator.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "expr.h"

int main(int argc, char *argv[])
{
	printf("\t%.8g\n", expr(argc, argv));
	return 0;
}
