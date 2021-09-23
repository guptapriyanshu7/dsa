#include <bits/stdc++.h>

using namespace std;

int solve(string text, string brokenLetters) {
  int count = 0;
  istringstream iss(text), issc(text);
  string word;
  while (issc >> word)
    count++;
  while (iss >> word) {
    for (auto a : word) {
      if (brokenLetters.find(a) != string::npos) {
        count--;
        break;
      }
    }
  }
  cout << count;
  return count;
}

int main() {
  solve("hello world", "ad");
  return 0;
}