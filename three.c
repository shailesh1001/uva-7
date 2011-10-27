#include <stdio.h>

int cycle(int n) {
  int r = 1;
  while (n != 1)  {
    if (n % 2 != 1)
      n = n / 2;
    else
      n = 3*n+1;
    r++;
  }

  return r;
}

int main() {
  int a=0, b=0;
  int max;
  int swap = 0;

  while(scanf("%d %d", &a, &b) != EOF) {
    max = 0;
    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
      swap = 1;
    }
    int i;
    for (i = a; i <= b; i++) {
      int result = cycle(i);
      if (result > max)
        max = result;
    }
    if (!swap)
      printf("%d %d %d\n", a, b, max);
    else {
      printf("%d %d %d\n", b, a, max);
      swap = 0;
    }
  }
  return 0;
}

