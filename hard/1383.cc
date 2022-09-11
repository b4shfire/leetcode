// https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<int,int>> engineers(n);
        
        for (int i=0; i<n; ++i)
            engineers[i] = {efficiency[i], speed[i]};
        
        sort(engineers.begin(), engineers.end(), greater<>());
        
        priority_queue<int, vector<int>, decltype(greater<>())> speeds;
        
        uint64_t speed_sum = 0, max_performance = 0;
        
        for (const pair<int,int>& stats : engineers) {
            speeds.push(stats.second);
            speed_sum += stats.second;
            max_performance = max(max_performance, speed_sum * stats.first);
            if (speeds.size() == k) {
                speed_sum -= speeds.top(); speeds.pop();
            }
        }
        
        return max_performance % 1000000007;
    }
};
