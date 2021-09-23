#include <bits/stdc++.h>

using namespace std;

void saveSolution(vector<vector<int>>& board, vector<vector<string>>& res) {
  auto N = board.size();
  vector<string> sol;
  for (int i = 0; i < N; i++) {
    string s = "";
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0)
        s += ".";
      else
        s += "Q";
    }
    sol.push_back(s);
  }
  res.push_back(sol);
}

bool isSafe(vector<vector<int>>& board, int row, int col) {
  auto N = board.size();
  for (int i = 0; i < col; i++)
    if (board[row][i]) return false;
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;
  for (int i = row + 1, j = col - 1; j >= 0 && i < N; i++, j--)
    if (board[i][j]) return false;
  return true;
}

void solveNQUtil(vector<vector<int>>& board, int col, vector<vector<string>>& res) {
  auto N = board.size();
  if (col == N) {
    saveSolution(board, res);
    return;
  }
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      solveNQUtil(board, col + 1, res);
      board[i][col] = 0;
    }
  }
}

vector<vector<string>> solve(int N) {
  vector<vector<int>> board(N);
  for (size_t i = 0; i < N; i++)
    board[i].resize(N, 0);
  vector<vector<string>> res;
  solveNQUtil(board, 0, res);
  return res;
}

int main() {
  cout << solve(8).size();
  return 0;
}