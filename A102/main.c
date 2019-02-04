#include <stdio.h>

int main( void )
{
  int n, i, num = 1, sum = 1;

  scanf("%i", &n);

  printf("%i", num);

  for (i = 2; i <= n; i++)
  {
    num += i;
    printf("+%i", num);
    sum += num;
  }

  printf("=%i", sum);

  return 0;
}
