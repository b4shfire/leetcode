// https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // sort on interval starts (asc), then interval ends (desc)
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b)
        {
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];
        });
        
        
        int count=0, end=0;
        
        for (const auto& i : intervals){
            
            // if this interval finishes after all currently open intervals
            if (i[1] > end){
                end = i[1];
                ++count;
            }
        }
        
        return count;
    }
};
