#include <iostream>
#include <memory>

struct Node {
  int data{};
  std::unique_ptr<Node> next;
};

class List {
public:
  void push(int new_data) {
    auto new_node  = std::make_unique<Node>();
    new_node->data = new_data;
    new_node->next = std::move(m_head);
    m_head         = std::move(new_node);
  }

  void print() {
    auto* temp = m_head.get();
    while (temp != nullptr) {
      std::cout << temp->data << std::endl;
      temp = temp->next.get();
    }
  }

private:
  std::unique_ptr<Node> m_head;
};

int main() {
  List list;
  list.push(1);
  list.push(2);
  list.push(3);
  list.print();
}
