#include <iostream>
#include <memory>

int main()
{
  // shared_ptr<T>:
  // - Multiple shared_ptr objects can share the ownership of a single object.
  // - The object is deleted when the last shared_ptr pointing to it is destroyed (use_count() == 0).
  // - Can be copied, assigned, and moved.

  std::cout << std::endl << "= = (1) = =" << std::endl;

  {
    std::shared_ptr<int> number {new int(100)};
    std::vector<std::shared_ptr<int>> numbers;
    std::cout << std::endl << "number.use_count() = " << number.use_count() << std::endl; // Output: 1
    numbers.push_back(number); // Copying is allowed. With a unique_ptr, std::move() would be required.
    // Now the integer is being pointed by number and numbers[0]. So, use_count() = 2.
    std::cout << std::endl << "number.use_count() = " << number.use_count() << std::endl; // Output: 2
  }

  std::cout << std::endl << "= = (2) = =" << std::endl;

  {
    std::shared_ptr<int> number_1 = std::make_shared<int>(-500); // std::make_shared was introduced in C++11 and is more efficient than new int(-500).
    std::cout << std::endl << "number_1.use_count() = " << number_1.use_count() << std::endl; // Output: 1
    std::shared_ptr<int> number_2 {number_1}; // Initialize number_2 with number_1 (copy constructor is used).
    std::cout << std::endl << "number_1.use_count() = " << number_1.use_count() << std::endl; // Output: 2
    std::shared_ptr<int> number_3; // Initialize as nullptr
    number_3 = number_2; // number_2 is assigned to number_3
    std::cout << std::endl << "number_1.use_count() = " << number_1.use_count() << std::endl; // Output: 3
  }

  return 0;
}
