#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num) {
  if(num == 0 || num == 1) return false;
  for (size_t i = 2; i <= sqrt(num); i++)
    if (num % i == 0) 
      return false;
  return true;
}

int solve(int left, int right) {
  auto count = 0;
  for (int i = left; i <= right; i++) {
    auto set = 0, n = i;
    while (n) {
      n &= n - 1;
      set++;
    }
    if (isPrime(set))
      count++;
  }
  return count;
}

int main() {
  cout << solve(6, 10);
  return 0;
}