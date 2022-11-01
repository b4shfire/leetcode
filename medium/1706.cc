// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        const int M = grid.size();
        const int N = grid[0].size();
        
        vector<int> dp(N);
        iota(dp.begin(), dp.end(), 0);
        
        for (int i=M-1; i>=0; --i) {
            int tmp;
            for (int j=0; j<N; ++j) {
                if (grid[i][j] == -1) {
                    if (j == 0 || grid[i][j-1] == 1)
                        tmp = -1;
                    swap(tmp, dp[j]);
                } else {
                    tmp = dp[j];
                    dp[j] = (j == N-1 || grid[i][j+1] == -1) ? -1 : dp[j+1]; 
                }
                
            }
        }
        
        return dp;
    }
};
