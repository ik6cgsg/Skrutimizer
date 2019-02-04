#include <stdio.h>

int main( void )
{
  int n, i, a[100], sum = 0;

  for (i = 0; i < 100; i++)
    a[i] = 0;

  scanf("%i", &n);

  for (i = 0; i < n; i++)
  {
    int el;
    scanf("%i", &el);
    sum += el;
  }

  printf("%i", sum);
  return 0;
}