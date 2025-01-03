#include <iostream>

class I_Printable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
  public:
  virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class DivideByZeroException : public I_Printable
{
  public:
  ~DivideByZeroException() {};
  virtual void print(std::ostream &os) const override { os << "Divided by Zero Exception"; }
};

class NegativeValueException : public I_Printable
{
  public:
  ~NegativeValueException() {};
  virtual void print(std::ostream &os) const override { os << "Negative Value Exception"; }
};

double divide(int a, int b)
{
  if (b == 0)
    throw DivideByZeroException();

  if(a < 0 || b < 0)
    throw NegativeValueException();

  return static_cast<double>(a) / b; // This to be a floating point division, we need to cast either 'a' or 'b' (or both) to double.
}

int main()
{
  // Divide by zero example

  int a {};
  int b {};
  double c {};

  std::cout << "Provide a value for 'a': ";
  std::cin >> a;

  std::cout << std::endl << "Provide a value for 'b': ";
  std::cin >> b;

  try
  {
    c = divide(a, b);
    std::cout << std::endl << "c: " << c << std::endl;
  }
  catch(const DivideByZeroException &e)
  {
    std::cerr << "e: " << e << std::endl; // Output: Divided by Zero Exception
  }
  catch(const NegativeValueException &e)
  {
    std::cerr << "e: " << e << std::endl; // Output: Negative Value Exception
  }

  return 0;
}
