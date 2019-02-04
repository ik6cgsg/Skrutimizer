#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define FRWD 5

/*
typedef struct node
{
  unsigned int weight;
  struct node *childs;
} node_t;
*/

typedef struct elem
{
  unsigned int weight;
  int mark, x, y;
} elem_t;

typedef struct queue
{
  unsigned int len, mem_len;
  elem_t *nodes;
} queue_t;

void Init( queue_t *q )
{
  q->len = 0;
  q->mem_len = FRWD;
  q->nodes = (elem_t *)malloc(FRWD * sizeof(elem_t));
  memset(q->nodes, (int)NULL, FRWD * sizeof(elem_t));
}

void Push( queue_t *q, elem_t *n)
{
  int i;

  q->len++;
  if (q->len > q->mem_len)
  {
    q->nodes = (elem_t *)realloc(q->nodes, (q->len + FRWD) * sizeof(elem_t));
    q->mem_len += FRWD;
  }

  for (i = q->len - 1; i > 0; i--)
  {
    q->nodes[i] = q->nodes[i - 1];
  }
  q->nodes[0] = *n;
}

/*
void BuildTree( node_t *graph, int ind_x, int ind_y, unsigned int *weights, int y, int x )
{
  if (ind_x >= 0 && ind_x < x && ind_y >= 0 && ind_y < y)
  {
    graph->weight = weights[ind_y * x + ind_x];
    graph->childs = (node_t *)malloc(3 * sizeof(node_t));
    memset(graph->childs, (int)NULL, 3 * sizeof(node_t));
  }
  else
  {
    graph->weight = 0;
    graph->childs = NULL;
    return;
  }

  BuildTree(&graph->childs[0], ind_x - 1, ind_y + 1, weights, y, x);
  BuildTree(&graph->childs[1], ind_x, ind_y + 1, weights, y, x);
  BuildTree(&graph->childs[2], ind_x + 1, ind_y + 1, weights, y, x);
}
 */

/*
void FreeNode( node_t *n )
{
  if (n == NULL)
    return;

  FreeNode(n->childs);

  free(n);
}
 *
void FreeTree( elem_t *graph )
{
  if (graph-> == NULL)
    return;

  FreeNode(graph->childs);
}
/*
void DrawTree( node_t *graph )
{
  if (graph->childs == NULL)
    return;

  printf("%i :", graph->weight);

  DrawTree(&graph->childs[0]);
  printf("_ _ _");
  DrawTree(&graph->childs[1]);
  printf(". . .");
  DrawTree(&graph->childs[2]);
  printf("/ / /");
}
*/

elem_t Pop( queue_t *q )
{
  elem_t tmp;

  q->len--;
  tmp = q->nodes[q->len];

  return tmp;
}

void Free( queue_t *q )
{
  free(q->nodes);
}

int BFS( /*node_t *graph*/elem_t *a, unsigned int *weights, int ind, int x, int y )
{
  unsigned int min_len = UINT_MAX;
  int str/* = ind_y + 1*/, stl, i;
  queue_t Q;

  /*
  if (str > y)
    return;
  /*
  queue_t Q;

  Init(&Q);
  Push(&Q, graph);

  while (Q.len != 0)
  {
    node_t curr;

    curr = Pop(&Q);

    if (curr.childs != NULL)
    {
      int i;

      if (curr.childs[0].childs == NULL && curr.childs[1].childs == NULL && curr.childs[1].childs == NULL)
      {
        if (curr.weight < min_len)
          min_len = curr.weight;
      }
      else
        for (i = 0; i < 3; i++)
        {
            curr.childs[i].weight += curr.weight;
          if (curr.childs[i].childs != NULL)
            Push(&Q, &curr.childs[i]);
        }
    }
  }
  */
  /*
  for (str = ind_y + 1; str <= y; str++)
  { */
  Init(&Q);
  a[ind].mark = 0;
  Push(&Q, &a[ind]);

  while (Q.len != 0)
  {
    elem_t curr;
    unsigned int val;

    curr = Pop(&Q);

    str = curr.y;

    if (str > y - 2)
      continue;

    val = curr.weight;

    for (stl = curr.x - 1; stl <= curr.x + 1; stl++)
    {
      unsigned int tmp;
      elem_t *next = &a[x * (str + 1) + stl];
      int n = 1;

      if (!(stl >= 0 && stl < x))
        continue;

      tmp = val + weights[x * (str + 1) + stl];

      if (next->mark == -1)
      {
        next->weight = tmp;
        next->mark = 0;
      }
      else
      {
        if (tmp < next->weight)
          next->weight = tmp;

        if (stl == curr.x - 1)
          if (Q.len > 1)
          {
            Q.nodes[1] = *next;
            n = 0;
          }
          else
            n = 1;
        else if (stl == curr.x)
          if (Q.len > 0)
          {
            Q.nodes[0] = *next;
            n = 0;
          }
          else
            n = 1;
      }
      
      if (n)
        Push(&Q, next);
    }
  }
  
  for (i = 0; i < x; i++)
    if (a[x * (y - 1) + i].weight < min_len && a[x * (y - 1) + i].mark != -1)
      min_len = a[x * (y - 1) + i].weight;

  Free(&Q);

  return min_len;
}

int main( void )
{
  unsigned int n, m, i, j, ind, *wts;
  elem_t *gr;

  /*
  freopen("b.in", "rt", stdin);
  freopen("a.out", "wt", stdout);
  */

  scanf("%i %i", &n, &m);

  wts = (unsigned int *)malloc(n * m * sizeof(unsigned int));
  gr = (elem_t *)malloc(n * m * sizeof(elem_t));

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    {
      scanf("%i", &wts[m * i + j]);
      gr[m * i + j].weight = wts[m * i + j];
      gr[m * i + j].mark = -1;
      gr[m * i + j].x = j;
      gr[m * i + j].y = i;
    }

  scanf("%i", &ind);

  //BuildTree(&gr, ind, 0, wts, n, m);

  n = BFS(gr, wts, ind, m, n);

  //FreeTree(&gr);
  free(wts);
  free(gr);

  printf("%i", n);

  return 0;
}
