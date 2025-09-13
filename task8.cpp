#include <iostream>
#include <string>

using namespace std;

// Returns the index of the first occurrence of pattern in text, or -1 if not found.
// If pattern is empty, returns 0.
int naiveSearch(const string& text, const string& pattern) {
    if (pattern.empty()) return 0;
    if (pattern.size() > text.size()) return -1;

    for (int i = 0; i + pattern.size() <= text.size(); ++i) {
        int j = 0;
        for (; j < pattern.size(); ++j) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == pattern.size()) return static_cast<int>(i);
    }
    return -1;
}

int main() {
    // Pattern at the beginning
    string text1 = "hello world";
    string pat1 = "hello";
    cout << "Pattern at beginning -> " << naiveSearch(text1, pat1) << " (expected 0)\n";

    // Pattern at the end
    string text2 = "this is a test";
    string pat2 = "test";
    cout << "Pattern at end -> " << naiveSearch(text2, pat2) << " (expected 10)\n";

    // Pattern not present
    string text3 = "abcdefg";
    string pat3 = "xyz";
    cout << "Pattern not present -> " << naiveSearch(text3, pat3) << " (expected -1)\n";

    // Empty pattern
    string text4 = "anything";
    string pat4 = "";
    cout << "Empty pattern -> " << naiveSearch(text4, pat4) << " (expected 0)\n";

    return 0;
}
