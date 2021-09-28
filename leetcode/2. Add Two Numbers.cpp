#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* np) : val(x), next(np) {}
};

ListNode* solve(ListNode* l1, ListNode* l2) {
  auto carry = 0;
  auto head  = new ListNode();
  auto* temp = head;
  while (l1 || l2 || carry) {
    int s = carry;
    if (l1) s += l1->val, l1 = l1->next;
    if (l2) s += l2->val, l2 = l2->next;
    temp->next = new ListNode(s % 10);
    carry      = s / 10;
    temp       = temp->next;
  }
  return head->next;
}

ListNode* LinkedListFromArray(vector<int>& nums) {
  int len = nums.size();
  if (len == 0) return nullptr;
  auto head = new ListNode(nums[0]), temp = head;
  for (int i = 1; i < len; i++) {
    auto* node = new ListNode(nums[i]);
    temp->next = node;
    temp       = node;
  }
  return head;
}

int main() {
  vector<int> nums{ 2, 4, 3 };
  auto* head = solve(LinkedListFromArray(nums), LinkedListFromArray(nums));
  while (head) {
    cout << head->val;
    head = head->next;
  }
  return 0;
}