#include <stdio.h>

char Num( int num )
{
  char c = '\0';

  if (num >= 0 && num <= 9)
    c = (char)('0' + num);
  else
    c = (char)('A' + num - 10);
  return c;
}

void Translate( int base1, int base2, char *a )
{
  int sum = 0, i = 0, j = 0, k = 0;

  while (a[i] != '\0')
    i++;
  i--;
  /* from any to 10 */
  for (j = 0; j <= i; j++)
  {
    if (a[j] >= 'A' && a[j] <= 'Z')
      sum = sum * base1 + (a[j] - 'A' + 10);
    else
      sum = sum * base1 + (a[j] - '0');
  }

  /* from 10 to any */
  if (sum < base2)
    a[0] = Num(sum);
  else
  {
    k = 0;
    while (sum / base2 != 0)
    {
      a[k] = Num(sum % base2);
      sum /= base2;
      k++;
    }
    a[k] = Num(sum % base2);
  }

  a[k + 1] = '\0';

  for (i = 0; i <= k / 2; i++)
  {
    char t = a[i];
    a[i] = a[k - i];
    a[k - i] = t;
  }
}

int main( void )
{
  int b, c;
  char a[300];

  scanf("%i %i\n%s", &b, &c, &a);

  Translate(b, c, a);

  printf("%s", a);

  return 0;
}
