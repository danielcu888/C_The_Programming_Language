//============================================================================
// Name        : Exercise_1_22.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int MAXLINE = 1024;
const int N = 10;
const int TABSPACES = 4;

int getLine(char[], int);
void wrap(char[], int, int);
void copy(char[], char[], int, int);

int main(int argc, char **argv)
{
	char line[MAXLINE];
	int len;
	while((len = getLine(line, MAXLINE)) > 0)
		wrap(line, MAXLINE, N);
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

void copy(char from[], char to[], int beg, int end)
{
	int i, j;
	for(i = beg, j = 0; i != end; ++i, ++j)
		to[j] = from[i];
	to[j] = '\0';
}

void wrap(char line[], int max, int n)
{
	if(max < n || max < 1 || n < 1)
	{
		printf("Invalid arguments!");
		return;
	}

	int readPos = 0, lineBegPos = 0, lineEndPos = 0, conPos = 0;
	char tmp[max];

	while(readPos < max - 1 && line[readPos] != '\0')
	{
		while(readPos < max - 1 && conPos < n && line[readPos] != '\0')
		{
			if(line[readPos++] == '\t')
				conPos += TABSPACES; //**
			else
				++conPos;
		}

		if(readPos == max - 1)
		{
			copy(line, tmp, lineBegPos, readPos);
			printf("%s\n", tmp);
			return;
		}
		else if(line[readPos] == '\0')
		{
			copy(line, tmp, lineBegPos, readPos);
			printf("%s\n", tmp);
			return;
		}
		else //i.e., conPos >= n
		{
			lineEndPos = readPos;
			while(lineEndPos > 0 && line[lineEndPos] != ' ' && line[lineEndPos] != '\t')
				--lineEndPos;
			if(lineEndPos <= lineBegPos)
			{
				lineEndPos = readPos;
				while(conPos >= n)
				{
					if(line[lineEndPos--] == '\t') conPos -= TABSPACES; //**
					else --conPos;
				}
			}

			++lineEndPos;
			readPos = lineEndPos;

			copy(line, tmp, lineBegPos, lineEndPos);
			printf("%s\n", tmp);

			lineBegPos = readPos;
			conPos = 0;
		}
	}
}
