#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
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
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Fill vector with random numbers between 1 and 100
    vector<int> vec(10); // Adjust size as needed
    for (int &item : vec) {
        item = rand() % 100 + 1;
    }

    // Sort the vector for binary search
    sort(vec.begin(), vec.end());

    // Generate a random target between 1 and 100
    int target = rand() % 100 + 1;

    // Display the contents of the vector
    cout << "Vector contents: ";
    for (int item : vec)
        cout << item << " ";
    cout << endl;

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, 0, vec.size() - 1, target);
    if (index >= 0)
        cout << "Recursive Binary Search: Target " << target << " found at location " << index << endl;
    else
        cout << "Recursive Binary Search: Target " << target << " was not found" << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target);
    if (index >= 0)
        cout << "Iterative Binary Search: Target " << target << " found at location " << index << endl;
    else
        cout << "Iterative Binary Search: Target " << target << " was not found" << endl;

    // Sequential Search
    index = sequentialSearch(vec, target);
    if (index >= 0)
        cout << "Sequential Search: Target " << target << " found at location " << index << endl;
    else
        cout << "Sequential Search: Target " << target << " was not found" << endl;

    return 0;
}
