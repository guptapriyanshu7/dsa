#include <bits/stdc++.h>
using namespace std;
class temp {
  float x, y, q;

  public:
  void input() {
    cout << "Enter Two Numbers: ";
    cin >> x >> y;
  }
  friend void swap(temp& t);
  void display() {
    cout << "The mean of numbers is: " << q << "\n";
  }
};
void swap(temp& t) {
  t.q = (t.x + t.y) / 2;
}
int main() {
  temp t1;
  t1.input();
  swap(t1);
  t1.display();
  return 0;
}