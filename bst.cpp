#include <iostream>

using namespace std;

class BST {
  int data;
  BST *left, *right;

  public:
  BST();
  BST(int);
  BST* Insert(BST*, int);
  void Delete(BST*&, int);
  void Inorder(BST*);
};

BST::BST() : data(0), left(nullptr), right(nullptr) {}

BST::BST(int value) : BST() {
  data = value;
}

BST* BST::Insert(BST* root, int value) {
  if (!root) {
    return new BST(value);
  }
  if (value > root->data) {
    root->right = Insert(root->right, value);
  } else {
    root->left = Insert(root->left, value);
  }
  return root;
}

void BST::Delete(BST*& root, int value) {
  if (!root) {
    return;
  }
  if (root->data == value) {
    if (!root->left && !root->right) {
      delete root;
      root = nullptr;
    } else if (!root->left || !root->right) {
      BST* child = root->left ? root->left : root->right;
      BST* curr  = root;
      root       = child;
      delete curr;
      curr = nullptr;
    } else {
      BST* inorderSuccessor = root->right;
      while (inorderSuccessor->left) {
        inorderSuccessor = inorderSuccessor->left;
      }
      root->data = inorderSuccessor->data;
      Delete(root->right, inorderSuccessor->data);
    }
  } else if (value > root->data) {
    Delete(root->right, value);
  } else {
    Delete(root->left, value);
  }
}

void BST::Inorder(BST* root) {
  if (!root) {
    return;
  }
  Inorder(root->left);
  cout << root->data << " ";
  Inorder(root->right);
}

int main() {
  BST bst, *root = nullptr;
  int keys[] = { 4, 2, 7, 5, 6, 1, 3 };
  for (int key : keys) {
    root = bst.Insert(root, key);
  }
  bst.Delete(root, 4);
  bst.Inorder(root);
  return 0;
}