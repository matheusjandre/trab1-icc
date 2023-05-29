#include <stdio.h>
#include <stdlib.h>
#include "./libs/test/tests.h"
#include "./libs/algorithms.h"

// MAIN -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(int argc, char **argv)
{
	int t = 1;
	tFunc *f = almostRosenbrock(t, t, t);

	for(int i = 0; i < 3; i++)
	{
		printf("%s\n", f->func);
	}

	// testGaussElim();
	
	return 0;
}
