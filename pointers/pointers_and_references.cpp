#include <iostream>

using namespace std;

void modifyWithPointer(int *number);
void modifyWithReference(int &number);
void modifyWithRValueReference(int &&number);

int main()
{
  int number = 10;

  cout << "&number : " << &number << endl;
  cout << "number : " << number << endl;

  modifyWithPointer(&number);

  cout << "&number : " << &number << endl;
  cout << "number : " << number << endl;

  modifyWithReference(number);

  cout << "&number : " << &number << endl;
  cout << "number : " << number << endl;

  return 0;
}

void modifyWithPointer(int *number)
{
  *number *= 2;
  cout << endl << "== BEGIN: Inside modifyWithPointer ==" << endl;
  cout << "number : " << number << endl;
  cout << "*number : " << *number << endl;
  cout << "== END: Inside modifyWithPointer ==" << endl << endl;
}


void modifyWithReference(int &number)
{
  number *= 2;
  cout << endl << "== BEGIN: Inside modifyWithReference ==" << endl;
  cout << "&number : " << &number << endl;
  cout << "number : " << number << endl;
  cout << "== END: Inside modifyWithReference ==" << endl << endl;
}
