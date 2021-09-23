#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int numRows) {
	vector<vector<int>> ans(numRows);
	for (size_t i = 0; i < numRows; i++) {
		ans[i].resize(i + 1);
		ans[i][0] = 1;
		ans[i][i] = 1;
		for (size_t j = 1; j < i; j++) {
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	return ans;
}

int main() {
	solve(5);
	return 0;
}