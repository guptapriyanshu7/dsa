#include <bits/stdc++.h>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
  if (a[0] == b[0])
    return a[1] > b[1];
  return a[0] < b[0];
}

int solve(vector<vector<int>>& nums) {
  int cnt = 0;
  sort(nums.begin(), nums.end(), comp);
  stack<int> st;
  st.push(nums[0][1]);
  for (size_t i = 1; i < nums.size(); i++) {
    while (!st.empty() && st.top() < nums[i][1]) {
      st.pop();
      cnt++;
    }
    st.push(nums[i][1]);
  }
  return cnt;
}

int main() {
  vector<vector<int>> nums{ {1,1},{1,2},{2,1},{2,2} };
  cout << solve(nums);
  return 0;
}

/*
1 2
1 1
2 2
2 1
*/