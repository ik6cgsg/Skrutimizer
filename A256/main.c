#include <stdio.h>

#define MAX 100
#define INF 2147483647

#define MIN2(A, B) ((A) < (B) ? (A) : (B))
#define MIN4(A, B, C, D) (MIN2(MIN2((A), (B)), MIN2((C), (D))))
#define MIN5(A, B, C, D, E) (MIN2((A), MIN4((B), (C), (D), (E))))

int arr[MAX][MAX];

int Value( int x, int y, int lin, int col )
{
  if (x < 0 || x >= col || y < 0 || y >= lin)
    return INF;
  return arr[y][x];
}

int main( void )
{
  int lin, col, i, j, cnt = 0;

  scanf("%i %i", &lin, &col);

  for (i = 0; i < lin; i++)
    for (j = 0; j < col; j++)
      scanf("%i", &arr[i][j]);

  for (i = 0; i < lin; i++)
    for (j = 0; j < col; j++)
      if (arr[i][j] == MIN5(Value(j, i, lin, col), Value(j, i + 1, lin, col),
          Value(j, i - 1, lin, col), Value(j + 1, i, lin, col), Value(j - 1, i, lin, col)))
        cnt++;

  printf("%i", cnt);

  return 0;
}
