#include <iostream>
using namespace std;
class student {
  public:
  int rno;
  void getdata() {
    cout << "Enter RollNo :- \t";
    cin >> rno;
  }
};
class marks : public student {
  public:
  float m1, m2, m3, tot, per;
  void getmarks() {
    getdata();
    cout << "Enter Marks 1 :- \t";
    cin >> m1;
    cout << "Enter Marks 2 :- \t";
    cin >> m2;
    cout << "Enter Marks 2 :- \t";
    cin >> m3;
    tot = m1 + m2 + m3;
    per = tot / 3;
  }
  void display() {
    cout << "Roll No \tAverage\n";
    cout << rno << "\t \t" << per << endl;
  }
};
int main() {
  marks m;
  m.getmarks();
  m.display();
  return 0;
}