#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element and std::max_element

using namespace std;

// Function to find the minimum element in an array
int min_array(int arr[], int n) {
    return *min_element(arr, arr + n);
}

// Function to find the maximum element in an array
int max_array(int arr[], int n) {
    return *max_element(arr, arr + n);
}

// Function to find the minimum element in a vector
int min_vector(const vector<int>& vec) {
    return *min_element(vec.begin(), vec.end());
}

// Function to find the maximum element in a vector
int max_vector(const vector<int>& vec) {
    return *max_element(vec.begin(), vec.end());
}

int main() {
    // Example with array
    int arr[] = {10, 20, 5, 25, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the minimum element in the array
    int min_element_array = min_array(arr, n);
    cout << "Minimum element in the array: " << min_element_array << endl;

    // Find the maximum element in the array
    int max_element_array = max_array(arr, n);
    cout << "Maximum element in the array: " << max_element_array << endl;

    // Example with vector
    vector<int> vec = {10, 20, 5, 25, 15};

    // Find the minimum element in the vector
    int min_element_vector = min_vector(vec);
    cout << "Minimum element in the vector: " << min_element_vector << endl;

    // Find the maximum element in the vector
    int max_element_vector = max_vector(vec);
    cout << "Maximum element in the vector: " << max_element_vector << endl;

    return 0;
}
