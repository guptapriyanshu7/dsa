#include <stdio.h>
#include <stdlib.h>

int Sum(int a, int b);
int Carry(int a, int b);

int Sum(int a, int b) {
  int x = a ^ b;
  return x;
}
int Carry(int a, int b) {
  int x = a & b;
  return x;
}

int main() {
  int a, b;
  printf("Enter a : ");
  scanf("%d", &a);
  printf("Enter b : ");
  scanf("%d", &b);
  printf("Sum : %d\nCarry : %d", Sum(a, b), Carry(a, b));
  return 0;
}