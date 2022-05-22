// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        
        const int N = s.size();
        
        int ans = N;
        
        for (int i=1; i<N; ++i) {
            
            // odd-length palindromes
            for (int j=1; j<min(i+1, N-i); ++j) {
                if (s[i-j] == s[i+j]) ++ans;
                else break;
            }
            
            // even-length palindromes
            for (int j=0; j<min(i, N-i); ++j) {
                if (s[i-j-1] == s[i+j]) ++ans;
                else break;
            }
        }
        
        return ans;
    }
};
