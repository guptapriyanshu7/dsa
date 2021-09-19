// #include <iostream>
// // using namespace std;
// class Animal {
// public:
//   virtual void show() = 0;  //Pure virtual function declaration.
// };
// class Man: public Animal {
// public:
//   void show() {
//     std::cout << "Man is the part of animal husbandry ";
//   }
// };
// int main() {
//   Animal* aptr; //Base class pointer
//   Man m;  //derived class object creation.
//   aptr = &m;
//   aptr->show();
//   return 0;
// }

// Not runtime polymorphism (tho' some references show)
#include <iostream>
using namespace std;
class Animal {
  public:
  virtual void function() {
    cout << "Eating..." << endl;
  }
};
class Man : public Animal {
  public:
  void function() {
    cout << "Walking ..." << endl;
  }
};
int main() {
  Animal A = Man();
  A.function();  // parent class object
  Animal* B = new Man();
  B->function();
  delete B;
  // Man m = Man();
  // m.function();   // child class object
  // return 0;
}