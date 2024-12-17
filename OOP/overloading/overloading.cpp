#include <iostream>

using namespace std;

class Point
{
  private:
  int x;
  int y;

  public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  Point operator+(const Point &point) const;
  void display() const;
};

Point Point::operator+(const Point &point) const
{
  return Point(x + point.x, y + point.y);
}

void Point::display() const
{
  cout << "(" << x << "," << y << ")" << endl;
}

int main()
{
  Point point_1(1,2);
  Point point_2(3,4);
  Point point_3 = point_1 + point_2; // point_1.operator+(point_2)

  cout << "point_3: ";
  point_3.display();

  return 0;
}
