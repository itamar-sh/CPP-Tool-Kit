#include <iostream>
#include <string>
using namespace std;


int main() {
    // Default constructor
    string str1;

    // Initializing with a C-string (null-terminated character array)
    string str2 = "Hello";

    // Copy constructor
    string str3 = str2;  // O(n)

    // Move values
    str3 = move(str2) // O(1) - str2 is empty after this operation.

    // Initializing with a part of another string
    string str4(str2, 1, 3); // str4 == "ell"

    // Initializing with multiple copies of a character
    string str5(5, 'A'); // str5 == "AAAAA"

    cout << "str1: " << str1 << "\n";
    cout << "str2: " << str2 << "\n";
    cout << "str3: " << str3 << "\n";
    cout << "str4: " << str4 << "\n";
    cout << "str5: " << str5 << "\n";

    // Appending and Concatenation:
    string str1 = "Hello";
    string str2 = "World";
    string str3 = str1 + " " + str2; // Concatenation
    str1 += " Everyone"; // Appending

    // Accessing Characters:
    string str = "Hello";
    char ch = str[1]; // 'e'
    str[0] = 'h'; // Modifying the string, str becomes "hello"

    // Getting Length:
    string str = "Hello";
    size_t length = str.length(); // or str.size()

    // Substrings:
    string str = "Hello World";
    string sub = str.substr(0, 5); // "Hello"

    // Finding Substrings:
    string str = "Hello World";
    string sub = str.substr(0, 5); // "Hello"

    // Comparing Strings:
    string str1 = "Hello";
    string str2 = "World";
    if (str1 == str2) {
        // Strings are equal
    }
    if (str1 < str2) {
        // str1 is lexicographically less than str2
    }

    /** Iterating Over a String */
    string str = "Hello";

    // Range-based for loop
    for (char ch : str) {
        cout << ch << " ";
    }
    cout << endl;

    // Using iterators
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    /** Common String Methods */
    string str = "Hello World";

    if (str.empty()) {
        cout << "String is empty" << endl;
    } else {
        cout << "String is not empty" << endl;
    }

    str.push_back('!');
    cout << str << endl; // "Hello World!"

    str.pop_back();
    cout << str << endl; // "Hello World"

    str.replace(0, 5, "Hi");
    cout << str << endl; // "Hi World"

    str.clear();
    cout << "String after clear: " << str << endl; // ""

    return 0;
}

