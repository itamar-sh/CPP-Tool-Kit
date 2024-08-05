#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
/**
 * Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time
    complexity and with the smallest space complexity possible.
*/
    void classicQuickSortHelper(vector<int>& nums, int start, int end) {
        // key points: 1) random or choose middle number. 2) using swap, 3) not the best quicksort algorithm.
        if (start >= end) {
            return;
        }
        int i = start; // all element left to i are smaller than pivot
        int j = start; // all element between i and j, not included i and j themselves. are bigger than pivot
        int temp;
        // int pivot_index = start + rand() % (end - start + 1); - ranodm option.
        int pivot_index = start + (end - start) / 2;
        // // swap last element with the random value.
        swap(nums[pivot_index], nums[end]);
        // pivot value located at the end of the list
        int pivot = nums[end];
        while (j < end) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        // swap last element with the most left value of the bigger elements from pivot.
        swap(nums[i], nums[end]);
        // pivot in the right place.
        sortArrayIndexed(nums, start, i-1);
        sortArrayIndexed(nums, i+1, end);
    }
    vector<int> classicQuickSort(vector<int>& nums) {
        classicQuickSortHelper(nums, 0, nums.size()-1);
        return nums;
    }


    void optimizedQuickSortHelper(vector<int>& nums, int start, int end) {
        if (left >= right) {
                return;
        }
        // Initialize pointers for partitioning process
        int pivotIndex = left + (right - left) / 2; // Choose middle element as pivot
        int pivotValue = nums[pivotIndex];
        int i = left - 1;
        int j = right + 1;

        // Partition the array into two halves
        while (i < j) {
            // Increment i until nums[i] is greater or equal to pivot
            do {
                i++;
            } while (nums[i] < pivotValue);

            // Decrement j until nums[j] is less or equal to pivot
            do {
                j--;
            } while (nums[j] > pivotValue);

            // If i and j haven't crossed each other, swap the elements
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        // Recursively apply the same logic to the left and right halves of the array
        sortArrayIndexed(nums, left, j);     // Apply quicksort to the left subarray
        sortArrayIndexed(nums, j + 1, right); // Apply quicksort to the right subarray
    }
    vector<int> optimizedQuickSort(vector<int>& nums) {
        optimizedQuickSortHelper(nums, 0, nums.size()-1);
        return nums;
    }
};
