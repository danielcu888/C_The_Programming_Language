/*
 ============================================================================
 Name        : Exercise_2_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char hexNum[])
{
	int i = ((hexNum[0] == '0' && hexNum[1] == 'x') || (hexNum[0] == '0' && hexNum[1] == 'X')) ? 2 : 0;
	int n = 0;
	for(; i != strlen(hexNum); ++i)
	{
		n *= 10;
		if(isdigit(hexNum[i]))
			n += hexNum[i] - '0';
		else if(hexNum[i] >= 'a' && hexNum[i] <= 'f')
			n += hexNum[i] - 'a' + 10;
		else if(hexNum[i] >= 'A' && hexNum[i] <= 'F')
			n += hexNum[i] - 'A' + 10;
		else
		{
			printf("Error: Invalid Character!\n" );
			return -1;
		}
	}
	return n;
}

int main(void)
{
	printf("%d\n", htoi("0x7f"));
	return 0;
}
