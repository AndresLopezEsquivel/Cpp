#include <iostream>
#include <climits>
using namespace std;

int main()
{
  /*
  Overflow occurs when the result of an arithmetic operation exceeds
  the maximum (or goes below the minimum) value that the variable can store.
  */

  /*
  Overflow in signed integers:
  The range of signed integers is from -2^(n-1) to 2^(n-1) - 1
  where n is the number of bits used to store the integer.
  If n = 32, the range is from -2147483648 to 2147483647
  */
  int maxInt = INT_MAX;
  cout << "Overflow in signed integers:" << endl;
  cout << "maxInt: " << maxInt << endl;
  cout << "maxInt + 1: " << maxInt + 1 << endl; // Overflow
  cout << endl;

  /*
  Expected output:
  Overflow in signed integers:
  maxInt: 2147483647
  maxInt + 1: -2147483648
  */

  int minInt = INT_MIN;
  cout << "minInt: " << minInt << endl;
  cout << "minInt - 1: " << minInt - 1 << endl; // Overflow
  cout << endl;

  /*
  Expected output:
  minInt: -2147483648
  minInt - 1: 2147483647
  */

  /*
  Overflow in unsigned integers:
  The range of unsigned integers is from 0 to 2^n - 1
  where n is the number of bits used to store the integer.
  */
  unsigned int maxUInt = UINT_MAX;
  cout << "Overflow in unsigned integers:" << endl;
  cout << "maxUInt: " << maxUInt << endl;
  cout << "maxUInt + 1: " << maxUInt + 1 << endl; // Overflow

  /*
  Expected output:
  Overflow in unsigned integers:
  maxUInt: 4294967295
  maxUInt + 1: 0
  */

  return 0;
}
