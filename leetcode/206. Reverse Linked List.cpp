#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* solve(ListNode* head) {
  if (head == nullptr || head->next == nullptr) return head;
  auto* last       = solve(head->next);
  head->next->next = head;
  head->next       = nullptr;
  return last;
}

ListNode* LinkedListFromArray(vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto *head = new ListNode(nums[0]), *temp = head;
  for (auto i = 1UL; i < nums.size(); i++) {
    temp->next = new ListNode(nums[i]);
    temp       = temp->next;
  }
  return head;
}

int main() {
  vector<int> nums{ 1, 2, 3, 4, 5 };
  auto* head = solve(LinkedListFromArray(nums));
  while (head != nullptr) {
    cout << head->val << " ";
    auto* temp = head;
    head       = head->next;
    delete temp;
  }
  return 0;
}