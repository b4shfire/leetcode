// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        int l=0, r=N*M-1;
        
        while (l<=r) {
            int m = (l+r)/2;
            int val = matrix[m/M][m%M];
            if (val == target) return true;
            else if (val < target) l = m + 1;
            else r = m - 1;
        }
        
        return false;
    }
};
