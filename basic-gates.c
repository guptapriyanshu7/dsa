#include <stdio.h>

void AND() {
  int a[4] = { 1, 0, 1, 0 };
  int b[4] = { 0, 1, 1, 0 };
  int i, and_ans;

  for (i = 0; i < 4; i++) {
    and_ans = a[i] & b[i];

    printf("\n %d AND %d = %d",
      a[i], b[i], and_ans);
  }
}

void OR() {
  int a[4] = { 1, 0, 1, 0 };
  int b[4] = { 0, 1, 1, 0 };
  int i, or_ans;

  for (i = 0; i < 4; i++) {
    or_ans = a[i] | b[i];

    printf("\n %d OR %d = %d",
      a[i], b[i], or_ans);
  }
}


void NAND() {
  int a[4] = { 1, 0, 1, 0 };
  int b[4] = { 0, 1, 1, 0 };
  int i, ans;

  for (i = 0; i < 4; i++) {
    ans = !(a[i] & b[i]);
    printf("\n %d NAND %d = %d",
      a[i], b[i], ans);
  }
}


void NOR() {

  int a[4] = { 1, 0, 1, 0 };
  int b[4] = { 0, 1, 1, 0 };
  int i, ans;

  for (i = 0; i < 4; i++) {
    ans = !(a[i] + b[i]);
    printf("\n %d NOR %d = %d",
      a[i], b[i], ans);
  }
}



void NOT() {

  int a[2] = { 1, 0 };
  int i, ans;

  for (i = 0; i < 2; i++) {
    ans = !(a[i]);
    printf("\n  NOT %d = %d", a[i], ans);
  }
}




void XOR() {
  int a[4] = { 1, 0, 1, 0 };
  int b[4] = { 0, 1, 1, 0 };
  int i, and_ans;

  for (i = 0; i < 4; i++) {
    and_ans = (a[i] | b[i]) & (!a[i] | !b[i]);

    printf("\n %d XOR %d = %d",
      a[i], b[i], and_ans);
  }
}




void XNOR() {
  int a[4] = { 1, 0, 1, 0 };
  int b[4] = { 0, 1, 1, 0 };
  int i, and_ans;

  for (i = 0; i < 4; i++) {
    and_ans = (a[i] & b[i]) | (!a[i] & !b[i]);

    printf("\n %d XNOR %d = %d",
      a[i], b[i], and_ans);
  }
}


int main() {
  AND();
  OR();
  NOT();
  NAND();
  NOR();
  XOR();
  XNOR();
}