#include <bits/stdc++.h>

using namespace std;
class fi;
class mc {
   int m, cm;
public:
   mc() {
      m = 0;
      cm = 0;
   }
   void getdata() {
      cout << "\nEnter the length in meter and centimeter ";
      cin >> m >> cm;
   }
   friend fi add(fi, mc);
};
class fi {
   int f, i;
public:
   void getdata() {
      cout << "\nEnter the length in feet and inch ";
      cin >> f >> i;
   }
   void putdata() {
      cout << f << " feet" << i << " inch";
   }
   friend fi add(fi, mc);
};
fi add(fi f1, mc m1) {
   fi t;
   float j;
   j = m1.m * 100 + m1.cm;
   j = j * 0.393700787;
   t.f = j / 12;
   int k = int(j);
   t.i = k % 12;
   t.i = t.i + f1.i;
   t.f = (t.i / 12) + t.f + f1.f;
   t.i = t.i % 12;
   return(t);
}
int main() {
   mc m1;
   fi f1, f2;
   m1.getdata();
   f1.getdata();
   f2 = add(f1, m1);
   cout << "\n Sum length ";
   f2.putdata();
   return 0;
}