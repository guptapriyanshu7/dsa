#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val{ 0 };
  ListNode* next{ nullptr };
  ListNode() = default;
  explicit ListNode(int x) : val(x) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* LinkedListFromArray(vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto *head = new ListNode(nums[0]), *temp = head;
  for (auto i = 1UL; i < nums.size(); i++) {
    temp->next = new ListNode(nums[i]);
    temp = temp->next;
  }
  return head;
}

ListNode* solve(ListNode* head, int n) {
  auto cnt = 0;
  auto* temp = head;
  while (temp != nullptr) {
    cnt++;
    temp = temp->next;
  }
  temp = head;
  if (n == cnt) {
    head = head->next;
    delete temp;
    return head;
  }
  for (auto i = 0; i < cnt - n - 1; i++)
    temp = temp->next;
  auto* del = temp->next;
  temp->next = del->next;
  delete del;
  return head;
}

int main() {
  vector<int> nums{ 1, 2, 3, 4, 5 };
  auto* head = solve(LinkedListFromArray(nums), 2);
  while (head != nullptr) {
    cout << head->val << ' ';
    head = head->next;
  }
  return 0;
}