#include <stdio.h>

#define MAX 100

int main(void)
{
  int i, j, k = 0, p = 0, lin_a, col_a, lin_b, col_b, a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

  scanf("%i %i", &lin_a, &col_a);

  for (i = 0; i < lin_a; i++)
    for (j = 0; j < col_a; j++)
      scanf("%i", &a[i][j]);

  scanf("%i %i", &lin_b, &col_b);

  if (col_a != lin_b || lin_b != col_b)
  {
    printf("-1");
    return 0;
  }

  for (i = 0; i < lin_b; i++)
    for (j = 0; j < col_b; j++)
      scanf("%i", &b[i][j]);

  for (k = 0; k < lin_a; k++)
  {
    for (p = 0; p < col_a; p++)
    {
      int sum = 0;
      for (j = 0; j < col_a; j++)
        sum += a[k][j] * b[j][p];
      c[k][p] = sum;
    }
  }

  for (i = 0; i < lin_a; i++)
    for (j = 0; j < col_a; j++)
      b[i][j] = c[i][j] - a[i][j];

  for (i = 0; i < lin_a; i++)
  {
    for (j = 0; j < col_a; j++)
      printf("%i ", b[i][j]);
    printf("\n");
  }

  return 0;
}
