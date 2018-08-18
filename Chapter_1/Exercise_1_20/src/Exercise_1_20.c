/*
 ============================================================================
 Name        : Exercise_1_20.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.20 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

const int TAB_SPACES = 3;
const int MAXLINE = 1024;

void detab(char[], int);
int getLine(char[], int);
void copy(char[], char[]);

int main(int argc, char **argv)
{
	char line[MAXLINE];
	int len;
	while((len = getLine(line, MAXLINE)) > 0)
	{
		detab(line, MAXLINE);
		printf("%s\n", line);
	}
	return 0;
}

void copy(char to[], char from[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

void detab(char line[], int max)
{
	char newLine[MAXLINE];
	int readPos = 0, writePos = 0;
	while(readPos < max - 1 && line[readPos] != '\n')
		{
			if(line[readPos] == '\t')
			{
				do{
					newLine[writePos++] = ' ';
				} while(writePos % TAB_SPACES != 0 && writePos < max-1);
				++readPos;
			}
			else
				newLine[writePos++] = line[readPos++];
		}
	newLine[writePos] = '\0';
	copy(line, newLine);
}

int getLine(char line[], int max)
{
	int i, c;
	for(i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	line[i] = '\0';
	return i;
}
