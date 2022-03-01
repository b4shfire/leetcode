// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1);
        ans[0] = 0;
        
        // for each power of two
        for (int cnt=1; cnt<=n*2; cnt*=2) {
            
            // duplicate the array, adding 1 to all copied elements
            for (int i=min(cnt, n-cnt); i>=0; --i) {
                
                ans[cnt+i] = ans[i]+1;
            }
        }
        
        return ans;
    }
};
