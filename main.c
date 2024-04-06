/* Bruno Crestani GRR:20221240 - Mateus Ruzene GRR:20221223 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <likwid.h>

#include "coreFunctions.h"
#include "gaussElimination.h"
#include "gaussSeidel.h"
#include "utils.h"

int main()
{

  int n;
  int iter = 0;
  scanf("%d", &n);

  double tempo;

  // Aloca um espaço para o sistema linear
  double **A = malloc(n * sizeof(double *));
  double *b = malloc(n * sizeof(double));

  // declara uma matriz e um vetor auxiliares para a leitura do sistema linear
  double **aux = malloc(n * sizeof(double *));
  double *bux = malloc(n * sizeof(double));

  LIKWID_MARKER_INIT;

  // Aloca espaço para as matrizes
  allocateMatrix(A, n);
  allocateMatrix(aux, n);

  // Le o sistema linear para os auxiliares
  readLinearSystem(aux, bux, n);

  // Aloca espaço para os vetores da matriz tridiagonal
  double *a = malloc((n - 1) * sizeof(double));
  double *c = malloc((n - 1) * sizeof(double));
  double *d = malloc(n * sizeof(double));

  // Aloca espaço para o vetor solução e o inicializa com zeros
  double *x = malloc(n * sizeof(double));
  initVector(x, n);

  // Aloca espaço para o vetor do resíduo
  double *residual = malloc(n * sizeof(double));

  LIKWID_MARKER_START("EG_Classico_LIKWID");

  // Realiza a eliminacao de gauss clássica com pivoteamento
  copiesLinearSystem(A, aux, b, bux, n);
  tempo = timestamp();
  gaussElimination(A, b, x, n);
  tempo = timestamp() - tempo;
  printf("EG Clássico:\n");
  printf("%.8f ms\n", tempo);
  printVector(x, n);
  printVector(CalculatesResidual(aux, bux, x, residual, n), n);

  LIKWID_MARKER_STOP("EG_Classico_LIKWID");

  LIKWID_MARKER_START("GS_Classico_LIKWID");

  // Realiza o metodo de gauss-seidel clássico
  initVector(x, n);
  copiesLinearSystem(A, aux, b, bux, n);
  tempo = timestamp();
  gaussSeidel(A, b, x, n, 0.0001, &iter);
  tempo = timestamp() - tempo;
  printf("GS Clássico [ %d iterações ]:\n", iter);
  printf("%.8f ms\n", tempo);
  printVector(x, n);
  printVector(CalculatesResidual(aux, bux, x, residual, n), n);

  LIKWID_MARKER_STOP("GS_Classico_LIKWID");

  LIKWID_MARKER_START("EG_Tridiagonal_LIKWID");
  // Inicio do trabalho com matriz tridiagonal
  iter = 0;

  initVector(x, n);
  // Realiza a eliminação de gauss em matriz tridiagonal
  copies3dLinearSystem(aux, a, c, d, b, bux, n);
  tempo = timestamp();
  gaussElimination3d(d, a, c, b, x, n);
  tempo = timestamp() - tempo;
  printf("EG Tridiagonal:\n");
  printf("%.8f ms\n", tempo);
  printVector(x, n);
  printVector(CalculatesResidual(aux, bux, x, residual, n), n);

  LIKWID_MARKER_STOP("EG_Tridiagonal_LIKWID");

  LIKWID_MARKER_START("GS_Tridiagonal_LIKWID");

  initVector(x, n);
  // Realiza o metodo de gauss-seidel em matriz tridiagonal
  copies3dLinearSystem(aux, a, c, d, b, bux, n);
  tempo = timestamp();
  gaussSeidel3d(d, a, c, b, x, n, 0.0001, &iter);
  tempo = timestamp() - tempo;
  printf("GS Tridiagonal [ %d iterações ]:\n", iter);
  printf("%.8f ms\n", tempo);
  printVector(x, n);
  printVector(CalculatesResidual(aux, bux, x, residual, n), n);

  LIKWID_MARKER_STOP("GS_Tridiagonal_LIKWID");

  freeAll(A, b, aux, bux, a, c, d, x, n);
  free(residual);

  LIKWID_MARKER_CLOSE;

  return 1;
}