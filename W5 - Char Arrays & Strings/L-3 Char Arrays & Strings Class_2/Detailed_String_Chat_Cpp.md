
# 💬 Detailed Chat: String Matching and C++ `std::string` Functions

This document captures a detailed and step-by-step version of our chat about C++ string functions, substring search algorithms, and implementation examples.

---

## ❓ Question 1: What is the value of `npos` in C++ string `find()`?

### 🔹 Answer:
- `std::string::npos` is returned when the substring is **not found**.
- It equals the **maximum value of `size_t`**, which is typically `-1` interpreted as an unsigned integer.

#### ✅ Example:
```cpp
std::string::npos == -1 == 18446744073709551615  // On 64-bit systems
```

#### 🔍 Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello World";
    size_t pos = str.find("Test");

    if (pos == string::npos) {
        cout << "Substring not found!" << endl;
    } else {
        cout << "Found at position: " << pos << endl;
    }
}
```

---

## ❓ Question 2: Which named substring search algorithms exist in C++ and what are their complexities?
### ✅ 1. Naive String Matching
**Idea:** Slide the pattern over text and compare each character.
```cpp
int naiveSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
            return i;  // Match found
    }
    return -1;
}
```
- Time: O(n × m)
- Space: O(1)

---

### ✅ 2. Knuth-Morris-Pratt (KMP)
**Idea:** Use LPS (Longest Prefix Suffix) table to avoid unnecessary checks.
```cpp
void computeLPS(string pattern, vector<int>& lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
}

int KMPSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps(m);
    computeLPS(pattern, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == m) return i - j;
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}
```
- Time: O(n + m)
- Space: O(m)

---

### ✅ 3. Rabin-Karp Algorithm
**Idea:** Use hashing to compare substring quickly.
```cpp
int rabinKarp(string text, string pattern, int prime = 101) {
    int n = text.size(), m = pattern.size();
    int d = 256;
    int h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * d) % prime;

    int p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && text.substr(i, m) == pattern)
            return i;
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % prime;
            if (t < 0) t += prime;
        }
    }
    return -1;
}
```
- Time: O(n + m) avg, O(n × m) worst (hash collisions)
- Space: O(1)

---

### ✅ 4. Boyer-Moore Algorithm (Bad Character Rule only for simplicity)
```cpp
#define ALPHABET_SIZE 256

void badCharHeuristic(string str, int size, int badChar[ALPHABET_SIZE]) {
    fill(badChar, badChar + ALPHABET_SIZE, -1);
    for (int i = 0; i < size; i++)
        badChar[(int) str[i]] = i;
}

int boyerMooreSearch(string text, string pattern) {
    int m = pattern.size(), n = text.size();
    int badChar[ALPHABET_SIZE];
    badCharHeuristic(pattern, m, badChar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) return s;
        else s += max(1, j - badChar[text[s + j]]);
    }
    return -1;
}
```
- Time: Best O(n/m), Worst O(n × m)
- Space: O(ALPHABET_SIZE)

---

### ✅ 5. Z-Algorithm
**Idea:** Build Z-array to find substring match.
```cpp
vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) R++;
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R - L] == s[R]) R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

int Zsearch(string text, string pattern) {
    string concat = pattern + "$" + text;
    vector<int> Z = computeZ(concat);
    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == pattern.length()) return i - pattern.length() - 1;
    }
    return -1;
}
```
- Time: O(n + m)
- Space: O(n + m)

---

### ✅ 6. Suffix Array + Binary Search (Simplified)
```cpp
#include <algorithm>
vector<string> buildSuffixArray(string s) {
    vector<string> suffixes;
    for (int i = 0; i < s.size(); i++) {
        suffixes.push_back(s.substr(i));
    }
    sort(suffixes.begin(), suffixes.end());
    return suffixes;
}

bool binarySearchSuffixArray(vector<string>& suffixes, string pattern) {
    int left = 0, right = suffixes.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (suffixes[mid].substr(0, pattern.size()) == pattern)
            return true;
        else if (suffixes[mid] < pattern)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
```
- Time: O(n log n + m log n)
- Space: O(n log n)

### ✅ Algorithms and Their Complexities:

| Algorithm        | Time Complexity          | Space Complexity | Notes                            |
|------------------|--------------------------|------------------|----------------------------------|
| Naive            | O(n × m)                 | O(1)             | Simple, inefficient              |
| KMP              | O(n + m)                 | O(m)             | Uses prefix table                |
| Rabin-Karp       | O(n + m) avg, O(n × m) worst | O(1)         | Hashing, collisions possible     |
| Boyer-Moore      | O(n) best, O(n × m) worst| O(m + σ)         | Fast in practice                 |
| Z-Algorithm      | O(n + m)                 | O(n + m)         | Efficient, useful in many problems |
| Suffix Array     | O(n log n + m log n)     | O(n) or O(n log n)| Good for multiple queries        |

---

## ❓ Question 3: What is the complexity of `find()` and `erase()`?

### 🔹 `std::string::find()`
- **Time Complexity:** O(n × m) in worst case

### 🔹 `std::string::erase(pos, len)`
- **Time Complexity:** O(n) (shifts characters after the removed part)

---

## ❓ Question 4: How to implement `erase(pos, len)` manually?

### 🔧 Basic Implementation (New String):

```cpp
string manualErase(string str, int pos, int len) {
    string result = "";

    for (int i = 0; i < pos; ++i)
        result += str[i];

    for (int i = pos + len; i < str.length(); ++i)
        result += str[i];

    return result;
}
```

#### 📦 Complexity:
- Time: O(n)
- Space: O(n) (new string created)

---

## ❓ Question 5: Optimized Implementation of `erase(pos, len)`?

### 🔧 Optimized In-Place Version:

```cpp
void optimizedErase(string& str, int pos, int len) {
    int n = str.length();

    for (int i = pos + len; i < n; ++i)
        str[i - len] = str[i];

    str.resize(n - len);
}
```

#### 📦 Complexity:
- Time: O(n - pos - len)
- Space: O(1)

---

## ✅ Summary of All Covered Topics

- `npos` meaning and value in C++.
- Named substring search algorithms and their performance.
- Internal working and complexity of `find()` and `erase()`.
- Manual and optimized implementation of `erase()` function.

---
