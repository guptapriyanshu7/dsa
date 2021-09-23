#include <bits/stdc++.h>

using namespace std;

uint32_t solve(uint32_t n) {
  uint32_t ans = 0, rem;
  for (int i = 0; i < 32; i++) {
    rem = n & 1;
    ans = ans << 1 | rem;
    n >>= 1;
  }
  return ans;
}

int main() {
  cout << solve(43261596);
  return 0;
}