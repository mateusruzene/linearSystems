#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function:  gaussSeidel
 * --------------------
 *  Resolve um sistema linear utilizando o método de Gauss-Seidel
 */
int gaussSeidel(double**A, double *b, double *x, int n, double tol, int maxIter){
  int i, j;
  double *x0;
  double sum;
  double diff;
  int iter;

  if(!(x0 = malloc(n*sizeof(double)))){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  for(i=0; i<n; i++)
    x0[i] = x[i];

  for(iter=0; iter<maxIter; iter++){
    for(i=0; i<n; i++){
      sum = 0.0;
      for(j=0; j<n; j++){
        if(j!=i)
          sum += A[i][j]*x[j];
      }
      x[i] = (b[i] - sum)/A[i][i];
    }

    diff = 0.0;
    for(i=0; i<n; i++)
      diff += fabs(x[i] - x0[i]);

    if(diff < tol){
      free(x0);
      return 0;
    }

    for(i=0; i<n; i++)
      x0[i] = x[i];
  }

  free(x0);
  return 1;

}
