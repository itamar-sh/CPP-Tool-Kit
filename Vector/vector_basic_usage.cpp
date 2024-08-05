#include <vector>
#include <iostream>
using namespace std;


void vector_basics() {
    vector<int> vec;  // Declare an empty vector of integers
    vector<int> vec2(10);  // Declare a vector of integers with 10 elements initialized to 0
    vector<int> vec3(10, 5);  // Declare a vector of integers with 10 elements initialized to 5
    vector<int*> vec4(10, nullptr);  // Declare a vector of pointers of integers.
    vec.push_back(1);  // Add element to the end
    vec.push_back(2);
    vec.push_back(3);
    int first = vec[0];  // Access element at index 0
    int second = vec.at(1);  // Access element at index 1 (with bounds checking)
    int front = vec.front();  // Access the first element
    int back = vec.back();  // Access the last element
    vec[0] = 10;  // Modify element at index 0
    vec.at(1) = 20;  // Modify element at index 1 (with bounds checking)
    vec.pop_back();  // Remove the last element

    // iterate over elements 1
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // iterate over elements 2
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;

    // iterate over elements 3
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // capacity checking
    size_t size = vec.size();  // Get the number of elements
    size_t capacity = vec.capacity();  // Get the current capacity
    bool is_empty = vec.empty();  // Check if the vector is empty

    // Resizing and Reserving Capacity, Clearing and Erasing Elements
    vec.resize(5);  // Resize the vector to contain 5 elements, if adding than it's give default value (0 in int)
    vec.reserve(20);  // Reserve space for at least 20 elements, capacity = min(capacity, reserve)
    vec.clear();  // Remove all elements from the vector
    vec.erase(vec.begin() + 1);  // Remove the element at index 1
    vec.insert(vec.begin() + 1, 2);  // Insert an element at index 1, shift all the values from his right so O(n) time complexity
}

void swapping_vectors() {
    // 1) O(n) - move all elements from one to another - not recommmended
    vector<int> vec1;
    vec1.push_back(1);  // Add element to the end
    vec1.push_back(2);
    vec1.push_back(3);
    vector<int> vec2;
    vec1.push_back(4);
    vec2 = vec1;  // O(n)
    // 2) O(1) using swap or move
    swap(vec1, vec2);  // change metadata and pointer for data
    vec1 = move(vec2); // change metadata and pointer for data
    // 3) O(1) using pointers - requires manual memory handelin, risky
    vector<int>* vec1_ptr = new vector<int>();
    vector<int>* vec2_ptr = new vector<int>();
    vec1_ptr->push_back(1);
    vec2_ptr->push_back(4);
    vector<int>* temp = vec1_ptr;  // for only move and not swap - delete vec1_ptr; && vec1_ptr = vec2_ptr;
    vec1_ptr = vec2_ptr;
    vec2_ptr = temp;
    delete vec1_ptr;
    delete vec2_ptr;
    // 4) O(1) using smart pointers.
    unique_ptr<vector<int>> vec1_ptr = make_unique<vector<int>>();
    unique_ptr<vector<int>> vec2_ptr = make_unique<vector<int>>();
    vec1_ptr->push_back(1);
    vec2_ptr->push_back(4);
    vec1_ptr.swap(vec2_ptr);  // Efficient swap using smart pointers
    vec1_ptr = move(vec2_ptr);  // Efficient move using smart pointers - this delets the vector in vec1_ptr.
}


int main() {
    vector_basics();

    swapping_vectors();
    return 0;
}