#include <iostream>

using namespace std;

#define MAX 1000

bool HASH[MAX + 1][2];

bool search(int value) {
  if(HASH[abs(value)][0] || HASH[abs(value)][1]) 
    return true;
  else
    return false;
}

void insert(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if(a[i] >= 0)
      HASH[a[i]][0] = 1;
    else 
      HASH[abs(a[i])][1] = 1;
  }
}

int main() {
  int a[] = { -1, 9, 2, 7, -3 };
  int n = sizeof(a) / sizeof(a[0]);
  insert(a, n);
  if(search(2))
    cout << "FOUND";
  else 
    cout << "NOT FOUND";
  return 0;
}