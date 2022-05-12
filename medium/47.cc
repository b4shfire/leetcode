// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        const int N = nums.size();
        
        vector<vector<int>> ans;
        
        // put nums into increasing order
        sort(nums.begin(), nums.end());
        
        while (true) {
            
            // add this permutation to the result
            ans.push_back(nums);
            
            int i, j;
            
            // find the largest i such that nums[i] < nums[i+1]
            for (i=N-2; i>=0; --i) {
                if (nums[i] < nums[i+1]) break;
            }
            
            // if nums is in decreasing order we have found all permutations
            if (i == -1) return ans;

            // find the largest j such that nums[j] > nums[i]
            for (j=N-1; j>i; --j) {
                if (nums[j] > nums[i]) break;
            }
            
            // generate the next permutation in numerical order
            swap(nums[i], nums[j]);
            sort(nums.begin()+i+1, nums.end());
        }
        
        return ans;
    }
};
