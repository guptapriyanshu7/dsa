#include <iostream>

int main() {
  auto&& x = 5;
  std::cout << &x << std::endl;
}

class Widget {
  public:
    template<typename T>
    void process_pointer(T* ptr) {}
};

template<>
void Widget::process_pointer<void>(void*) = delete;

class Base {
  public:
    virtual void mf1() const;
    virtual void mf2(int x);
    virtual void mf3() &;
    virtual void mf4() const;
};

// class Derived : public Base {
//   public:
//     virtual void mf1();
//     virtual void mf2(unsigned int x);
//     virtual void mf3() &&;
//     void mf4() const;
// };

class Derived : public Base {
  public:
    // adding "virtual" is OK, but not necessary
    virtual void mf1() const override;
    virtual void mf2(int x) override;
    virtual void mf3() & override;
    virtual void mf4() const override;
};
