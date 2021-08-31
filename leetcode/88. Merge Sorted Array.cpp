#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums1, vector<int>& nums2) {
  int n = nums2.size(), m = nums1.size() - n;
  vector<int> temp(m + n);
  int i = 0, j = 0;
  while (i < m && j < n) {
    if (nums2[j] < nums1[i]) temp[i + j] = nums2[j], j++;
    else temp[i + j] = nums1[i], i++;
  }
  if (i < m) copy(nums1.begin() + i, nums1.begin() + m, temp.begin() + i + j);
  else copy(nums2.begin() + j, nums2.end(), temp.begin() + i + j);
  nums1 = temp;
}

int main() {
  vector<int> nums1{ 2,0 }, nums2{ 1 };
  solve(nums1, nums2);
  for (auto&& i : nums1) {
    cout << i << " ";
  }
  return 0;
}