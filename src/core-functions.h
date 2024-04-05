int leSistemaLinear(double **A, double *b, int n);
int alocaMatriz(double **A, int n);
void liberaMatriz(double **A, int n);
void imprimeMatriz(double **A, int n);
void imprimeVetor(double *b, int n);
void copiesMatrix(double **A, double **B, int n);
void copiesVector(double *a, double *b, int n);
void copiesLinearSystem(double **A, double **aux, double *b, double *bux, int n);
void copies3dLinearSystem(double** aux, double *a, double *c, double *d, double *b, double *bux, int n);
double* CalculatesResidual(double **A, double *b, double *x, double* residual, int n);
double* CalculatesResidual3d(double *d, double *a, double *c, double *b, double *x, double* residual, int n);
void initVector(double *v, int n);
void freeAll(double **A, double *b, double **aux, double *bux, double *a, double *c, double *d, double *x, int n);
