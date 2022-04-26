// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
    
    // returns the manhattan distance between a and b
    int _dist(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // stores {distance to closest connected point, index} for all unconnected points
        vector<pair<int, int>> todo;
        
        // initialise todo with distances to points[0]
        for (int i=1; i<points.size(); ++i)
            todo.push_back({_dist(points[0], points[i]), i});
        
        // the length of our path
        int total_dist = 0;
        
        while (!todo.empty()) {
            
            // find the unconnected point which is closest to a connected point
            auto closest = min_element(todo.begin(), todo.end());
            
            int dist = closest->first;
            int idx = closest->second;
            
            // add the distance to this point
            total_dist += dist;
            
            // remove the point from todo (swap with last element for faster deletion)
            swap(*closest, todo.back());
            todo.pop_back();
            
            // update the distances in todo, as some points may now be closer
            for (pair<int, int>& p : todo)
                p.first = min(p.first, _dist(points[idx], points[p.second]));
        }
        
        return total_dist;
    }
};
