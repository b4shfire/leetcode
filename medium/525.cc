// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        const int N = nums.size();
        
        // maps i => j, where j is the smallest number such that nums[0:j] contains i more 1s than 0s
        unordered_map<int, int> firsts;
        firsts[0] = -1;
        
        int longest = 0;
        int balance = 0;
        
        for (int i=0; i<N; ++i){
            
            balance += (nums[i]==1 ? 1 : -1);
            
            auto prev = firsts.find(balance);
            
            if (prev == firsts.end()) firsts[balance] = i;
            else longest = max(longest, i - prev->second);
        }

        return longest;        
    }
};
