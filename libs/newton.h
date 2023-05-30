#ifndef _NEWTON_H_
#define _NEWTON_H_

#include <stdio.h>
#include <matheval.h>
#include <math.h>
#include "algorithms.h"

double * newtonModificado(tFunc * func, int max_iter, int hess_steps, double epsilon, int *qntIter);
double * quasiNewton(tFunc *func, int max_iter, int hess_steps, double epsilon, int *qntIter);

#endif