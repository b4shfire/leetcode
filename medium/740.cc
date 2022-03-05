// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        // maps n => points gained by deleting all occurences of n
        map<int, int> m;
        
        // populate the map
        for (int n : nums) m[n] += n;

        int points = 0, prev_points = 0, prev = 0;
        
        for (const auto& curr : m) {
            
            // if curr.first == prev + 1, choosing this number would delete the previous number
            // in that case, we have to decide whether to keep this number or the previous one
            int new_points = (curr.first == prev + 1) ? max(points, prev_points + curr.second) : points + curr.second;
            
            // update the state
            prev = curr.first;
            prev_points = points;
            points = new_points;
        }
        
        return points;
    }
};
