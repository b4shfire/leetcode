// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
            
        vector<int> partitions;
        unordered_map<char, int> freq;
        unordered_map<char, bool> seen;
        
        // count the occurences of each character
        for (char c : s) ++freq[c];

        int remaining = 0, prev_idx = -1;
        
        for (int i=0; i<s.size(); ++i) {
            
            if (seen[s[i]] == true) {
                // this partition already includes s[i]
                --remaining;
            } else {
                // this partition needs to include all occurences of s[i]
                remaining += freq[s[i]] - 1;
                seen[s[i]] = true;
            }
            
            if (remaining == 0) {
                // this partition includes all occurences of its constituent characters
                partitions.push_back(i-prev_idx);
                prev_idx = i;
            }
        }
        
        return partitions;
    }
};
