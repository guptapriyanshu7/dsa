#include <iostream>

using namespace std;

void reverse(string s, int x, int y) {
	int cost = 0, k;
	for (k = 0; k < s.length(); k++) {
		if (s[k] != '?') {
			break;
		}
	}
	if (k == s.length()) {
		if (x < y) {
			s[0] = 'C';
		} else s[0] = 'J';
	}
	if (s[0] == '?') {
		if (x < 0 || y < 0) {
			if (k % 2 == 0)
				s[0] = s[k];
			else
				s[0] = (s[k] == 'C') ? 'J' : 'C';
		} else s[0] = s[k];
	}
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '?') {
			if (x < 0 || y < 0) {
				s[i] = (s[i - 1] == 'C') ? 'J' : 'C';
				if (s[i - 1] == 'C' && s[i] == 'J') {
					if (x > 0) {
						s[i] = 'C';
					}
				}
				if (s[i - 1] == 'J' && s[i] == 'C') {
					if (y > 0) {
						s[i] = 'J';
					}
				}
			} else s[i] = s[i - 1];
		}
		if (s[i - 1] == 'C' && s[i] == 'J') {
			cost += x;
		} else if (s[i - 1] == 'J' && s[i] == 'C') {
			cost += y;
		}
	}
	cout << cost << "\n";
}

int main() {
	int caseNo = 1, t;
	cin >> t;
	while (caseNo <= t) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		cout << "Case #" << caseNo << ": ";
		reverse(s, x, y);
		caseNo++;
	}
	return 0;
}