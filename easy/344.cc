// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        const int N = s.size();
        
        for (int i=0; i<N/2; ++i) {
            char temp = s[i];
            s[i] = s[N-i-1];
            s[N-i-1] = temp;
        }
    }
};
