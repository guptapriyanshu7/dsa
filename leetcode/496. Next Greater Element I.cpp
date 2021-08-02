#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> uMap;
  stack<int> nums2Stack;
  for (auto&& num2 : nums2) {
    while (!nums2Stack.empty()) {
      auto i = nums2Stack.top();
      if (num2 > i) {
        uMap[i] = num2;
        nums2Stack.pop();
      } else break;
    }
    nums2Stack.push(num2);
  }
  for (auto&& num1 : nums1)
    num1 = uMap.find(num1) != uMap.end() ? uMap[num1] : -1;
  return nums1;
}

int main() {
  vector<int> nums1{ 1, 4 };
  vector<int> nums2{ 2, 1, 3, 4 };
  solve(nums1, nums2);
  return 0;
}