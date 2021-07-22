#include<bits/stdc++.h>

using namespace std;

class simpleCalculator {
protected:
  int a, b;
public:
  void enter() {
    cout << "Enter values for simple calculator: ";
    cin >> a;
    cin >> b;
  }
  void scalc() {
    cout << "Addition: " << a + b << "\n";
    cout << "Subtraction: " << a - b << "\n";
    cout << "Multiplication: " << a * b << "\n";
    cout << "Division: " << a / b << "\n";
  }
};

class scientificCalculator {
protected:
  int c;
public:
  void enter() {
    cout << "Enter value for scientific calculator: ";
    cin >> c;
  }
  void sCcalc() {
    cout << "Square root: " << sqrt(c) << "\n";
    cout << "Square: " << c * c << "\n";
    cout << "Cube: " << pow(c, 3) << "\n";
    cout << "Log: " << log(c) << "\n";
  }
};

class hybridCalculator : public simpleCalculator, public scientificCalculator {
public:
  void hcalc() {
    scalc();
    sCcalc();
  }
};

int main() {
  hybridCalculator hc;
  hc.simpleCalculator::enter();
  hc.scientificCalculator::enter();
  hc.hcalc();
  return 0;
}