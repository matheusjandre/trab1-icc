#include "tests.h"

void testGaussElim()
{
	double **A;
	double *b;
	double *x;
	unsigned int n = 3;
	
	// Aloca a matriz
	A = malloc(n * sizeof(double));
	for(int i = 0; i < n; i++)
		A[i] = malloc(n * sizeof(double));
	
	A[0][0] = 5;
	A[0][1] = 9;
	A[0][2] = 7;
	A[1][0] = 8;
	A[1][1] = 1;
	A[1][2] = 4;
	A[2][0] = 3;
	A[2][1] = 6;
	A[2][2] = 2;
	
	b = malloc(n * sizeof(double));
	
	b[0] = 11;
	b[1] = 14;
	b[2] = 9;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%6.2lf ", A[i][j]);
		}
		printf(" | %6.2lf\n", b[i]);
	}
	
	printf("Calling gauss elimination: \n");
	x = gaussElim(A, b, n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%6.2lf ", A[i][j]);
		}
		printf(" | %6.2lf\n", b[i]);
	}

	printf("Resulting vector:\n");
	for(int i = 0; i < n; i++)
		printf("x[%d] = %6.2lf\n", i+1, x[i]);
	
	//Destroy
	for(int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	free(b);
}

void testTrocaLinha()
{
	double **A;
	double *b;
	unsigned int n = 3;
	
	// Aloca a matriz
	A = malloc(n * sizeof(double));
	for(int i = 0; i < n; i++)
		A[i] = malloc(n * sizeof(double));
	
	A[0][0] = 5;
	A[0][1] = 9;
	A[0][2] = 7;
	A[1][0] = 8;
	A[1][1] = 1;
	A[1][2] = 4;
	A[2][0] = 3;
	A[2][1] = 6;
	A[2][2] = 2;
	
	b = malloc(n * sizeof(double));
	
	b[0] = 11;
	b[1] = 14;
	b[2] = 9;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%6.2lf ", A[i][j]);
		}
		printf(" | %6.2lf\n", b[i]);
	}
	
	printf("Calling shift row: \n");
	shiftRow(A, b, 0, 1, n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%6.2lf ", A[i][j]);
		}
		printf(" | %6.2lf\n", b[i]);
	}
	
	//Destroy
	for(int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	free(b);
}