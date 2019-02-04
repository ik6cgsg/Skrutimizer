#include <stdio.h>

int main( void )
{
  int n, k, i;

  scanf("%i %i", &n, &k);

  for (i = 0; i < n; i++)
  {
    int el, j;
    scanf("%i", &el);
    for (j = 0; j < k; j++)
      printf("%i ", el);
  }

  return 0;
}