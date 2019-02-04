#include <stdio.h>

int main( void )
{
  int i, n, min = 2147483647;

  scanf("%i", &n);

  for (i = 0; i < n; i++)
  {
    int el;
    scanf("%i", &el);
    if (el < min)
      min = el;
  }

  printf("%i", min);
  return 0;
}