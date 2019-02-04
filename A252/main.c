#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF -1

/* Global start end exit coordinates */
int x_st, y_st, x_out, y_out;

typedef struct lab_cell_t
{
  int
    type,
    value;
} lab_cell_t;

/* Global labirint array */
lab_cell_t lab[MAX][MAX];

typedef enum
{
  WALL = -3, EMPTY, SET, OUT
} types_t;

void Set( char c, int x, int y )
{
  switch (c)
  {
  case '#':
    lab[y][x].type = WALL;
    lab[y][x].value = INF;
    break;
  case 'O':
    lab[y][x].type = OUT;
    lab[y][x].value = INF;
    x_out = x;
    y_out = y;
    break;
  case 'X':
    lab[y][x].type = EMPTY;
    lab[y][x].value = 0;
    x_st = x;
    y_st = y;
    break;
  case ' ':
    lab[y][x].type = EMPTY;
    lab[y][x].value = INF;
    break;
  }
}

int SetCellRec( int x, int y, int wide, int dst )
{
  if (lab[y][x].type == OUT)
  {
    lab[y][x].value = dst;
    return 1;
  }

  if (lab[y][x].type == EMPTY)
  {
    lab[y][x].type = SET;
    lab[y][x].value = dst;

    if ((lab[y][x + 1].type != EMPTY && lab[y][x - 1].type != EMPTY && lab[(y + 1)][x].type != EMPTY && lab[(y - 1)][x].type != EMPTY) &&
        (lab[y][x + 1].type != OUT && lab[y][x - 1].type != OUT && lab[(y + 1)][x].type != OUT && lab[(y - 1)][x].type != OUT))
      return 0;
    if (lab[y][x + 1].type == EMPTY || lab[y][x + 1].type == OUT)
      if (SetCellRec(x + 1, y, wide, dst + 1))
        return 1;
    if (lab[y][x - 1].type == EMPTY || lab[y][x - 1].type == OUT)
      if (SetCellRec(x - 1, y, wide, dst + 1))
        return 1;
    if (lab[(y + 1)][x].type == EMPTY || lab[(y + 1)][x].type == OUT)
      if (SetCellRec(x, y + 1, wide, dst + 1))
        return 1;
    if (lab[(y - 1)][x].type == EMPTY || lab[(y - 1)][x].type == OUT)
      if (SetCellRec(x, y - 1, wide, dst + 1))
        return 1;
    return 0;
  }
  
  return 0;
}

int FindWay( unsigned int m )
{
  return SetCellRec(x_st, y_st, m, 0);
}

void BuildWay( int wdh, int len, int x, int y )
{
  if (x < 0 || y < 0 || x >= wdh || y >= len)
    return;

  if (y != y_st || x != x_st)
  {
    if (x < wdh - 1 && lab[y][x + 1].value == lab[y][x].value - 1)
    {
      BuildWay(wdh, len, x + 1, y);
      printf("L");
      return;
    }
    if (x > 0 && lab[y][x - 1].value == lab[y][x].value - 1)
    {
      BuildWay(wdh, len, x - 1, y);
      printf("R");
      return;
    }
    if (y < len - 1 && lab[(y + 1)][x].value == lab[y][x].value - 1)
    {
      BuildWay(wdh, len, x, y + 1);
      printf("U");
      return;
    }
    if (y > 0 && lab[(y - 1)][x].value == lab[y][x].value - 1)
    {
      BuildWay(wdh, len, x, y - 1);
      printf("D");
      return;
    }
  }
}

void PrintLab( int n, int m )
{
  int i, j;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (lab[i][j].value < 0)
        printf("%s#", j == 0 ? "" : "  ");
      else
        printf("%s%i", lab[i][j].value < 10 ? "  " : " ", lab[i][j].value);
    }
    printf("\n");
  }
}

int main( void )
{
  unsigned int n, m, i, j;

#ifndef SCRUTINIZER
  freopen("a.in", "rt", stdin);
  //freopen("a.out", "wt", stdout);
#endif

  scanf("%i %i\n", &n, &m);

  for (i = 0; i < n; i++)
  {
    char c;

    for (j = 0; j < m; j++)
    {
      scanf("%c", &c);

      Set(c, j, i);
    }

    scanf("%c", &c);      /* Skip '\n' */
  }

  if (!FindWay(m))
  {
    printf("NO WAY");
    return 0;
  }

  //PrintLab(n, m);

  BuildWay(m, n, x_out, y_out);

  return 0;
}
