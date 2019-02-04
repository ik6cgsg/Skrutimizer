#include <stdio.h>
#include <ctype.h>

int main( void )
{
  char c;
  int prob = 1;

  scanf("%c", &c);
  
  while (c != '\n')
  {
    if (isalpha(c))
      if (prob)
      {
        if (islower(c))
          printf("%c", c - 'a' + 'A');
        else
          printf("%c", c);
        prob = 0;
      }
      else if (isupper(c))
        printf("%c", c - 'A' + 'a');
      else
        printf("%c", c);
    else
    {
      printf("%c", c);
      prob = 1;
    }
    scanf("%c", &c);
  }
  return 0;
}
