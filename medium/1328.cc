// https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        const int N = palindrome.size();
        
        if (N == 1) return "";
        
        for (int i=0; i<N/2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[N-1] = 'b';
        return palindrome;
    }
};
