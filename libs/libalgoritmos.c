#include "libalgoritmos.h"

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
		if(A[i][j] > A[row][j])
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



// TESTS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
double *testRetroSubs()
{
	double **A;
	double *b;
	double *x;
	unsigned int n = 3;
	
	// Aloca a matriz
	A = malloc(n * sizeof(double));
	for(int i = 0; i < n; i++)
		A[i] = malloc(n * sizeof(double));

	b = malloc(n * sizeof(double));
	x = malloc(n * sizeof(double));
	
	A[0][0] = 2;
	A[0][1] = 3;
	A[0][2] = -1;
	A[1][0] = 0;
	A[1][1] = 1;
	A[1][2] = 2;
	A[2][0] = 0;
	A[2][1] = 0;
	A[2][2] = 3;
	
	b[0] = 3;
	b[1] = 1;
	b[2] = -6;

	printf("A: \n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%6.2lf ", A[i][j]);
		}
		printf(" | %6.2lf\n", b[i]);
	}
	
	printf("\nCalling RetoSubs: \n");

	retroSubs(A, b, x, n);

	for(int i = 0; i < n; i++)
		printf("X[%d]: %6.2lf\n", i+1, x[i]);
	printf("\n");
	
	//Destroy
	for(int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	free(b);

	return x;
}