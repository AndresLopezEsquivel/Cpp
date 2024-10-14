#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int numbers [] {1, 2, 3, 4, 5};

  cout << "Size of numbers in bytes: " << sizeof(numbers) << endl;
  cout << "Size of each element of numbers in bytes: " << sizeof(numbers[0]) << endl;
  cout << "Length of numbers: " << sizeof(numbers) / sizeof(numbers[0]) << endl;
  cout << endl;

  for(int num : numbers)
    cout << num << " ";

  cout << endl;

  for(auto num : numbers)
    cout << num << " ";

  cout << endl;

  for(int num : {1, 2, 3, 4, 5})
    cout << num << " ";

  cout << endl;
  cout << "Lets check memory addresses..." << endl;
  cout << endl;

  cout << "Original memory addresses:" << endl;
  const unsigned short numbers_size = sizeof(numbers) / sizeof(numbers[0]);

  for(int i {0}; i < numbers_size; i++)
    cout << numbers[i] << " at " << &numbers[i] << endl;

  cout << endl;
  cout << "Addresses from a range based for loop (without reference): " << endl;
  for(int num : numbers)
    cout << num << " at " << &num << endl;

  cout << endl;
  cout << "Addresses from a range based for loop (with reference): " << endl;
  // num doesn't hold a copy of the element from numbers but rather refers directly to the element in the container.
  for(int &num : numbers)
    cout << num << " at " << &num << endl;

  cout << endl;
  cout << "Looping through a multidimensional vector: " << endl;

  vector <vector <int>> matrix {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  for(auto row : matrix)
  {
    for (int element : row)
      cout << element << " ";

    cout << endl;
  }

  return 0;
}
