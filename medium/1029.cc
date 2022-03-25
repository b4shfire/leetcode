// https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        const int N = costs.size();
        
        // sort 'costs' on the price difference between flying each candidate to city a vs city b
        // we use nth_element because a full sort is not required
        nth_element(costs.begin(), costs.begin()+N/2, costs.end(), 
                    [](const vector<int>& a, const vector<int>& b){
                        return (a[0] - a[1]) > (b[0] - b[1]);
                    });
        
        int cost = 0;
        
        for (int i=0; i<N/2; ++i) cost += costs[i][1];
        for (int i=N/2; i<N; ++i) cost += costs[i][0];
        
        return cost;
    }
};
