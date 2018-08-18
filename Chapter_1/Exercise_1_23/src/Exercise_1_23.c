/*
 ============================================================================
 Name        : Exercise_1_23.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

const int MAXLINE = 1024;

int getLine(char[], int);
void remCom(char[], int);
static int flag = 0;

int main(int argc, char **argv)
{
	char line[MAXLINE];
	int len;
	while((len = getLine(line, MAXLINE)) > 0)
	{
		remCom(line, MAXLINE);
		printf("%s\n", line);
	}

	return 0;
}

int getLine(char line[], int max)
{
	int c, i = 0;
	while(i < max - 1 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

void remCom(char line[], int max)
{
	int readPos = 0;

	while(readPos < max - 1)
	{
		if(!flag)
		{
			if(readPos < max - 2 && line[readPos] == '*' && line[readPos+1] == '\\')
			{
				line[readPos++] = ' ';
				line[readPos++] = ' ';
			}

			while(readPos < max - 2 && !(line[readPos] == '/' && line[readPos+1] == '/') && !(line[readPos] == '/' && line[readPos+1] == '*'))
				++readPos;
			if(readPos == max - 2)
				return;
			if(line[readPos] == '/' && line[readPos+1] == '/')
			{
				line[readPos] = '\0';
				return;
			}
		}

		if(line[readPos] == '/' && line[readPos+1] == '*' && flag)
		{
			line[readPos++] = ' ';
			line[readPos++] = ' ';
			continue;
		}

		if((line[readPos] == '/' && line[readPos+1] == '*') || flag)
		{
			flag = 1;
			while(readPos != max - 2 && !(line[readPos] == '*' && line[readPos+1] == '\\'))
				line[readPos++] = ' ';
			if(readPos == max - 2)
			{
				line[readPos++] = ' ';
				return;
			}
			else
			{
				line[readPos++] = ' ';
				line[readPos++] = ' ';
				flag = 0;
			}
		}
	}
}
