#include "newton.h"

void calculeGradient(tFunc *func, double *gradient)
{
    for(int i = 0; i < func->n; i++)
    {
        gradient[i] = evaluator_evaluate(func->derivatives[i], func->n, func->names, func->values);
    }
}

void calculeHessian(tFunc *func, double **hessian)
{
    void *derivative;

    for(int i = 0; i < func->n; i++)
    {
        for(int j = 0; j < func->n; j++)
        {
            derivative = evaluator_derivative(func->derivatives[i], func->names[j]);
            hessian[i][j] = evaluator_evaluate(derivative, func->n, func->names, func->values);
        }       
    }
}

void metodoBroyden(tFunc *func, double * hessian, double * delta)
{

}

double *quasiNewton(tFunc *func, int max_iter, double epsilon, int *qntIter)
{
    return NULL;
}

double *newtonModificado(tFunc *func, int max_iter, int hess_steps, double epsilon, int *qntIter)
{
    int iter, n;
    double **hessian, *values, *delta, *gradient;
    n = func->n;

    if (!(hessian = malloc(sizeof(double) * n * n)) || !(values = malloc(sizeof(double) * max_iter)) || !(gradient = malloc(sizeof(double) * n)) || !(delta = malloc(sizeof(double) * n)))
    {
        return NULL;
    }

    for(int i = 0; i < n; i++)
        hessian[i] = malloc(sizeof(double) * n);

    iter = 0;
    while (iter < max_iter)
    {
        values[iter] = evaluator_evaluate(func->function, n, func->names, func->values);
        (*qntIter)++;
        if (iter % hess_steps == 0)
        {
            calculeHessian(func, hessian);
        }

        calculeGradient(func, gradient);
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