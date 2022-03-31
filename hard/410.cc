// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
    
    // check whether nums can be partitioned into m subarrays such that no subarray sum exceeds max_sum
    bool partition_possible(const vector<int>& nums, int m, int max_sum) {

        int curr_sum = 0;
        
        for (int n : nums) {
            
            curr_sum += n;
                           
            // if max_sum exceeded, start a new subarray and decrement m 
            if (curr_sum > max_sum) {
                curr_sum = n;
                if (--m == 0)
                    return false; // we require more than m subarrays
            }
        }
        
        // successfully partitioned the array
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        
        int l = *max_element(nums.begin(), nums.end()); // smallest possible answer, the largest element in nums
        int r = accumulate(nums.begin(), nums.end(), 0); // largest possible answer, sum of all elements (when m=1)
        
        while (l < r) {
            int mid = (l+r)/2;
            if (partition_possible(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        
        // l now contains the smallest possible value of max_sum
        return l;
    }
};
