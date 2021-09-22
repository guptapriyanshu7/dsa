#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* solve(ListNode* head, int val) {
  auto* temp = head;
  while (temp != nullptr) {
    if (temp->val == val) {
      head = temp->next;
      delete temp;
      temp = head;
    } else if (temp->next != nullptr && temp->next->val == val) {
      auto* save_pointer = temp->next->next;
      delete temp->next;
      temp->next = save_pointer;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

ListNode* LinkedListFromArray(const vector<int>& nums) {
  auto len = nums.size();
  if (len == 0) return nullptr;
  auto* head = new ListNode(nums[0]);
  auto* temp = head;
  for (size_t i = 1; i < len; i++) {
    auto* node = new ListNode(nums[i]);
    temp->next = node;
    temp       = node;
  }
  return head;
}

int main() {
  vector<int> nums{ 6, 6, 3, 4, 5, 6 };
  auto* i = solve(LinkedListFromArray(nums), 6);
  while (i != nullptr) {
    cout << i->val << " ";
    i = i->next;
  }
  return 0;
}