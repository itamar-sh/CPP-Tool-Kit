#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    //     answer[0] is a list of all integers in nums1 which are present more in nums1 than in nums2.
    //     answer[1] is a list of all integers in nums2 which are present more in nums2 than in nums1.
    // Note that the integers in the lists may be returned in any order.
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> diff;

        // Process nums1
        cout << "Processing nums1:" << endl;
        for (const auto &num : nums1) {
            cout << "num: " << num << endl;
            if (diff.find(num) == diff.end()) {
                diff[num] = 0;
            }
            diff[num] += 1;
        }

        // Process nums2
        cout << "Processing nums2:" << endl;
        for (const auto &num : nums2) {
            cout << "num: " << num << endl;
            if (diff.find(num) == diff.end()) {
                diff[num] = 0;
            }
            diff[num] -= 1;
        }

        // Print the content of the diff map
        cout << "Contents of the diff map:" << endl;
        for (const auto &pair : diff) {
            cout << "key: " << pair.first << ", value: " << pair.second << endl;
        }

        // Prepare the result
        vector<vector<int>> res(2); // Initialize the vector of vectors with 2 empty vectors
        for (const auto &pair : diff) {
            cout << "pair: " << pair.first << " -> " << pair.second << endl;
            if (pair.second > 0) {
                res[0].push_back(pair.first);
            } else if (pair.second < 0) {
                res[1].push_back(pair.first);
            }
            cout << "end pair: " << pair.first << endl;
        }

        return res;
    }
    // Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    //     answer[0] is a list of all integers in nums1 which are not at all present in nums2.
    //     answer[1] is a list of all integers in nums2 which are not at all present in nums1.
    // Note that the integers in the lists may be returned in any order.
    vector<vector<int>> findUniqueDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_unique(nums1.begin(), nums1.end());
        unordered_set<int> nums2_unique;
        unordered_set<int> nums_common;
        for (const auto &num: nums1) {
            if (nums1_unique.find(num) == nums1_unique.end()) {
                nums1_unique.insert(num);
            }
        }
        cout << "Processing nums2:" << endl;
        for (const auto &num: nums2) {
            if ((nums2_unique.find(num) == nums2_unique.end()) && (nums_common.find(num) == nums_common.end())) {
                if (nums1_unique.find(num) != nums1_unique.end()) {  // exists in both arrays
                    nums1_unique.erase(num);
                    nums_common.insert(num);
                } else {  // only on nums2
                    nums2_unique.insert(num);
                }
            }
        }
        vector<vector<int>> res(2);  // Initialize the vector of vectors with 2 empty vectors
        res[0].assign(nums1_unique.begin(), nums1_unique.end());
        res[1].assign(nums2_unique.begin(), nums2_unique.end());
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 4, 5, 6};
    vector<vector<int>> result = solution.findDifference(nums1, nums2);

    cout << "Unique to nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Unique to nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
