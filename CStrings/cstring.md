# Why Do We Need to Add `+1` When Allocating Space for a C String?

The reason for adding `+1` when allocating space for a C string is to account for the **null terminator (`'\0')** that marks the end of the string. Without this extra space, the null terminator might overwrite other memory or lead to undefined behavior when accessing or manipulating the string.

---

## Example Without `+1`

Consider this code:

```cpp
#include <cstring>
#include <iostream>

int main() {
    const char* original = "Hello";
    size_t length = strlen(original); // length = 5 (does not count '\0')

    char* copy = new char[length]; // Incorrect! No space for '\0'
    strcpy(copy, original);        // Copies "Hello" + '\0' into insufficient memory

    std::cout << copy << std::endl;

    delete[] copy;
    return 0;
}
```
`strlen(original)` returns 5 because it counts only the characters, not the null terminator.
Allocating `new char[length]` creates memory for 5 characters, but not the null terminator.
`strcpy(copy, original)` attempts to copy "Hello" plus the null terminator, which writes into memory past the allocated space (buffer overflow).
The program might work, but this is undefined behavior, leading to possible crashes or memory corruption.

## Correct example with `+1`

```cpp
#include <cstring>
#include <iostream>

int main() {
    const char* original = "Hello";
    size_t length = strlen(original); // length = 5

    char* copy = new char[length + 1]; // Correct! Space for "Hello" + '\0'
    strcpy(copy, original);            // Copies "Hello\0" safely

    std::cout << copy << std::endl;

    delete[] copy;
    return 0;
}
```
