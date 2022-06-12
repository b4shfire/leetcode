// https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        // maps nums[i] => {i, sum(nums[0]...nums[i-1])}
        unordered_map<int,pair<int,int>> indices;
        
        int start=0, sum=0, max_score=0;
        
        for (int end=0; end<nums.size(); ++end) {
            
            auto prev = indices.find(nums[end]);
            
            if (prev != indices.end() && prev->second.first >= start) {
                max_score = max(max_score, sum - indices[nums[start]].second);
                start = prev->second.first + 1;
            }
            
            indices[nums[end]] = {end, sum};
            sum += nums[end];
        }
        
        return max(max_score, sum - indices[nums[start]].second);
    }
};
