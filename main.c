#include <stdio.h>
#include <stdlib.h>
#include "./libs/test/tests.h"
#include "./libs/algorithms.h"

// MAIN -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(int argc, char **argv)
{
	int t = 4;
	tFunc *f = createRosenbrockFunction(t, t, 1.2);

	printf("%s\n", f->functionString);

	for(int i = 0; i < t; i++)
	{
		printf("%s = %lf\n", f->variables[i], f->values[i]);
	}
	// testGaussElim();
	
	return 0;
}
