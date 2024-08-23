#include <iostream>
using namespace std;

int main()
{
  float base;
  float height;
  float area;
  /*
  endl:
  - Inserts a new line and flushes the stream.
  - Equivalent to '\n' and flush.
  Flushing the buffer means that the output is written to the console immediately.
  */
  // Equivalent to cout << "Enter the base of the triangle:\n"
  cout << "Enter the base of the triangle: " << endl;
  cin >> base;
  cout << "Enter the height of the triangle: " << endl;
  cin >> height;
  area = 0.5 * base * height;
  cout << "The triangle area is: " << area << endl;
  return 0;
}
