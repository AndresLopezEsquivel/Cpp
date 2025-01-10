#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <memory>
#include <numeric>
#include <set>

class Processor
{
  public:
  virtual void process() = 0;
  ~Processor() { std::cout << "In ~Processor()" << std::endl; }
};

class MapProcessor : public Processor
{
  private:
  const std::map<int, std::vector<int>> &m;
  public:
  MapProcessor(const std::map<int, std::vector<int>> &m) : m(m) {};
  ~MapProcessor() { std::cout << "In ~MapProcessor()" << std::endl; }
  virtual void process() override
  {
    for(const auto& entry : m)
    {
      std::cout << entry.first << " : ";
      for(const auto& value : entry.second)
      {
        std::cout << value << " ";
      }
      std::cout << std::endl;
    }
  }
};

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


  // 2. Write lambda functions to:
  // (a) Count the total number of elements across all vectors that are greater than 10
  int greater_than_10 = std::accumulate(m.begin(), m.end(), 0, [](int acc, std::pair<int, std::vector<int>> entry){
    return acc + std::count_if(entry.second.begin(), entry.second.end(), [](int x) { return x > 10; });
  });

  std::cout << "greater_than_10: " << greater_than_10 << std::endl; // 8

  // (b) Find the sum of all elements in the map
  int map_sum {0};

  std::for_each(m.begin(), m.end(), [&map_sum](std::pair<int, std::vector<int>> entry){
    map_sum += std::accumulate(entry.second.begin(), entry.second.end(), 0);
  });

  std::cout << "map_sum: " << map_sum << std::endl; // 255

  // 3. Create a std::shared_ptr<std::vector<int>> to store all unique elements from all vectors in the map.
  // Note: Use std::set to identify unique elements before adding them to the shared_ptr vector.

  std::set<int> unique_numbers;

  std::for_each(m.begin(), m.end(), [&unique_numbers](const std::pair<int, std::vector<int>>& pair){
    std::for_each(pair.second.begin(), pair.second.end(), [&unique_numbers](const int number){
      unique_numbers.insert(number);
    });
  });

  std::cout << "{ " << *unique_numbers.begin();
  std::for_each(next(unique_numbers.begin()), unique_numbers.end(), [](const int number){
    std::cout << ", " << number;
  });
  std::cout << " }" << std::endl; // { 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 20, 25 }

  std::shared_ptr<std::vector<int>> unique_numbers_vec = std::make_shared<std::vector<int>>();

  for(const auto& number : unique_numbers)
  {
    unique_numbers_vec->push_back(number);
  }

  print<int>(*unique_numbers_vec); // 1 2 3 4 5 6 8 9 10 12 15 16 20 25

  // 4. Implement an abstract class Processor with a pure virtual function process(). Derive a class MapProcessor from it that:
  // (a) Takes the map as input.
  // (b) Implements process() to print all keys and their corresponding sorted vector values.

  std::unique_ptr<MapProcessor> map_processor {new MapProcessor(m)};

  map_processor->process();

  return 0;
}
