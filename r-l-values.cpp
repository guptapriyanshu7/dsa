// #include <bits/stdc++.h>

// using namespace std;

// int global_int = 1;

// // T as int is r-value
// // T as int& is l-value
// template <typename T>
// T get_vector() {
//   return global_int;
// }

// // v is r-value ref
// int main() {
//   auto&& v = get_vector<int>();
//   v = 5;
//   cout << v << " " << global_int << endl;
//   cout << &v << " " << &global_int;
//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

vector<int> global_vec{ 1, 2, 3 };

template <typename T>
T get_vector() {
  return global_vec;
}

template <typename T>
void foo() {
  auto&& vec = get_vector<T>();
  auto i = begin(vec);
  (*i)++;
  cout << vec[0] << endl;
}

int main() {
  foo<vector<int>>();
  cout << global_vec[0] << endl;
  foo<vector<int>&>();
  cout << global_vec[0] << endl;
  return 0;
}
