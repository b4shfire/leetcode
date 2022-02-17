// https://leetcode.com/problems/combination-sum/

class Solution {
    
    void find_combinations(vector<int>& candidates, vector<vector<int>>& combos, vector<int>& path, int index, int sum, int target){
        
        // base cases
        if (sum == target) combos.push_back(path);
        if (sum >= target) return;
        
        // start at 'index' to avoid duplicate solutions
        for (int i=index, n=candidates.size(); i<n; ++i){
            
            sum += candidates[i];
            path.push_back(candidates[i]);
            
            find_combinations(candidates, combos, path, i, sum, target);
            
            sum -= candidates[i];
            path.erase(path.end()-1);
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // put candidates in increasing order to avoid duplicate solutions
        sort(candidates.begin(), candidates.end());
                
        vector<vector<int>> combos;
        vector<int> prefix;
        
        find_combinations(candidates, combos, prefix, 0, 0, target);
        
        return combos;
    }
};
