#include <stdio.h>
#include <math.h>

void PrintNum( int num, int fl )
{
  switch (num)
  {
  case 1:
    if (fl)
      printf("-one");
    else
      printf("one");
    break;
  case 2:
    if (fl)
      printf("-two");
    else
      printf("two");
    break;
  case 3:
    if (fl)
      printf("-three");
    else
      printf("three");
    break;
  case 4:
    if (fl)
      printf("-four");
    else
      printf("four");
    break;
  case 5:
    if (fl)
      printf("-five");
    else
      printf("five");
    break;
  case 6:
    if (fl)
      printf("-six");
    else
      printf("six");
    break;
  case 7:
    if (fl)
      printf("-seven");
    else
      printf("seven");
    break;
  case 8:
    if (fl)
      printf("-eight");
    else
      printf("eight");
    break;
  case 9:
    if (fl)
      printf("-nine");
    else
      printf("nine");
    break;
  case 10:
    printf("ten");
    break;
  case 11:
    printf("eleven");
    break;
  case 12:
    printf("twelve");
    break;
  case 13:
    printf("thirteen");
    break;
  case 14:
    printf("fourteen");
    break;
  case 15:
    printf("fifteen");
    break;
  case 16:
    printf("sixteen");
    break;
  case 17:
    printf("seventeen");
    break;
  case 18:
    printf("eighteen");
    break;
  case 19:
    printf("nineteen");
    break;
  case 20:
    printf("twenty");
    break;
  case 30:
    printf("thirty");
    break;
  case 40:
    printf("forty");
    break;
  case 50:
    printf("fifty");
    break;
  case 60:
    printf("sixty");
    break;
  case 70:
    printf("seventy");
    break;
  case 80:
    printf("eighty");
    break;
  case 90:
    printf("ninety");
    break;
  }
}

void PrintR( int ind, int no )
{
  static int bl = 0;

  switch (ind)
  {
  case 10:
    if (!no)
      printf("billion");
    break;
  case 9:
  case 6:
  case 3:
    if (!no)
    {
      printf("hundred");
      bl = 1;
    }
    break;
  case 7:
    if (!no || bl)
      printf("million");
    if (bl)
    {
      bl = 0;
      if (no)
        printf(" ");
    }
    break;
  case 4:
    if (!no || bl)
      printf("thousand");
    if (bl)
    {
      bl = 0;
      if (no)
        printf(" ");
    }
    break;
  }
}

void Translate( int n )
{
  int n_c = n, len = 0, i, num = 0, teen = 0, need_t = 0;

  while (n_c > 0)
  {
    n_c /= 10;
    len++;
  }

  for (i = len - 1; i >= 0; i--)
  {
    int tmp = n / (int)pow(10, i) % 10;

    if (!teen)
      num = tmp;
    else
    {
      num = num * 10 + tmp;
      teen = 0;
    }

    if (i != 7 && i != 4 && i != 1)
    {
      int no = 0;

      PrintNum(num, need_t);

      if (num != 0 || need_t)
        printf(" ");
      else
        no = 1;

      PrintR(i + 1, no);

      if (!no)
        printf(" ");

      need_t = 0;
    }
    else if (num != 0)
      if (num != 1)
      {
        PrintNum(num * 10, 0);
        need_t = 1;
      }
      else
        teen = 1;
  }
}

int main( void )
{
  int n;

  scanf("%i", &n);

  if (n == 0)
    printf("zero");
  else
    Translate(n);

  return 0;
}
