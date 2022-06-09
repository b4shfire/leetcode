// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i=0, j=numbers.size()-1;
        
        while (i < j) {
            if (numbers[i] + numbers[j] < target) ++i;
            else if (numbers[i] + numbers[j] > target) --j;
            else return {i+1, j+1};
        }
        
        return {};
    }
};
