/*
 ============================================================================
 Name        : Exercise_1_18.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.18 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int MAXLINE = 100;

int getLine(char[], int);

int main(int argc, char** argv)
{
	char line[MAXLINE];

	for(;;)
	{
		if(getLine(line, MAXLINE) == 0)
			line[0] = '\0';
		printf("%s\n", line);
	}

	return 0;
}

int getLine(char s[], int lim)
{
	int c;
	while(((c = getchar()) == ' ' || c == '\t') && c != EOF && c != '\n')
		;
	if(c == EOF || c == '\n')
		return 0;
	int i = 0;
	while(i < lim - 1 && c != ' ' && c != '\t' && c != EOF && c != '\n')
	{
		s[i++] = c;
		c = getchar();
	}
	s[i] = '\0';
	return i;
}
