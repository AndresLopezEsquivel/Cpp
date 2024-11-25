#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
  private:

  std::string brand;

  public:

  /*
    Key Insights about const methods:
    1. This method guarantees it does not modify the state of the object.
    2. It can be called on both const and non-const objects.
    3. If 'const' is omitted, the method cannot be called on const objects, reducing usability.
    4. The compiler enforces immutability of the object for this method.
  */
  std::string getBrand() const;

};

#endif
