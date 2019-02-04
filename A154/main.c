#include <stdio.h>

int main( void )
{
  int n, i, sum = 0;
  
  scanf("%i", &n);

  for (i = 0; i < n; i++)
  {
    int el;
    scanf("%i", &el);
    sum += el;
    printf("%i ", sum);
  }

  return 0;
}