// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1];
            });
    
        int units = 0;
    
        for (const vector<int>& b : boxTypes) {
            units += min(b[0], truckSize) * b[1];
            truckSize -= b[0];
            if (truckSize <= 0) return units;
        }
        
        return units;
    }
};
