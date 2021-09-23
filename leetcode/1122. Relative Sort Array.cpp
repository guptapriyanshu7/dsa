#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& arr1, vector<int>& arr2) {
  map<int, int> map;
  for (int n : arr1) map[n]++;
  int i = 0;
  for (int n : arr2) {
    for (int j = 0; j < map[n]; j++)
      arr1[i++] = n;
    map.erase(n);
  }
  for (auto pair : map)
    for (int j = 0; j < pair.second; j++)
      arr1[i++] = pair.first;
  return arr1;
}

int main() {
  vector<int> arr1{ 2,3,1,3,2,4,6,7,9,2,19 }, arr2{ 2,1,4,3,9,6 };
  solve(arr1, arr2);
  return 0;
}