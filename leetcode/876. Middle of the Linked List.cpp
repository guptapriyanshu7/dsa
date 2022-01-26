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
  auto cnt   = 0;
  auto* temp = head;
  while (temp != nullptr) {
    cnt++;
    temp = temp->next;
  }
  for (auto i = 0; i < cnt / 2; i++) head = head->next;
  return head;
}

ListNode* LinkedListFromArray(vector<int>& nums) {
  int len = nums.size();
  if (len == 0) return nullptr;
  auto head = new ListNode(nums[0]), temp = head;
  for (int i = 1; i < len; i++) {
    auto node  = new ListNode(nums[i]);
    temp->next = node;
    temp       = node;
  }
  return head;
}

int main() {
  vector<int> nums{ 1, 2, 3, 4, 5, 6 };
  auto node = solve(LinkedListFromArray(nums));
  while (node != nullptr) {
    cout << node->val << " ";
    node = node->next;
  }
  return 0;
}