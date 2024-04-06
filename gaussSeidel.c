/* Bruno Crestani GRR:20221240 - Mateus Ruzene GRR:20221223 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gaussSeidel.h"

#define MAX_ITER 50

double calculatesError(double *x, double *x0, int n, double max)
{
  for (int i = 0; i < n; i++)
  {
    if (fabs(x[i] - x0[i]) > max)
      max = fabs(x[i] - x0[i]);
  }
  return max;
}

/* Function:  gaussSeidel
 * --------------------
 *  Resolve um sistema linear utilizando o método de Gauss-Seidel
 */
int gaussSeidel(double **A, double *b, double *x, int n, double tol, int *iter)
{
  int j;
  double error = tol + 1.0;
  double *x0, max;

  if (!(x0 = malloc(n * sizeof(double))))
  {
    printf("Erro na alocação de memória\n");
    return 0;
  }

  for (int i = 0; i < n; i++)
    x0[i] = x[i];

  while (*iter < MAX_ITER)
  {
    for (int i = 0; i < n; i++)
    {
      max = 0.0;
      for (j = 0; j < n; j++)
      {
        if (j != i)
          max += A[i][j] * x[j];
      }
      x[i] = (b[i] - max) / A[i][i];
    }

    error = calculatesError(x, x0, n, max);

    if (error < tol)
    {
      free(x0);
      return 1;
    }

    for (int i = 0; i < n; i++)
      x0[i] = x[i];

    (*iter)++;
  }

  free(x0);
  return 1;
}

void gaussSeidel3d(double *d, double *a, double *c, double *b, double *x, int n, double tol, int *iter)
{
  int i;
  double *x0, max, error = tol + 1.0;

  if (!(x0 = malloc(n * sizeof(double))))
  {
    printf("Erro na alocação de memória\n");
    return;
  }

  for (i = 0; i < n; i++)
    x0[i] = x[i];

  while (*iter < MAX_ITER)
  {
    for (i = 0; i < n; i++)
    {
      max = 0.0;
      if (i > 0)
        max += a[i - 1] * x[i - 1];
      if (i < n - 1)
        max += c[i] * x[i + 1];
      x[i] = (b[i] - max) / d[i];
    }

    error = calculatesError(x, x0, n, max);

    if (error < tol)
    {
      free(x0);
      return;
    }

    for (i = 0; i < n; i++)
      x0[i] = x[i];

    (*iter)++;
  }

  free(x0);
  return;
}
