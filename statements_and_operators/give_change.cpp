#include <iostream>

using namespace std;

int main()
{
  cout << "Enter an amount in cents: " << endl;

  int cents{150};
  int balance{};
  int dollars{};
  int dimes{};
  int quarters{};
  int nickels{};

  balance = cents;

  dollars = balance / 100;
  balance -= dollars * 100;

  quarters = balance / 25;
  balance -= quarters * 25;

  dimes = balance / 10;
  balance -= dimes * 10;

  nickels = nickels / 5;
  balance -= nickels * 5;

  cout << dollars << endl;
  cout << dimes << endl;
  cout << quarters << endl;
  cout << nickels << endl;
  cout << balance << endl;

  return 0;
}
