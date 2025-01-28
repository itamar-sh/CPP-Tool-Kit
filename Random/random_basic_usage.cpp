#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <numeric> // for iota

using namespace std;

int main() {
    // most easy but not good practice way to random an int.
    int num = rand();
    int num_in_range = 5 + rand() % 5;  // range between [5, 9]
    // Initialize a random number generator with a random seed
    random_device rd;
    mt19937 gen(rd());

    // Generate a random integer between 1 and 100 using random lib
    uniform_int_distribution<> distr_int(1, 100);
    int random_number = distr_int(gen);
    cout << "Random number: " << random_number << endl;

    // Generate a random float between 0 and 1
    uniform_real_distribution<> distr_float(0.0, 1.0);
    double random_float = distr_float(gen);
    cout << "Random float: " << random_float << endl;

    // Shuffle a list
    vector<int> my_list = {1, 2, 3, 4, 5};
    shuffle(my_list.begin(), my_list.end(), gen);
    cout << "Shuffled list: ";
    for (int num : my_list) {
        cout << num << " ";
    }
    cout << endl;

    // Choose a random element from a list
    uniform_int_distribution<> distr_choice(0, my_list.size() - 1);
    int random_element = my_list[distr_choice(gen)];
    cout << "Random element: " << random_element << endl;

    // Sample elements without replacement (can't choose the same element twice)
    vector<int> range_list(10);
    iota(range_list.begin(), range_list.end(), 1); // Fill the list with 1 to 10
    vector<int> sample;
    sample.reserve(8);
    sample(range_list.begin(), range_list.end(), back_inserter(sample), 8, gen);
    cout << "Sample without replacement: ";
    for (int num : sample) {
        cout << num << " ";
    }
    cout << endl;

    // Sample elements with replacement
    vector<char> elements = {'A', 'B', 'C'};
    uniform_int_distribution<> distr_with_replacement(0, elements.size() - 1);
    vector<char> sample_with_replacement(5);
    for (auto &elem : sample_with_replacement) {
        elem = elements[distr_with_replacement(gen)];
    }
    cout << "Sample with replacement: ";
    for (char elem : sample_with_replacement) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
