// without using temp variable
#include <iostream>
using namespace std;
int main() {
  int a = 5, b = 3, temp;
  a = a + b;
  b = a - b;
  a = a - b;
  cout << a << " " << b << "\n";
  return 0;
}
