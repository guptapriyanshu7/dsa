#include <bits/stdc++.h>

using namespace std;

bool solve(string str) {
	stack<char> s;
	for (auto&& c : str) {
		switch (c) {
			case '(': s.push(')'); break;
			case '{': s.push('}'); break;
			case '[': s.push(']'); break;
			default:
				if (s.empty() || c != s.top()) return false;
				s.pop();
		}
	}
	return s.empty();
}

int main() {
	cout << solve("()[]{}");
	return 0;
}