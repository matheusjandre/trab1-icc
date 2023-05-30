#include "newton.h"

void calcularHessiana(tFunc *func, double *hessiane)
{
    int iter;
    void **derivatives;
    void *function;
    char **names;

    if (!(derivatives = malloc(sizeof(void) * func->n)))
    {
        return;
    }

    function = evaluator_create(func->functionString);
    evaluator_get_variables(function, &names, &func->n);

    for (iter = 0; iter < func->n; iter++)
    {
        derivatives[iter] = evaluator_derivative(function, names[iter]);
        hessiane[iter] = evaluator_evaluate(derivatives[iter], func->n, names, func->values);
    }
}

void metodoBroyden(tFunc func, double * hessiane, double * delta)
{

}

double *quasiNewton(tFunc *func, int max_iter, double epsilon, int *qntIter)
{
    int iter, n;
    double *hessiane, *values, *delta;
    void *function;
    char **names;
    n = func->n;

    if (!(hessiane = malloc(sizeof(double) * n)) || !(values = malloc(sizeof(double) * max_iter)) || !(delta = malloc(sizeof(double) * n)))
    {
        return NULL;
    }

    function = evaluator_create(func->functionString);
    evaluator_get_variables(function, &names, &n);

    iter = 0;
    while (iter < max_iter)
    {
        (*qntIter)++;

        values[iter] = evaluator_evaluate(function, n, names, func->values);

        if (fabs(values[iter]) < epsilon)
        {
            return values;
        }

        for (int j = 0; j < n; j++)
        {
            delta[j] = -fabs(values[iter]) / hessiane[j];
            func->values[j] = func->values[j] + delta[j];
        }

        if (normalArray(delta, n) < epsilon)
        {
            return values;
        }

        metodoBroyden(func, hessiane, delta);
        iter++;
    }

    free(hessiane);

    return values;
}

double *newtonModificado(tFunc *func, int max_iter, int hess_steps, double epsilon, int *qntIter)
{
    int iter, n;
    double *hessiane, *values, *delta;
    void *function;
    char **names;
    n = func->n;

    if (!(hessiane = malloc(sizeof(double) * n)) || !(values = malloc(sizeof(double) * max_iter)) || !(delta = malloc(sizeof(double) * n)))
    {
        return NULL;
    }

    function = evaluator_create(func->functionString);
    evaluator_get_variables(function, &names, &n);

    iter = 0;
    while (iter < max_iter)
    {
        (*qntIter)++;
        if (iter % hess_steps == 0)
        {
            calcularHessiana(func, hessiane);
        }

        values[iter] = evaluator_evaluate(function, n, names, func->values);

        if (fabs(values[iter]) < epsilon)
        {
            return values;
        }

        for (int j = 0; j < n; j++)
        {
            delta[j] = -fabs(values[iter]) / hessiane[j];
            func->values[j] = func->values[j] + delta[j];
        }

        if (normalArray(delta, n) < epsilon)
        {
            return values;
        }

        iter++;
    }

    free(hessiane);

    return values;
}