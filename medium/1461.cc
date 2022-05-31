// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<int> seen;
        int curr = 0, mask = (1<<k)-1;
        
        for (int i=0; i<s.size(); ++i) {
            curr = ((curr << 1) + (s[i] == '1')) & mask;
            if (i >= k-1) seen.insert(curr);
            if (seen.size() == mask+1) return true;
        }
        
        return false;
    }
};
