#include <iostream>
using namespace std;

class Car {
public:
  int speed(int);
};

int Car::speed(int maxSpeed) {
  return maxSpeed;
}

int main() {
  Car myObj;
  cout << myObj.speed(200) << "\n";
  return 0;
}
