#include <bits/stdc++.h>

using namespace std;

struct Memory {
  int x = 0;
  explicit Memory(int val) : x(val) {}
};

int main() {
  auto* ptr = new Memory(3);
  cout << ptr->x;
  delete ptr;
  return 0;
}