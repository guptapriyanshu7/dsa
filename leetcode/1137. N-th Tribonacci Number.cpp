#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
	auto t0 = 0, t1 = 1, t2 = 1, i = 3;
	if(n <= 1) return n;
	if(n == 2) return 1;
	int ans;
	while (i <= n) {
		ans = t2 + t1 + t0;
		t0 = t1;
		t1 = t2;
		t2 = ans;
		i++;
	}
	return ans;
}

int main() {
	cout << solve(25);
	return 0;
}