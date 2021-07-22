//using temp variable
#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 3, temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << "\n";
    return 0;
}