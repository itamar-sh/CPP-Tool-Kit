#include <vector>
#include <unordered_map>


class Solution {
public:
/*
    Given an array of integers arr, replace each element with its rank.

    The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.
 */
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_vector = arr;
        sort(sorted_vector.begin(), sorted_vector.end());
        unordered_map<int, int> num_to_rank;
        vector<int> ranks;
        if (sorted_vector.size() != 0) {
            num_to_rank[sorted_vector[0]] = 1;
        }
        for (size_t i = 1; i < sorted_vector.size(); ++i) {
            if (sorted_vector[i-1] != sorted_vector[i]) {
                num_to_rank[sorted_vector[i]] = num_to_rank[sorted_vector[i-1]]+1;
            }
        }
        for (size_t i = 0; i < arr.size(); ++i) {
            ranks.push_back(num_to_rank[arr[i]]);
        }z
        return ranks;
    }
};