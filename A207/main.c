#include <stdio.h>
#include <stdlib.h>

int main( void )
{
  int n, *arr, i, cnt = 0, sum = 0;

  scanf("%i", &n);

  arr = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    scanf("%i", &arr[i]);
    sum += arr[i];
  }

  for (i = 0; i < n; i++)
    if (arr[i] == sum - arr[i])
      cnt++;

  free(arr);

  printf("%i", cnt);

  return 0;
}
