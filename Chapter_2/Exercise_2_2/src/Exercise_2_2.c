/*
 ============================================================================
 Name        : Exercise_2_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	const int MAXLINE = 1024;
	int i = 0, lim = 10, c;
	char s[MAXLINE-1];

	while(i < lim - 1)
	{
		c = getchar();
		if(c == '\n') break;
		if(c == EOF) break;
		s[i++] = c;
	}
	return 0;
}
