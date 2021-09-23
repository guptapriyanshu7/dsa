#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n) {
  vector<int> ans;
  for (size_t i = 0; i <= n; i++) {
    int c = 0, num = i;
    while (num) {
      num &= (num - 1);
      c++;
    }
    ans.push_back(c);
  }
  for (auto&& i : ans) {
    cout << i << " ";
  }
  return ans;
}

int main() {
  solve(5);
  return 0;
}