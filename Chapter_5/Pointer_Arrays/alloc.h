/*
 * alloc.h
 *
 *  Created on: Feb 22, 2012
 *      Author: danielcumberbatch
 */

#ifndef ALLOC_H_
#define ALLOC_H_

const int ALLOCSIZE = 1000;

static char *allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int);
void afree(char*);

#endif /* ALLOC_H_ */
