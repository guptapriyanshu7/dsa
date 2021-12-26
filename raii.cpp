// C++ 17 program to demonstrate
// Structure Bindings

#include <iostream>
#include <map>
#include <string>

// Driver Code
int main() {
  constexpr auto TEN_MILLION = 10'000'000;
  // Key-value pair declared inside
  // Map data structure
  std::map<std::string, std::string> fav_lang{
    { "John", "Java" },
    { "Alex", "C++" },
    { "Peter", "Python" }
  };

  // Structure binding concept used
  // position and success are used
  // in place of first and second
  auto [process, success] = fav_lang.insert({ "Henry", "Golang" });

  // Check boolean value of success
  if (success) {
    std::cout << "Insertion done!!" << std::endl;
  }

  // Iterate over map
  for (const auto& [name, lang]: fav_lang) {
    std::cout << name << ":" << lang << std::endl;
  }

  auto [a, b, c] = std::make_tuple(1, 2, 3);
  std::cout << a << b << c << std::endl;

  return 0;
}

template<typename Container, typename Index>  // final
decltype(auto)                                // C++14
auth_and_access(Container&& c, Index i)       // version
{
  return std::forward<Container>(c)[i];
}
