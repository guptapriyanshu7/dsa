#include <bits/stdc++.h>

using namespace std;

class LRUCache {
  int c;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  list<pair<int, int>> l;

  public:
  LRUCache(int capacity) {
    c = capacity;
  }

  int get(int key) {
    if (!m.count(key)) return -1;
    l.splice(l.begin(), l, m[key]);
    return m[key]->second;
  }

  void put(int key, int value) {
    if (m.count(key)) {
      l.splice(l.begin(), l, m[key]);
      m[key]->second = value;
      return;
    }
    if (m.size() == c) {
      m.erase(l.back().first);
      l.pop_back();
    }
    l.push_front({ key, value });
    m[key] = l.begin();
  }
};

int main() {
  LRUCache lRUCache(2);
  lRUCache.put(1, 1);              // cache is {1=1}
  lRUCache.put(2, 2);              // cache is {1=1, 2=2}
  cout << lRUCache.get(1) << " ";  // return 1
  lRUCache.put(3, 3);              // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache.get(2) << " ";  // returns -1 (not found)
  lRUCache.put(4, 4);              // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache.get(1) << " ";  // return -1 (not found)
  cout << lRUCache.get(3) << " ";  // return 3
  cout << lRUCache.get(4) << " ";  // return 4
  return 0;
}