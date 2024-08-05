#include <iostream>
using namespace std;

// Function to print the elements of an array
void printArrayWithKnownSize(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int ArrayInit() {
    // 1) Declare and initialize an array with fixed size
    int numbers[5] = {10, 20, 30, 40, 50};

    // Access and print array elements with known size
    cout << "Array elements:" << endl;
    printArrayWithKnownSize(numbers, 5);

    // Modify an array element
    numbers[2] = 99;
    cout << "Array after modifying the third element:" << endl;
    printArrayWithKnownSize(numbers, 5);

    // 2) Declare an array without initializing
    int uninitializedArray[5];

    // Assign values to the uninitialized array
    for (int i = 0; i < 5; i++) {
        uninitializedArray[i] = i + 1;
    }
    cout << "Uninitialized array after assigning values:" << endl;
    printArrayWithKnownSize(uninitializedArray, 5);

    // 3) Declare and initialize a 2D array with fixed size
    int multiArray[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "Multidimensional array elements:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << multiArray[i][j] << " ";
        }
        cout << endl;
    }

    // 4) Declare and initialize a string array with fixed size
    string fruits[3] = {"Apple", "Banana", "Cherry"};
    cout << "Array of strings:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << fruits[i] << " ";
    }
    cout << endl;

    // 5) Declare and initialize array with unknown size

    return 0;
}

int main() {
    return ArrayInit();
}