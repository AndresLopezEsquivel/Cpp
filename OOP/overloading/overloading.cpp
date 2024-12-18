#include <iostream>

using namespace std;

class Point
{
  private:
  int x;
  int y;

  public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  // Because we overloaded the assignment operator, we must also overload the copy constructor.
  Point(const Point &point) : x(point.x), y(point.y) {};
  Point operator+(const Point &point) const;
  Point &operator=(const Point &point);
  Point &operator=(Point &&point);
  void display() const;
};

Point Point::operator+(const Point &point) const
{
  // After the function returns, the temporary object is destroyed but a copy of it is returned.
  // So, copy constructor is called to create a copy of the temporary object.
  return Point(x + point.x, y + point.y);
}

Point &Point::operator=(const Point &point)
{
  x = point.x;
  y = point.y;
  return *this;
}

Point &Point::operator=(Point &&point)
{
  x = point.x;
  y = point.y;
  point.x = 0;
  point.y = 0;
  return *this;
}

void Point::display() const
{
  cout << "(" << x << "," << y << ")" << endl;
}

int main()
{
  Point point_1(1,2);
  Point point_2(3,4);
  Point point_3(-2,-2);
  Point point_4 = point_1 + point_2 + point_3; // point_1.operator+(point_2)

  cout << "point_4: ";
  point_4.display();

  // point_1.operator=(point_2.operator=(point_3.operator=(point_4)));
  point_1 = point_2 = point_3 = point_4 = Point(5,5);
  cout << "point_1: ";
  point_1.display();
  cout << "point_2: ";
  point_2.display();
  cout << "point_3: ";
  point_3.display();
  cout << "point_4: ";
  point_4.display();

  return 0;
}
