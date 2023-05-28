#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>
#include "./libs/algorithms.h"
#include "./libs/report.h"

double * initializeVariablesArray(int n, double x)
{
	double * array;

	if(!(array=(malloc(sizeof(double) * n)))) 
	{
		return NULL;
	}

	for(int i = 0; i < n; i++) 
	{
		array[i] = x;
	}

	return array;
}

// MAIN -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(int argc, char **argv)
{	
	int n, k, max_iter, hess_steps;
	double x, epsilon;

	scanf("%d %d %ld %ld %d %d", n, k, x, epsilon, max_iter, hess_steps);
	
	LIKWID_MARKER_INIT;



	LIKWID_MARKER_CLOSE;

	return 0;
}
