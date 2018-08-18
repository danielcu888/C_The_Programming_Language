/*
 * utility.c
 *
 *  Created on: Feb 24, 2012
 *      Author: danielcumberbatch
 */

#include <stdio.h>

static int daytab[2][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31},
};

int day_of_year(int y, int m, int d)
{
	if(y < 0)
	{
		printf("error: illegal arguments.\n");
		return -1;
	}
	int i, leap = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
	if(d > *(*(daytab + leap) + m))
	{
		printf("error: illegal arguments.\n");
		return -1;
	}
	for(i = 1; i < m; ++i)
		d += *(*(daytab + leap) + i);
	return d;
}

void month_day(int year, int day, int *m, int *d)
{
	if(day < 0 || day > 31 || year < 0)
	{
		printf("error: illegal arguments.\n");
		m = d = 0;
	}
	int i, leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	for(i = 1; day > *(*(daytab + leap) + i); ++i)
		day -= *(*(daytab + leap) + i);
	*m = i;
	*d = day;
}
