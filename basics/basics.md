## Increment and decrement operators

`x++` (post-increment):

- The value of `x` is incremented after its current value is used in the expression.
  `++x` (pre-increment):
- The value of `x` is incremented before its new value is used in the expression.

```cpp
#include <iostream>

int main()
{
  int a = 5;
  int r;

  // post-increment
  // r = 5 and, then, a is incremented to 6
  r = x++;
  x = 5;
  // pre-increment
  // x is incremented to 6 and, then, is assigned to r
  // Now, r = 6
  r = ++x;
}
```
