#include <math.h>

#include <iostream>

using namespace std;

class Prime {
  int a, k, i;

  public:
  Prime(int x) {
    a = x;
    k = 1;
    for (i = 2; i <= sqrt(a); i++) {
      if (a % i == 0) {
        k = 0;
        break;
      }
    }
  }
  void show() {
    if (k == 1)
      cout << a << " is Prime Number.\n";
    else
      cout << a << " is not a Prime Number.\n";
  }
};
int main() {
  int a;
  cout << "Enter the Number:";
  cin >> a;
  Prime obj(a);
  obj.show();
  return 0;
}