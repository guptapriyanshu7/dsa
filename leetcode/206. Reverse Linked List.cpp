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
  ListNode* prev = nullptr, * curr = head;
  while (curr != nullptr) {
    auto temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

ListNode* solveR(ListNode* head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  auto last = solveR(head->next);
  head->next->next = head;
  head->next = nullptr;
  return last;
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
  vector<int> nums{};
  solveR(LinkedListFromArray(nums));
  return 0;
}