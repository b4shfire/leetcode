// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int low = prices[0];
        int ans = 0;
        
        for (const auto& p : prices){
            low = min(low, p);
            ans = max(ans, p - low);
        }
        
        return ans;
    }
};
