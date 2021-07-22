#include <iostream>

using namespace std;

const int operands[] = { 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0 };
const string operators = "|^&|^^^|&^|^^&^|^";
const int n = sizeof(operands) / sizeof(operands[0]);
int dp[n][n];
int c[n + 1];
const int MOD = 1003;

void catalan() {
  c[0] = 1;
  c[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      c[i] += c[j] * c[(i - 1) - j];
      c[i] %= MOD;
    }
  }
}

void print(int arr[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
}

int count() {
  int i, j, k, L, q;
  catalan();
  for (i = 0; i < n; i++)
    dp[i][i] = operands[i];
  for (L = 2; L <= n; L++) {
    for (i = 0; i < n - L + 1; i++) {
      j = i + L - 1;
      for (k = i; k < j; k++) {
        if (operators[k] == '&') {
          dp[i][j] += dp[i][k] * dp[k + 1][j];
          dp[i][j] %= MOD;
        } else if (operators[k] == '|') {
          int left = c[k - i];
          int right = c[j - (k + 1)];
          int total = left * right;
          dp[i][j] += total - (left - dp[i][k]) * (right - dp[k + 1][j]);
          dp[i][j] %= MOD;
        } else {
          int left = c[k - i];
          int right = c[j - (k + 1)];
          dp[i][j] += dp[i][k] * (right - dp[k + 1][j]) + (left - dp[i][k]) * dp[k + 1][j];
          dp[i][j] %= MOD;
          if (dp[i][j] < 0)
            dp[i][j] += MOD;
        }
      }
    }
  }
  print(dp);
  return dp[0][n - 1];
}

int main() {
  cout << count();
  return 0;
}