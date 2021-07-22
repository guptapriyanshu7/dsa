#include <iostream>

class MaxThis {
  int a;
public:
  MaxThis(int x) : a(x) {};
  bool findMax(MaxThis& rhs) {
    return this->a > rhs.a;
  }
};

int main() {
  MaxThis ob1(5);
  MaxThis ob2(10);
  if (ob1.findMax(ob2)) {
    std::cout << "ob1 is max.";
  } else {
    std::cout << "ob2 is max.";
  }
  return 0;
}