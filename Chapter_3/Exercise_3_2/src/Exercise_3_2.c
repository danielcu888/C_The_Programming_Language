/*
 ============================================================================
 Name        : Exercise_3_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

const int MAXLINE = 1024;

void escape(char s[], char t[])
{
	int i = 0, j = 0, c;
	while(i < MAXLINE - 1 && j < MAXLINE - 1 && (c = s[i++]) != '\0')
	{
		switch(c)
		{
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		default:
			t[j++] = c;
			break;
		}
	}

	if(c != '\0') t[j] = '\0';
}

void revEscape(char s[], char t[])
{
	int i = 0, j = 0;
	while(i < MAXLINE - 1 && j < MAXLINE - 1 && s[i] != '\0')
	{
		if(i < MAXLINE - 2 && s[i] == '\\')
		{
			switch(s[i+1])
			{
			case 't':
				t[j++] = '\t';
				i += 2;
				break;
			case 'n':
				t[j++] = '\n';
				i += 2;
				break;
			default:
				t[j++] = s[i++];
				break;
			}
		}
		else
			t[j++] = s[i++];
	}
	if(s[i] != '\0') t[j] = '\0';
}

int getLine(char s[], int lim)
{
	int c, i = 0;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int main()
{
	char s[MAXLINE], t[MAXLINE];
	int len;
	while((len = getLine(s, MAXLINE)) > 0)
	{
		revEscape(s, t);
		printf("%s\n", s);
		printf("%s\n", t);
	}

	return 0;
}
