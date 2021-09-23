# include <iostream>
# include <queue>

using namespace std;

int main() {
  priority_queue<int> pq;
  pq.push(10);
  pq.push(20);
  pq.push(50);
  pq.push(15);
  pq.push(5);
  priority_queue <int, vector<int>, greater<int>> pq_dec;
  pq_dec.push(20);
  pq_dec.push(10);
  pq_dec.push(50);
  pq_dec.push(15);
  pq_dec.push(5);
  while (!pq.empty()) {
    cout << '\t' << pq.top();
    pq.pop();
  }
  while (!pq_dec.empty()) {
    cout << '\t' << pq_dec.top();
    pq_dec.pop();
  }
  return 0;
}