#include <iostream>
using namespace std;
class consts {
  int x, y;

  public:
  consts(int, int);
  void putdata() {
    cout << "(" << x << "," << y << ")\n";
  }
};
consts::consts(int a, int b) {
  x = a;
  y = b;
}
int main() {
  consts p1(1, 1);
  consts p2 = consts(8, 9);
  p1.putdata();
  p2.putdata();
  return 0;
}