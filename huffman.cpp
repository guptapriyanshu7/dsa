#include <iostream>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

map<char, int> freq;
map<char, string> codes;

struct MinHeapNode {
  char data;
  int freq;
  MinHeapNode *left, *right;
  MinHeapNode(char data, int freq) {
    left = right = NULL;
    this->data = data;
    this->freq = freq;
  }
};

void storeCodes(MinHeapNode *top, string code) {
  if(top == NULL) {
    return;
  }
  if(top->data != '#') {
    codes[top->data] = code;
  }
  storeCodes(top->left, code + '0');
  storeCodes(top->right, code + '1');
}

struct compare {
  bool operator()(MinHeapNode *l, MinHeapNode *r) {
    return (l->freq > r->freq);
  }
};

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

void huffmanTree(int size) {
  for(auto i: freq) {
    minHeap.push(new MinHeapNode(i.first, i.second));
  }
  
  while(minHeap.size() != 1) {
    MinHeapNode *left = minHeap.top();
    minHeap.pop();
    MinHeapNode *right = minHeap.top();
    minHeap.pop();
    MinHeapNode *top = new MinHeapNode('#', left->freq + right->freq);
    top->left = left;
    top->right = right;
    minHeap.push(top);
  }
  storeCodes(minHeap.top(), "");
}

void decode(string encodedString) {
  string ans = "";
  MinHeapNode *top = minHeap.top();
  for (int i = 0; i < encodedString.length(); i++) {
    if(encodedString[i] == '0') {
      top = top->left;
    } else {
      top = top->right;
    }
    if(top->data != '#'){
      ans += top->data;
      top = minHeap.top();
    }
  }
  cout << ans << '\n';
}

int main() {
  string s = "heimurjestnetikras";
  for(char i: s) {
    freq[i]++;
  }
  huffmanTree(s.length());
  string encodedString = "";
  for(char i: s) {
    encodedString += codes[i];
  }
  for(auto i: codes) {
    cout << i.first << ' ' << i.second << '\n';
  }
  cout << encodedString << '\n';
  decode(encodedString);
  bitset<63> bs(encodedString);
  cout << sizeof(s) << ' ' << sizeof(bs);
  return 0;
}