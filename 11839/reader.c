/*
 * Author: Phillip LeBlanc
 * Problem: Optical Reader 11839
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0
#define printd if (DEBUG) printf

char ans[6] = { 'A', 'B', 'C', 'D', 'E', '*' };

void run()
{
  int i, num, foundAt;
  foundAt = -1;
  for (i = 0; i < 5; i++) {
    scanf("%d", &num); 
    printd("%d ", num);

    if (num < 128) { 
      if (foundAt == -1)
        foundAt = i;
      else
        foundAt = 5;
    }
  }
  if (foundAt == -1)
    foundAt = 5;
  printf("%c\n", ans[foundAt]);
  printd("\n");
}

int main()
{
  int count,j;
  while (1) {
    scanf("%d", &count);
    printd("%d\n", count);
    if (count == 0)
      exit(0);
    for (j=0;j<count;j++)
    {
      run();
    }
  }
}

