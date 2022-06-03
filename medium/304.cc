// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
    
    vector<vector<int>> _dp;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {

        int M = matrix.size(), N = matrix[0].size();
        _dp = vector<vector<int>>(M+1, vector<int>(N+1, 0));
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                // _dp[i+1][j+1] = sum(0,0,i,j)
                _dp[i+1][j+1] = matrix[i][j] + _dp[i][j+1] + _dp[i+1][j] - _dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // sum(a,b,c,d) = sum(0,0,c,d) - sum(0,0,a-1,d) - sum(0,0,c,b-1) + sum(0,0,a-1,b-1)
        
        return _dp[row2+1][col2+1] - _dp[row1][col2+1] - _dp[row2+1][col1] + _dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
