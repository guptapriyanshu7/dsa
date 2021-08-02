#include <bits/stdc++.h>

#define MAX_HEIGHT 1000
#define null __INT_MAX__

typedef struct asciinode_struct asciinode;

using namespace std;

int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
int gap = 3;
int print_next;

struct TreeNode {
  int val;
  TreeNode* left, * right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct asciinode_struct {
  asciinode* left, * right;
  int edge_length, height, lablen, parent_dir;
  char label[11];
};

asciinode* build_ascii_TreeNode_recursive(TreeNode* t) {
  asciinode* node;
  if (t == nullptr) return nullptr;
  node = (asciinode*)malloc(sizeof(asciinode));
  node->left = build_ascii_TreeNode_recursive(t->left);
  node->right = build_ascii_TreeNode_recursive(t->right);
  if (node->left != nullptr)
    node->left->parent_dir = -1;
  if (node->right != nullptr)
    node->right->parent_dir = 1;
  sprintf(node->label, "%d", t->val);
  node->lablen = strlen(node->label);
  return node;
}

asciinode* build_ascii_TreeNode(TreeNode* t) {
  asciinode* node;
  if (t == nullptr) return nullptr;
  node = build_ascii_TreeNode_recursive(t);
  node->parent_dir = 0;
  return node;
}

void free_ascii_TreeNode(asciinode* node) {
  if (node == nullptr) return;
  free_ascii_TreeNode(node->left);
  free_ascii_TreeNode(node->right);
  free(node);
}

void compute_lprofile(asciinode* node, int x, int y) {
  int i, isleft;
  if (node == nullptr) return;
  isleft = (node->parent_dir == -1);
  lprofile[y] = min(lprofile[y], x - ((node->lablen - isleft) / 2));
  if (node->left != nullptr)
    for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
      lprofile[y + i] = min(lprofile[y + i], x - i);
  compute_lprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
  compute_lprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_rprofile(asciinode* node, int x, int y) {
  int i, notleft;
  if (node == nullptr) return;
  notleft = (node->parent_dir != -1);
  rprofile[y] = max(rprofile[y], x + ((node->lablen - notleft) / 2));
  if (node->right != nullptr)
    for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
      rprofile[y + i] = max(rprofile[y + i], x + i);
  compute_rprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
  compute_rprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_edge_lengths(asciinode* node) {
  int h, hmin, i, delta;
  if (node == nullptr) return;
  compute_edge_lengths(node->left);
  compute_edge_lengths(node->right);
  if (node->right == nullptr && node->left == nullptr)
    node->edge_length = 0;
  else {
    if (node->left != nullptr) {
      for (i = 0; i < node->left->height && i < MAX_HEIGHT; i++)
        rprofile[i] = -null;
      compute_rprofile(node->left, 0, 0);
      hmin = node->left->height;
    } else hmin = 0;
    if (node->right != nullptr) {
      for (i = 0; i < node->right->height && i < MAX_HEIGHT; i++)
        lprofile[i] = null;
      compute_lprofile(node->right, 0, 0);
      hmin = min(node->right->height, hmin);
    } else hmin = 0;
    delta = 4;
    for (i = 0; i < hmin; i++)
      delta = max(delta, gap + 1 + rprofile[i] - lprofile[i]);
    if (((node->left != nullptr && node->left->height == 1) ||
      (node->right != nullptr && node->right->height == 1)) && delta > 4)
      delta--;
    node->edge_length = ((delta + 1) / 2) - 1;
  }
  h = 1;
  if (node->left != nullptr)
    h = max(node->left->height + node->edge_length + 1, h);
  if (node->right != nullptr)
    h = max(node->right->height + node->edge_length + 1, h);
  node->height = h;
}

void print_level(asciinode* node, int x, int level) {
  int i, isleft;
  if (node == nullptr) return;
  isleft = (node->parent_dir == -1);
  if (level == 0) {
    for (i = 0; i < (x - print_next - ((node->lablen - isleft) / 2)); i++)
      printf(" ");
    print_next += i;
    printf("%s", node->label);
    print_next += node->lablen;
  } else if (node->edge_length >= level) {
    if (node->left != nullptr) {
      for (i = 0; i < (x - print_next - (level)); i++)
        printf(" ");
      print_next += i;
      printf("/");
      print_next++;
    }
    if (node->right != nullptr) {
      for (i = 0; i < (x - print_next + (level)); i++)
        printf(" ");
      print_next += i;
      printf("\\");
      print_next++;
    }
  } else {
    print_level(node->left,
      x - node->edge_length - 1,
      level - node->edge_length - 1);
    print_level(node->right,
      x + node->edge_length + 1,
      level - node->edge_length - 1);
  }
}

void print_ascii_TreeNode(TreeNode* t) {
  asciinode* proot;
  int xmin, i;
  if (t == nullptr) return;
  proot = build_ascii_TreeNode(t);
  compute_edge_lengths(proot);
  for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
    lprofile[i] = null;
  }
  compute_lprofile(proot, 0, 0);
  xmin = 0;
  for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    xmin = min(xmin, lprofile[i]);
  for (i = 0; i < proot->height; i++) {
    print_next = 0;
    print_level(proot, -xmin, i);
    printf("\n");
  }
  if (proot->height >= MAX_HEIGHT)
    printf("(This TreeNode is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
  free_ascii_TreeNode(proot);
}

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

void dfs(TreeNode* root, vector<int>& leaves) {
  if (root == nullptr) return;
  if (root->left == nullptr && root->right == nullptr)
    leaves.push_back(root->val);
  dfs(root->left, leaves);
  dfs(root->right, leaves);
}

bool solve(TreeNode* root1, TreeNode* root2) {
  vector<int> leaves1, leaves2;
  dfs(root1, leaves1);
  dfs(root2, leaves2);
  return leaves1 == leaves2;
}

int main() {
  vector<int> nums1{ 119,113,null,11,30,43,76,15,60,67,74 };
  vector<int> nums2{ 11,69,60,115,66,15,60,67,74,null,76 };
  print_ascii_TreeNode(TreeFromArray(nums1));
  print_ascii_TreeNode(TreeFromArray(nums2));
  cout << solve(TreeFromArray(nums1), TreeFromArray(nums2));
  return 0;
}