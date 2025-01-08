#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <numeric>

template<class T>
void print(const std::vector<T> &container)
{
  for(auto it = container.begin(); it != container.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

template<class key, class val_type>
void print(const std::map<key,std::vector<val_type>> &container)
{
  for(auto it = container.begin(); it != container.end(); it++)
  {
    std::cout << it->first << " : ";
    print<val_type>(it->second);
    std::cout << std::endl;
  }
}

int main()
{
  // == CHALLENGE 1 ==

  std::cout << "== CHALLENGE 1 ==" << std::endl;

  // Create a std::vector<int> and fill it with the first 10 positive integers.
  std::vector<int> numbers(10);
  std::iota(numbers.begin(), numbers.end(), 1);;

  // Use iterators to print all elements of the vector
  std::cout << "numbers: ";
  print<int>(numbers); // Output: 1 2 3 4 5 6 7 8 9 10

  // Use iterators to reverse the vector's order
  std::reverse(numbers.begin(), numbers.end());

  std::cout << "numbers: ";
  print<int>(numbers); // Output: 10 9 8 7 6 5 4 3 2 1

  // Use iterators to replace every number with its square
  std::transform(numbers.begin(), numbers.end(), numbers.begin(), [](int number){
    return number % 2 == 0 ? number * number : number;
  });

  std::cout << "numbers: ";
  print<int>(numbers); // Output: 100 9 64 7 36 5 16 3 4 1

  // Use a std::deque<int> to copy all modified elements from the vector.
  std::deque<int> numbers_deque;

  std::copy(numbers.begin(), numbers.end(), std::back_inserter(numbers_deque));

  // Use a std::deque<int> to print the deque elements in reverse order using reverse iterators.

  // std::for_each(numbers_deque.rbegin(),
  //               numbers_deque.rend(),
  //               [](int number){
  //                 std::cout << number << " ";
  //               });
  std::cout << "numbers_deque: ";
  std::copy(numbers_deque.rbegin(), numbers_deque.rend(), std::ostream_iterator<int>(std::cout, " "));
  // Output: 1 4 3 16 5 36 7 64 9 100

  std::cout << std::endl;

  // == CHALLENGE 2 ==

  // 1. Create a std::map<int, std::vector<int>> where the key is an integer and the value is a vector of integers.
  // Populate the map such that:
  // (a) Keys are integers from 1 to 5.
  // (b) Each value (vector) contains the first 5 multiples of its corresponding key.

  std::cout << "== CHALLENGE 2 ==" << std::endl;

  std::map<int, std::vector<int>> m;
  std::vector<int> multiples;

  for(int i = 1; i < 6; i++)
  {
    for(int j = 1; j < 6; j++)
    {
      multiples.push_back(i * j);
    }

    m[i] = multiples;
    multiples.clear();
  }

  print<int, int>(m);

  return 0;
}
