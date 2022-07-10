// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int prev_prev=0, prev=0;
        
        for (int c : cost) {
            prev_prev = min(prev_prev, prev) + c;
            swap(prev_prev, prev);
        }
        
        return min(prev_prev, prev);
    }
};
