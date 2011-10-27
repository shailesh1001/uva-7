/*
 * Author: Phillip LeBlanc
 * Problem: 11879 Multiple of 17
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define DEBUG 0
#define printd if (DEBUG) printf

int num_took_off;
int get_num(char * n, int target) {
  int length = strlen(n);
  int num = 0;
  num_took_off = 0;
  while (num < target) {
    num += ((int)pow(10.0, (double)num_took_off))*((n[length-(num_took_off+1)]) - '0');
    num_took_off++;
  }
  n[length-(num_took_off+1)] = 0;
  return num;
}

void put_back(char * n, int num) {
  char *newnum = malloc(sizeof(char)*(num_took_off+1));
  int i = num_took_off;
  while (num < (int)pow(10.0, (double)i)) {
    sprintf(newnum, "0");
    i--;
  }
  sprintf(newnum, "%d", num);
  strcat(n, newnum);
}

void run(char * n)
{
  int length = strlen(n);
  int ans;

  while (length > 4) {
    
    int d = n[length-1] - '0';
    int x;
    n[length-1] = 0;

    x = get_num(n, d*5);
    x -= d*5;
    put_back(n, x);

    length--;
  }
  sscanf(n, "%d", &ans);
  printd("ans:%d\n",ans);
  if (ans%17 == 0)
    printf("1\n");
  else
    printf("0\n");
  return;
}

int main()
{
  char num[101];
  scanf("%s", num);
  for (;strcmp(num, "0")!=0; scanf("%s",num))
  {
    run(num);
  }
  return 0;
}

