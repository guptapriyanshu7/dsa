#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node* parent  = nullptr;
  bool isLocked = false;
  int user      = 0;
  vector<Node*> ch;
};

class LockingTree {
  vector<Node> lockTree;

  bool isAnyAncestorLocked(Node* parent) {
    if (parent == nullptr) return false;
    return parent->isLocked || isAnyAncestorLocked(parent->parent);
  }

  void unlockDescendents(Node& node) {
    for (auto&& x : node.ch) {
      x->user     = 0;
      x->isLocked = false;
      unlockDescendents(*x);
    }
  }

  bool checkDescendents(Node& node) {
    for (auto&& x : node.ch) {
      if (x->isLocked || checkDescendents(*x)) return true;
    }
    return false;
  }

  public:
  LockingTree(vector<int>& parent) {
    lockTree.resize(parent.size());
    for (size_t i = 1; i < parent.size(); i++) {
      lockTree[i].parent = &lockTree[parent[i]];
      lockTree[parent[i]].ch.push_back(&lockTree[i]);
    }
  }

  bool lock(int num, int user) {
    if (!lockTree[num].isLocked) {
      lockTree[num].user            = user;
      return lockTree[num].isLocked = true;
    }
    return false;
  }

  bool unlock(int num, int user) {
    if (lockTree[num].isLocked && lockTree[num].user == user) {
      lockTree[num].user     = 0;
      lockTree[num].isLocked = false;
      return true;
    }
    return false;
  }

  bool upgrade(int num, int user) {
    if (lockTree[num].isLocked) return false;

    if (isAnyAncestorLocked(lockTree[num].parent)) return false;

    if (!checkDescendents(lockTree[num])) return false;

    unlockDescendents(lockTree[num]);
    return lock(num, user);
  }
};

int main() {
  vector<int> nums{ -1, 0, 0, 1, 1, 2, 2 };
  LockingTree* obj = new LockingTree(nums);
  bool param_1     = obj->lock(2, 2);
  bool param_2     = obj->unlock(2, 3);
  bool param_3     = obj->unlock(2, 2);
  bool param_4     = obj->lock(4, 5);
  bool param_5     = obj->upgrade(0, 1);
  bool param_6     = obj->lock(0, 1);
  cout << param_1 << param_2 << param_3 << param_4 << param_5 << param_6;
  return 0;
}