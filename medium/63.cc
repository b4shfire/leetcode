// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        const int M = obstacleGrid.size();
        const int N = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[M-1][N-1] == 1) return 0;
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        dp[0][0] = 1;
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (j > 0) dp[i][j] += dp[i][j-1];
                if (i > 0) dp[i][j] += dp[i-1][j];
            }
        }
        
        return dp[M-1][N-1];
    }
};
