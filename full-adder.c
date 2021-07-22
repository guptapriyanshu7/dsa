#include <stdio.h>
#include <stdlib.h>

int Sum(int a, int b, int c)
{
  int x = c ^ (a ^ b);
  return x;
}
int Cout(int a, int b, int c)
{
  int x = (a & b) | (b & c) | (c & a);
  return x;
}

int main()
{
  int a, b, c;
  printf("Enter a : ");
  scanf("%d", &a);
  printf("Enter b : ");
  scanf("%d", &b);
  printf("Enter Cin : ");
  scanf("%d", &c);
  printf("Sum : %d\nCarry : %d", Sum(a, b, c), Cout(a, b, c));
  return 0;
}