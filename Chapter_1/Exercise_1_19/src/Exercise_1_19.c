/*
 ============================================================================
 Name        : Exercise_1_4.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.5 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int MAXLENGTH = 1024;

char* reverse(char[]);
int getLine(char[], int);

int main(int argc, char** argv)
{
	char line[MAXLENGTH];

	for(;;)
		if(getLine(line, MAXLENGTH) > 0)
			printf("%s\n", reverse(line));
	return 0;
}

int getLine(char line[], int lim)
{
	int c, i = 0;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

char* reverse(char line[])
{
	int i = 0, j = 0;
	while(line[j] != '\0')
		++j;
	--j;
	while(i < j)
	{
		char tmp = line[i];
		line[i++] = line[j];
		line[j--] = tmp;
	}
	return line;
}
