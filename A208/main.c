#include <stdio.h>

int main( void )
{
  int i, n, tmp, c_0 = 0, c_1 = 0, c_2 = 0;

  scanf("%i", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%i", &tmp);
    switch (tmp)
    {
    case 0:
      c_0++;
      break;
    case 1:
      c_1++;
      break;
    case 2:
      c_2++;
      break;
    }
  }

  for (i = 0; i < c_0; i++)
    printf("0 ");
  for (i = 0; i < c_1; i++)
    printf("1 ");
  for (i = 0; i < c_2; i++)
    printf("2 ");

  return 0;
}
