#include <bits/stdc++.h>

#define null INT_MAX

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

bool solve(TreeNode* root, int targetSum) {
  if (root == nullptr) return false;
  if (root->left == nullptr && root->right == nullptr) return targetSum == root->val;
  return solve(root->left, targetSum - root->val) || solve(root->right, targetSum - root->val);
}

int main() {
  vector<int> nums{ 5,4,8,11,null,13,4,7,2,null,null,null,1 };
  cout << solve(TreeFromArray(nums), 22);
  return 0;
}