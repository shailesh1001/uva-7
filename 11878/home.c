/*
 * Author: Phillip LeBlanc
 * Problem: Homework Checker 11878
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0
#define printd if (DEBUG) printf

int main()
{
  char input[120];
  int a,b,c;
  int correct = 0;
  while (scanf("%s", input) == 1) {
    if (sscanf(input, "%d-%d=%d", &a, &b, &c) == 3) {
      if ((a-b)==c)
        correct++;
      continue;
    }
    if (sscanf(input, "%d+%d=%d", &a, &b, &c) == 3) {
      if ((a+b)==c)
        correct++;
      continue;
    }

  }
  printf("%d\n", correct);
  return 0;
}

