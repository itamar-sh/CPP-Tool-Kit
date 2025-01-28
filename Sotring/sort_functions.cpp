#include <vector>
#include <unordered_map>
using namespace std;

vector<int> sort_outplace(vector<int>& arr) {
    vector<int> sorted_vector = arr;
    sort(sorted_vector.begin(), sorted_vector.end());
    return sorted_vector;
}


vector<int> sort_unordred_map_by_value_anonymus_func(unordered_map<string, int>& dict) {
    vector<pair<string, int>> dict_sorted(dict.begin(), dict.end());
    sort(dict_sorted.begin(), dict_sorted.end(),
    [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    })
}


bool compareByValue(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

vector<int> sort_unordred_map_by_value_custom_func(unordered_map<string, int>& dict) {
    vector<pair<string, int>> dict_sorted(dict.begin(), dict.end());


    sort(dict_sorted.begin(), dict_sorted.end(), compareByValue);
}


int main() {
    vector<int> vec = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

    // Defining the range as whole vector
      auto first = vec.begin();
      auto last = vec.end();

    // calling the sort for the above defined range
    sort(first, last);
    return 0;
}