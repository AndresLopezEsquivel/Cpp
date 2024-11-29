#include "Deep.h"
#include "Shallow.h"
#include <iostream>

using namespace std;

int main()
{
  Shallow obj1 {1};
  Shallow obj2 = obj1;

  cout << "Shallow copy example:" << endl << endl;
  cout << "obj1.getData() = " << obj1.getData() << endl;
  cout << "obj2.getData() = " << obj2.getData() << endl;
  cout << "Modifying : obj2.setData(2)" << endl;
  obj2.setData(2);
  cout << "obj1.getData() = " << obj1.getData() << endl;
  cout << "obj2.getData() = " << obj2.getData() << endl;

  Deep obj3 {3};
  Deep obj4 = obj3;

  cout << endl << "Deep copy example:" << endl << endl;
  cout << "obj3.getData() = " << obj3.getData() << endl;
  cout << "obj4.getData() = " << obj4.getData() << endl;
  cout << "Modifying : obj4.setData(4)" << endl;
  obj4.setData(4);
  cout << "obj3.getData() = " << obj3.getData() << endl;
  cout << "obj4.getData() = " << obj4.getData() << endl;

  return 0;
}
