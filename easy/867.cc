// https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        vector<vector<int>> ans(N, vector<int>(M));
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                ans[j][i] = matrix[i][j];
            }
        }
        
        return ans;
    }
};
