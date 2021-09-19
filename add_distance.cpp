#include <bits/stdc++.h>

using namespace std;

class fi {
  int f, i, m, cm;

  public:
  void getdata() {
    cout << "Enter the length in meter and cm: ";
    cin >> m >> cm;
  }
  void putdata() { cout << f << " feet " << i << " inch\n"; }
  friend fi add(fi, fi);
};

fi add(fi m2, fi m1) {
  fi t;
  int j;
  m1.m  = m1.m + m2.m;
  m1.cm = m1.cm + m2.m;
  j     = m1.m * 100 + m1.cm;
  j     = j * 0.393700787;
  t.f   = j / 12;
  t.i   = j % 12;
  return t;
}

int main() {
  fi m1, m2, f;
  m1.getdata();
  m2.getdata();
  f = add(m2, m1);
  cout << "Sum length: ";
  f.putdata();
  return 0;
}