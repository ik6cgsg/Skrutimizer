#include <stdio.h>
#include <stdlib.h>

int Find( int el, int *src, int len )
{
  int k = len / 2, o_f = 0;

  if (len % 2 != 0)
    o_f = 1;

  if (len == 1 && el != src[0])
    return 0;

  if (el == src[k])
    return 1;
  else if (el < src[k])
    return Find(el, src, k);
  else
    return Find(el, src + k, k + o_f);
}

int main( void )
{
  int n, m, *a, el, i;

  scanf("%i %i", &n, &m);

  a = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
    scanf("%i", &a[i]);

  for (i = 0; i < m; i++)
  {
    scanf("%i", &el);
    printf("%i", Find(el, a, n));
  }

  free(a);

  return 0;
}
