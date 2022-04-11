// https://leetcode.com/problems/shift-2d-grid/

class Solution {
    
    void _reverse2d(vector<vector<int>>& grid, int start, int end) {

        const int N = grid[0].size();
        
        for (int i=start, j=end; i<j; ++i, --j) {
            swap(grid[i/N][i%N], grid[j/N][j%N]);
        }
    }
    
public:
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        const int M = grid.size();
        const int N = grid[0].size();
        
        k %= M*N;

        _reverse2d(grid, 0, M*N-1);
        _reverse2d(grid, k, M*N-1);
        _reverse2d(grid, 0, k-1);
        
        return grid;
    }
};
