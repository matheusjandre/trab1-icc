#include <string.h>
#include "algorithms.h"
#include "math.h"
// ALGORITHMS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

/*Seja um S.L. de ordem 'n'*/
void retroSubs(double **A, double *b, double *x, unsigned int n)
{
	for(int i = n-1; i >= 0; --i)
	{
		x[i] = b[i];
		for(int j = i+1; j < n; ++j)
			x[i] -= A[i][j] * x[j];
		x[i] /= A[i][i];
	}
}

/** Troca duas linhas de um sistema linear*/
void shiftRow(double **A, double *b, int l1, int l2, int n)
{
	double temp = 0.0;

	for(int j = 0; j < n; j++)
	{
		temp = A[l1][j];
		A[l1][j] = A[l2][j];
		A[l2][j] = temp;
	}

	temp = b[l1];
	b[l1] = b[l2];
	b[l2] = temp;
}

/** Retorna o indice da linha com o maior valor da coluna*/
int maxRow(double **A, int j, int n)
{
	int row = j;

	for(int i = j+1; i < n; i++)
		if(fabs(A[i][j]) > fabs(A[row][j]))
			row = i;
		
	return row;
}

/*Seja um S.L. de ordem 'n'*/
double *gaussElim(double **A, double *b, unsigned int n)
{
	unsigned int pivot;
	double m;
	double *x;

	x = malloc(sizeof(double)*n);

	for(int i = 0; i < n; ++i)
	{
		pivot = maxRow(A, i, n);
		if(i != pivot) 
			shiftRow(A, b, i, pivot, n);

		for(int k = i+1; k < n; ++k)
		{
			m = A[k][i] / A[i][i];
			A[k][i] = 0.0;
			for(int j = i+1; j < n; ++j)
				A[k][j] -= A[i][j] * m;
			b[k] -= b[i] * m;
		}
	}

	retroSubs(A, b, x, n);

	return x;
}

tFunc *almostRosenbrock(int n, int k, int x)
{
	

	return f;
}