class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> partial_totals;
        
        for (const auto& a : nums1){
            for (const auto& b : nums2){
                partial_totals[a+b]++;
            }
        }
        
        int count = 0;

        for (const auto& a : nums3){
            for (const auto& b : nums4){
                count += partial_totals[-(a+b)];
            }
        }
        
        return count;
    }
};
