/* Bruno Crestani GRR:20221240 - Mateus Ruzene GRR:20221223 */
#ifndef __CORE_FUNCTIONS__
#define __CORE_FUNCTIONS__

int readLinearSystem(double **A, double *b, int n);
int allocateMatrix(double **A, int n);
void freeMatrix(double **A, int n);
void printMatrix(double **A, int n);
void printVector(double *b, int n);
void copiesMatrix(double **A, double **B, int n);
void copiesVector(double *a, double *b, int n);
void copiesLinearSystem(double **A, double **aux, double *b, double *bux, int n);
void copies3dLinearSystem(double **aux, double *a, double *c, double *d, double *b, double *bux, int n);
double *CalculatesResidual(double **A, double *b, double *x, double *residual, int n);
double *CalculatesResidual3d(double *d, double *a, double *c, double *b, double *x, double *residual, int n);
void initVector(double *v, int n);
void freeAll(double **A, double *b, double **aux, double *bux, double *a, double *c, double *d, double *x, int n);

#endif // __CORE_FUNCTIONS__