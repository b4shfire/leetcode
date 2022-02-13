// https://leetcode.com/problems/subsets/

class Solution {   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        const int N = nums.size();
        const int NUM_SUBSETS = 1 << N;
        
        vector<vector<int>> subs(NUM_SUBSETS);
        
        // each subset can be represented by a bitmask, 1=include and 0=exclude the corresponding element in @nums
        for (int bitmask=0; bitmask<NUM_SUBSETS; ++bitmask){
            
            for (int i=0; i<N; ++i){
                if (bitmask & 1<<i) subs[bitmask].push_back(nums[i]);
            }
        }
        
        return subs;
    }
};
