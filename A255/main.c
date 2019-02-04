#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix
{
  double *a;
  int side;
} matrix_t;


void Init( matrix_t *m, int size )
{
  m->side = size;
  m->a = (double *)malloc(size * size * sizeof(double));
}

void Free( matrix_t *m )
{
  free(m->a);
}

void Feel( matrix_t *m, int x, int y )
{
  int i, j;

  for (i = 0, j = x; i < m->side; i++)
    m->a[i * m->side + j] = 0;

  for (j = 0, i = y; j < m->side; j++)
    m->a[i * m->side + j] = 0;

  m->a[y * m->side + x] = 1;
}

void Copy( matrix_t *dest, matrix_t *src )
{
  int i, j;

  for (i = 0; i < dest->side; i++)
    for (j = 0; j < dest->side; j++)
      dest->a[i * dest->side + j] = src->a[i * src->side + j];
}

void MultByNum( matrix_t *m, double num )
{
  int i, j;

  for (i = 0; i < m->side; i++)
    for (j = 0; j < m->side; j++)
      m->a[i * m->side + j] *= num;
}

double Determ2x2( matrix_t *m )
{
  return m->a[0] * m->a[3] - m->a[1] * m->a[2];
}

int Triangle( matrix_t *m )
{
  int i, j;

  for (j = 0; j < m->side - 1; j++)
    for (i = j + 1; i < m->side; i++)
      if (m->a[i * m->side + j] != 0)
        return 0;
  return 1;
}

long double DetermGauss( matrix_t *m )
{
  int i, j, k, pwr = 0;
  long double det = 1, treshold = 0.0001;

  if (m->side == 1)
    return m->a[0];
  else if (m->side == 2)
    return Determ2x2(m);
  else if (Triangle(m))
  {
    for (i = 0; i < m->side; i++)
      det *= m->a[i * m->side + i];
    return det;
  }
  else
    for (k = 0; k < m->side - 1; k++)
    {
      if (m->a[k * m->side + k] >= -treshold && m->a[k * m->side + k] <= treshold)
      {
        int e = k + 1, l = k + 1;
        while (e < m->side && (m->a[e * m->side + k] <= treshold && m->a[e * m->side + k] >= -treshold))
          e++;
        if (e < m->side)
        {
          int r;
          for (r = 0; r < m->side; r++)
          {
            double tmp = m->a[e * m->side + r];
            m->a[e * m->side + r] = m->a[k * m->side + r];
            m->a[k * m->side + r] = tmp;
          }
          pwr++;
        }
        else
        {
          while (l < m->side && (m->a[k * m->side + l] >= -treshold && m->a[k * m->side + l] <= treshold))
            l++;
          if (l < m->side)
          {
            int r;
            for (r = 0; r < m->side; r++)
            {
              double tmp = m->a[r * m->side + k];
              m->a[r * m->side + k] = m->a[r * m->side + l];
              m->a[r * m->side + l] = tmp;
            }
            pwr++;
          }
          else
            return 0;
        }
      }

      for (i = 1; i < m->side; i++)
      {
        double alpha;
        if (i <= k)
          continue;
        alpha = -m->a[i * m->side + k] / m->a[k * m->side + k];
        for (j = 0; j < m->side; j++)
          m->a[i * m->side + j] += alpha * m->a[k * m->side + j];
      }

      if (Triangle(m))
        break;
    }

  for (i = 0; i < m->side; i++)
    det *= m->a[i * m->side + i];

  return det * pow(-1, pwr);
}

int main( void )
{
  int m, i, j;
  long double det, tres = 0.0001;
  matrix_t mtx, mtx_tr, mtx_b, tmp;

  /*
  freopen("a.in", "rt", stdin);
  freopen("a.out", "wt", stdout);
  */
  scanf("%i", &m);

  Init(&mtx, m);

  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
      scanf("%lf", &mtx.a[i * m + j]);

  Init(&mtx_b, m);
  Copy(&mtx_b, &mtx);

  det = DetermGauss(&mtx);

  Free(&mtx);

  if (det <= tres && det >= -tres)
  {
    printf("NONE");
    Free(&mtx_b);
    return 0;
  }

  Init(&mtx_tr, m);
  Init(&tmp, m);

  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
    {
      Copy(&tmp, &mtx_b);
      Feel(&tmp, i, j);

      mtx_tr.a[i * m + j] = (double)DetermGauss(&tmp);
    }

  MultByNum(&mtx_tr, (double)(1 / det));

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
      printf("%.0f ", floor(mtx_tr.a[i * m + j] + 0.5));
    printf("\n");
  }

  Free(&mtx_b);
  Free(&mtx_tr);
  Free(&tmp);

  return 0;
}
