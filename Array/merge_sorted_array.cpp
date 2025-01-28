#include <vector>
#include <algorithm>


class Solution {
public:
    void merge_int_arrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!nums1) {
            return nums2;
        } else if (!nums2) {
            return nums1;
        }
        int min_size = min(nums1.size(), nums2.size());
    }
};