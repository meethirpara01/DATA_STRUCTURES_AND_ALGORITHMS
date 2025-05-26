# Important Pre-Built String Functions in C++

| **Function**              | **Description**                                                                 | **Example**                                      |
|--------------------------|---------------------------------------------------------------------------------|--------------------------------------------------|
| `length()` / `size()`    | Returns the length of the string                                                | `s.length();`                                     |
| `empty()`                | Checks if the string is empty                                                   | `s.empty();`                                      |
| `at(index)`              | Returns character at specified index with bounds checking                       | `s.at(2);`                                        |
| `[]` (indexing)          | Access character at index (no bounds checking)                                  | `s[2];`                                           |
| `append(str)`            | Appends string `str` at the end                                                 | `s.append("world");`                              |
| `+`                      | Concatenates strings                                                            | `s1 + s2;`                                        |
| `compare(str)`           | Compares two strings (returns 0 if equal)                                       | `s1.compare(s2);`                                 |
| `find(str)`              | Finds first occurrence of substring `str`                                       | `s.find("abc");`                                  |
| `rfind(str)`             | Finds last occurrence of substring `str`                                        | `s.rfind("abc");`                                 |
| `substr(pos, len)`       | Returns substring starting from `pos` of length `len`                           | `s.substr(2, 4);`                                 |
| `insert(pos, str)`       | Inserts `str` at position `pos`                                                 | `s.insert(3, "abc");`                             |
| `erase(pos, len)`        | Erases `len` characters from position `pos`                                     | `s.erase(2, 3);`                                  |
| `replace(pos, len, str)` | Replaces part of string with another string                                     | `s.replace(2, 3, "xyz");`                         |
| `c_str()`                | Converts `std::string` to C-style string (`const char*`)                        | `const char* c = s.c_str();`                      |
| `push_back(ch)`          | Appends character `ch` at the end                                               | `s.push_back('a');`                               |
| `pop_back()`             | Removes last character                                                          | `s.pop_back();`                                   |
| `clear()`                | Clears the string                                                               | `s.clear();`                                      |
| `begin()` / `end()`      | Returns iterator to the beginning / end of the string                          | `auto it = s.begin();`                            |
| `toupper(ch)` / `tolower(ch)` | Converts character to upper/lowercase (from `<cctype>` header)            | `toupper('a');`                                   |
