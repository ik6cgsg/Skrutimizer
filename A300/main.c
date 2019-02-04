#include <stdio.h>
#include <ctype.h>

int main( void )
{
  char c;

  scanf("%c", &c);

  while (c != '\n')
  {
    if (isalpha(c) || isdigit(c))
      printf("%c", c);
    scanf("%c", &c);
  }

  return 0;
}