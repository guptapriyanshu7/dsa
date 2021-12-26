#include <iostream>
#include <vector>

void merge(std::vector<int>& vec, size_t l, size_t m, size_t r) {
  std::vector<int> temp;
  auto i = l, j = m + 1;

  while (i <= m && j <= r) {
    if (vec[i] <= vec[j]) {
      temp.push_back(vec[i]);
      ++i;
    } else {
      temp.push_back(vec[j]);
      ++j;
    }
  }

  while (i <= m) {
    temp.push_back(vec[i]);
    ++i;
  }

  while (j <= r) {
    temp.push_back(vec[j]);
    ++j;
  }

  for (auto k = l; k <= r; ++k)
    vec[k] = temp[k - l];
}

void divide(std::vector<int>& vec, size_t l, size_t r) {
  if (l >= r) return;
  auto mid = l + (r - l) / 2;
  divide(vec, l, mid);
  divide(vec, mid + 1, r);
  merge(vec, l, mid, r);
}

int main() {
  std::vector<int> vec{ 4, 1, 5, 3, 7 };
  divide(vec, 0, vec.size() - 1);
  for (auto&& i: vec)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
