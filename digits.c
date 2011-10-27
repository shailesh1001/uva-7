/*
 * Phillip LeBlanc
 * UVa 993 Product of digits
 * Homework 1
 * 9/7/2011
*/

#include <stdio.h>
#include <string.h>

char result[1000] = "";

char * digit(int n) {

  int two = 0;
  int three = 0;
  int five = 0;
  int seven = 0;

  if (n == 1) {
    strcpy(result, "1");
    return result;
  }

  while (n % 2 == 0) {
    two++;
    n = n / 2;
  }

  while (n % 3 == 0) {
    three++;
    n = n / 3;
  }

  while (n % 5 == 0) {
    five++;
    n = n / 5;
  }

  while (n % 7 == 0) {
    seven++;
    n = n / 7;
  }

  if (n > 1) {
    strcpy(result, "-1");
    return result;
  }

  while (three >= 2) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "9");
    strcat(result, rest);
    three -= 2;
  }

  while (two >= 3) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "8");
    strcat(result, rest);
    two -= 3;
  }

  while (seven > 0) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "7");
    strcat(result, rest);
    seven--;
  }

  while (two > 0 && three > 0) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "6");
    strcat(result, rest);
    two--;
    three--;
  }

  while (five > 0) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "5");
    strcat(result, rest);
    five--;
  }

  while (two >= 2) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "4");
    strcat(result, rest);
    two -= 2;
  }

  while (three > 0) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "3");
    strcat(result, rest);
    three--;
  }

  while (two > 0) {
    char rest[1000];
    strcpy(rest, result);
    strcpy(result, "2");
    strcat(result, rest);
    two--;
  }

  return result;

}

int main() {
  int num;
  int n;

  scanf("%d", &num);

  int i;
  for (i = 0; i < num; i++) {
    scanf("%d", &n); 
    printf("%s\n", digit(n));
    result[0] = '\0';
  }
  return 0;
}

