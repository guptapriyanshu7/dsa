#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
  vector<string> ans(200);
  istringstream iss(s), issc(s);
  string word, sentence = "";
  int count = 0;

  while (iss >> word) {
    int i = word.size() - 1;
    int y = int(word[i] - '1');
    ans[y] = word.erase(i);
    count++;
  }

  for (size_t i = 0; i < count; i++)
    sentence += " " + ans[i];
  sentence.erase(0, 1);

  return sentence;
}

int main() {
  cout << solve("is2 sentence4 This1 a3");
  return 0;
}