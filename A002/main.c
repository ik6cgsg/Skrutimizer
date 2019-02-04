#include <stdio.h>
#include <math.h>

int main( void )
{
  int a, b, c, amount = 59;
  float x1 = 30, x2 = 30, d;

  scanf("%i %i %i", &a, &b, &c);

  if (a == 0)
    if (b == 0)
      if (c == 0)
        amount = 30;
      else
        amount = 0;
    else
    {
      x1 = -c * (float)1 / b;
      amount = 1;
    }
  else
  {
    d = b * b - (float)4 * a * c;

    if (d < 0)
      amount = 0;
    else if (d == 0)
    {
      x1 = -b / ((float)2 * a);
      amount = 1;
    }
    else
    {
      x1 = (-b + sqrtf(d)) / ((float)2 * a);
      x2 = (-b - sqrtf(d)) / ((float)2 * a);
      if (x1 < x2)
      {
        float x = x1;
        x1 = x2;
        x2 = x;
      }
      amount = 2;
    }
  }

  if (amount == 0)
    printf("NONE");
  else if (amount == 30)
    printf("ALL");
  else if (amount == 1)
    printf("%.4f", x1);
  else
    printf("%.4f %.4f", x1, x2);
            
  return 0;
}
