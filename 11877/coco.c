/*
 * Author: Phillip LeBlanc
 * Problem:
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0
#define printd if (DEBUG) printf

int main()
{
  int j;
  while (1)
  {
    scanf("%d", &j);
    if (j == 0)
      return 0;
    printf("%d\n", j/2);
  }
  return 0;
}

