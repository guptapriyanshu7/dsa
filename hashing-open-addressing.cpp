#include <iostream>
#include <list>
#include <ctime>

#define TABLE_SIZE 7
#define PRIME 5

using namespace std;

class Hash {
  int *table;
  public:
    Hash();
    bool insertItem(int);
    void searchItem(int);
    void deleteItem(int);
    void displayHash();
    int hash1(int x) {
      return (x % TABLE_SIZE);
    }
    int hash2(int x) {
      return (PRIME - (x % PRIME));
    }
};

Hash::Hash() {
  table = new int[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = -1;
  } 
}

bool Hash::insertItem(int value) {
  int index = hash1(value);
  for (int i = 1; i <= TABLE_SIZE; i++) {
    if (table[index] == -1) {
      table[index] = value;
      return false;
    } else {
      index = (hash1(value) + i * hash2(value)) % TABLE_SIZE;
    }
  }
  return true;
}

void Hash::searchItem(int key) {
  int index1 = hash1(key);
  int index2 = hash2(key);
  int i = 0;
  while (table[(index1 + i * index2) % TABLE_SIZE] != key && i < TABLE_SIZE) {
    if (table[(index1 + i * index2) % TABLE_SIZE] == -1) {
      cout << key << " does not exist" << endl;
      return;
    }
    i++;
  }
  if(i == TABLE_SIZE) {
    cout << key << " does not exist" << endl;
  } else {
    cout << key << " found" << endl;
  }
}

void Hash::deleteItem(int value) {
  int index = hash1(value);
  int i;
  for (i = 1; i <= TABLE_SIZE; i++) {
    if (table[index] == value || table[index] == -1) {
      if(table[index] == -1) {
        break;
      }
      table[index] = -1;
      return;
    } else {
      index = (hash1(value) + i * hash2(value)) % TABLE_SIZE;
    }
  }
  cout << "NOT FOUND\n";
}

void Hash::displayHash() {
  for (int index = 0; index < TABLE_SIZE; index++) {
    cout << index << " -> ";
    cout << table[index] << " ";
    cout << "\n";
  }
}

int main() {
  int a[] = { 19, 27, 36, 10, 0, 4, 64, 1, 2 };
  int n = sizeof(a)/sizeof(a[0]);
  Hash h;
  for (int i = 0; i < n; i++) {
    bool full = h.insertItem(a[i]);
    if(full) {
      cout << "TABLE FULL\n";
      break;
    }
  }
  h.deleteItem(64);
  h.searchItem(4);
  h.displayHash();
  cout << "time taken : " << clock() << " ms";
  return 0;
}