#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector <int> vector_1;
  short max {10};

  for(int i {0}, j {10}; i < max; i += 1, j += 10)
    vector_1.push_back(j);

  for(int i {0}; i < vector_1.size(); i++)
    cout << "vector_1(" << i << ") = " << vector_1.at(i) << endl;

  return 0;
}
