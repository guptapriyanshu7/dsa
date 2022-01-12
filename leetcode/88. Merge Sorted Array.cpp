#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums1, size_t m, vector<int>& nums2, size_t n) {
  if (n == 0) return;
  size_t i = 0, j = 0;
  while (i < m) {
    if (nums1[i] > nums2[j]) {
      swap(nums1[i], nums2[j]);
      sort(nums2.begin(), nums2.end());
    }
    i++;
  }
  while (j < n) nums1[i++] = nums2[j++];
}

int main() {
  vector<int> nums1{ 2, 0 }, nums2{ 1 };
  solve(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
  for (auto&& i: nums1) {
    cout << i << " ";
  }
  return 0;
}