#include <iostream>
#include <memory>
#include <string.h>

class I_Printable
{
  friend std::ostream& operator<<(std::ostream &os, const I_Printable &ob);
  public:
  virtual void print(std::ostream &os) const = 0;
};

std::ostream& operator<<(std::ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Test : public I_Printable
{
  private:
  int data;

  public:
  Test();
  Test(int data);
  ~Test();
  int get_data() const;
  virtual void print(std::ostream &os) const override;
};

Test::Test() : data(0) { std::cout << std::endl << "In Test::Test()" << std::endl; }

Test::Test(int data) : data(data) { std::cout << std::endl << "In Test::Test(int data)" << std::endl; }

Test::~Test() { std::cout << std::endl << "In Test::~Test()" << std::endl; }

int Test::get_data() const { return data; }

void Test::print(std::ostream &os) const
{
  os << data;
}

class Person : public I_Printable
{
  protected:
  std::string name;
  unsigned short age;

  public:
  Person();
  Person(const std::string &name, unsigned short age);
  virtual ~Person();
  virtual void say_hello() const = 0;
};

Person::Person() : name("no-name"), age(0) { std::cout << std::endl << "In Person::Person()" << std::endl; }

Person::Person(const std::string &name, unsigned short age)
: name(name), age(age) { std::cout << std::endl << "In Person::Person(str,short)" << std::endl; }

Person::~Person() { std::cout << std::endl << "In Person::~Person()" << std::endl; }

class Employee : public Person
{
  private:
  std::string company;
  unsigned int salary;

  public:
  Employee();
  Employee(const std::string &name, unsigned short age, const std::string &company, unsigned int salary);
  virtual ~Employee();
  virtual void say_hello() const override;
  virtual void print(std::ostream &os) const override;
};

Employee::Employee()
: Person(), company("no-company"), salary(0)
{ std::cout << std::endl << "In Employee::Employee()" << std::endl; }

Employee::Employee(const std::string &name, unsigned short age, const std::string &company, unsigned int salary)
: Person(name, age), company(company), salary(salary)
{ std::cout << std::endl << "In Employee::Employee(str,short,str,int)" << std::endl; }

Employee::~Employee() { std::cout << std::endl << "In Employee::~Employee()" << std::endl; }

void Employee::say_hello() const
{
  std::cout << "Hello from Employee::say_hello()" << std::endl;
}

void Employee::print(std::ostream &os) const
{
  os << std::endl << "{ name: " << name << " , "
     << "age: " << age << " , "
     << "company: " << company << " , "
     << "salary: " << salary << " }" << std::endl;
}

int main()
{
  // Compile and execute with g++ -std=c++14 -o main main.cpp && ./main;

  // A unique smart pointer:
  // - Is a class that wraps a raw pointer.
  // - Is unique (there can only be one unique pointer pointing to a memory location).
  // - Is not copyable (copy constructor and copy assignment operator are deleted).
  // - Is movable (move constructor and move assignment operator are available).
  // - Is automatically deleted when it goes out of scope. It also destroys the object it points to.

  std::cout << std::endl << "= = (1) = =" << std::endl;

  {
    // Same as std::unique_ptr<int> number(new int(1000));
    // std::make_unique is available since C++14
    std::unique_ptr<int> number = std::make_unique<int>(1000);
    std::cout << std::endl << "number: " << number << std::endl;
    std::cout << std::endl << "*number: " << *number << std::endl;
    *number = 2000;
    std::cout << std::endl << *number << std::endl;
    int *number_raw = number.get(); // Get the raw pointer. It doesn't transfer the ownership.
    std::cout << std::endl << "number_raw: " << number_raw << std::endl;
    std::cout << std::endl << "*number_raw: " << *number_raw << std::endl;
    std::cout << std::endl << "number: " << number << std::endl;
  }

  std::cout << std::endl << "= = (2) = =" << std::endl;

  {
    // Sames as std::unique_ptr<Test> t {new Test(-500)};
    std::unique_ptr<Test> t = std::make_unique<Test>(-500);// Output: In Test::Test(int data)
    std::cout << std::endl << t << std::endl; // Output: a memory address (i.e. 0x7f8e1b402010)
    std::cout << std::endl << *t << std::endl; // Output: -500 <- operator<< was overloaded
  } // When exiting the scope, prints In Test::~Test(). Pointer t is automatically deleted.

  std::cout << std::endl << "= = (3) = =" << std::endl;

  {
    // Same as std::unique_ptr<Person> p {new Employee("John Doe", 30, "Google", 100000)};
    std::unique_ptr<Person> e = std::make_unique<Employee>("John Doe", 30, "Google", 100000);
    // Output:
    // In Person::Person(str,short)
    // In Employee::Employee(str,short,str,int)
    std::cout << std::endl << e << std::endl; // Output: a memory address (i.e. 0x7f8e1b402010)
    std::cout << std::endl << *e << std::endl; // Output: { name: John Doe , age: 30 , company: Google , salary: 100000 }
    e->say_hello(); // Output: Hello from Employee::say_hello()
  } // When exiting the scope, prints In Employee::~Employee() and In Person::~Person(). Pointer e is automatically deleted.

  std::cout << std::endl << "= = (4) = =" << std::endl;

  {
    std::unique_ptr<Test> t1 {new Test(100)};
    std::unique_ptr<Test> t2;
    // t2 = t1; // Object of type 'std::unique_ptr<Test>' cannot be assigned because its copy assignment operator is implicitly deleted
    std::cout << std::endl << "t1 : " << t1 << std::endl; // Output: a memory address (i.e. 0x7f8e1b402010)
    t2 = std::move(t1);
    std::cout << std::endl << "After moving t1 to t2" << std::endl;
    std::cout << std::endl << "t1 : " << t1 << std::endl; // Output: 0
    std::cout << std::endl << "t2 : " << t2 << std::endl; // Output: a memory address (i.e. 0x7f8e1b402010)
  }

  std::cout << std::endl << "= = (5) = =" << std::endl;

  {
    std::unique_ptr<Employee> e1 = std::make_unique<Employee>("John Doe", 30, "Google", 100000); // Output: In Person::Person(str,short) and In Employee::Employee(str,short,str,int)
    std::unique_ptr<Employee> e2 = std::make_unique<Employee>("Jane Doe", 25, "Facebook", 90000); // Output: In Person::Person(str,short) and In Employee::Employee(str,short,str,int)
    std::unique_ptr<Employee> e3 = std::make_unique<Employee>("Jack Doe", 35, "Amazon", 110000); // Output: In Person::Person(str,short) and In Employee::Employee(str,short,str,int)
    std::vector<std::unique_ptr<Employee>> employees;
    // employees.push_back(e1); // Cannot be used because the copy constructor is not allowed for unique_ptr
    // employees.push_back(e2); // Cannot be used because the copy constructor is not allowed for unique_ptr
    // employees.push_back(e3); // Cannot be used because the copy constructor is not allowed for unique_ptr
    // But move constructor is allowed
    employees.push_back(std::move(e1)); // Vector employees now possesses the ownership of e1
    employees.push_back(std::move(e2)); // Vector employees now possesses the ownership of e2
    employees.push_back(std::move(e3)); // Vector employees now possesses the ownership of e3
    std::cout << std::endl << "e1 : " << e1 << std::endl; // Output: 0
    std::cout << std::endl << "e2 : " << e2 << std::endl; // Output: 0
    std::cout << std::endl << "e3 : " << e3 << std::endl; // Output: 0
    for(const auto &e : employees)
      std::cout << std::endl << *e << std::endl;
      // Output:
      // { name: John Doe , age: 30 , company: Google , salary: 100000 }
      // { name: Jane Doe , age: 25 , company: Facebook , salary: 90000 }
      // { name: Jack Doe , age: 35 , company: Amazon , salary: 110000 }
  }

  return 0;
}
