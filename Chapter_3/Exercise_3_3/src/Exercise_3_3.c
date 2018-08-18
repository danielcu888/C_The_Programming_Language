/*
 ============================================================================
 Name        : Exercise_3_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

const int MAXLINE = 1024;

enum SIGN {NEG = -1, POS = 1};

int myAtoi(char s[], int lim)
{
	int i = 0, n = 0;
	enum SIGN sign;

	while(i < lim - 1 && isspace(s[i++]))
		;
	sign = s[i] == '-' ? NEG : POS;
	if(s[i] == '+' || s[i] == '-')
		++i;
	while(i < lim - 1 && isdigit(s[i]))
		n = n*10 + (s[i++] - '0');
	return n * sign;
}

// shellsort: sort v[0]...v[n-1] into increasing order
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; ++i)
			for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				{
					temp = v[j];
					v[j] = v[j + gap];
					v[j+gap] = temp;
				}
}

void reverse(char s[])
{
	size_t beg, end;
	for(beg = 0, end = strlen(s) - 1; beg < end; ++beg, --end)
	{
		char tmp = s[beg];
		s[beg] = s[end];
		s[end] = tmp;
	}
}

int getLine(char s[], int lim)
{
	int i = 0, c;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void copy(char from[], char to[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

void expand(char s[], char t[], int lim)
{
	if(strlen(s) < 3) return;
	int readPos = 0, writePos = 0, acBeg, acEnd;

	while(readPos < strlen(s) && writePos < lim - 1)
	{
		if(readPos >= strlen(s) - 2)
			t[writePos++] = s[readPos++];
		else
		{
			if(s[readPos + 1] != '-')
				t[writePos++] = s[readPos++];
			else if(s[readPos + 1] == '-')
			{
				if((s[readPos] >= 'a' && s[readPos] <= 'z' && s[readPos + 2] >= 'a' && s[readPos + 2] <= 'z' && s[readPos] < s[readPos + 2]) ||
				   (isdigit(s[readPos]) && isdigit(s[readPos + 2]) && s[readPos] < s[readPos + 2]))
				{
					acBeg = s[readPos]; acEnd = s[readPos + 2];
					while(acBeg < acEnd && writePos != lim - 1)
						t[writePos++] = acBeg++;
					readPos += 2;
				}
				else
				{
					t[writePos++] = s[readPos++];
					t[writePos++] = s[readPos++];
				}
			}
		}
	}
	t[writePos] = '\0';
}


int main()
{
	char s[MAXLINE];
	char t[MAXLINE];
	int len;
	while((len = getLine(s, MAXLINE)) > 0)
	{
		expand(s, t, MAXLINE);
		printf("%s\n", t);
	}

	return 0;
}
