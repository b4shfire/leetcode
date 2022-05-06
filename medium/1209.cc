// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector<pair<char, int>> st = {{' ', 0}};
        
        for (char c : s) {
            if (c == st.back().first) {
                if (++st.back().second == k) st.pop_back();
            } else {
                st.push_back({c, 1});
            }
        }
        
        string res;
        
        for (const pair<char, int>& p : st)
            res.append(p.second, p.first);
        
        return res;
    }
};
