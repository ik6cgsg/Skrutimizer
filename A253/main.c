#include <stdio.h>
#include <stdlib.h>

int main( void )
{
  int n, *arr, i, j, size;

  scanf("%i", &n);

  size = 2 * n + 1;

  arr = (int *)malloc(size * size * sizeof(int));

  for (i = 0; i <= n; i++)
  {
    int y = i;
    for (j = i; j < size - i; j++)
      arr[y * size + j] = i;
    j--;
    y++;
    for (y; y < size - i; y++)
      arr[y * size + j] = i;
    y--;
    for (j = i; j < size - i - 1; j++)
      arr[y * size + j] = i;
    j = i;
    for (y = i + 1; y < size - i - 1; y++)
      arr[y * size + j] = i;
  }

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
      printf("%i ", arr[i * size + j]);
    printf("\n");
  }

  free(arr);

  return 0;
}
