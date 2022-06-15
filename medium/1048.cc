// https://leetcode.com/problems/longest-string-chain/

class Solution {
    
    // assumes that b.size() == a.size() + 1
    bool is_predecessor(const string& a, const string& b) {

        bool inserted = false;
        
        for (int i=0; i<a.size(); ++i) {
            if (a[i] != b[i+inserted]) {
                if (inserted) return false;
                if (a[i] == b[i+1]) inserted = true;
                else return false;
            }
        }
        
        return true;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        
        // maps len => vector of words with length len
        map<int,vector<string>> length_to_words;
        
        for (const string& w : words)
            length_to_words[w.size()].push_back(w);
        
        int longest = 0;
        int prev_len = -1;
        
        // stores {end word, chain length} for all chains being considered
        vector<pair<string,int>> prev;
        
        // iterate in increasing order of length
        for (auto&[len, v] : length_to_words) {
            
            // we can only add a single character in one step
            if (len != prev_len + 1) prev.clear();

            vector<pair<string,int>> next;
            
            for (const string& w : v) {
                
                int longest_pred = 0;
                
                // search for predecessors
                for (const pair<string,int>& p : prev) {
                    if (is_predecessor(p.first, w)) {
                        longest_pred = max(longest_pred, p.second);
                    }
                }
                
                // extend an existing chain or create a new one
                next.push_back({w, longest_pred+1});
                longest = max(longest, longest_pred+1);
            }
            
            // move semantics for O(1) assignment
            prev = move(next);
            prev_len = len;
        }
        
        return longest;
    }
};
