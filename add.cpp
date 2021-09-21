#include <bits/stdc++.h>

using namespace std;

class Fi;

class Mc {
  int m_m = 0, m_cm = 0;

  public:
  void getdata() {
    cout << "\nEnter the length in meter and centimeter ";
    cin >> m_m >> m_cm;
  }

  friend Fi add(Fi f1, Mc m1);
};

class Fi {
  int m_f = 0, m_i = 0;

  public:
  void getdata() {
    cout << "\nEnter the length in feet and inch ";
    cin >> m_f >> m_i;
  }

  void putdata() const {
    cout << m_f << " feet" << m_i << " inch";
  }

  friend Fi add(Fi f1, Mc m1);
};

Fi add(Fi f1, Mc m1) {
  Fi t{};
  float j = m1.m_m * 100 + m1.m_cm;
  j       = j * 0.393700787;
  t.m_f   = j / 12;
  auto k  = static_cast<int>(j);
  t.m_i   = k % 12;
  t.m_i   = t.m_i + f1.m_i;
  t.m_f   = (t.m_i / 12) + t.m_f + f1.m_f;
  t.m_i   = t.m_i % 12;
  return t;
}

int main() {
  Mc m1;
  Fi f1{}, f2{};
  m1.getdata();
  f1.getdata();
  f2 = add(f1, m1);
  cout << "\nSum length ";
  f2.putdata();
  return 0;
}