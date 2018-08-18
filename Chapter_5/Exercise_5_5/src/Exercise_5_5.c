/*
 ============================================================================
 Name        : Exercise_5_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void mystrcpy(char *s, char *t)
{
	while(*s++ = *t++);
}

int mystrcmp(char *s, char *t)
{
	while(*s == *t)
	{
		if(*s == '\0') return 0;
		++s; ++t;
	}

	return *s - *t;
}

void mystrcat(char *s, char *t)
{
	s += strlen(s);
	while(*s++ = *t++);
}

int mystrend(char *s, char *t)
{
	char *tmp = t;
	if(strlen(s) == 0) return 0;
	s += strlen(s) - 1;
	if(strlen(t) == 0) return 0;
	tmp += strlen(t) - 1;
	while(*s-- == *tmp--);
	return t == ++tmp;
}

char* mystrncpy(char *s, char *t, size_t n)
{
	size_t count = 0;
	while((*s++ = *t++) && count++ != n)
		;
	*s++ = '\0';
	while(count++ <= n)
		*s++ = '\0';
	return s;
}

char* mystrncat(char *s, char* t, size_t n)
{
	size_t count = 0;
	s += strlen(s);
	while((*s++ = *t++) && count++ != n)
		;
	*s = '\0';
	return s;
}

int mystrncmp(char *s, char *t, size_t n)
{
	size_t count = 0;
	while(*s == *t && count++ != n)
	{
		if(*s == '\0') return 0;
		++s; ++t;
	}
	return *s - *t;
}

int main()
{
	return 0;
}
