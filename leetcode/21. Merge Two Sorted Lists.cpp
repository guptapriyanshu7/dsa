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

ListNode* solve(ListNode* list1, ListNode* list2) {
  auto *ans = new ListNode(), *temp = ans;
  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      temp->next = list1;
      list1 = list1->next;
    } else {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  temp->next = list1 == nullptr ? list2 : list1;
  return ans->next;
}

int main() {
  vector<int> nums1{}, nums2{};
  solve(LinkedListFromArray(nums1), LinkedListFromArray(nums2));
  return 0;
}