#include <stdio.h>
#include <stdlib.h>

int Compare( const void *a, const void *b )
{
  return (*(int *)a - *(int *)b);
}

int main( void )
{
  int n, i, *arr;

#ifndef SCRUTINIZER
  freopen("a.in", "rt", stdin);
  //freopen("a.out", "wt", stdout);
#endif

  scanf("%i", &n);

  arr = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
    scanf("%i", &arr[i]);

  qsort(arr, n, sizeof(int), Compare);

  printf("%i", arr[(n + 1) / 2 - 1]);

  free(arr);

  return 0;
}
