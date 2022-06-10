// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // maps s[i] => i for the most recent occurence of s[i]
        unordered_map<char, int> indices;
        
        int start = 0, end = 0, longest = 0;
        
        for (; end<s.size(); ++end){
            
            auto prev = indices.find(s[end]);
            
            // check if this character is already in the substring
            if (prev != indices.end() && prev->second >= start){
                longest = max(longest, end-start);
                start = prev->second + 1; // move start to exclude the first occurence
            }
        
            // add the current character to the map
            indices[s[end]] = end;
        }
        
        return max(longest, end-start);
    }
};
