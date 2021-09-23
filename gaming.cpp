#include <iostream>

class Entity {
  public:
  Entity(int x, int y) : m_x(x), m_y(y) {}
  virtual ~Entity() = default;

  virtual void render_entity() const = 0;

  // More class methods to change Entity proprties

  protected:
  int m_x;
  int m_y;
};

class Triangle : public Entity {
  public:
  Triangle(int x, int y, int z) : Entity(x, y),
                                  m_z(z) {
  }

  void render_entity() const override {
    // Handle rendering for Traingle entities, 100 lines of code
    std::cout << "RENDERING TRIANGLE\n";
  }

  protected:
  int m_z;

  // More properties defining a Triangle
  // int m_color;
  // bool transparent;
  //
};

class Bullet : public Entity {
  public:
  Bullet(int x, int y, int v) : Entity(x, y),
                                m_velocity(v) {
  }

  void render_entity() const override {
    // Handle rendering for Bullet entities, 100 lines of code
    std::cout << "RENDERING BULLET\n";
  }

  protected:
  int m_velocity;
  // More properties defining a bullet
  // std::string shooter;
  // std::string victim;
  //
};

class Fire : public Entity {
  public:
  Fire(int x, int y, int t) : Entity(x, y), m_temp(t) {}

  void render_entity() const override {
    // Handle rendering for Bullet entities, 100 lines of code
    std::cout << "RENDERING FIRE PARTICLES\n";
  }

  protected:
  int m_temp;
  // More properties defining fire particles
};

int game_loop(Entity* e) {
  // Handle physics
  // Handle audio
  // Handle properties of Entity using more class methods

  e->render_entity();  // Aha, RUNTIME POLYMORPHISM
                       // No function overloading for every entity type, we JUST have to call render_entity
                       // This entity will always have a render_entity() function since it is a pure virtual function in the class

  // Handle AI
  // Change enitity type at runtime if we want
  // Eg - Someone shoots a bullet, so maybe create a new Entity using, Entity& bullet = Bullet(x,y,v)
  // And them call the render_entity() function which is guaranteed to exist

  return 0;
}

Entity* set_entity_type(int i)  // JUST A HELPER FUNCTION TO TEST, IN REAL CODE THIS IS DYNAMIC
                                // Exaample, pressing a button to draw a triangle
                                // Think how UI frameworks handle this
{
  Entity* e{};

  // These new instances are dynamically created at runtime by some other function which creates
  // these instances and returns their addresses and manages deletion as well.
  // A well known Design pattern known as a Factory (I think.)
  switch (i) {
    case 1:
      e = new Triangle(1, 2, 3);
      break;
    case 2:
      e = new Bullet(1, 2, 69);
      break;
    case 3:
      e = new Fire(1, 2, 100);
      break;
    case 4:
      return nullptr;
    default:
      std::cout << "Entity not yet handled\n";
      break;
  }

  return e;
}
int main() {
  std::cout << "What to render?\n1Triangle 2Bullet 3Fire 4ExitGame\n";  // This part comes from a different function in your game engine
                                                                        // We take input from user just to test

  while (true) {
    int i = 0;
    std::cin >> i;  // This will be decided by some other function at runtime, but lets test for now

    Entity* e = set_entity_type(i);

    if (e)           // Check nullptr
      game_loop(e);  // This is the actual game loop, everything else before this is just to help test
    else
      return 0;
  }
}
