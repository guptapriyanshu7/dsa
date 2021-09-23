#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// void for_each(const std::vector<int>& values, void (*func)(int)) {
//   for (auto&& value: values)
//     func(value);
// }

// int main() {
//   std::vector<int> values{ 1, 2, 3, 4 };
//   auto lambda = [](int value) { std::cout << "value: " << value << "\n"; };
//   for_each(values, lambda);
//   return 0;
// }

void for_each(const std::vector<int>& values, const std::function<void(int)>& func) {
  for (auto&& value: values)
    func(value);
}

int main() {
  std::vector<int> values{ 1, 2, 3, 4 };

  auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 4; });
  std::cout << *it << "\n";

  int a = 5;

  // capture specific by value
  auto lambda = [a](int value) mutable { a = 6; std::cout << "value: " << a << "\n"; };
  // capture specific byy ref
  // auto lambda = [&a](int value) { a = 6; std::cout << "value: " << a << "\n"; };
  // capture all by value
  // auto lambda = [=](int value) {  std::cout << "value: " << a << "\n"; };
  // capture all by ref
  // auto lambda = [&](int value) { std::cout << "value: " << a << "\n"; };

  for_each(values, lambda);
  std::cout << a;

  return 0;
}