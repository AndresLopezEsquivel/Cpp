| **Concept**       | **Example**           | **Usage**                                                                                  |
|--------------------|-----------------------|--------------------------------------------------------------------------------------------|
| **Pointer**        | `int* ptr = &x;`     | Stores the memory address of a variable. Can be dereferenced to access/modify the value.   |
| **L-Value Ref**    | `int& ref = x;`      | Refers to an existing variable (l-value). Can be used to modify the original variable.     |
| **R-Value Ref**    | `int&& ref = 100;`   | Refers to temporary values (r-values). Useful for optimizing temporary object handling.    |
