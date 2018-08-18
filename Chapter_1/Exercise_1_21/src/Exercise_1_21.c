/*
 ============================================================================
 Name        : Exercise_1_21.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXLINE = 1024;
const int TABSPACE = 3; //number of spaces between tab stops

void entab(char[], int);
void copy(char[], char[]);
int getLine(char[], int);

int main(int argc, char** argv)
{
	if(TABSPACE < 1) return -1;
	int len;
	char line[MAXLINE];
	while((len = getLine(line, MAXLINE)) > 0)
	{
		printf("%s\n", line);
		entab(line, MAXLINE);
		printf("%s\n", line);
	}

	return 0;
}

int getLine(char line[], int max)
{
	int c, i;
	for(i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	line[i] = '\0';
	return i;
}

void entab(char line[], int max)
{
	char newLine[max];
	int readPos = 0, writePos = 0, conPos = 0, blankCount = 0;

	while(readPos < max - 1 && line[readPos] != '\0')
	{
		while(readPos < max - 1 && line[readPos] == ' ')
		{
			++blankCount;
			++readPos;
		}

		if(blankCount > 1)
		{
			int preNumBlanks = conPos % TABSPACE == 0 ? 0 : TABSPACE - (conPos % TABSPACE);
			int postNumBlanks = (conPos + blankCount) % TABSPACE;
			int numTabs = (blankCount - preNumBlanks - postNumBlanks)/TABSPACE;
			printf("%d\t%d\t%d\t%d\n", blankCount, preNumBlanks, postNumBlanks, numTabs);

			int i;
			for(i = 0; i != preNumBlanks; ++i)
			{
				newLine[writePos++] = ' ';
				++conPos;
			}
			for(i = 0; i != numTabs; ++i)
			{
				newLine[writePos++] = ' ';
				conPos += TABSPACE;
			}
			for(i = 0; i != postNumBlanks; ++i)
			{
				newLine[writePos++] = ' ';
				++conPos;
			}
		}
		else if(blankCount == 1)
			{
				newLine[writePos++] = ' ';
				++conPos;
			}

		blankCount = 0;

		while(readPos < max - 1 && line[readPos] != ' ' && line[readPos] != '\0')
		{
			if(line[readPos] == '\t') conPos += TABSPACE;
			newLine[writePos++] = line[readPos++];
		}
	}

	newLine[writePos] = '\0';
	copy(newLine, line);
}

void copy(char from[], char to[])
{
	int i = 0;
	while((to[i] == from[i]) != '\0')
		++i;
}

