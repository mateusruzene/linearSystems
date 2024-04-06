/* Bruno Crestani GRR:20221240 - Mateus Ruzene GRR:20221223 */
#ifndef __GAUSS_ELIMINATION__
#define __GAUSS_ELIMINATION__

void lineSwap(double **A, double *b, int n, int i);
void gaussElimination(double **A, double *b, double *x, int n);
void gaussElimination3d(double *d, double *a, double *c, double *b, double *x, int n);

#endif // __GAUSS_ELIMINATION__