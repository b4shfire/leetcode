// https://leetcode.com/problems/jump-game-vi/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        // monodeque storing {i, maxResult(nums[0]...nums[i], k)}
        deque<pair<int,int>> dq({{0,nums[0]}});
        
        for (int i=1; i<nums.size(); ++i) {
            int curr = dq.back().second + nums[i];
            if (nums[i] > 0) {
                dq.clear();
            } else {
                while (dq.front().second < curr)
                    dq.pop_front();
            }
            dq.push_front({i,curr});
            while (dq.back().first + k <= i)
                dq.pop_back();
        }
        
        return dq.front().second;
    }
};
