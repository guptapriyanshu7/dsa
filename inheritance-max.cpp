#include<iostream>
using namespace std;
class base {
	public:
	int rno;
	int m1,m2;
	void getnumbers() {
		cout<<"Enter Number 1 :- ";
		cin>>m1;
		cout<<"Enter Number 2 :- ";
		cin>>m2;
	}
};
class numbers : public base {
    public:
	void display() {
        getnumbers();
		cout << max(m1, m2) << endl;
	}
};
int main() {
	numbers m;
	m.display();
	return 0;
}