#include <iostream>
#include <vector>
using namespace std;


string createMapping(string str) {
    char start = 'a';
    char mapping[128] = {0};

    for (char ch : str) {
        if (mapping[ch] == 0) {
            mapping[ch] = start++;
        }
    }

    for (int i = 0; i < str.length(); i++) {
        str[i] = mapping[str[i]];
    }

    return str;
}

int main() {
    int size;
    cout << "Enter Number Of Words: ";
    cin >> size;

    vector<string> words(size);
    for (int i = 0; i < size; i++) {
        cout << "Enter String " << i + 1 << ": ";
        getline(cin, words[i]);
    }

    string pattern;
    cout << "Enter Pattern: ";
    getline(cin, pattern);

    string patternMapped = createMapping(pattern);
    vector<string> matchedWords;

    for (string word : words) {
        if (createMapping(word) == patternMapped) {
            matchedWords.push_back(word);
        }
    }

    cout << "\nMatching Words:\n";
    for (const string& word : matchedWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
