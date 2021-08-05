#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr) {
  vector<pair<int, int>> res(arr.size());
  stack<int> st;
  st.push(0);
  res[0] = { 0, -1 };
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[st.top()]) {
      st.push(i);
      res[i] = { i, -1 };
    } else {
      while (!st.empty() && arr[i] > arr[st.top()]) {
        auto p = st.top();
        st.pop();
        res[p].second = i - 1;
        res[i].first = res[p].first;
      }
      st.push(i);
      res[i].second = -1;
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
  int t;
  cin >> t;
  while (t--) {
    int size;
    cin >> size;
    vector<int> arr(size);
    for (size_t i = 0; i < size; i++)
      cin >> arr[i];
    solve(arr);
  };
  return 0;
}