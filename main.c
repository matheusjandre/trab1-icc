#include <stdio.h>
#include <stdlib.h>
#include <matheval.h>
#include "./libs/test/tests.h"
#include "./libs/algorithms.h"

// MAIN -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(int argc, char **argv)
{
	void *function;
	char **names;
	int count;
	int n = 3, k = 5;
	double result;
	tFunc *f = createRosenbrockFunction(n, k, 4);

	printf("%s\n", f->functionString);

	for (int i = 0; i < n; i++)
	{
		printf("%lf\n", f->values[i]);
	}

	function = evaluator_create(f->functionString);

	evaluator_get_variables(function, &names, &count);
	printf("\n");
	for (int i = 0; i < count; i++)
		printf("%s ", names[i]);
	printf("\n");

	result = evaluator_evaluate(function, n, names, f->values);

	printf("RESULTADO DESSA PORRA DO CARAI: %lf\n", result);

	return 0;
}
