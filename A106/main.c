#include <stdio.h>
#include <math.h>

typedef struct
{
  int num, pow;
} str;

int IsSimple( int a )
{
  int i, res = 1;

  for (i = 2; i <= (int)sqrt(a); i++)
    if (a % i == 0)
      res = 0, i = a;
  return res;
}

void PushBack( str *mas, int num )
{
  int i, fnd = 0;

  for (i = 0; i < 10; i++)
    if (mas[i].num == num)
    {
      mas[i].pow++;
      fnd = 1;
    }

  if (!fnd)
  {
    i = 0;
    while (mas[i].num != 0)
      i++;
    mas[i].num = num;
    mas[i].pow = 1;
  }
}

void Rec( str *mas, int num )
{
  int i, e = (int)sqrt(num);

  if (IsSimple(num))
    PushBack(mas, num);
  else
    for (i = 2; i <= e; i++)
      if (num % i == 0)
      {
        if (IsSimple(i))
          PushBack(mas, i);
        Rec(mas, num / i);
        i = e;
      }
}

int main( void )
{
  int n, i, fst = 1;
  str mas[10] = {0};

  scanf("%i", &n);

  Rec(mas, n);

  if (n == 1)
    printf("1^1");
  else if (IsSimple(n))
    printf("%i^1", n);
  else
    for (i = 0; i < 10; i++)
      if (mas[i].num != 0)
        if (fst)
        {
          printf("%i^%i", mas[i].num, mas[i].pow);
          fst = 0;
        }
        else
          printf(" * %i^%i", mas[i].num, mas[i].pow);
  return 0;
}
