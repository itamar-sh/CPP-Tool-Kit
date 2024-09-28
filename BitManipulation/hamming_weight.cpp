// Write a function that takes the binary representation of a positive integer and returns
// the number of set bits it has (also known as the Hamming weight).


class Solution {
public:
    // 32 times since every int has 32 bits
    int hammingWeight(int n) {
        int counter = 0;
        while (n > 0) {
            counter += n & 1;
            n = n >> 1;
        }
    }
    // num of bits with 1 - since we unset every 1 bit of n
    int hammingWeight2(int n) {
        int counter = 0;
        while (n > 0) {
            n = n & (n - 1);
            counter += 1;
        }
    }
};