/*
   1010
&  0010
   0010

0010 is acting as a mask allowing only set bits to pass through it.

to check k-th bit is set -
x&(1<<(k - 1))

to turn-off k-th bit -
check whether bit is on then x^(1<<(k - 1)) to turn it off.

rows = person, col = jobs
mat[i][j] = cost of person i doing job j
[
9 4 3 7
2 3 4 8
5 6 7 1
8 2 1 8
]

states: (job to give, persons set available for work)

                    (1, {p1, p2, ..., pn})
         cost[p1][1]   /              \   cost[p2][1]
                      /                \
        (2, {p2, p3, ..., pn})      (2, {p1, p3, ..., pn})
       cost[p2][2]     /              \   cost[p1][2]
                      /                \
(3, {p3, p4, ..., pn})      ==       (3, {p3, p4, ..., pn})   *same states we can memoize*

Checkout: https://sodocumentation.net/algorithm/topic/6631/travelling-salesman
*/

#include <bits/stdc++.h>

using namespace std;

// vector<vector<int>> grid{ { 9,4,3,7 },
//                           { 2,3,4,8 },
//                           { 5,6,7,1 },
//                           { 8,2,1,8 } };
vector<vector<int>> grid{ { 9,2,7,8 },
                          { 6,4,3,7 },
                          { 5,8,1,8 },
                          { 7,6,9,4 } };

int solve(int j, int pset, vector<int>& dp) {
  if (j == grid[0].size()) return 0;
  if (dp[pset] != -1) return dp[pset];
  auto res = INT_MAX;
  for (size_t i = 0; i < grid.size(); i++)
    if (pset & (1 << i))
      res = min(res, grid[i][j] + solve(j + 1, pset ^ (1 << i), dp));
  return dp[pset] = res;
}

int main() {
  vector<int> dp(1 << grid.size(), -1);
  cout << solve(0, (1 << grid.size()) - 1, dp);
  return 0;
}

/*
Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job,
incurring some cost that may vary depending on the work-job assignment.
It is required to perform all jobs by assigning exactly one worker to each job and
exactly one job to each agent in such a way that the total cost of the assignment is
minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning
ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20

*/