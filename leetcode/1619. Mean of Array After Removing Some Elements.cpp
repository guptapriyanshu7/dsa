#include <bits/stdc++.h>

using namespace std;

double solve(vector<int>& arr) {
  int len = arr.size(), percent = (5 * len) / 100, sum = 0;
  sort(arr.begin(), arr.end());
  arr.erase(arr.begin(), arr.begin() + percent);
  arr.erase(arr.end() - percent, arr.end());
  for (auto i : arr)
    sum += i;
  return (double)sum / arr.size();
}

int main() {
  vector<int> nums{ 6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4 };
  cout << solve(nums);
  return 0;
}