#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

class Person {
private:
  std::string m_name = "abc";
  std::uint8_t m_age{ '0' };

public:
  Person() {
    std::cout << "Constructor called" << std::endl;
  }

  Person(const Person& rhs) : m_name{ rhs.m_name }, m_age{ rhs.m_age } {
    std::cout << "Copy Constructor called" << std::endl;
  }
  Person& operator=(const Person& rhs) {
    if (this != &rhs) {
      std::cout << "Copy assignment called" << std::endl;
      m_name = rhs.m_name;
      m_age  = rhs.m_age;
    }
    return *this;
  }

  Person(Person&& rhs) noexcept : m_name{ std::move(rhs.m_name) }, m_age{ rhs.m_age } {
    std::cout << "Move Constructor called" << std::endl;
  }
  Person& operator=(Person&& rhs) noexcept {
    std::cout << "Move assignment called" << std::endl;
    m_name = std::move(rhs.m_name);
    m_age  = rhs.m_age;
    return *this;
  }

  ~Person() { std::cout << "Destructor called" << std::endl; }

  [[nodiscard]] std::string get_name() const { return m_name; }
  [[nodiscard]] std::uint8_t get_age() const { return m_age; }
};

// void pass_to_func(Person p) {}
// void pass_to_func(Person& p) {}
Person&& pass_to_func(Person&& p) { return std::move(p); }

int main() {
  // Person p1;
  // auto p1{Person()};
  // auto p1 = Person();

  // std::cout << "Before move: " << p1.get_name() << std::endl;

  // auto p2(p1);
  // auto p3 = p1;
  // p3      = p1;

  // auto p4{ std::move(p1) };
  // auto p5 = std::move(p4);
  // p5      = std::move(p2);
  // std::cout << "After move: " << p1.get_name() << std::endl;

  std::vector<Person> vp;
  // vp.reserve(2);
  // vp.push_back(p1);
  // vp.push_back(p1);

  // vp.push_back(Person());
  // vp.emplace_back();  // No need to call Person() ctor

  pass_to_func(Person());
  // pass_to_func(pass_to_func(Person()));
  // pass_to_func(p1);
  // pass_to_func(std::move(p1));

  return 0;
}
