#include <iostream>
#include <memory>

void my_deleter(int* p)
{
  std::cout << "Using custom deleter" << std::endl;
  delete p;
}

int main()
{
  std::shared_ptr<int> p1(new int, my_deleter);

  std::shared_ptr<int> p2(new int, [](int* p) {
    std::cout << "Using lambda deleter" << std::endl;
    delete p;
  });

  return 0;
}
