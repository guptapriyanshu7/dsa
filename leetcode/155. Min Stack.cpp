#include <bits/stdc++.h>

using namespace std;

class MinStack {
  struct Node {
    int val;
    int min;
    Node* next;
    Node(int val, int min, Node* next) : val(val), min(min), next(next) {}
  }* head = nullptr;

  public:
  void push(int x) {
    if (head == nullptr)
      head = new Node(x, x, nullptr);
    else
      head = new Node(x, min(x, head->min), head);
  }

  void pop() {
    head = head->next;
  }

  int top() {
    return head->val;
  }

  int getMin() {
    return head->min;
  }
};

int main() {
  MinStack* obj = new MinStack();
  obj->push(-1);
  obj->push(3);
  obj->push(2);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  cout << param_3 << " " << param_4;
  return 0;
}
