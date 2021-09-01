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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p->val < root->val && q->val < root->val)
    return lowestCommonAncestor(root->left, p, q);
  else if (p->val > root->val && q->val > root->val)
    return lowestCommonAncestor(root->right, p, q);
  return root;
}

int main() {
  vector<int> nums{ 6,2,8,0,4,7,9,null,null,3,5 };
  auto root = TreeFromArray(nums);
  cout << lowestCommonAncestor(root, root->left, root->right)->val;
  return 0;
}