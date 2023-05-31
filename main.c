#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>
#include <matheval.h>
#include "./libs/algorithms.h"
#include "./libs/report.h"
#include "./libs/newton.h"

// MAIN -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(int argc, char **argv)
{
	int i;
	int n = 5, k = 5, max_iter = 10;
	int qntIter = 0;
	double *valuesModifiedNewton, *valuesQuasiNewton;
	tFunc *f = createRosenbrockFunction(n, k, 2);

	valuesModifiedNewton = newtonModificado(f, max_iter, 2, 1e-30, &qntIter);
	/*valuesQuasiNewton = quasiNewton(f, max_iter, 1e-30, &qntIter);*/

	printf("Iteração | Newton Modificado | Quasi-Newton DFP\n");
	for (i = 0; i < qntIter; i++)
	{
		printf("%8d | %.10e |\n", i, valuesModifiedNewton[i]);
	}

	return 0;
}
