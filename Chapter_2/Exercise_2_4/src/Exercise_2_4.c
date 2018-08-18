/*
 ============================================================================
 Name        : Exercise_2_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[])
{

	int used[127], i, j; //Valid for ASCII character set only!
	for(i = 0; i != 127; ++i) used[i] = 0;
	for(i = 0; s2[i] != '\0'; ++i) used[(int)s2[i]] = 1;
	for(i = 0, j = 0; s1[i] != '\0'; i++)
		if(!used[(int)s1[i]])
				s1[j++] = s1[i];
	s1[j] = '\0';
}

int main(void)
{
	char s1[4] = {'a', 'b', 'c', '\0'};
	char s2[3] = {'d', 'c', '\0'};
	squeeze(s1, s2);

	printf("%s\n", s1);

	return 0;
}
