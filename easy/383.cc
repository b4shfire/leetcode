// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> magazine_chars;
        
        for (char c : magazine)
            ++magazine_chars[c];
        
        for (char c : ransomNote)
            if (--magazine_chars[c] < 0) return false;
        
        return true;
    }
};
