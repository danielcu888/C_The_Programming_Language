/*
 ============================================================================
 Name        : Exercise_1_16.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.16 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int MAXLINE = 10;

int getLine(char[], int);

int main(int argc, char** argv)
{
	int len;
	char line[MAXLINE];

	while((len = getLine(line, MAXLINE)) != 0)
		printf("%d\t%s\n", len, line);

	return 0;
}

int getLine(char s[], int lim)
{
	int c, i = 0;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	while(c != EOF && c != '\n')
	{
		++i;
		c = getchar();
	}
	return i;
}
