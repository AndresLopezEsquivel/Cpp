#include "Car.h"

/*
  Why initialize `brand` in the initialization list instead of the body?
    1. Directly initializes the member variable `brand` with the argument `brand`.
    2. Avoids default constructing `brand` (using its default constructor) and then assigning a new value in the constructor body.
      - Example of inefficient assignment:
      Car::Car(const std::string& brand) {
        this->brand = brand; // Calls the copy constructor of std::string after default construction
      }
*/
Car::Car(const std::string &brand) : brand{brand} {};

std::string Car::getBrand() const
{
  return brand;
}

void Car::setBrand(const std::string &newBrand)
{
  brand = newBrand;
}
