// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // stores the color of each node: -1=A, 0=unset, 1=B
        vector<int> colors(graph.size(), 0);
        
        // stores the index of each node being considered
        queue<int> q;
        
        for (int i=0; i<graph.size(); ++i) {
        
            // check if node has already been visited
            if (colors[i] != 0) continue;

            // color the node and add it to the queue
            colors[i] = -1;
            q.push(i);

            while (!q.empty()) {
                int idx = q.front(); q.pop();
                
                // all neighbouring nodes should have the opposite color
                for (int n : graph[idx]) {
                    if (colors[n] == 0) {
                        colors[n] = -colors[idx];
                        q.push(n);
                    } else if (colors[n] != -colors[idx]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
