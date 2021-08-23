#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* solve(ListNode* l1, ListNode* l2) {
  auto head = new ListNode();
  auto ans = head;
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val <= l2->val) {
      ans->next = l1;
      l1 = l1->next;
    } else {
      ans->next = l2;
      l2 = l2->next;
    }
    ans = ans->next;
  }
  ans->next = l1 ? l1 : l2;
  return head->next;
}

ListNode* LinkedListFromArray(vector<int>& nums) {
  int len = nums.size();
  if (len == 0) return nullptr;
  auto head = new ListNode(nums[0]), temp = head;
  for (int i = 1; i < len; i++) {
    auto node = new ListNode(nums[i]);
    temp->next = node;
    temp = node;
  }
  return head;
}

int main() {
  vector<int> l1{ 1,2,4 }, l2{ 1,3,4 };
  solve(LinkedListFromArray(l1), LinkedListFromArray(l2));
  return 0;
}