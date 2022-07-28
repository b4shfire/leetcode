// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;
        
        unordered_map<char, int> s_chars;
        
        for (char c : s)
            ++s_chars[c];
    
        for (char c : t) {
            if (--s_chars[c] < 0)
                return false;
        }
        
        return true;
    }
};
