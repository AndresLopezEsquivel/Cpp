#include <iostream>
#include "Car/Car.h"

using namespace std;

int main()
{
  Car myCar{"Toyota"};

  cout << "myCar.getBrand() = " << myCar.getBrand() << endl;
  cout << "After modifying brand..." << endl;
  myCar.setBrand("Ford");
  cout << "myCar.getBrand() = " << myCar.getBrand() << endl;

  return 0;
}
