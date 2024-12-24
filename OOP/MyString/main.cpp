#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
  MyString s1;
  cout << "s1: " << s1.get_str() << endl;

  MyString s2("Hello");
  cout << "s2: " << s2.get_str() << endl;

  MyString s3(nullptr);
  cout << "s3: " << s3.get_str() << endl;

  MyString s4(s2);
  cout << "s4: " << s4.get_str() << endl;

  MyString s5(std::move(s2));
  cout << "s5: " << s5.get_str() << endl;

  return 0;
}
