#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculatesError(double *x, double *x0, int n, double max){
  for(int i=0;i<n;i++){
    if(fabs(x[i] - x0[i]) > max)
      max = fabs(x[i] - x0[i]);
  }
  return max;
}
/* Function:  gaussSeidel
 * --------------------
 *  Resolve um sistema linear utilizando o método de Gauss-Seidel
 */
int gaussSeidel(double**A, double *b, double *x, int n, double tol){
  int j;
  double error = 1.0 + tol;
  double *x0, sum;
  double max = 0.0;
  int iter;

  if(!(x0 = malloc(n*sizeof(double)))){
    printf("Erro na alocação de memória\n");
    return 0;
  }

  for(int i=0; i<n; i++)
    x0[i] = x[i];

  while(error < tol){
    for(int i=0; i<n; i++){
      sum = 0.0;
      for(j=0; j<n; j++){
        if(j!=i) sum += A[i][j]*x[j];
      }
      x[i] = (b[i] - sum)/A[i][i];
    }

    max = calculatesError(x, x0, n, max);

    if(max < tol){
      free(x0);
      return 1;
    }

    for(int i=0; i<n; i++)
      x0[i] = x[i];
  }

  free(x0);
  return 1;

}

int gaussSeidel3d(double*d, double *a, double* c, double *b, double *x, int n, double tol){
  double error = 1.0 + tol;
  double *x0, sum;
  double max = 0.0;

  if(!(x0 = malloc(n*sizeof(double)))){
    printf("Erro na alocação de memória\n");
    return 0;
  }

  for(int i=0; i<n; i++)
    x0[i] = x[i];

  while(error < tol){
    x[0] = (b[0] - c[0]*x[1])/d[0];

    for(int i=0; i<n; i++){
      x[i] = (b[i] - a[i-1] * x[i-1] - c[i] * x[i+1])/d[i];
    }

    x[n-1] = (b[n-1] - a[n-1]*x[n-2])/d[n-1];

    max = calculatesError(x, x0, n, max);

    if(max < tol){
      free(x0);
      return 1;
    }

    for(int i=0; i<n; i++)
      x0[i] = x[i];
  }

  free(x0);
  return 1;

}

