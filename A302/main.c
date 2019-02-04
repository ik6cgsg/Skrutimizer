#include <stdio.h>
#include <ctype.h>

int main( void )
{
  int n;
  char c;
  
  scanf("%i\n", &n);
  scanf("%c", &c);

  while (c != '\n')
  {
    if (isalpha(c))
    {
      if (isupper(c))
        if (c - 'A' - n < 0)
          printf("%c", 'Z' - (0 - (c - 'A' - n)) + 1);
        else
          printf("%c", c - n);
      else
        if (c - 'a' - n < 0)
          printf("%c", 'z' - (0 - (c - 'a' - n)) + 1);
        else
          printf("%c", c - n);
    }
    else
      printf("%c", c);
    scanf("%c", &c);
  }

  return 0;
}
