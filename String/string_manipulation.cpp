#include <iostream>
#include <string>
using namespace std;


class StringManipulation {
public:
    /**
    You are given two strings word1 and word2.
    Merge the strings by adding letters in alternating order, starting with word1.
    If a string is longer than the other, append the additional letters onto the end of the merged string.
    Return the merged string.
    */
    string mergeAlternately(string word1, string word2) {
        int min_length = word1.length() < word2.length() ? word1.length() : word2.length();
        string result;
        result.reserve(word1.length() + word2.length());
        for (int i = 0; i < 2 * min_length; i++) {
            if (i % 2 == 0) {
                result.push_back(word1[i/2]);
            } else {
                result.push_back(word2[i/2]);
            }
        }
        if (word1.length() > word2.length()) {
            for (int i = min_length; i < word1.length(); i++) {
                result.push_back(word1[i]);
            }
        } else {
            for (int i = min_length; i < word2.length(); i++) {
                result.push_back(word2[i]);
            }
        }
        return result;
    }
};