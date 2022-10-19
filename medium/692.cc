// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> counts;
        priority_queue<pair<int,string>> pq;
        vector<string> ans(k);
        
        for (const string& w : words) ++counts[w];
        
        for (const pair<string,int>& c : counts) {
            pq.push({c.second*-1, c.first}); // multiply count by -1 to make the sort order work
            if (pq.size() > k) pq.pop();
        }
        
        for (int i=k-1; i>=0; --i) {
            ans[i] = pq.top().second; pq.pop();
        }
        
        return ans;
    }
};
