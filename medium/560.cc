// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // maps sum(nums[0:i]) => number of 'i's for which this is true
        unordered_map<int, int> prev;
        prev[0] = 1;
        
        int count = 0, rt = 0;
        
        for (const auto& n : nums){
            rt += n;                // update running total
            count += prev[rt-k];    // find number of valid subarrays which end here
            prev[rt]++;             // add running total to map
        }
        
        return count;
    }
};
