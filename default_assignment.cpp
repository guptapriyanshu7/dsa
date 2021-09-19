#include <iostream>

using namespace std;

class Test {
  int x;
  int& ref;

  public:
  Test(int i) : x(i), ref(x) {}
  void print() { cout << ref; }
  void setX(int i) { x = i; }
  Test& operator=(const Test& t) {
    x = t.x;
    return *this;
  }
};

int main() {
  Test t1(10);
  Test t2(20);
  // t2.operator=(t1);
  Test& t3 = (t2 = t1);
  t3.setX(60);
  t3.print();
  cout << '\n';
  t2.print();
  return 0;
}