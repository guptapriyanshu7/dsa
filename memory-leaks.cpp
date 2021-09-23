#include <bits/stdc++.h>

#include <memory>

using namespace std;

struct Memory {
  int x = 0;
  explicit Memory(int val) : x(val) {}
};

class Entity {
  public:
  Entity() {
    cout << "Entity created\n";
  }
  void print() {
    cout << "Print Called\n";
  }
  ~Entity() {
    cout << "Entity deleted\n";
  }
};

int main() {
  shared_ptr<Entity> e1;
  {
    unique_ptr<Entity> unq_ent = make_unique<Entity>();
    unq_ent->print();
    cout << "\n";
    shared_ptr<Entity> shared_entity = make_shared<Entity>();
    // unique_ptr<Entity> e0 = ent;
    e1 = shared_entity;
    // unq_ent will be deleted and shared_ptr's references will be reduced to 1
  }
  cout << "\nOut of nested scope\n";
  e1->print();
  Memory* ptr = new Memory(3);
  cout << ptr->x << "\n";
  delete ptr;
  return 0;
  // Finally shared_ptr will be deleted
}