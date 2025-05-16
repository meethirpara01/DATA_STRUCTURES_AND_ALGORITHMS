# Type Casting from int to char in C++

## What Happens When an int is Cast to a char?
In C++, when you type cast an `int` to a `char`, and the integer value is too large to fit in a `char`, the value undergoes **truncation** (wrapping around) according to integer conversion rules.

### Size and Range of char:
A `char` typically has a size of **1 byte (8 bits)** and can store values in the following ranges:

- **Signed char**: `-128` to `127`
- **Unsigned char**: `0` to `255`

When an `int` is cast to a `char`, only the **least significant byte (LSB)** of the integer is retained, and higher-order bytes are discarded.

---

## Example Code:
```cpp
#include <iostream>

int main() {
    int largeValue = 300;
    char c = (char)largeValue; // Explicit cast

    std::cout << "Original int: " << largeValue << std::endl;
    std::cout << "Converted char: " << (int)c << std::endl; // Cast to int for display
    return 0;
}
```

### Output:
```
Original int: 300
Converted char: 44
```

#### Why?
- `300` in binary (assuming 32-bit int): `00000000 00000000 00000001 00101100`
- Only the **last 8 bits** (`00101100`, which is `44` in decimal) are retained.
- Hence, `c` gets the value `44`, which corresponds to the ASCII character **','**.

---

## Behavior with Signed char
If `char` is signed, the conversion might also involve **sign extension**, potentially leading to negative values.

### Example with Negative Value:
```cpp
int largeValue = -300;
char c = (char)largeValue;
std::cout << "Converted char: " << (int)c << std::endl;
```

#### Output (assuming `char` is signed):
```
Converted char: -44
```
Because `-300` in binary is `11111111 11111111 11111110 11010100`, and the last byte `11010100` is interpreted as `-44` in signed 8-bit representation.

---

## Key Takeaways:
1. **Only the lowest 8 bits are retained**.
2. **Values wrap around** (modulo 256 for unsigned `char`).
3. **Signed `char` may interpret values as negative** due to sign extension.
4. **Potential loss of information** when truncating higher-order bits.

This behavior is essential to understand when dealing with type conversions to avoid unexpected results in C++ programs! 🚀
