class Solution {
public:
    bool isPalindrome(string s) {
        int s_len = s.length();
        for (int i = 0; i < s_len / 2; i++) {
            if (s[i] != s[s_len-1-i]) {
                return false;
            }
        }
        return true;
    }
};