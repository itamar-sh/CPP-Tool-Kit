#include <iostream>
#include <string>
using namespace std;

void pointers_basic_use() {
    int var = 10;
    int* ptr = &var;  // Pointer to var

    // Output the value of var
    cout << "Value of var: " << var << endl;
    // Output the address of var
    cout << "Address of var: " << &var << endl;
    // Output the address stored in ptr
    cout << "Address stored in ptr: " << ptr << endl;
    // Output the value pointed to by ptr
    cout << "Value pointed to by ptr: " << *ptr << endl;

    int** pptr = &ptr;   // Pointer to ptr
}

void basic_dynamic_allocation() {
    int* ptr = new int;  // Allocate memory for a single integer
    *ptr = 20;           // Assign a value to the allocated memory
    cout << "Value at ptr: " << *ptr << endl;
    delete ptr;          // Free the allocated memory

    int* arr = new int[5];  // Allocate memory for an array of 5 integers
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    delete[] arr;  // Free the allocated array memory
}

void array_as_pointer() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // ptr points to the first element of arr

    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = " << *(ptr + i) << endl;
    }
}

void func_with_pointer(int* ptr) {
    (*ptr)++;  // increment num
    cout << "value of num: :" << *ptr;
}

void string_use() {
    // Initialize a string
    string str = "Hello, World!";

    // Get a pointer to the first character of the string
    char* ptr = &str[0];

    // Output the original string
    cout << "Original string: " << str << endl;

    // Modify the string using the pointer
    *(ptr + 7) = 'C';
    *(ptr + 8) = 'P';
    *(ptr + 9) = 'P';
    *(ptr + 10) = '!';

    // Output the modified string
    cout << "Modified string: " << str << endl;

    // Access characters using the pointer
    cout << "Characters in the string:" << endl;
    for (size_t i = 0; i < str.size(); ++i) {
        cout << *(ptr + i) << ' ';
    }
    cout << endl;
}

int main() {
    pointers_basic_use();

    basic_dynamic_allocation();

    array_as_pointer();

    int num = 42;
    func_with_pointer(&num);

    strings_use();
    return 0;
}
