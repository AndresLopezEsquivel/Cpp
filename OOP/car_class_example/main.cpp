#include <iostream>
#include "Car/Car.h"

using namespace std;

int main()
{
  // Create a Car object using the primary constructor
  Car car1("Toyota");
  std::cout << car1.getDetails() << std::endl;

  // Create a Car object using the secondary constructor
  Car car2("Honda", 2015);
  std::cout << car2.getDetails() << std::endl;

  // Create a Car object with brand, model, and year using the primary constructor
  Car car3("Ford", "Mustang", 1969);
  std::cout << car3.getDetails() << std::endl;

  cout << endl << "After modifying car3..." << endl;

  car3.setModel("GT500");
  car3.setYear(2022);
  cout << endl << car3.getDetails() << endl;

  return 0;
}
