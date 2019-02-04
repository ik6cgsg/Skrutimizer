#include <stdio.h>

int main( void )
{
  int n, k, i, off = 0;

  scanf("%i %i", &n, &k);

  for (i = 0; i < n; i++)
  {
    int el;
    scanf("%i", &el);
    if (i == off)
    {
      printf("%i ", el);
      off += k;
    }
  }

  return 0;
}