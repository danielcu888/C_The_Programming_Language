/*
 ============================================================================
 Name        : Exercise_5_4.c
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

int strend(char *s, char *t)
{
	char *tmp = t;
	if(strlen(s) == 0) return 0;
	s += strlen(s) - 1;
	if(strlen(t) == 0) return 0;
	tmp += strlen(t) - 1;
	while(*s-- == *tmp--);
	return t == tmp;
}

int main()
{
	return 0;
}
