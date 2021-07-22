#include <iostream>

using namespace std;

int dimensions[] = { 10, 100, 20, 5, 80 };
const int n = sizeof(dimensions) / sizeof(dimensions[0]);
int dp[n][n];
int divisions[n][n];

void print(int arr[][n]) {
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      cout << arr[i][k] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

void printParenthesis(int i, int j, char &name) {
  if (i == j) {
    cout << name++;
    return;
  }
  cout << "(";
  printParenthesis(i, divisions[i][j], name);
  printParenthesis(divisions[i][j] + 1, j, name);
  cout << ")";
}

int matrixMultiplication() {
  int i, j, k, L, q;
  for (L = 2; L < n; L++) {
    for (i = 1; i < n - L + 1; i++) {
      j = i + L - 1;
      dp[i][j] = INT_MAX;
      for (k = i; k < j; k++) {
        q = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
        if (q < dp[i][j]) {
          dp[i][j] = q;
          divisions[i][j] = k;
        }
      }
    }
  }
  print(dp);
  print(divisions);
  char name = 'A';
  printParenthesis(1, n - 1, name);
  cout << '\n';
  return dp[1][n - 1];
}

int main() {
  cout << matrixMultiplication();
  return 0;
}
