#include <stdio.h>
#include <stdlib.h>

int Compare( const void *a, const void *b )
{
  return (*(int *)a - *(int *)b);
}

int main( void )
{
  int n, m, i, *pnts;

  /*
  freopen("a.in", "rt", stdin);
  freopen("a.out", "wt", stdout);
  */
  scanf("%i %i", &n, &m);

  pnts = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
    scanf("%i", &pnts[i]);

  qsort(pnts, n, sizeof(int), Compare);

  for (i = 0; i < m; i++)
  {
    int l, r, j = 0, cnt = 0;

    scanf("%i %i", &l, &r);

    if (pnts[n - 1] < l)
      cnt = 0;
    else if (pnts[0] > r)
      cnt = 0;
    else if (pnts[0] < l)
    {
      while (pnts[j] < l)
        j++;
      while (pnts[j] <= r && j < n)
      {
        cnt++;
        j++;
      }
    }
    else if (pnts[n - 1] <= r)
      cnt = n;
    else
      while (pnts[j] <= r && j < n)
      {
        cnt++;
        j++;
      }

    printf("%i ", cnt);
  }

  free(pnts);

  return 0;
}
