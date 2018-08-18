/*
 ============================================================================
 Name        : Exercise_2_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stddef.h>

enum boolean {F, T};

int any(char s1[], char s2[])
{
	enum boolean used[127];
	size_t i;
	for(i = 0; i != 127; ++i) used[i] = F;
	for(i = 0; s2[i] != '\0'; ++i) used[(int)s2[i]] = T;
	for(i = 0; s1[i] != '\0'; i++)
		if(used[(int)s1[i]] == T) return i;
	return -1;
}

int main(void)
{
	char s1[5] = {'a', 'b', 'c', 'd', '\0'};
	char s2[5] = {'f', 'i', 'g', 'd', '\0'};

	printf("%d\n", any(s1,s2));
	return 0;
}
