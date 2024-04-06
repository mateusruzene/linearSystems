/* Bruno Crestani GRR:20221240 - Mateus Ruzene GRR:20221223 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gaussElimination.h"

void lineSwap(double **A, double *b, int n, int i)
{
  int max = i;
  for (int j = i + 1; j < n; j++)
  {
    if (fabs(A[j][i]) > fabs(A[max][i]))
      max = j;
  }
  if (max != i)
  {
    double *aux = A[i];

    for (int j = 0; j < n; j++)
    {
      A[i][j] = A[max][j];
      A[max][j] = aux[j];
    }

    double aux2 = b[i];
    b[i] = b[max];
    b[max] = aux2;
  }
}

void gaussElimination(double **A, double *b, double *x, int n)
{
  double m;

  for (int i = 0; i < n; i++)
  {
    lineSwap(A, b, n, i);

    for (int k = i + 1; k < n; k++)
    {
      m = A[k][i] / A[i][i];
      A[k][i] = 0.0;

      for (int j = i + 1; j < n; j++)
        A[k][j] -= m * A[i][j];
      b[k] -= m * b[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
      x[i] = b[i];
      for (int j = i + 1; j < n; j++)
      {
        x[i] -= A[i][j] * x[j];
      }
      x[i] /= A[i][i];
    }
  }
}

void gaussElimination3d(double *d, double *a, double *c, double *b, double *x, int n)
{
  double m;

  for (int i = 0; i < n - 1; i++)
  {

    m = a[i] / d[i];
    a[i] = 0.0;

    d[i + 1] -= m * c[i];
    b[i + 1] -= m * b[i];
  }

  x[n - 1] = b[n - 1] / d[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    x[i] = (b[i] - c[i] * x[i + 1]) / d[i];
  }
}
