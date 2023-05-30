#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>
#include <matheval.h>
#include <likwid.h>
#include "./libs/test/tests.h"
#include "./libs/algorithms.h"
<<<<<<< HEAD
#include "./libs/report.h"
=======
<<<<<<< HEAD
#include "./libs/newton.h"
=======
#include "./libs/report.h"
>>>>>>> 73e26c32a7d0c1441c02b7d5d2f0fbf5d6857668
>>>>>>> 29713612f5b5e78053cc4ba98c69c7c39d651dff

// MAIN -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(int argc, char **argv)
{
	int i;
	int n = 3, k = 5, max_iter = 1000;
	int qntIter = 0;
	double *valuesModifiedNewton, *valuesQuasiNewton;
	tFunc *f = createRosenbrockFunction(n, k, 4);

	valuesModifiedNewton = newtonModificado(f, max_iter, 2, 0.0001, &qntIter);
	valuesQuasiNewton = quasiNewton(f, max_iter, 0.0001, &qntIter);

	printf("Iteração | Newton Modificado | Quasi-Newton DFP\n");
	for (i = 0; i < qntIter; i++)
	{
		printf("%8d | %17lf |\n", i, valuesModifiedNewton[i]);
	}

	return 0;
}
