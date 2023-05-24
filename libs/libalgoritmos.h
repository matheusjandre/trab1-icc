void retroSubs(double **A, double *b, double *x, unsigned int n);
void shiftRow(double **A, double *b, int l1, int l2, int n);
int maxRow(double **A, int j, int n);
double *gaussElim(double **A, double *b, unsigned int n);
double *testRetroSubs();
