#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  /*
  Bitwise operations are operations that directly manipulate bits.
  They are faster than arithmetic operations and are often used in low-level programming.
  */

  /*
   Before we start, let's understand how to represent a binary number into a signed integer.
   The most significant bit (MSB) is the sign bit.
   If the sign bit is 0, the number is positive. If the sign bit is 1, the number is negative.
   The remaining bits represent the magnitude of the number.
   Let's take a 4-bit signed integer as an example.
   0110 represents 6. The sign bit is 0, so the number is positive.
   1110 represents -6. The sign bit is 1, so the number is negative.
  */

  // Bitwise AND
  // 0 & 0 = 0
  // 0 & 1 = 0
  // 1 & 0 = 0
  // 1 & 1 = 1
  int a = 5;             // 101
  int b = 3;             // 011
  int resultAnd = a & b; // 001
  cout << "Bitwise AND:" << endl;
  cout << "a & b: " << resultAnd << endl;
  cout << endl;

  // Bitwise OR
  // 0 | 0 = 0
  // 0 | 1 = 1
  // 1 | 0 = 1
  // 1 | 1 = 1
  int resultOr = a | b; // 111
  cout << "Bitwise OR:" << endl;
  cout << "a | b: " << resultOr << endl;
  cout << endl;

  // Bitwise XOR
  // 0 ^ 0 = 0
  // 0 ^ 1 = 1
  // 1 ^ 0 = 1
  // 1 ^ 1 = 0
  int resultXor = a ^ b; // 110
  cout << "Bitwise XOR:" << endl;
  cout << "a ^ b: " << resultXor << endl;
  cout << endl;

  // Bitwise NOT
  // ~0 = 1
  // ~1 = 0
  int resultNotA = ~a; // 11111111111111111111111111111010
  cout << "Bitwise NOT:" << endl;
  cout << "~a: " << resultNotA << endl;
  cout << endl;

  // Bitwise left shift
  a = 1;
  char resultLeftShift = a << 7; // 1000 0000
  cout << "Bitwise left shift:" << endl;
  cout << "a: " << bitset<8>(a) << endl;                    // 0000 0001
  cout << "a << 7: " << bitset<8>(resultLeftShift) << endl; // 1000 0000
  cout << endl;

  return 0;
}
