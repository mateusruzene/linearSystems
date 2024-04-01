#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss-elimination.h"
#include "gauss-seidel.h"

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
      printf("A[%d][%d]: ", i, j);

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
    printf("%lf ", b[i]);
  }
}

void copiesMatrix(double **A, double **B, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      B[i][j] = A[i][j];
    }
  }
}

int main(){

  int n;
  double residue, tol;
  scanf("%d", &n);

  double **A = malloc(n*sizeof(double*));
  double **aux = malloc(n*sizeof(double*));
  double *b = malloc(n*sizeof(double));
  double *x = malloc(n*sizeof(double));

  alocaMatriz(A, n);
  leSistemaLinear(aux, b, n);

  //Realiza a eliminacao de gauss clássica com pivoteamento
  copiesMatrix(aux, A, n);
  printf("EG Clássico:\n");
  gaussElimination(A, b, x, n);
  printf("\n");
  imprimeVetor(x, n);
  residue = gaussEliminationResidue(A, b, x, n);  
  printf("Residuo: %lf\n", residue);

  //Realiza o metodo de gauss-seidel
  copiesMatrix(aux, A, n);
  printf("GS Clássico:\n");
  gaussSeidel(A, b, x, n, tol);
  printf("\n");
  imprimeVetor(x, n);
  residue = gaussSeidelResidue(A, b, x, n);

  //Realiza a eliminação de gauss em matriz tridiagonal
  copiesMatrix(aux, A, n);
  printf("EG Tridiagonal:\n");

  //Realiza o metodo de gauss-seidel em matriz tridiagonal
  copiesMatrix(aux, A, n);
  printf("GS Tridiagonal:\n");
  

  liberaMatriz(A, n);

  return 1;
}
