// https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
            
        const vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

        // stores the lowest effort path that has reached each square
        vector<vector<int>> lowest_effort(ROWS, vector<int>(COLS, -1));
        
        // custom comparison lambda - sorts on effort descending then x+y ascending
        auto comp = [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
                        if (a.second != b.second) return a.second > b.second;
                        else return (a.first.first + a.first.second) < (b.first.first + b.first.second);
                    };
        
        // stores {{x,y}, effort} for all paths being considered
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(comp)> pq(comp);
        
        // add the start square
        pq.push({{0,0}, 0});
        lowest_effort[0][0] = 0;
        
        while (!pq.empty()) {
            
            auto[pos, effort] = pq.top(); pq.pop();
            
            // check if we have reached the target
            if (pos.first == COLS-1 && pos.second == ROWS-1) return effort;
            
            for (const pair<int, int>& d : directions) {
                
                // the coordinates of the neighbouring square being considered
                int x = pos.first + d.first;
                int y = pos.second + d.second;

                // make sure the square is within the bounds of the grid
                if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
                    
                    int new_effort = max(effort, abs(heights[pos.second][pos.first] - heights[y][x]));
                    
                    // avoid visiting previously-visited squares, unless we have a lower effort than the previous visit
                    if (lowest_effort[y][x] == -1 || new_effort < lowest_effort[y][x]) {
                        pq.push({{x,y}, new_effort});
                        lowest_effort[y][x] = new_effort;
                    }
                }
            }
        }
        
        return -1;
    }
};
