#include <iostream>
#include <memory>

class B;

class A {
private:
    std::shared_ptr<B> b_ptr;
public:
    A() { std::cout << "A constructor" << std::endl; }
    ~A() { std::cout << "A destructor" << std::endl; }
    void setB(std::shared_ptr<B> b) { b_ptr = b; }
};

class B {
private:
    std::weak_ptr<A> a_ptr;
public:
    B() { std::cout << "B constructor" << std::endl; }
    ~B() { std::cout << "B destructor" << std::endl; }
    void setA(std::shared_ptr<A> a) { a_ptr = a; }
};

int main() {

  // weak_ptr:
  // - Does not increase the reference count of the object.
  // - Does not participate in the ownership of the object.
  // - Created from a shared_ptr.
  // - Used to break circular references. Circular reference avoid the destruction of the objects.
  // - An object is destroyed when the last shared_ptr pointing to it is destroyed (use_)

  {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    // a is the only owner of the object of the class A
    // b is the only owner of the object of the class B

    std::cout << std::endl << "a.use_count() = " << a.use_count() << std::endl; // Output: 1
    std::cout << std::endl << "b.use_count() = " << b.use_count() << std::endl; // Output: 1

    a->setB(b);
    b->setA(a);

    // a and b->a_ptr are the owners of the object of the class A if a_ptr is a shared_ptr
    // If a_ptr is a weak_ptr, a is the only owner of the object of the class A

    // b and a->b_ptr are the owners of the object of the class B if b_ptr is a shared_ptr
    // If b_ptr is a weak_ptr, b is the only owner of the object of the class B

    std::cout << std::endl << "a.use_count() = " << a.use_count() << std::endl; // Output: 2 if a_ptr is a shared_ptr; 1 if a_ptr is a weak_ptr
    std::cout << std::endl << "b.use_count() = " << b.use_count() << std::endl; // Output: 2 if b_ptr is a shared_ptr; 1 if b_ptr is a weak_ptr

  }
  // If both a_ptr and b_ptr are shared_ptr, the objects of the classes A and B won't be destroyed
  // because a_ptr and b_ptr are owners of the objects (although pointers a and b were destroyed).
  // So the destructors of the classes A and B won't be called.

  // That is why it is important to declared either a_ptr or b_ptr as weak_ptr to avoid circular references.

    return 0;
}
