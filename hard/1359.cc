// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution {
public:
    int countOrders(int n) {
        
        long ans = 1;
        
        for (int i=2; i<=n; ++i){
            
            ans *= (i*2 - 1) * i;
            ans %= 1000000007;
        }
        
        return ans;
    }
};
