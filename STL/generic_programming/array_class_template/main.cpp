#include <iostream>

template <class T, int N>
class Array
{
  private:
  int size {N};
  T values [N];

  public:
  friend std::ostream& operator<<(std::ostream& os, const Array<T,N> &array)
  {
    os << "[ ";
    for(const T& value : array.values)
      os << value << " ";
    os << "]";
    return os;
  }

  Array() = default;

  Array(const T init_val)
  {
    for(T& value : values)
      value = init_val;
  }

  T& operator[](int index)
  {
    if(index < 0 || index >= size)
      throw std::out_of_range("Index out of range");
    return values[index];
  }

  int get_size() const
  {
    return size;
  }
};

int main()
{
  Array<int,5> numbers(0);

  std::cout << numbers << std::endl;

  try
  {
    numbers[-1];
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << e.what() << std::endl;
  }

  numbers[0] = 1;
  numbers[numbers.get_size() - 1] = 1;

  std::cout << numbers << std::endl;

  return 0;
}
