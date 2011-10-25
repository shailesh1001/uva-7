/*
 * Author: Phillip LeBlanc
 * Problem: 11869 Soap Response
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0
#define printd if (DEBUG) printf

typedef struct {
  char *key;
  char *val;
  struct prop *next;
} prop;

typedef struct {
  char *name;
  struct node *next;
  struct node *parent;
  struct node *child;
  struct prop *props;
} node;

void run()
{
  /*do stuff*/
}

int main()
{
  int count,j;
  scanf("%d", &count);
  for (j=0;j<count;j++)
  {
    run();
  }
  return 0;
}

