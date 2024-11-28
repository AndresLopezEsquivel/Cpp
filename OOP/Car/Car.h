#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
  private:

  std::string brand;
  std::string model;
  int year;

  public:
  /*
  Why use `const std::string&` here?
    1. Using a reference avoids calling the copy constructor of `std::string`, which can be expensive.
      - Passing by value (e.g., `Car(std::string brand)`) would copy the string argument, resulting in unnecessary overhead.
      - By using a reference, the string is not duplicated, making the program faster and more memory-efficient.
    2. Adding `const` ensures that the constructor cannot modify the original string argument.
    3. Allows passing temporary (rvalue) objects like `Car("Toyota")` because rvalues can bind to `const` references.
  */

 /*
  Use pass by value for small, simple types like int, float, char.
  Use pass by reference for large or complex types like std::string to avoid unnecessary copying.
  */

  Car(const std::string &brand = "Unknown", const std::string &model = "Unknown", int year = 0);
  Car(const std::string &brand, int year);
  /*
    Key Insights about const methods:
    1. This method guarantees it does not modify the state of the object.
    2. It can be called on both const and non-const objects.
    3. If 'const' is omitted, the method cannot be called on const objects, reducing usability.
    4. The compiler enforces immutability of the object for this method.
  */
  std::string getDetails() const;

  void setBrand(const std::string &newBrand);
  std::string getBrand() const;

  void setModel(const std::string &newModel);
  std::string getModel() const;

  void setYear(int newYear);
  int getYear() const;



};

#endif
