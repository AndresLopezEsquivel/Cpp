
### **How to Properly Use Stateful Lambda Functions**

A **stateful lambda** is a lambda function that captures variables from its enclosing scope. Captures can be:

1. **By value (`[=]` or `[x]`)**: The lambda gets a copy of the captured variable. Changes inside the lambda do not affect the original variable.
2. **By reference (`[&]` or `[&x]`)**: The lambda works with the original variable, and changes made inside the lambda affect it.

Stateful lambdas are typically used when you need to retain context across function calls, such as counters, filters, or accumulating values.

---

### **How They Work Behind the Scenes**

Under the hood, a lambda function is converted into an **anonymous functor** (function object) by the compiler. Here's what happens:

1. The lambda expression is transformed into a class with an overloaded `operator()` to represent the callable behavior.
2. If variables are captured, they are stored as member variables of this class.
3. When the lambda is called, it invokes `operator()` on the underlying object.

Example:
```cpp
int x = 5;
auto lambda = [x](int y) { return x + y; };
// Equivalent to something like:
struct Lambda {
    int x; // Captured state
    int operator()(int y) const { return x + y; }
};
Lambda lambda_obj = {5};
lambda_obj(3); // Returns 8
```

---

### **Examples with STL**

Here are practical examples that demonstrate the use of stateful lambdas with STL.

#### **1. Using Stateful Lambda with `std::for_each`**
Suppose we want to calculate the sum of a vector's elements:

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::for_each

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int sum = 0;

    // Capture sum by reference to modify it
    std::for_each(nums.begin(), nums.end(), [&sum](int n) {
        sum += n;
    });

    std::cout << "Sum: " << sum << std::endl; // Output: Sum: 15
    return 0;
}
```

---

#### **2. Using Stateful Lambda with `std::sort`**
Sort strings by their length and use a stateful lambda to track the number of comparisons:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry", "date"};
    int comparison_count = 0;

    // Capture comparison_count by reference
    std::sort(words.begin(), words.end(), [&comparison_count](const std::string& a, const std::string& b) {
        ++comparison_count;
        return a.size() < b.size();
    });

    std::cout << "Sorted words: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\nNumber of comparisons: " << comparison_count << std::endl;

    return 0;
}
```

---

#### **3. Using Stateful Lambda with `std::generate`**
Generate a sequence of numbers using a counter in a stateful lambda:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sequence(10);
    int counter = 0;

    // Capture counter by reference to increment it
    std::generate(sequence.begin(), sequence.end(), [&counter]() {
        return counter++;
    });

    std::cout << "Generated sequence: ";
    for (int n : sequence) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

---

#### **4. Using Stateful Lambda with `std::transform`**
Transform one vector into another using a stateful lambda that captures an external multiplier:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> results(nums.size());
    int multiplier = 3;

    // Capture multiplier by value
    std::transform(nums.begin(), nums.end(), results.begin(), [multiplier](int n) {
        return n * multiplier;
    });

    std::cout << "Transformed vector: ";
    for (int n : results) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### **Default Captures in C++ Lambdas**

Default captures specify how variables in the surrounding scope are captured within a lambda function. They simplify the lambda syntax by reducing the need to explicitly list each variable to capture. Let's break this down:

---

### **1. What are Default Captures?**

Default captures define the default behavior for capturing variables from the surrounding scope. They can be:

1. **By value (`=`):**
   Captures all variables by value. Each captured variable is copied, meaning changes to the captured variables within the lambda do not affect the originals.

2. **By reference (`&`):**
   Captures all variables by reference. Each captured variable is an alias to the original, so changes within the lambda affect the original variables.

3. **`this` pointer:**
   Captures the enclosing class's `this` pointer. This allows access to the enclosing class's members and methods.

---

### **2. Purpose of Default Captures**

- **Simplification:** Avoid explicitly listing each variable to capture.
- **Consistency:** Ensure consistent capture behavior for multiple variables.
- **Convenience:** Enable quick access to surrounding variables without verbose syntax.

---

### **3. Examples of Default Captures**

#### **3.1. Default Capture by Value (`=`)**
Captures all variables by value.

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    auto lambda = [=]() {
        // x and y are captured by value
        std::cout << "x + y = " << (x + y) << std::endl;
    };

    lambda();
    // Modifications inside the lambda do not affect the original variables
    return 0;
}
```

---

#### **3.2. Default Capture by Reference (`&`)**
Captures all variables by reference.

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    auto lambda = [&]() {
        // x and y are captured by reference
        x += 5;
        y += 10;
        std::cout << "Inside lambda: x = " << x << ", y = " << y << std::endl;
    };

    lambda();
    // Modifications inside the lambda affect the original variables
    std::cout << "Outside lambda: x = " << x << ", y = " << y << std::endl;

    return 0;
}
```

---

#### **3.3. Capturing `this`**
Allows the lambda to access members of the enclosing class.

```cpp
#include <iostream>
#include <string>

class Greeter {
    std::string name;

public:
    Greeter(const std::string& n) : name(n) {}

    void greet() {
        // Capture this by default
        auto lambda = [this]() {
            std::cout << "Hello, " << name << "!" << std::endl;
        };

        lambda();
    }
};

int main() {
    Greeter greeter("Andrés");
    greeter.greet();

    return 0;
}
```

---

#### **3.4. Mixing Default Captures and Explicit Captures**
You can mix default captures with specific variable captures to override the default for certain variables.

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;
    int z = 30;

    auto lambda = [=, &z]() {
        // x and y are captured by value
        // z is captured by reference
        std::cout << "x + y + z = " << (x + y + z) << std::endl;
        z += 5; // Modifies the original z
    };

    lambda();
    std::cout << "z after lambda: " << z << std::endl;

    return 0;
}
```

---

#### **3.5. Using Mutable with Default Capture by Value**
By default, lambdas that capture by value are `const`. To allow modifications of captured variables, use the `mutable` keyword.

```cpp
#include <iostream>

int main() {
    int x = 10;

    auto lambda = [=]() mutable {
        x += 5; // Allowed because of `mutable`
        std::cout << "Inside lambda: x = " << x << std::endl;
    };

    lambda();
    std::cout << "Outside lambda: x = " << x << std::endl; // Original x is unchanged

    return 0;
}
```

### **Question 1: Why Use `auto` for Lambda Functions?**

When defining a lambda, the `auto` keyword is used because the type of a lambda is unique and cannot be directly named in standard C++. Lambdas are implemented as **anonymous functor objects** (i.e., objects of a compiler-generated class with an overloaded `operator()`), and their exact type is not exposed.

#### **What Is the Type of a Lambda?**

The type of a lambda is a unique, unnamed type generated by the compiler, derived from its specific structure. Each lambda has a distinct type, even if they are structurally identical. For example:

```cpp
auto lambda1 = [](int x) { return x + 1; };
auto lambda2 = [](int x) { return x + 1; };
```

Here, `lambda1` and `lambda2` have different types, despite having the same behavior.

If you need a way to refer to a lambda's type, you can use `std::function`:

```cpp
#include <functional>

std::function<int(int)> lambda = [](int x) { return x + 1; };
```

However, note that using `std::function` introduces additional overhead because it involves type erasure and dynamic dispatch.

#### **Why Use `auto`?**

The `auto` keyword allows the compiler to deduce the lambda's unique type automatically, avoiding the need to specify the type explicitly.

```cpp
auto lambda = [](int x) { return x * x; }; // Compiler deduces the type
```

This is also why lambdas are commonly passed as template arguments to functions like those in the STL, as templates can work with the unique types of lambdas.

---

### **Question 2: Contradiction in Using `=` with `mutable`?**

At first glance, it might seem contradictory to use default capture by value (`=`) with `mutable`. However, this is not a contradiction; it’s a matter of how lambda semantics work.

#### **Why Is `mutable` Needed with `=`?**

When variables are captured by value (`=`), they are **copied into the lambda's internal storage** and treated as **const by default**. This means you cannot modify the captured variables inside the lambda unless you declare it `mutable`.

The `mutable` keyword relaxes this const constraint, allowing you to modify the copies of the captured variables stored inside the lambda, but not the originals.

#### **Example to Clarify:**

```cpp
#include <iostream>

int main() {
    int x = 10;

    auto lambda = [=]() mutable {
        x += 5; // Modifies the internal copy of x
        std::cout << "Inside lambda: x = " << x << std::endl; // Prints 15
    };

    lambda();
    std::cout << "Outside lambda: x = " << x << std::endl; // Prints 10

    return 0;
}
```

Here’s what’s happening step-by-step:
1. The `=` capture makes a **copy** of `x` inside the lambda.
2. The `mutable` keyword allows the lambda to modify its internal copy of `x`.
3. The modification inside the lambda has no effect on the original `x` because the lambda only modifies its copy.

---

### **Key Takeaways**

- **Default Capture by Value (`=`) with `mutable`** is not contradictory; it simply enables modification of the lambda’s **own copies** of captured variables, not the original variables.
- If you need to modify the original variable, you should capture it by reference (`&`) instead.

#### **Example Without `mutable`**

If `mutable` is omitted, this code would fail to compile:

```cpp
auto lambda = [=]() {
    x += 5; // ERROR: Cannot modify a captured-by-value variable without mutable
};
```

Would you like further clarification or additional examples?
