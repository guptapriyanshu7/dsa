#include <bits/stdc++.h>

using namespace std;

int solve(int num) {
  int bits = floor(log2(num)) + 1; // 4
  int allOnes = pow(2, bits) - 1; // 1111
  return num ^ allOnes; // 1101 ^ 1111 = 0010
}

int main() {
  cout << solve(13);
  return 0;
}