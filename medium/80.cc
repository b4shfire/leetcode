// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        const int N = nums.size();
        
        // d = dest index, s = source index
        int d = 2;
        
        for (int s=2; s<N; ++s){

            // check for repeats
            if (nums[s] != nums[s-1] || nums[d-1] != nums[d-2]){
                nums[d++] = nums[s];
            }
        }
        
        // guard against N=1
        return min(d, N);
    }
};
