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

vector<double> solve(TreeNode* root) {
  queue<TreeNode*> q;
  vector<double> ans;
  q.push(root);
  while (!q.empty()) {
    long long sum = 0, count = 0;
    queue<TreeNode*> temp;
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      sum += v->val;
      count++;
      if (v->left != nullptr) temp.push(v->left);
      if (v->right != nullptr) temp.push(v->right);
    }
    q = temp;
    ans.push_back(sum * 1.0 / count);
  }
  return ans;
}

int main() {
  vector<int> nums{ 3,9,20,null,15,7 };
  solve(TreeFromArray(nums));
  return 0;
}