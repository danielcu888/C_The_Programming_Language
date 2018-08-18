/*
 ============================================================================
 Name        : Exercise_3_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <time.h>
#include <math.h>

int binarySearch(int v[], size_t n, int x)
{
	if(n == 0 || x > v[n-1] || x < v[0]) return -1;

	int start = 0, end = n-1, mid;
	while(start <= end)
	{
		mid = (start + end)/2;
		if(x > v[mid])
			start = mid + 1;
		else if(x < v[mid])
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

int binarySearch2(int v[], size_t n, int x)
{
	if(n == 0 || x > v[n-1] || x < v[0]) return -1;

	int start = 0, end = n-1, mid;
	do {
		mid = (start + end)/2;
		if(x > v[mid])
			start = mid + 1;
		else
			end = mid - 1;
	} while(x != v[mid] && start <= end);
	if(x == v[mid]) return mid;

	return -1;
}

int main()
{
	int v[10] = {0,1,3,6,8,12,45,67,90,101};

	time_t start, end;
	double dif1, dif2;
	time(&start);
	printf("%d\n", binarySearch(v, 10, 3));
	time(&end);
	dif1 = difftime(start, end);
	time(&start);
	printf("%d\n", binarySearch2(v, 10, 3));
	time(&end);
	dif2 = difftime(start, end);

	printf("t(b2) = %.18e\n", (dif1 - dif2)*pow(10.0, 100)); //no discernable difference

	return 0;
}
