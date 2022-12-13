// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        const int N = matrix.size();

        vector<int> dp = matrix[0];
        dp.push_back(INT_MAX); // sentinel value to obviate the need for bounds-checking 

        for (int i=1; i<N; ++i) {
            int tmp = dp[0]; // tmp stores dp[j-1] before it was overwritten
            for (int j=0; j<N; ++j) {
                tmp = min({tmp, dp[j], dp[j+1]}) + matrix[i][j];
                swap(tmp, dp[j]);
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};
