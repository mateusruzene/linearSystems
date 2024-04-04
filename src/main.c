#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss-elimination.h"
#include "gauss-seidel.h"
//#include <likwid.h>

#include "utils.h"

/*
 * Function:  leSistemaLinear  
 * ---------------------------
 *  Lê a matriz A e o vetor b no formato:
 *  A[0][0] A[0][1] ... A[0][n-1] b[0]
 *  
 * 
 *  A: matriz de ordem n
 *  n: ordem da matriz
 * 
 *  returns: 0 se a leitura foi bem sucedida, 1 caso contrário
 */
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

/*
 * Residuo é o quão distante a solução encontrada está da solução "exata"
 */
double* CalculatesResidual(double **A, double *b, double *x, int n){
  double* residue = (double*)malloc(n*sizeof(double));
  double sum;

  for(int i=0; i<n; i++){
    sum = 0.0;

    for(int j=0; j<n; j++)
      sum += A[i][j]*x[j];

    residue[i] += fabs(b[i] - sum);
  }

  return residue;
}

int isTridiagonal(double **A, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i!=j && i!=j+1 && i!=j-1 && A[i][j] != 0)
        return 0;
    }
  }
  return 1;
}

int main(){

  int n;
  double tol;
  scanf("%d", &n);

  double **A = malloc(n*sizeof(double*));
  double **aux = malloc(n*sizeof(double*));
  double *b = malloc(n*sizeof(double));
  double *x = malloc(n*sizeof(double));

  alocaMatriz(A, n);
  alocaMatriz(aux, n);
  leSistemaLinear(aux, b, n);

  //Realiza a eliminacao de gauss clássica com pivoteamento
  copiesMatrix(aux, A, n);
  printf("EG Clássico:\n");
  gaussElimination(A, b, x, n);
  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(A, b, x, n), n);

  //Realiza o metodo de gauss-seidel
  copiesMatrix(aux, A, n);
  printf("GS Clássico:\n");
  gaussSeidel(A, b, x, n, tol);
  imprimeVetor(x, n);
 
  imprimeVetor(CalculatesResidual(A, b, x, n), n);

  double *a = malloc((n-1)*sizeof(double));
  double *c = malloc((n-1)*sizeof(double));
  double *d = malloc(n*sizeof(double));

  for(int i=0; i<n; i++){
    d[i] = A[i][i];
    if(i<n-1)
      c[i] = A[i][i+1];
    if(i>0)
      a[i-1] = A[i][i-1];
  }

  //Realiza a eliminação de gauss em matriz tridiagonal
  copiesMatrix(aux, A, n);
  printf("EG Tridiagonal:\n");
  gaussElimination3d(d, a, c, b, x, n);

  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(A, b, x, n), n);

  //Realiza o metodo de gauss-seidel em matriz tridiagonal
  copiesMatrix(aux, A, n);
  printf("GS Tridiagonal:\n");
  gaussSeidel3d(d, a, c, b, x, n);
  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(A, b, x, n), n);
  
  liberaMatriz(A, n);
  liberaMatriz(aux, n);
  free(b);
  free(x);
  free(a);

  return 1;
}
