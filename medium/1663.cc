// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution {
public:
    string getSmallestString(int n, int k) {
        
        // the best solution is always ...aaa?zzz...
        // where ? represents an unknown 'bridge' character to add up to exactly k
        // we can find the number of 'a's and the value of '?' by solving the equation:
        // a_count + bridge + (n-a_count-1)*26 = k
        
        int a_count = n - (k-n-1)/25 - 1;
        char bridge = 'a' + (a_count+1)*25 + k - n*26;
        
        string ans(n, 'z');
        fill(ans.begin(), ans.begin()+a_count, 'a');
        ans[a_count] = bridge;
        
        return ans;
    }
};
