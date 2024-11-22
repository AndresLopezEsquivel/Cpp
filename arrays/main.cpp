#include <iostream>

using namespace std;

int* allocate_array(size_t size);

int main()
{
  int *numbers = allocate_array(3);

  delete [] numbers;

  return 0;
}

int* allocate_array(size_t size)
{
  return new int[size];
}
