#include <iostream>
#include "cstring.h"
#include <cstring>

using namespace std;

int main()
{
  cout << "== Empty CString ==" << endl;
  CString emptyStr;
  emptyStr.print();

  cout << "== myStr ==" << endl;
  const char *str = "Hello, I am Andrew!";
  CString myStr(str);
  myStr.print();

  cout << "== myStr1 ==" << endl;
  CString myStr1(myStr);
  myStr1.print();

  cout << "== myStr2 ==" << endl;
  CString myStr2("Hey!");
  myStr2.print();

  return 0;
}
