#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tFunc
{
	int n;
	int k;
	char *functionString;
	double *values;
	char **variables;
} tFunc;

void retroSubs(double **A, double *b, double *x, unsigned int n);

void shiftRow(double **A, double *b, int l1, int l2, int n);

int maxRow(double **A, int j, int n);

double *gaussElim(double **A, double *b, unsigned int n);

double *testRetroSubs();

tFunc *createRosenbrockFunction(int n, int k, double x);

#endif