/* Bruno Crestani GRR:20221240 - Mateus Ruzene GRR:20221223 */
#ifndef __GAUSS_SEIDEL__
#define __GAUSS_SEIDEL__

double calculatesError(double *x, double *x0, int n, double max);
int gaussSeidel(double **A, double *b, double *x, int n, double tol, int *iter);
void gaussSeidel3d(double *d, double *a, double *c, double *b, double *x, int n, double tol, int *iter);

#endif // __GAUSS_SEIDEL__