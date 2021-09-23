#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> perm;

void heapPermutation(int a[], int size, int n) {
	if (size == 1) {
		vector<int> b;
		for (int i = 0; i < n; i++) {
			b.push_back(a[i]);
		}
		perm.push_back(b);
		return;
	}
	for (int i = 0; i < size; i++) {
		heapPermutation(a, size - 1, n);
		if (size % 2 == 1)
			swap(a[0], a[size - 1]);
		else
			swap(a[i], a[size - 1]);
	}
}

void reverse(int Cost, int n) {
	int arr[n];
	for (int j = 0; j < n; j++) {
		arr[j] = j + 1;
	}
	heapPermutation(arr, n, n);
	for (int k = 0; k < perm.size(); k++) {
		int cost = 0;
		int a[n];
		for (int i = 0; i < n; i++) {
			a[i] = perm[k][i];
		}
		for (int i = 0; i < n - 1; i++) {
			int j;
			for (j = i; j < n; j++) {
				if (perm[k][j] == i + 1) {
					break;
				}
			}
			reverse(perm[k].begin() + i, perm[k].begin() + j + 1);
			cost += j - i + 1;
		}
		if (cost == Cost) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			return;
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}

int main() {
	int caseNo = 1, t;
	cin >> t;
	while (caseNo <= t) {
		int n, cost;
		cin >> n >> cost;
		perm.assign(0, vector<int>(n));
		cout << "Case #" << caseNo << ": ";
		reverse(cost, n);
		caseNo++;
	}
	return 0;
}