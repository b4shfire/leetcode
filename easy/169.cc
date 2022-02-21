// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int val = 0, count = 0;
        
        for (const auto& n : nums){
            
            if (count == 0) val = n;
            count += (n == val) ? 1 : -1;
        }
        
        return val;
    }
};
