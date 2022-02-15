// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int XOR = 0;
        
        for (const auto& n : nums) XOR ^= n;
        
        // x ^ x = 0, so elements which occur twice will cancel each other out
        return XOR;
    }
};
