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


bool isSymmetric(TreeNode* left, TreeNode* right) {
  if (left == nullptr || right == nullptr) return left == right;
  if (left->val != right->val) return false;
  return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool solve(TreeNode* root) {
  return isSymmetric(root->left, root->right);
}

int main() {
  vector<int> nums{ 1,2,2,3,4,4,3 };
  cout << solve(TreeFromArray(nums));
  return 0;
}