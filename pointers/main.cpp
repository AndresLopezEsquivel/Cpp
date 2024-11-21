#include <iostream>

using namespace std;

int main()
{
  int numbers [5] {1, 2, 3, 4, 5};
  int numbers_size = sizeof(numbers) / sizeof(*numbers);

  cout << "numbers_size: " << numbers_size << endl;
  cout << endl;

  for(size_t i = 0; i < numbers_size; i++)
  {
    if (i == 0)
    {
      cout << "numbers: " << numbers << endl;
      cout << "*numbers: " << *numbers << endl;
    }
    else
    {
      cout << "numbers + " << i << " : " << numbers + i << endl;
      cout << "*(numbers + " << i << ") : " << *(numbers + i) << endl;
    }
    cout << endl;
  }

  // Dynamic memory allocation

  return 0;
}
