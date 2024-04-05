#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss-elimination.h"
#include "gauss-seidel.h"
#include "core-functions.h"
//#include <likwid.h>

#include "utils.h"

int leSistemaLinear(double **A, double *b, int n){
  int i, j;

  for (i=0;i<n; i++){
    for(j=0; j<n; j++){

      if(!(scanf("%lf", &A[i][j]))){
        printf("Erro na leitura da matriz A\n");
        return 0;
      }
    }
    if(!(scanf("%lf", &b[i]))){
      printf("Erro na leitura do vetor b\n");
      return 0;
    }
  }
  return 1;
}

int alocaMatriz(double **A, int n){
  for(int i=0;i<n;i++){
    if(!(A[i] = malloc(n*sizeof(double)))){
      printf("Erro na alocação de memória\n");
      return 0;
    }
  }
  return 1;
}

void liberaMatriz(double **A, int n){
  for(int i=0;i<n;i++)
    free(A[i]);
}

void imprimeMatriz(double **A, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%lf ", A[i][j]);
    }
    printf("\n");
  }
} 

void imprimeVetor(double *b, int n){
  for(int i=0; i<n; i++){
    printf("%.12f ", b[i]);
  }
  printf("\n");
}

void copiesMatrix(double **A, double **B, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      B[i][j] = A[i][j];
    }
  }
}

void copiesVector(double *a, double *b, int n){
  for(int i=0; i<n; i++){
    b[i] = a[i];
  }
}

void copiesLinearSystem(double **A, double **aux, double *b, double *bux, int n){
  copiesMatrix(aux, A, n);
  copiesVector(bux, b, n);
}

void copies3dLinearSystem(double** aux, double *a, double *c, double *d, double *b, double *bux, int n){

  for(int i=0; i<n; i++){
    d[i] = aux[i][i];
    if(i<n-1)
      c[i] = aux[i][i+1];
    if(i>0)
      a[i-1] = aux[i][i-1];
 }
  copiesVector(bux, b, n);
}

/*
 * Residuo é o quão distante a solução encontrada está da solução "exata"
 */
double* CalculatesResidual(double **A, double *b, double *x, double* residue, int n){
  double sum;

  for(int i=0; i<n; i++){
    sum = 0.0;

    for(int j=0; j<n; j++)
      sum += A[i][j]*x[j];

    residue[i] = fabs(b[i] - sum);
  }

  return residue;
}

double* CalculatesResidual3d(double *d, double *a, double *c, double *b, double *x, double* residual, int n){
  for(int i=0; i<n; i++){
    residual[i] = b[i] - d[i]*x[i];

    if(i>0) residual[i] += a[i]*x[i-1];
    if(i<n-1) residual[i] += c[i]*x[i+1];

  }

  return residual;
}

void initVector(double *v, int n){
  for(int i=0; i<n; i++)
    v[i] = 0.0;
}

void freeAll(double **A, double *b, double **aux, double *bux, double *a, double *c, double *d, double *x, int n){
  liberaMatriz(A, n);
  liberaMatriz(aux, n);
  free(b);
  free(bux);
  free(a);
  free(c);
  free(d);
  free(x);
}
