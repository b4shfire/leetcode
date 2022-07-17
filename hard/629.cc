// https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int kInversePairs(int n, int k) {
        
        const int P = 1000000007;
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        
        for (int i=2; i<=n; ++i) {
            for (int j=1; j<k+1; ++j)
                dp[j] = (dp[j] + dp[j-1]) % P;
            for (int j=k; j>=i; --j)
                dp[j] = (P + dp[j] - dp[j-i]) % P;
        }
        
        return dp[k];
    }
};
