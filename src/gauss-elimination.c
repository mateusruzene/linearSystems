#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss-elimination.h"

/*
 * is used to prevent the pivot element from being zero
 * so a division by zero does not occur
 */
void lineSwap(double **A, double *b, int n, int i){
  int max = i;
  for(int j=i+1; j<n; j++){
    //Comparison between absolute values
    if(fabs(A[j][i]) > fabs(A[max][i]))
      max = j;
  }
  if(max != i){
    //creating a copy of the line about to be swapped
    double *aux = A[i];

    for(int j=0; j<n; j++){
      //swapping lines
      A[i][j] = A[max][j];
      A[max][j] = aux[j];
    }
    
    //swapping b values
    double aux2 = b[i];
    b[i] = b[max];
    b[max] = aux2;
  }
}

/*
 *  A: matrix of n elements
 *  b: array of n elements
 *  n: matrix order
 *  x: result array of n elements
 */
void gaussElimination(double **A, double *b, double *x, int n){
  double m;

  //0 --> n-1 loops
  for(int i=0; i<n; i++){
    lineSwap(A, b, n, i);

    //n - (i + 1) loops
    for(int k=i+1; k<n; k++){
      //1 division
      m = A[k][i]/A[i][i];
      A[k][i] = 0.0;

      //n - (i + 1) subtractions
      //n - (i + 1) products
      for(int j=i+1; j<n; j++)
        A[k][j] -= m*A[i][j];
      //1 subtraction and 1 product
      b[k] -= m*b[i];
    }
    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
      x[i] = b[i];
      for (int j = i + 1; j < n; j++) {
        x[i] -= A[i][j] * x[j];
      }
      x[i] /= A[i][i];
    }
  }
}

// (n - i - 1) * (2n - 2i + 1)
// SOMATORIO EM QUE I=0 ATE N-1 DE (2i^2 + i - 4ni + 2n^2 - n - 1)
//
// 2n^3 + n^2/2 - 7n/6 FLOPs


void gaussElimination3d(double *d, double *a, double*c, double*b, double *x, int n){
  double m;

  //0 --> n-1 loops
  for(int i=0; i<n; i++){

      //1 division
      m = a[i]/d[i];
      a[i] = 0.0;
      
      //(1 subtraction and 1 product) * 2
      d[i+1] -= m*c[i];
      b[i+1] -= m*b[i];
    }

  // Back substitution
  x[n-1] = b[n-1] / d[n-1];
  for (int i =n-2; i>0; i--) {
    x[i] = (b[i] - c[i] * x[i+1]) / d[i];
  }
}
