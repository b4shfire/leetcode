// https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        vector<vector<string>> ans(searchWord.size());
        sort(products.begin(), products.end());
        
        for (const string& p : products) {
            
            // find the longest common prefix between p and searchWord
            int len = distance(searchWord.begin(),
                               mismatch(searchWord.begin(), searchWord.end(), 
                                        p.begin(), p.end()).first);
            
            for (int i=len-1; i>=0; --i) {
                if (ans[i].size() == 3) break;
                ans[i].push_back(p);
            }
            
            if (ans.back().size() == 3)
                return ans;
        }
        
        return ans;
    }
};
