#include <iostream>

using namespace std;

class Car
{
  private:
  static int total_cars;

  public:
  Car() { total_cars++; }
  ~Car() { total_cars--; }
  static int get_total_cars() { return total_cars; }
};

// This is part of the class implementation, so it must be defined outside the class
int Car::total_cars = 0;

int main()
{
  cout << "Total car objects: " << Car::get_total_cars() << endl;
  Car car1, car2;
  cout << "Creating car1 and car2 objects..." << endl;
  cout << "Total car objects: " << Car::get_total_cars() << endl;

  {
    Car car3;
    cout << "Creating car3 object..." << endl;
    cout << "Total car objects: " << Car::get_total_cars() << endl;
  }

  cout << "After car3 was destroyed..." << endl;
  cout << "Total car objects: " << Car::get_total_cars() << endl;

  return 0;
}
