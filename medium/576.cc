// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<uint32_t>> dp(m+2, vector<uint32_t>(n+2, 0));
        
        for (int i=0; i<m+2; ++i) dp[i][0] = dp[i][n+1] = 1;
        for (int j=0; j<n+2; ++j) dp[0][j] = dp[m+1][j] = 1;

        for (int move=0; move<maxMove; ++move) {
            vector<uint32_t> saved(n+2, 1);
            for (int i=1; i<m+1; ++i) {
                for (int j=1; j<n+1; ++j) {
                    uint32_t temp = dp[i][j];
                    dp[i][j] = (saved[j] + saved[j-1] + dp[i][j+1] + dp[i+1][j]) % 1000000007;
                    saved[j] = temp;
                }
            }
        }
        
        return dp[startRow+1][startColumn+1];
    }
};
