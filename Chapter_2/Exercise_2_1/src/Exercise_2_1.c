/*
 ============================================================================
 Name        : Exercise_2_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("signed char ranges from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char ranges from %u to %u\n", 0, UCHAR_MAX);

	printf("signed short ranges from %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short ranges from %u to %u\n", 0, USHRT_MAX);

	printf("signed int ranges from %d to %d\n", INT_MIN, INT_MAX);
	printf("unsigned int ranges from %u to %u\n", 0, UINT_MAX);

	printf("signed long ranges from %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long ranges from %lu to %lu\n", 0, ULONG_MAX);

	printf("range of float is: %e to %e\n", FLT_MIN, FLT_MAX);
	printf("range of double is: %e to %e\n", DBL_MIN, DBL_MAX);

	return 0;
}
