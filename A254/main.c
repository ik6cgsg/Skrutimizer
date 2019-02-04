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


double Determ2x2( matrix_t *m )
{
  return m->a[0] * m->a[3] - m->a[1] * m->a[2];
}

/*
int DetermRec( matrix_t *mt, int ind )
{
  int sum = 0;
  int i, j, m = 0, n = 0;
  matrix_t newm;

  Init(&newm, mt->side - 1);

  for (i = 1; i < mt->side; i++)
  {
    for (j = 0; j < mt->side; j++)
      if (j != ind)
      {
        newm.a[m * newm.side + n] = mt->a[i * mt->side + j];
        n++;
      }
    m++;
    n = 0;
  }

  if (newm.side == 2)
    return Determ2x2(&newm);

  for (i = 0; i < newm.side; i++)
    sum += (int)pow(-1, i) * newm.a[i] * DetermRec(&newm, i);

  Free(&newm);

  return sum;
}

int Determ( matrix_t *m )
{
  int i, sum = 0;
  
  if (m->side == 1)
    return m->a[0];
  else if (m->side == 2)
    return Determ2x2(m);
  else
    for (i = 0; i < m->side; i++)
      sum += (int)pow(-1, i) * m->a[i] * DetermRec(m, i);

  return sum;
}
*/

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
        while (m->a[e * m->side + k] <= treshold && m->a[e * m->side + k] >= -treshold && e < m->side)
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
          while (m->a[k * m->side + l] >= -treshold && m->a[k * m->side + l] <= treshold && l < m->side)
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
  long double det;
  matrix_t mtx;

  
  freopen("a.in", "rt", stdin);
  freopen("a.out", "wt", stdout);
  
  scanf("%i", &m);

  Init(&mtx, m);

  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++)
      scanf("%lf", &mtx.a[i * m + j]);

  det = DetermGauss(&mtx);

  Free(&mtx);

  printf("%.0lf", floorl(det + 0.5));

  return 0;
}
