
# Binary Search Algorithm

## Types of Binary Search

Binary Search can be classified into four types:

1. **Classical Binary Search**  
   - Example: Find target element in a sorted array.

2. **Search Space Based Binary Search**  
   - Example: Find SQRT.

3. **Predicate Function Based Binary Search**  
   - Example: book allocation And Advance Question.

4. **Index Logic Based Binary Search**  
   - Example: Find the odd occurring element.

---

## Key Points to Note

1. **Check Monotonicity**:  
   Always first check whether the array is monotonic or not.

2. **Classical Approach Loop Condition**:  
   We usually loop with the condition:  
   ```
   while (start <= end)
   ```

3. **Midpoint Uncertainty**:  
   If you are not sure whether the `mid` is on the right side and on the answer, store the `mid` result first and then move on.

4. **Conditional Updates**:  
   In some problems, if you need to apply conditions like:  
   ```
   end = mid
   start = mid
   ```  
   then avoid using:  
   ```
   while (start <= end)
   ```  
   Instead, use:  
   ```
   while (start < end)
   ```  
   and return `start`, `mid`, or `end` separately at the end.

   You want to apply this:  
   ```
   while (start <= end)
   ```
   Than Handel Separately to equaleness like
   ```
   while (start == end)
      return `start` or `mid` or `end` 
   ```

---

## Additional Optimization Tips

5. **Optimizing Code**:  
   If checking `mid == target`, and the element has already been checked, you can skip it using:  
   ```
   start = mid + 1
   end = mid - 1
   ```

   **Example Use Case**: Nearly sorted array, or finding the odd occurring element(IMP).
