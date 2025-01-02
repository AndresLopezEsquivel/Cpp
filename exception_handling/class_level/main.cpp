#include <iostream>
#include <string>

class IllegalBalanceException : public std::exception
{
  public:
  IllegalBalanceException() noexcept = default; // noexcept means the constructor won't throw an exception
  ~IllegalBalanceException() = default; // noexcept by default
  virtual const char* what() const noexcept override // overriding the what() method from the base class std::exception
  {
    return "Illegal Balance";
  }
};

class Account
{
  private:
  double balance;
  std::string name;

  public:
  Account() noexcept : balance(0.0), name("no-name") {};
  Account(double balance, std::string name) : balance(balance), name(name)
  {
    if(balance < 0)
      throw IllegalBalanceException();
  };
  ~Account() {};
};

int main()
{
  try
  {
    std::unique_ptr<Account> a = std::make_unique<Account>(-500, "John Doe");
  }
  catch(const IllegalBalanceException &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
