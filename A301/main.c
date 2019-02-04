#include <stdio.h>
#include <ctype.h>

int main( void )
{
  char c;
  
  scanf("%c", &c);
  
  while (c != '\n')
  {
    if (isupper(c))
      printf("%c", c - 'A' + 'a');
    else if (islower(c))
      printf("%c", c - 'a' + 'A');
    else
      printf("%c", c);
    scanf("%c", &c);
  }
  
  return 0;
}