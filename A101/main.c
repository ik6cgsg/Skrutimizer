#include <stdio.h>

int main( void )
{
  int n, i, sum = 0;

  scanf("%i", &n);
  
  for (i = 1; i < n; i++)
  {
    sum += i;
    printf("%i+", i);
  }
  printf("%i=%i", i, sum + i);

  return 0;
}