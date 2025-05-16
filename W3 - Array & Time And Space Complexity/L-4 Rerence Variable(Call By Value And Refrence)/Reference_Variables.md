
# Reference Variables: Call by Value and Call by Reference

## 🔹 Reference Variables

A **reference variable** is an alias for another variable. Instead of storing its own value, it refers to another variable’s memory location.

### Example in C++:
```cpp
int a = 10;
int &ref = a; // ref is a reference to a
ref = 20;
cout << a; // Output: 20
```

## 🔹 Call by Value

In **Call by Value**, a **copy** of the variable is passed to the function. Changes made inside the function **do not affect** the original variable.

### Example:
```cpp
void update(int x) {
    x = x + 10;
}

int main() {
    int a = 5;
    update(a);
    cout << a; // Output: 5
}
```

✔️ **Key Point:** Original variable is safe; only a copy is modified.

## 🔹 Call by Reference

In **Call by Reference**, a **reference** (or address) of the variable is passed to the function. So, changes made inside the function **do affect** the original variable.

### Example using references:
```cpp
void update(int &x) {
    x = x + 10;
}

int main() {
    int a = 5;
    update(a);
    cout << a; // Output: 15
}
```

✔️ **Key Point:** The function works with the actual variable, not a copy.

## 🧠 Summary

| Feature             | Call by Value              | Call by Reference               |
|---------------------|----------------------------|---------------------------------|
| Data Passed         | Copy of variable           | Address or reference of variable |
| Original Data       | Not modified               | Modified                         |
| Memory Used         | More (copies created)      | Less (no extra copies)           |
| Safety              | Safer (original unchanged) | Riskier (can change original)    |
