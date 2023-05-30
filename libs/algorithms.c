#include <string.h>
#include <math.h>

#include "algorithms.h"
// ALGORITHMS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

/*Seja um S.L. de ordem 'n'*/
void retroSubs(double **A, double *b, double *x, unsigned int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		x[i] = b[i];
		for (int j = i + 1; j < n; ++j)
			x[i] -= A[i][j] * x[j];
		x[i] /= A[i][i];
	}
}

/** Troca duas linhas de um sistema linear*/
void shiftRow(double **A, double *b, int l1, int l2, int n)
{
	double temp = 0.0;

	for (int j = 0; j < n; j++)
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

	for (int i = j + 1; i < n; i++)
		if (fabs(A[i][j]) > fabs(A[row][j]))
			row = i;

	return row;
}

/*Seja um S.L. de ordem 'n'*/
double *gaussElim(double **A, double *b, unsigned int n)
{
	unsigned int pivot;
	double m;
	double *x;

	x = malloc(sizeof(double) * n);

	for (int i = 0; i < n; ++i)
	{
		pivot = maxRow(A, i, n);
		if (i != pivot)
			shiftRow(A, b, i, pivot, n);

		for (int k = i + 1; k < n; ++k)
		{
			m = A[k][i] / A[i][i];
			A[k][i] = 0.0;
			for (int j = i + 1; j < n; ++j)
				A[k][j] -= A[i][j] * m;
			b[k] -= b[i] * m;
		}
	}

	retroSubs(A, b, x, n);

	return x;
}

char *genVarStr(int i)
{
	char *variable;
	int size = 16;

	if (!(variable = malloc(sizeof(char) * size)))
		return NULL;

	snprintf(variable, size, "x%d", i);

	return variable;
}

char *genPowStr(int i)
{
	char *pow;

	if (!(pow = malloc(sizeof(char) * 12)))
	{
		return NULL;
	}

	snprintf(pow, 12, "^%d", i);

	return pow;
}

char *createFunctionString(int n, int k)
{
	char *function;
	function = malloc(sizeof(char) * 1024);
	int max_i, max_j;

	max_i = n - floor(k / 2);
	max_j = floor(k / 2);

	for (int i = 1; i <= max_i; i++)
	{
		strcat(function, "(");
		strcat(function, genVarStr(i));
		strcat(function, "-(");

		for (int j = 1; j <= max_j; j++)
		{
			strcat(function, genVarStr(i + j));
			strcat(function, genPowStr(j));

			if (j < max_j)
				strcat(function, "+");
			else
				strcat(function, ")");
		}

		strcat(function, ")");
		strcat(function, "^2");

		if (i < max_i)
			strcat(function, "+");
	}

	return function;
}

double normalArray(double * array, int n)
{
	int index;
	double normal;

	for(index = 0; index < n; index++)
	{
		if(array[index] > normal)
			normal = array[index];
	}

	return normal;
}

tFunc *createRosenbrockFunction(int n, int k, double x)
{
	tFunc *func;

	if (!(func = malloc(sizeof(tFunc))))
		return NULL;

	func->values = malloc(sizeof(double) * n);
	func->n = n;
	func->k = k;

	for (int i = 0; i < n; i++)
	{
		func->values[i] = x;
	}

	func->functionString = createFunctionString(n, k);

	return func;
}