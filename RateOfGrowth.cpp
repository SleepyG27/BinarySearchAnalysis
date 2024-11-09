#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const int N = 1000000; // Starting size of the array
double SumRBS = 0.0;
double SumIBS = 0.0;
double SumSeqS = 0.0;

// Search function 
int recursiveBinarySearch(const vector<int>& vec, int left, int right, int target);
int iterativeBinarySearch(const vector<int>& vec, int target);
int sequentialSearch(const vector<int>& vec, int target);

int main() {
    srand(time(0)); // Seed for random number generation

    // Loop to run the tests 10 times
    for (int test = 0; test < 10; ++test) {
        // Generate a vector with N random numbers
        vector<int> vec(N);
        for (int &num : vec) {
            num = rand() % 100 + 1;
        }

        // Sort the vector for binary search
        sort(vec.begin(), vec.end());

        // Generate a random target value
        int target = rand() % 100 + 1;

        // Timing and running Recursive Binary Search
        auto startRBS = high_resolution_clock::now();
        recursiveBinarySearch(vec, 0, vec.size() - 1, target);
        auto endRBS = high_resolution_clock::now();
        SumRBS += duration_cast<microseconds>(endRBS - startRBS).count();

        // Timing and running Iterative Binary Search
        auto startIBS = high_resolution_clock::now();
        iterativeBinarySearch(vec, target);
        auto endIBS = high_resolution_clock::now();
        SumIBS += duration_cast<microseconds>(endIBS - startIBS).count();

        // Timing and running Sequential Search
        auto startSeqS = high_resolution_clock::now();
        sequentialSearch(vec, target);
        auto endSeqS = high_resolution_clock::now();
        SumSeqS += duration_cast<microseconds>(endSeqS - startSeqS).count();
    }

    // Display the average running times
    cout << fixed << setprecision(4); 
    cout << "Average Running Time for Recursive Binary Search in microseconds is " << (SumRBS / 10.0) << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << (SumIBS / 10.0) << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << (SumSeqS / 10.0) << endl;

    return 0;
}

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& vec, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        else if (vec[mid] > target) return recursiveBinarySearch(vec, left, mid - 1, target);
        else return recursiveBinarySearch(vec, mid + 1, right, target);
    }
    return -1;
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        else if (vec[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

// Sequential Search
int sequentialSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) return i;
    }
    return -1;
}
