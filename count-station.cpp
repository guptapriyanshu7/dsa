#include <iostream>

using namespace std;

int binomialCoeff(int n, int k) {
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;
  return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int main() {
  int n, s;
  cin >> n >> s;
  if (binomialCoeff(n - s + 1, s) == 0) {
    cout << "NA";
  } else {
    cout << binomialCoeff(n - s + 1, s);
  }
  return 0;
}