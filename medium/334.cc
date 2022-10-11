// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int a=INT_MAX, b=INT_MAX;
        
        for (int n : nums) {
            if (n <= a)
                a = n;
            else if (n <= b)
                b = n;
            else
                return true;
        }
        
        return false;
    }
};
