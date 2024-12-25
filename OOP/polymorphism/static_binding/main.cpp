#include <iostream>

class Base
{
  public:

  void sayHello() const
  {
    std::cout << std::endl << "Hello, I am a Base class." << std::endl;
  }
};

class Derived : public Base
{
  public:

  // If Derived::sayHello() is not defined, Base::sayHello() will be called
  void sayHello() const
  {
    std::cout << std::endl << "Hello, I am a derived class." << std::endl;
  }
};

void greet(const Base &obj)
{
  obj.sayHello();
}

int main()
{
  Base base;
  Derived derived;

  base.sayHello(); // Since base is of type Base, Base::sayHello() will be called
  derived.sayHello(); // Since derived is of type Derived, Derived::sayHello() will be called

  greet(base); // Base::sayHello() will be called
  // Although derived is of type Derived, static binding is the default behavior
  // and, inside greet(), Base::sayHello() will be called.
  greet(derived);

  Base *ptr = new Derived;
  ptr->sayHello(); // Base::sayHello() will be called
  return 0;
}
