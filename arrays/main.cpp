#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_array(const int *array, size_t size);
int* allocate_array(size_t size);
void initialize_array(int *array, size_t size);
void init_random_generator();
int generate_random_int(unsigned int lower_lim, unsigned int upper_lim);

int main()
{
  init_random_generator();

  size_t array_size = 3;

  int *numbers = allocate_array(array_size);

  initialize_array(numbers, array_size);

  print_array(numbers, array_size);

  delete [] numbers;

  return 0;
}

void print_array(const int *array, size_t size)
{
  cout << "[";
  for(size_t i = 0; i < size; i++)
    cout << array[i] << (i + 1 == size ? "" : ", ");
  cout << "]" << endl;
}

int* allocate_array(size_t size)
{
  return new int[size];
}

void initialize_array(int *array, size_t size)
{
  for(size_t i = 0; i < size; i++)
    *(array + i) = generate_random_int(1, 100);
}

void init_random_generator()
{
  // Seed random generator with current time
  srand(time(0));
}

int generate_random_int(unsigned int lower_lim, unsigned int upper_lim)
{
  // Generate a random number in the range [N, M]:
  // 1. rand() % (M - N + 1): Generates a number in the range [0, M - N]
  // 2. Adding N shifts the range to [N, M], making the bounds inclusive
  return rand() % (upper_lim - lower_lim + 1) + lower_lim;
}
