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
 *  n: ordem da matriz
 */
void gaussElimination(double **A, double *b, int n){
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
  }
}

// (n - i - 1) * (2n - 2i + 1)
// SOMATORIO EM QUE I=0 ATE N-1 DE (2i^2 + i - 4ni + 2n^2 - n - 1)
//
// 2n^3 + n^2/2 - 7n/6 FLOPs


/*
 * Residuo é o quão distante a solução encontrada está da solução "exata"
 */
double calculateResidue(double **A, double *b, double *x, int n){
}
