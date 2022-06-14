// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int N=word1.size(), M=word2.size();

        vector<int> dp(M+1, 0);
        
        for (int i=1; i<N+1; ++i) {
            int temp = 0;
            for (int j=1; j<M+1; ++j) {
                temp = (word1[i-1] == word2[j-1] ? temp + 1 : max(dp[j-1], dp[j]));
                swap(dp[j], temp);
            }
        }
        
        return N + M - 2*dp[M];
    }
};
