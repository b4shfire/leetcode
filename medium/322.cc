// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        
        for (int i=0; i<amount+1; ++i) {
            for (int c : coins) {
                if (i - c < 0) break;
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }

        return (dp[amount] == INT_MAX-1 ? -1 : dp[amount]);
    }
};
