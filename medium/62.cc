// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {

        long ans = 1;
        
        for (int i=1; i<n; ++i) {
            ans *= (m + i - 1);
            ans /= i;
        }

        return ans;
    }
};
