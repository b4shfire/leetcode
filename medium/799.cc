// https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // dp[i][j] represents the units of champagne that pass through the glass at row i, col j
        vector<vector<double>> dp(query_row+1, vector<double>(query_row+1, 0.0));
        dp[0][0] = static_cast<int>(poured);
        
        // simulate down to query_row
        for (int row=0; row<query_row; row++){
            for (int glass=0; glass<=row; glass++){
                
                double overflow = max(dp[row][glass]-1.0, 0.0) / 2;
                
                dp[row+1][glass] += overflow;
                dp[row+1][glass+1] += overflow;
            }
        }
        
        // if more than 1 unit flows through the query glass, must return 1.0
        return min(dp[query_row][query_glass], 1.0);
    }
};
