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
Car::Car(const std::string &brand,
         const std::string &model,
         int year) :
         brand{brand},
         model{model},
         year{year} {};

Car::Car(const std::string &brand, int year) : Car(brand, "unknown", year) {};

void Car::setBrand(const std::string &newBrand)
{
  brand = newBrand;
}

std::string Car::getBrand() const
{
  return brand;
}

void Car::setModel(const std::string &newModel)
{
  model = newModel;
}

std::string Car::getModel() const
{
  return model;
}

void Car::setYear(int newYear)
{
  year = newYear;
}

int Car::getYear() const
{
  return year;
}

std::string Car::getDetails() const
{
  return "Brand: " + brand + ", Model: " + model + ", Year: " + std::to_string(year);
}
