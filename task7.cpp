#include <iostream>
#include <vector>

using namespace std;

// Finds all indices of `key` in `arr`. Returns an empty vector if not found.
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) indices.push_back(static_cast<int>(i));
    }
    return indices;
}

void printIndices(const vector<int>& idx) {
    if (idx.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < idx.size(); ++i) {
        cout << idx[i];
        if (i + 1 < idx.size()) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    // Test: Multiple occurrences
    vector<int> a1 = {1, 3, 7, 3, 9, 3};
    int key1 = 3;
    cout << "Multiple occurrences (key=3) -> ";
    printIndices(findAllIndices(a1, key1)); // expected [1, 3, 5]

    // Test: Key not present
    vector<int> a2 = {2, 4, 6, 8};
    int key2 = 5;
    cout << "Key not present (key=5) -> ";
    printIndices(findAllIndices(a2, key2)); // expected []

    // Test: Empty array
    vector<int> a3;
    int key3 = 0;
    cout << "Empty array (key=0) -> ";
    printIndices(findAllIndices(a3, key3)); // expected []

    return 0;
}
