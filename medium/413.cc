// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        const int N = nums.size();
        
        int delta=0, count=0, ans=0;
        
        for (int i=1; i<N; ++i) {
            
            if (nums[i]-nums[i-1] == delta) {
                ans += count;
                count++;
            } else {
                delta = nums[i]-nums[i-1];
                count = 1;
            }
        }

        return ans;
    }
};
