#include <bits/stdc++.h>

using namespace std;

void printSolution(vector<vector<int>>& board) {
	auto N = board.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}

bool isSafe(vector<vector<int>>& board, int row, int col) {
	auto N = board.size();
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = row + 1, j = col - 1; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;
	return true;
}

void solveNQUtil(vector<vector<int>>& board, int col, int& c) {
	auto N = board.size();
	if (col == N) {
		printSolution(board);
		c++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			solveNQUtil(board, col + 1, c);
			board[i][col] = 0;
		}
	}
}

int solve(int N) {
	vector<vector<int>> board(N);
	for (size_t i = 0; i < N; i++) {
		board[i].resize(N, 0);
	}
	int c = 0;
	solveNQUtil(board, 0, c);
	return c;
}

int main() {
	cout << solve(7);
	return 0;
}