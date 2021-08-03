#include <bits/stdc++.h>

#define null __INT_MAX__

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left, * right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* TreeFromArray(vector<int>& array) {
  int len = array.size();
  if (len == 0)
    return nullptr;
  int nextItem = 0;
  auto root = new TreeNode(array[nextItem++]);
  queue<TreeNode*> q;
  q.push(root);
  while (q.size() > 0 && nextItem < len) {
    auto current = q.front();
    q.pop();
    const int item = array[nextItem++];
    if (item != null) {
      auto node = new TreeNode(item);
      current->left = node;
      q.push(node);
    }
    if (nextItem < len) {
      const int item = array[nextItem++];
      if (item != null) {
        auto node = new TreeNode(item);
        current->right = node;
        q.push(node);
      }
    }
  }
  return root;
}

int dfs(int d, TreeNode* root) {
  if (root == nullptr) return d - 1;
  if (root->left == nullptr)
    return dfs(d + 1, root->right);
  else if (root->right == nullptr)
    return dfs(d + 1, root->left);
  int depth = min(dfs(d + 1, root->left), dfs(d + 1, root->right));
  return depth;
}

int solve(TreeNode* root) {
  return dfs(1, root);
}

int main() {
  vector<int> nums{ 3,9,20,null,null,15,7 };
  cout << solve(TreeFromArray(nums));
  return 0;
}