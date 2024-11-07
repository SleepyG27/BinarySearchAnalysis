#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& vec, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] > target)
            return recursiveBinarySearch(vec, left, mid - 1, target);
        else
            return recursiveBinarySearch(vec, mid + 1, right, target);
    }
    return -1; // Target not found
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; // Target not found
}

// Sequential Search
int sequentialSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target)
            return i;
    }
    return -1; // Target not found
}

int main() {
    // Initialize a vector with test data
    vector<int> vec = {3, 5, 2, 8, 6, 1, 9, 4, 7};

    // Sort the vector for binary search
    sort(vec.begin(), vec.end());

    // Set up targets
    int target1 = 5; // Item in the list
    int target2 = 10; // Item not in the list

    // Display the contents of the vector
    cout << "Vector contents: ";
    for (int item : vec)
        cout << item << " ";
    cout << endl;

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, 0, vec.size() - 1, target1);
    cout << "Recursive Binary Search: Target " << target1 << " found at location " << index << endl;

    index = recursiveBinarySearch(vec, 0, vec.size() - 1, target2);
    cout << "Recursive Binary Search: Target " << target2 << " was not found, return value is " << index << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target1);
    cout << "Iterative Binary Search: Target " << target1 << " found at location " << index << endl;

    index = iterativeBinarySearch(vec, target2);
    cout << "Iterative Binary Search: Target " << target2 << " was not found, return value is " << index << endl;

    // Sequential Search
    index = sequentialSearch(vec, target1);
    cout << "Sequential Search: Target " << target1 << " found at location " << index << endl;

    index = sequentialSearch(vec, target2);
    cout << "Sequential Search: Target " << target2 << " was not found, return value is " << index << endl;

    return 0;
}
