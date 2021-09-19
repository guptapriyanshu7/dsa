#include <bits/stdc++.h>
using namespace std;
class dist {
  int a1, b1, a2, b2;

  public:
  dist(int x1, int x2, int y1, int y2) {
    a1 = x1;
    b1 = y1;
    a2 = x2;
    b2 = y2;
  }
  void show() {
    cout << sqrt(((a2 - a1) * (a2 - a1)) + ((b2 - b1) * (b2 - b1))) << "\n";
  }
};

int main() {
  int x1, y1, x2, y2;
  cout << "Enter first point:";
  cin >> x1 >> y1;
  cout << "Enter second point:";
  cin >> x2 >> y2;
  dist obj(x1, y1, x2, y2);
  obj.show();
  return 0;
}