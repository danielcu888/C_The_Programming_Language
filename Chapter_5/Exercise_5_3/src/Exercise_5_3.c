/*
 ============================================================================
 Name        : Exercise_5_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void strcpy(char *s, char *t)
{
	while(*s++ = *t++);
}

int strcmp(char *s, char *t)
{
	while(*s == *t)
	{
		if(*s == '\0') return 0;
		++s; ++t;
	}

	return *s - *t;
}

void strcat(char *s, char *t)
{
	*s += strlen(s);
	while(*s++ = *t++);
}

int main()
{
	return 0;
}
