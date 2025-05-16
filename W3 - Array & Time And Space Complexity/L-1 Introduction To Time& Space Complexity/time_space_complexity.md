
# Time and Space Complexity

## 🕒 Time Complexity

Time complexity describes how the **runtime** of an algorithm changes with the size of the input.

### Common Time Complexities:
- **O(1)** – Constant time: Doesn’t grow with input size.
  - Example: Accessing an element in an array by index.
- **O(log n)** – Logarithmic time: Grows slowly as input increases.
  - Example: Binary search.
- **O(n)** – Linear time: Grows directly with input size.
  - Example: Looping through a list once.
- **O(n log n)** – Linearithmic time:
  - Example: Merge sort, quicksort (average case).
- **O(n²)** – Quadratic time:
  - Example: Nested loops (like bubble sort).
- **O(2ⁿ)** – Exponential time:
  - Example: Brute force algorithms for NP problems.
- **O(n!)** – Factorial time:
  - Example: Generating all permutations of a list.

---

## 🧠 Space Complexity

Space complexity is about how much **memory** an algorithm uses as the input size grows.

### Example 1:
```python
def sum_list(lst):
    total = 0          # O(1) space
    for num in lst:
        total += num   # O(1) space used in loop
    return total
```
- Space Complexity: **O(1)** – uses a constant amount of extra space.

### Example 2:
```python
def duplicate_list(lst):
    new_lst = lst[:]  # makes a copy
    return new_lst
```
- Space Complexity: **O(n)** – stores a full copy of the list.

---

## Summary

- **Time complexity** = how fast an algorithm runs.
- **Space complexity** = how much memory it uses.
- Described using **Big O notation**.
