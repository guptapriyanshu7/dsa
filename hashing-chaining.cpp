#include <iostream>
#include <list>

using namespace std;

class Hash {
  int BUCKETS;
  list<int>* table;

  public:
  Hash(int);
  void insertItem(int);
  void deleteItem(int);
  void displayHash();
  int hashFunction(int x) {
    return (x % BUCKETS);
  }
};

Hash::Hash(int buckets) {
  BUCKETS = buckets;
  table   = new list<int>[BUCKETS];  // 7 lists, table is pointer to the first list
}

void Hash::insertItem(int value) {
  int index = hashFunction(value);
  table[index].push_back(value);
}

void Hash::deleteItem(int value) {
  int index = hashFunction(value);
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == value) {
      table[index].erase(i);
      return;
    }
  }
  cout << "NOT FOUND\n";
}

void Hash::displayHash() {
  list<int>::iterator i;
  for (int index = 0; index < BUCKETS; index++) {
    cout << index << " -> ";
    for (i = table[index].begin(); i != table[index].end(); i++) {
      cout << *i << " ";
    }
    cout << "\n";
  }
}

int main() {
  int a[] = { 15, 11, 27, 8, 12, 6, 4, 44, 34, 3, 5, 56 };
  int n   = sizeof(a) / sizeof(a[0]);
  Hash h(7);
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);
  h.deleteItem(5);
  h.displayHash();
  return 0;
}