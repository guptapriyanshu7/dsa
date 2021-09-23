#include <bits/stdc++.h>

using namespace std;

bool solve(string coordinates) {
  return ((coordinates[0] - 'a' + 1) + coordinates[1]) % 2;
}

int main() {
  cout << solve("a1");
  return 0;
}