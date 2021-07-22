#include <bits/stdc++.h>
using namespace std;
class temp {
    float x, y, q;
public:
    void input() {
        cout << "Enter Two Distances(in m): ";
        cin >> x >> y;
    }
    friend void sum(temp& t);
    void display() {
        cout << "The sum of distances is(in feet): " << q << "\n";
    }
};
void sum(temp& t) {
    t.q = (t.x + t.y) * 3.28084;
}
int main() {
    temp t1;
    t1.input();
    sum(t1);
    t1.display();
    return 0;
}