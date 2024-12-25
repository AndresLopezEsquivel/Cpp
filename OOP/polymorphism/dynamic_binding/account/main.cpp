#include <iostream>

class Account
{
  public:
  virtual ~Account();
  virtual void withdraw(double amount);
};

class Checking : public Account
{
  public:
  virtual ~Checking();
  // Neither virtual nor override keywords are required for the derived class method.
  // In derived classes, the virtual keyword is a good practice,
  // whereas the override keyword is useful for ensuring that the method signature matches the base class method signature.
  virtual void withdraw(double amount) override;
};

class Savings : public Account
{
  public:
  virtual ~Savings();
  virtual void withdraw(double amount) override;
};

class Trust : public Account
{
  public:
  virtual ~Trust();
  virtual void withdraw(double amount) override;
};

Account::~Account()
{
  std::cout << std::endl << "In Account::~Account()" << std::endl;
}

Checking::~Checking()
{
  std::cout << std::endl << "In Checking::~Checking()" << std::endl;
}

Savings::~Savings()
{
  std::cout << std::endl << "In Savings::~Savings()" << std::endl;
}

Trust::~Trust()
{
  std::cout << std::endl << "In Trust::~Trust()" << std::endl;
}

void Account::withdraw(double amount)
{
  std::cout << std::endl << "In Account::withdraw" << std::endl;
}

void Checking::withdraw(double amount)
{
  std::cout << std::endl << "In Checking::withdraw" << std::endl;
}

void Savings::withdraw(double amount)
{
  std::cout << std::endl << "In Savings::withdraw" << std::endl;
}

void Trust::withdraw(double amount)
{
  std::cout << std::endl << "In Trust::withdraw" << std::endl;
}

void do_withdraw(Account& account, double amount)
{
  account.withdraw(amount);
}

int main()
{
  /*
  For dynamic binding:
  - There must be inheritance.
  - The base class method to be overridden must be a virtual function.
  - We need to use a base class pointer or reference.
  - The derive method's signature and return type must match the base class method's signature and return type.
    If it doesn't match, the compiler considers it as a redefinition, which corresponds to static binding.
    To ensure that the method signature matches the base class method signature, we can use the override keyword.
  */
  Account* p1 = new Account;
  Account* p2 = new Checking;
  Account* p3 = new Savings;
  Account* p4 = new Trust;
  Account* accounts [] = {p1, p2, p3, p4}; // Array of pointers to Account objects


  std::cout << std::endl << "== Dynamic binding using pointers to base class ==" << std::endl;
  for(size_t i = 0;  i < 4; i++)
    accounts[i]->withdraw(1000);
    // Thanks to dynamic binding, the output is:
    // In Account::withdraw
    // In Checking::withdraw
    // In Savings::withdraw
    // In Trust::withdraw

  std::cout << std::endl << "== Dynamic binding using references to base class ==" << std::endl;
  Trust t;
  Account& a = t;
  do_withdraw(a, 1000);
  // Thanks to dynamic binding, the output is:
  // In Trust::withdraw

  std::cout << std::endl << "== Clean up ==" << std::endl;

  // If no virtual destructor is declared in the base class,
  // Account::~Account() will be called 4 times (the base class destructor)
  // and the derived class destructors will not be called.

  for(size_t i = 0;  i < 4; i++)
    delete accounts[i];
  // Thanks to virtual destructors, the output is:
  // In Account::~Account()
  // In Checking::~Checking()
  // In Account::~Account()
  // In Savings::~Savings()
  // In Account::~Account()
  // In Trust::~Trust()
  // In Account::~Account()

  // As can been seen, for a given derived object,
  // the derived class destructor is called first, then the base class destructor is called.

  std::cout << std::endl;

  return 0;
}
