// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int XOR = nums.size();

        for (int i=0; i<nums.size(); ++i) {
            XOR ^= nums[i] ^ i;
        }
        
        return XOR;
    }
};
