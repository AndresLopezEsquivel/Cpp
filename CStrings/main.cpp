#include <iostream>
#include "cstring.h"

using namespace std;

int main()
{
  char *str = new char(33);
  cout << static_cast<int>(*str) << endl;
  cout << *str << endl;
  return 0;
}
