// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
  
    void _dfs(vector<vector<int>>& paths, int node, vector<vector<int>>& graph, vector<int>& prefix) {
        if (node == graph.size() - 1)
            return paths.push_back(prefix);

        for (int neighbour : graph[node]) {
            prefix.push_back(neighbour);
            _dfs(paths, neighbour, graph, prefix);
            prefix.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> prefix({0});
        _dfs(paths, 0, graph, prefix);
        return paths;
    }
};
