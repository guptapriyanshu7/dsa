#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr) {
  vector<pair<int, int>> res(arr.size());
  stack<int> st;
  st.push(0);
  res[0] = { 0, -1 };
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[st.top()]) {
      res[i] = { i, -1 };
      st.push(i);
      res[i - 1].second = i;
    } else {
      while (!st.empty() && arr[i] > arr[st.top()]) {
        auto p = st.top();
        st.pop();
        res[p].second = i - 1;
        res[i].first = p;
      }
      st.push(i);
    }
  }
  for (auto&& i : res) {
    if (i.second == -1)
      i.second = arr.size() - 1;
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}

int main() {
  vector<int> arr{28, 13, 82, 62, 97, 49, 59, 54, 92, 21 };
  solve(arr);
  return 0;
}