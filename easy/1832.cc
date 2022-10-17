// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_set<char> seen;
        
        for (char c : sentence) {
            seen.insert(c);
            if (seen.size() == 26) return true;
        }
        
        return false;
    }
};
