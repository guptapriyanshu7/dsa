// C++ operator and function overloading, the classic simple complex number example
#include <iostream>
using namespace std;
class complexnum {
private:
    double p, q;
public:
    // constructor forming the a + bi
    // overloaded function, with two arguments
    complexnum(double a, double b) {
        p = a;
        q = b;
    }
    // Constructor forming the a + 0i
    // overloaded function, with single argument
    complexnum(double a) {
        p = a;
        q = 0;
    }
    // returns the real part
    double realpart() {
        return p;
    }
    // returns the complex part
    double imaginarypart() {
        return q;
    }
    // addition operation of two complex numbers
    // overloaded operator +
    complexnum operator+(complexnum a) {
        return complexnum(a.p + p, a.q + q);
    }
    // addition a complex number and a double
    // overloaded operator +
    complexnum operator+(double a) {
        return complexnum(p + a, q);
    }
    // subtraction operation of two complex numbers
    // overloaded operator -
    complexnum operator-(complexnum a) {
        return complexnum(p - a.p, q - a.q);
    }
    // subtraction a complex number and a double
    // overloaded operator -
    complexnum operator-(double a) {
        return complexnum(p - a, q);
    }
};
// display format for complex number
// overloaded operator <<
ostream& operator<<(ostream& s, complexnum r) {
    // if no imaginary part
    if (r.imaginarypart() == 0)
        // return real part only
        return s << r.realpart();
    // if imaginary part < 0, i.e negative
    else {
        // and if no real part
        if (r.realpart() == 0)
            // return imaginary part only
            return s << r.imaginarypart() << "i";
        else
            // return both real and imaginary parts
            return s << r.realpart() << ((r.imaginarypart() < 0) ? " " : "+") << r.imaginarypart() << "i";
    }
}

int main() {
    double a, b;
    // prompt for two numbers
    cout << "Enter 2 numbers: ";
    // read and store the two numbers
    cin >> a >> b;
    complexnum r = complexnum(a, b);
    cout << "\nThe complex form is r = " << r << endl;
    complexnum t = complexnum(7.0);
    cout << "\nGiven t = " << t << endl;
    // addition of complex number and constant
    cout << "\nThen, r + t = " << (r + t) << endl;
    // subtraction of complex number and complex number
    cout << "\nThen, r - (4 + 2i) = " << (r - complexnum(4, 2)) << endl;
    // addition of complex number and complex number
    cout << "\nThen, r + (2 + 2i) = " << (r + complexnum(2, 2)) << endl;
    return 0;
}
