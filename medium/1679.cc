// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int, int> prev;
        
        int pairs = 0;
        
        for (int n : nums) {
            if (prev[k-n] > 0) {
                --prev[k-n];
                ++pairs;
            } else {
                ++prev[n];
            }
        }
        
        return pairs;
    }
};
