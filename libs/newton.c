#include "newton.h"

void calculeGradiente(tFunc *func, void * function, double *gradient)
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
        gradient[iter] = evaluator_evaluate(derivatives[iter], func->n, names, func->values);
    }

    free(derivatives);
    free(names);
    free(function);
}

void calculeDerivatives(tFunc *func, double *gradient, double **hessian)
{
    void * derivative;
    void *function;
    char **names;

    function = evaluator_create(func->functionString);
    evaluator_get_variables(function, &names, &func->n);

    for(int i = 0; i < func->n; i++)
    {
        derivative = evaluator_derivative(function, names[i]);
        gradient[i] = evaluator_evaluate(derivative, func->n, names, func->values);
        for(int j = 0; j < func->n; j++)
        {
            hessian[i][j] = evaluator_evaluate(evaluator_derivative(derivative, names[j]), func->n, names, func->values);
        }       
    }
}

void metodoBroyden(tFunc *func, double * hessian, double * delta)
{

}

double *quasiNewton(tFunc *func, int max_iter, double epsilon, int *qntIter)
{
    int iter, n;
    double *hessian, *values, *delta;
    void *function;
    char **names;
    n = func->n;

    if (!(hessian = malloc(sizeof(double) * n * n)) || !(values = malloc(sizeof(double) * max_iter)) || !(delta = malloc(sizeof(double) * n)))
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
            delta[j] = -fabs(values[iter]) / hessian[j];
            func->values[j] = func->values[j] + delta[j];
        }

        if (normalArray(delta, n) < epsilon)
        {
            return values;
        }

        metodoBroyden(func, hessian, delta);
        iter++;
    }

    free(hessian);

    return values;
}

double *newtonModificado(tFunc *func, int max_iter, int hess_steps, double epsilon, int *qntIter)
{
    int iter, n;
    double **hessian, *values, *delta, *gradient;
    void *function;
    char **names;
    n = func->n;

    if (!(hessian = malloc(sizeof(double) * n * n)) || !(values = malloc(sizeof(double) * max_iter)) || !(gradient = malloc(sizeof(double) * n)) || !(delta = malloc(sizeof(double) * n)))
    {
        return NULL;
    }

    for(int i = 0; i < n; i++)
        hessian[i] = malloc(sizeof(double) * n);

    function = evaluator_create(func->functionString);
    evaluator_get_variables(function, &names, &n);

    iter = 0;
    while (iter < max_iter)
    {
        (*qntIter)++;
        if (iter % hess_steps == 0)
        {
        }

        calculeDerivatives(func, gradient, hessian);
        values[iter] = evaluator_evaluate(function, n, names, func->values);
        delta = gaussElim(hessian, gradient, n);
        
        if (fabs(values[iter]) < epsilon)
        {
            return values;
        }

        for (int j = 0; j < n; j++)
        {
            func->values[j] = func->values[j] + delta[j];
        }

        if (normalArray(delta, n) < epsilon)
        {
            return values;
        }

        iter++;
    }

    free(hessian);

    return values;
}