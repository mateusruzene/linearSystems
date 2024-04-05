#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "core-functions.h"
#include "gauss-elimination.h"
#include "gauss-seidel.h"
//#include <likwid.h>

#include "utils.h"

int main(){

  int n;
  int iter = 0;
  scanf("%d", &n);
  
  double tempo;

  //Aloca um espaço para o sistema linear
  double **A = malloc(n*sizeof(double*));
  double *b = malloc(n*sizeof(double));

  //declara uma matriz e um vetor auxiliares para a leitura do sistema linear
  double **aux = malloc(n*sizeof(double*));
  double *bux = malloc(n*sizeof(double));

  //Aloca espaço para as matrizes
  alocaMatriz(A, n);
  alocaMatriz(aux, n);

  //Le o sistema linear para os auxiliares
  leSistemaLinear(aux, bux, n);

  //Aloca espaço para os vetores da matriz tridiagonal
  double *a = malloc((n-1)*sizeof(double));
  double *c = malloc((n-1)*sizeof(double));
  double *d = malloc(n*sizeof(double));

  //Aloca espaço para o vetor solução e o inicializa com zeros
  double *x = malloc(n*sizeof(double));
  initVector(x, n);

  //Aloca espaço para o vetor do resíduo
  double *residual = malloc(n*sizeof(double));

  //Realiza a eliminacao de gauss clássica com pivoteamento
  copiesLinearSystem(A, aux, b, bux, n);
  tempo = timestamp();
  gaussElimination(A, b, x, n);
  tempo = timestamp() - tempo;
  printf("EG Clássico:\n");
  printf("%.8f ms\n", tempo);
  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(aux, bux, x, residual, n), n);

  initVector(x, n);
  //Realiza o metodo de gauss-seidel clássico
  copiesLinearSystem(A, aux, b, bux, n);
  tempo = timestamp();
  gaussSeidel(A, b, x, n, 0.0001, &iter);
  tempo = timestamp() - tempo;
  printf("GS Clássico [ %d iterações ]:\n", iter);
  printf("%.8f ms\n", tempo);
  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(aux, bux, x, residual, n), n);

  
  //Inicio do trabalho com matriz tridiagonal
  iter = 0;

  initVector(x, n);
  //Realiza a eliminação de gauss em matriz tridiagonal
  copies3dLinearSystem(aux, a, c, d, b, bux, n);
  tempo = timestamp();
  gaussElimination3d(d, a, c, b, x, n);
  tempo = timestamp() - tempo;
  printf("EG Tridiagonal:\n");
  printf("%.8f ms\n", tempo);
  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(aux, bux, x, residual, n), n);

  initVector(x, n);
  //Realiza o metodo de gauss-seidel em matriz tridiagonal
  copies3dLinearSystem(aux, a, c, d, b, bux, n);
  tempo = timestamp();
  gaussSeidel3d(d, a, c, b, x, n, 0.0001, &iter);
  tempo = timestamp() - tempo;
  printf("GS Tridiagonal [ %d iterações ]:\n", iter);
  printf("%.8f ms\n", tempo);
  imprimeVetor(x, n);
  imprimeVetor(CalculatesResidual(aux, bux, x, residual, n), n);
  
  freeAll(A, b, aux, bux, a, c, d, x, n);
  free(residual);

  return 1;
}
