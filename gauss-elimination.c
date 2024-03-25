#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss-elimination.h"

/*
 * Function:  eliminacaoGauss 
 * --------------------
 *  Realiza a eliminação de Gauss em uma matriz A de ordem n
 * 
 *  A: matriz de ordem n
 *  b: vetor de ordem n
 *  n: ordem da matriz
 * 
 *  returns: void
 */
void gaussElimination(double **A, double *b, int n){
  double m;

  for(int i=0; i<n; i++){

    for(int k=i+1; k<n; k++){
      m = A[k][i]/A[i][i];
      A[k][i] = 0.0;

      for(int j=i+1; j<n; j++)
        A[k][j] -= m*A[i][j];
      b[k] -= m*b[i];
    }
  }
}

