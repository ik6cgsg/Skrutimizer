#include <stdio.h>

int main( void )
{
  int n, i, a[100];
  
  scanf("%i", &n);

  for (i = 0; i < n; i++)
    scanf("%i", &a[i]);
  for (i = 0; i < n / 2; i++)
  {
    int t = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = t;
  }

  for (i = 0; i < n; i++)
    printf("%i ", a[i]);

  return 0;
}