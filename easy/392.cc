// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        const int NS = s.size();
        const int NT = t.size();
        
        // stores the current index in s
        int i = 0;
        
        // loop over each character in t
        for (int j=0; i<NS && j<NT; j++){

            // if t[j] matches s[i], move on to the next char in s
            if (s[i] == t[j]) i++;
        }
        
        // check whether we got to the end of s
        return (i == NS);
    }
};
