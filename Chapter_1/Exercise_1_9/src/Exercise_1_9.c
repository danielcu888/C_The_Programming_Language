/*
 ============================================================================
 Name        : Exercise_1_9.c
 Author      : D. T. Cumberbatch
 Version     :
 Copyright   : D. T. Cumberbatch 2011
 Description : Solution to Ex 1.9 of ``C The Programming Language''
 ============================================================================
 */

#include <stdio.h>

int main(int argc, char** argv)
{
  int c;
  while((c = getchar()) != EOF)
    {
	  if(c == ' ') putchar(c);
      while(c != EOF &&	c == ' ')
      {
          c = getchar();
      }
      if(c == EOF)
    	  return 0;
      else
    	  putchar(c);
    }
  return 0;
}

