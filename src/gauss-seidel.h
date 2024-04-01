double calculatesError(double *x, double *x0, int n, double max);
int gaussSeidel(double **A, double *b, double *x, int n, double tol);
double gaussSeidelResidue(double **A, double *b, double *x, int n);
