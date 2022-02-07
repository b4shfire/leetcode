// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int XOR = 0;
        
        // x ^ x = 0 so letters which occur an even number of times will cancel out
        for (const auto& c : s) XOR ^= c;
        for (const auto& c : t) XOR ^= c;

        return XOR;
    }
};
