// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> counts;

        for (int t : tasks) ++counts[t];

        int rounds = 0;

        for (const pair<int,int>& c : counts) {
            if (c.second == 1) return -1;
            rounds += (c.second - 1) / 3 + 1;
        }

        return rounds;
    }
};
