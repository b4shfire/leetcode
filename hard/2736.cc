// https://leetcode.com/problems/maximum-sum-queries/

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

        vector<pair<int,int>> pairs(nums1.size());
        transform(nums1.begin(), nums1.end(), nums2.begin(), pairs.begin(),
                [](int a, int b) { return make_pair(a,b); });
        sort(pairs.begin(), pairs.end(), greater<>());

        auto dst = pairs.begin();
        for (auto src = next(pairs.begin()); src != pairs.end(); ++src)
            if (src->second > dst->second) *(++dst) = *src;
        pairs.erase(next(dst), pairs.end());

        const unsigned M = pairs.size(), N = bit_ceil(M);
        vector<int> dp(N*2);

        transform(pairs.begin(), pairs.end(), dp.begin()+N, 
            [](const auto& p) { return p.first + p.second; });
        for (int i=N-1; i>0; --i)
            dp[i] = max(dp[2*i], dp[2*i+1]);

        vector<int> ans(queries.size(), -1);

        for (int i=queries.size()-1; i>=0; --i) {
            auto lb = lower_bound(pairs.begin(), pairs.end(), queries[i][1],
                [](const pair<int,int>& a, int b) { return a.second < b; });
            auto rb = lower_bound(pairs.rbegin(), pairs.rend(), queries[i][0],
                [](const pair<int,int>& a, int b) { return a.first < b; });
 
            if (distance(lb, rb.base()) <= 0)
                continue;

            unsigned l = N + (lb - pairs.begin()),
                     r = N + (pairs.rend() - rb - 1),
                     depth = max(bit_width(l ^ r) - 1, 0);

            ans[i] = max(dp[l], dp[r]);

            while (depth--) {
                if (!(l & 1))  ans[i] = max(ans[i], dp[l+1]);
                if (  r & 1 )  ans[i] = max(ans[i], dp[r-1]);
                l >>= 1, r >>= 1;
            }
        }

        return ans;
    }
};
