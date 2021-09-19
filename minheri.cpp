#include <math.h>

#include <iostream>
using namespace std;

class AB {
  public:
  int a, b;

  void input1() {
    cout << "Enter values for simple calculator: ";
    cin >> a >> b;
  }

  void disp1() {
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
  }
};

class C {
  public:
  int c;

  void input2() {
    cout << "Enter values for scientific calculator: ";
    cin >> c;
  }

  void disp2() {

    cout << "Square root: " << pow(c, 0.5) << endl;
    cout << "Square: " << pow(c, 2) << endl;
    cout << "Cube: " << pow(c, 3) << endl;
    cout << "Log: " << log(c) << endl;
  }
};

class Display : public AB, public C {
  public:
  void disp() {
    disp1();
    disp2();
  }
};

int main() {
  Display obj;
  obj.input1();
  obj.input2();
  obj.disp();

  return 0;
}