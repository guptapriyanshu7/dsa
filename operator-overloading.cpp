#include <iostream>

using namespace std;

class Complex {
  int real, img;
  public:
    Complex(int r = 0, int i = 0) {
      real = r;
      img = i;
    }
    Complex operator()(int x, int y) {
      return Complex(real + x, img - y);
    }
    Complex operator+(Complex obj) {
      Complex res;
      res.real = real + obj.real;
      res.img = img + obj.img;
      return res;
    }
    operator float() {
      return float(real) / float(img);
    }
    friend Complex operator-(Complex, Complex);
    friend ostream& operator<<(ostream &output, Complex obj) {
      output << obj.real << " + i" << obj.img;
      return output;
    }
};

Complex operator-(Complex c1, Complex c2) {
  return Complex(c1.real - c2.real, c1.img - c2.img);
}

int main() {
  Complex c1(10, 6), c2(2, 4);
  Complex c3 = c1 + c2 + Complex(0, -2);
  cout << c3 << '\n';
  cout << c1 - c2 << '\n';
  float floaT = c1;
  // cout << float(c1);
  cout << floaT << '\n';
  c2 = 3;
  cout << c2 << '\n';
  Complex c4 = c1(3, 5);
  cout << c4;
  return 0;
}