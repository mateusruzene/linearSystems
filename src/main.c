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
    printf("Digite a linha %d da matriz A\n", i);
    for(j=0; j<n; j++){
      printf("A[%d][%d]: ", i, j);

      if(!(scanf("%lf", &A[i][j]))){
        printf("Erro na leitura da matriz A\n");
        return 1;
      }
    }
    printf("Digite o valor de b[%d]: ", i);
    if(!(scanf("%lf", &b[i]))){
      printf("Erro na leitura do vetor b\n");
      return 1;
    }
  }
  return 0;
}

int alocaMatriz(double **A, int n){
  for(int i=0;i<n;i++){
    if(!(A[i] = malloc(n*sizeof(double)))){
      printf("Erro na alocação de memória\n");
      return 1;
    }
  }
  return 0;
}

int liberaMatriz(double **A, int n){
  for(int i=0;i<n;i++)
    free(A[i]);
  return 0;
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
    printf("%lf\n", b[i]);
  }
}

int main(){

  int n;
  printf("Digite a ordem da matriz: ");
  scanf("%d", &n);

  double **A = malloc(n*sizeof(double*));
  double *b = malloc(n*sizeof(double));

  alocaMatriz(A, n);

  double **A2 = malloc(n*sizeof(double*));
  double *b2 = malloc(n*sizeof(double));

  alocaMatriz(A2, n);

  //Realiza a eliminacao de gauss clássica
  leSistemaLinear(A, b, n);
  gaussElimination(A, b, n);
  imprimeMatriz(A, n);
  imprimeVetor(b, n);

  //Realiza Gauss-Seidel clássica
  leSistemaLinear(A2, b2, n);
  gaussSeidel(A2, b2, b2, n, 1e-6, 1000);
  imprimeMatriz(A2, n);
  imprimeVetor(b2, n);

  liberaMatriz(A, n);
  liberaMatriz(A2, n);

  return 1;
}
