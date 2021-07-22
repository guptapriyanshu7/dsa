#include <iostream>

class Fib {
public:
  Fib(int n, int i = 1, int t1 = 0, int t2 = 1) {
    if (i <= n) {
      std::cout << t1 << ' ';
      Fib(n, ++i, t2, t1 + t2);
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  auto fib = Fib(n);
  return 0;
}