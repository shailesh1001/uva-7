/*
 * Author: Phillip LeBlanc
 * Problem: 11894 Genius MJ
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 1
#define printd if (DEBUG) printf

typedef struct {
  int x;
  int y;
} point;

void translateToOrigin(point *p, int num_pins) {
  int i;
  int transx = p[0].x;
  int transy = p[0].y;
  
  for(i = 0; i < num_pins; ++i) {
    p[i].x += (-transx);
    p[i].y += (-transy);
  }
}

void rotateToLeft(point *p, int num_pins) {
  int i;
  for(i = 0; i < num_pins; ++i) {
    int x = p[i].x;
    int y = p[i].y;
    p[i].x = -y;
    p[i].y = x;
  }
}

int comparePins(point *p1, point *p2, int num_pins) {
  int i;
  for(i = 0; i < num_pins; ++i) {
    if (p1[i].x != p2[i].x || p1[i].y != p2[i].y)
      return 0;
  }
  return 1;
}

int compare(const void *v1, const void *v2) {
  point *p1 = (point *)v1;
  point *p2 = (point *)v2;
  
  if (p1->x < p2->x)
    return -1;
  if (p1->x == p2->x) {
    if (p1->y == p2->y)
      return 0;
    if (p1->y < p2->y)
      return -1;
    return 1;
  }
  return 1;
}

void printPort(point *p, int pins) {
  int i;
  for (i = 0; i < pins; ++i) {
    printd("%d %d\n", p[i].x, p[i].y);
  }
  printd("\n");
}

/* Check Pairs */
void run()
{
  int pins, i;
  point *port1;
  point *port2;
  scanf("%d", &pins);
  port1 = malloc(pins*sizeof(point));
  port2 = malloc(pins*sizeof(point));
  
  for(i = 0; i < pins; ++i)
  {
    scanf("%d %d", &(port1[i].x), &(port1[i].y));
  }
  for(i = 0; i < pins; ++i)
  {
    scanf("%d %d", &(port2[i].x), &(port2[i].y));
  }
  qsort(port1, pins, sizeof(point), compare);
  qsort(port2, pins, sizeof(point), compare);
  
  translateToOrigin(port1, pins);
  
  for (i = 0; i < 4; ++i) {
    rotateToLeft(port2, pins);
    qsort(port2, pins, sizeof(point), compare);
    translateToOrigin(port2, pins);
    if (comparePins(port1, port2, pins)) {
      printf("MATCHED\n");
      return;
    }
  }
  printf("NOT MATCHED\n");

}

int main()
{
  int count,j;
  scanf("%d", &count);
  for (j=0;j<count;j++)
  {
    run();
  }
  
  return 1;
}

