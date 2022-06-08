// https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    int removePalindromeSub(string s) {
        
        const int N = s.size();
        
        // return 1 if s is a palindrome, and 2 if it isn't
        for (int i=0; i<N/2; ++i) {
            if (s[i] != s[N-i-1]) return 2;
        }
        
        return 1;
    }
};
